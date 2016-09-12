"""
    Name: simpleArduinoOutputCapture.py
    Author: Chris Wininger
    Install:
        1. install python3
        2. install pip for python3
        3. run: pip install pyserial
        4. update Serial string from /dev/ttyACM0 to port with arduino
    Ussage
        python simpleArduinoOutputCapture.py
"""

import serial
import io
import datetime

ser = serial.Serial('/dev/ttyACM0', 9600)
fileName = 'sample_{:%Y_%m_%d_%H_%M_%S}.csv'.format(datetime.datetime.now())

print('writing data to ' + fileName);
with io.open(fileName, 'wb') as myFile:
    while True:
        serialData = ser.readline()
        myFile.write(serialData)
        print(serialData)
