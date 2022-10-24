import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
import serial
from datetime import datetime
import time
import string

ser1 = serial.Serial("/dev/rfcomm0", 9600)
ser2 = serial.Serial("/dev/rfcomm1", 9600)
ser3 = serial.Serial("/dev/rfcomm2", 9600)

while True:
    dtime = datetime.now()
    minute = dtime.minute
    if minute < 10:
        watch = str(dtime.hour) + ':0' + str(minute)
    else:
        watch = str(dtime.hour) + ':' + str(minute)
    print('Watch: ', watch)
    second = dtime.second
    print('Second:', second)

    if watch == "10:52" and second < 30:
        ser1.write(str.encode("ALARM_ON"))
        publish.single("ifn649", "ALARM_RINGING", hostname="3.27.28.141")
        
    if ser2.in_waiting > 0:
        button_status = ser2.readline().decode('utf-8').strip('\r\n')
        if button_status != '':
            print('Buttonstatus:', button_status)
            button = int(button_status)
            if button == 1:
                ser1.write(str.encode("ALARM_OFF"))
                
    if ser1.in_waiting > 0:
        temp = ser1.readline().decode('UTF-8').strip('\r\n')
        if temp != '':
            temperature = float(temp)
            print('The current temperature is: ', temperature)
            if temperature < 25:
                ser3.write(str.encode("COLD"))
                publish.single("ifn649", "COLD", hostname="3.27.28.141")
            elif 25 <= temperature <= 26:
                ser3.write(str.encode("MODERATE"))
                publish.single("ifn649", "MODERATE", hostname="3.27.28.141")
            elif temperature > 26:
                ser3.write(str.encode("HOT"))
                publish.single("ifn649", "HOT", hostname="3.27.28.141")
                
    time.sleep(2)