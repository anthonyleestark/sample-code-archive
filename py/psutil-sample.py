# If you want a cross-platform solution, you can use the psutil library in Python. This works on Windows, Linux, and macOS:
# This will continuously check if the specified process is running and print a message when it starts.

import psutil
import time

def check_for_process(process_name):
    for proc in psutil.process_iter(['pid', 'name']):
        if proc.info['name'] == process_name:
            return True
    return False

process_name = "yourprocess.exe"  # Change as needed

while True:
    if check_for_process(process_name):
        print(f"Process {process_name} has started.")
        break
    time.sleep(1)
