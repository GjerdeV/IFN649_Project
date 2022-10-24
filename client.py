import paho.mqtt.client as mqtt
import serial

ser1 = serial.Serial{"/dev/rfcomm0", 9600}
ser1 = serial.Serial{"/dev/rfcomm1", 9600}
ser1 = serial.Serial{"/dev/rfcomm2", 9600}

def on_connect(client, userdata, flags, rc):
    client.subscribe('ifn649')
    
def on_message(client, userdata, msg):
    if msg.payload.decode('UTF-8') == "ALARM_OFF":
        ser1.write(str.encode("ALARM_OFF"))
        print('success')
        
client = mqtt.Client()
client.on_message = on_message
client.connect('3.27.28.141', 1883, 60)
client.loop_forever