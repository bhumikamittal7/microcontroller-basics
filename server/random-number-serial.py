import serial
import csv
import time

filename = 'ECGdata3.csv'

# Create a CSV file and write the header
with open(filename, 'w', newline='') as csvFile:
    writer = csv.writer(csvFile)
    writer.writerow(['Time_in_ms', 'ECG_value'])

print(f'Created Log File -> {filename}')

arduino_port = "COM5"  # Serial port of Arduino
baud = 9600  # Arduino runs at 9600 baud

SerialObj = serial.Serial(arduino_port, baud)

# Open the serial port
while True:
    received_string = SerialObj.readline().decode().strip()
    print(received_string)
    try:
        analog_data = received_string.split('\t')
        ecg_value = analog_data[0]
        time_now = time.strftime('%H:%M:%S')

        # Write the time and ECG value to the CSV file
        with open(filename, 'a', newline='') as csvFile:
            writer = csv.writer(csvFile)
            # write time in next column
            writer.writerow([time_now, ecg_value])

        print(f'Received: {ecg_value}')
    except Exception as e:
        print(str(e))
