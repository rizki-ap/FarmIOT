#define CONST_PH_MUL -5.70
#define CONST_PH_ADD 21.34
#define TDS_FACTOR 0.5

const int pHAnalogPin = A0; 
const int pHEnablePin = 5; 
const int ECAnalogPin = A1; 
const int ECEnablePin = 6; 
//float waterTemperature = 25.0;

void setup() {
  //setting Serial comm
  Serial.begin(115200);
  //setting ph enable pin
  pinMode(pHEnablePin, OUTPUT);
  digitalWrite(pHEnablePin, HIGH);
  //setting ec enable pin
  pinMode(ECEnablePin, OUTPUT);
  digitalWrite(ECEnablePin, HIGH);
}

void loop() {
  float sensorPH = bacaPH();
  Serial.print("sensor pH = ");
  Serial.println(sensorPH);
  float sensorTDS = bacaTDS(25.0);
  Serial.print("sensor TDS (ppm)= ");
  Serial.println(sensorTDS);
}

float bacaEC(float waterTemperature){
  int buf[10],temp;
  unsigned long int avgValue=0; 

  digitalWrite(ECEnablePin, LOW);
  delay(1000);

  for(int i=0;i<10;i++) { 
    buf[i]=analogRead(ECAnalogPin);
    delay(10);
  }
  for(int i=0;i<9;i++){
    for(int j=i+1;j<10;j++){
      if(buf[i]>buf[j]){
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  for(int i=1;i<9;i++) avgValue+=buf[i];
  
  float voltage = (float)avgValue*5.0/1024/8;
  float ecValue = 133.42*voltage*voltage*voltage - 255.86*voltage*voltage + 857.39*voltage;
  float ecValue25 = ecValue / (1.0+0.02*(waterTemperature-25.0));  //temperature compensation

  digitalWrite(ECEnablePin, HIGH);
  return(ecValue25); 
}

float bacaTDS(float waterTemperature){
    return(bacaEC(waterTemperature)*TDS_FACTOR);
}

float bacaPH() {
  int buf[10],temp;
  unsigned long int avgValue=0; 

  digitalWrite(pHEnablePin, LOW);
  delay(1000);
  
  for(int i=0;i<10;i++) { 
    buf[i]=analogRead(pHAnalogPin);
    delay(10);
  }
  for(int i=0;i<9;i++){
    for(int j=i+1;j<10;j++){
      if(buf[i]>buf[j]){
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  for(int i=1;i<9;i++) avgValue+=buf[i];
  
  float pHVol = (float)avgValue*5.0/1024/8;
  float phValue = (pHVol* CONST_PH_MUL) + CONST_PH_ADD ;
  
  digitalWrite(pHEnablePin, HIGH);
  return(phValue); 
}
