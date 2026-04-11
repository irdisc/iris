import socket
import time
import sys

def request(self, IP):
 for Port in range(1, 1024):
  
  scan = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
  scan.settimeout(0.5)

  try:
    #time.sleep(5)
    result = scan.connect_ex((IP, Port))
    if result == 0:
     print(f"OPEN: IP: {IP}", f"Port: {Port}")
    #else:
     #print(f"CLOSE: IP: {IP}", f"Port: {Port}")  
  except Exception as e:
     print("test error:") 
  finally:
    scan.close()   


if __name__ == '__main__':
    # Access the same index you used in C
    IP = sys.argv[1] 
    print(f"IP address passed to script: {IP}")
    request(self="", IP=IP)