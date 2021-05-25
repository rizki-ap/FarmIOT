# FarmIOT
Hidroponic, Aquaponic automation system with IOT for TelkomUniversity Research

**Version-1

Using modules :
- PH-sensor of PH-4502C
- EC/TDS sensor 
- ESP32 module for wifi+BLE
- Arduino-Nano for sensor reading and control
- 5-pin 5v relays
- 

IOT server method:

Query:
http://hydropoda.smartiotindo.com/tes2.php?key_api=HibahYPT2021&s0=0&s1=1&s2=2&s3=3&s4=4&s5=5
Respon:
{"id":"1","id_pengguna":"2","security_key":"xeWlBl%2F98qVUtyxiVAL2ArVyr0md2L%2Bdd0JXrzc5wIs%3D","gambar":"","date_time":"2020-12-17 09:36:02"}

Query:
http://hydropoda.smartiotindo.com/tes3.php?key_api=HibahYPT2021&jenis=Pakcoy or
http://hydropoda.smartiotindo.com/tes3.php?key_api=HibahYPT2021&jenis=Selada or
http://hydropoda.smartiotindo.com/tes3.php?key_api=HibahYPT2021&jenis=Bayam or
http://hydropoda.smartiotindo.com/tes3.php?key_api=HibahYPT2021&jenis=Kangkung or
http://hydropoda.smartiotindo.com/tes3.php?key_api=HibahYPT2021&jenis=Sawi or
Respon:
{"ph_b":"5.5000","ph_a":"6.5000","ppm_b":"1050.0000","ppm_a":"1400.0000","suhu_b":"18.0000","suhu_a":"22.0000","kelembaban_b":"73.0000","kelembaban_a":"89.0000","rataan_cahaya":"12000.000","created_time":"2020-06-22 02:03:28"}
