#!/usr/bin/env python3

import serial # type: ignore
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)

time.sleep(3)
ser.reset_input_buffer()
print('Serial OK')

try:
    while True:
        time.sleep(1)
        print("Sending message to Arduino!")
        ser.write("Hello from Raspberry Pi\n".encode('utf-8'))

        while ser.in_waiting <= 0:
            time.sleep(0.01)

        response = ser.readline().decode('utf-8').rstrip()
        print('Response: ' + response)
except KeyboardInterrupt:
    print('Closing Serial Communication.')
    ser.close()
