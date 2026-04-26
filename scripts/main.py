# # # # # # # # # # # # # # # # # # # # # # # #
# Copyright (c) 2026 Nora Rose                # 
# All rights reserved.                        #
# This code is proprietary of Nora Rose.      #
# # # # # # # # # # # # # # # # # # # # # # # #

import socket
import time
import sys

def request(self, IP):
 for Port in range(1, 1024):

  if IPv6 == "-ipv6":
   scan = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
   if Protocol == "tcp": 
     scan = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
   if Protocol == "udp":
     scan = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
  else:
    scan = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if Protocol == "tcp": 
     scan = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if Protocol == "udp":
     scan = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

  scan.settimeout(0.5)

  try:
    #time.sleep(5)
    result = scan.connect_ex((IP, Port))
    if result == 0:
     print(f"OPEN: IP: {IP}", f"Port:{Port}")
    #else:
     #print(f"CLOSE: IP: {IP}", f"Port: {Port}")  
  #except Exception as e:
     #print("test error:") 
  except socket.gaierror as e:
    print(f"ERROR: INVAILD USE HOSTNAME: {e}")
    exit(1)
  finally:
    scan.close()   


if __name__ == '__main__':

    ART = """
     ███ ███ ███████████                      █████   
    ░███░███░░███░░░░░███                    ░░███    
    ░███░███ ░███    ░███  ██████  ████████  ███████  
    ░███░███ ░██████████  ███░░███░░███░░███░░░███░   
    ░███░███ ░███░░░░░░  ░███ ░███ ░███ ░░░   ░███    
    ░░░ ░░░  ░███        ░███ ░███ ░███       ░███ ███
     ███ ███ █████       ░░██████  █████      ░░█████ 
    ░░░ ░░░ ░░░░░         ░░░░░░  ░░░░░        ░░░░░  
                                                  
                                                  
                                                  
      █████████                                ███ ███
     ███░░░░░███                              ░███░███
    ░███    ░░░   ██████   ██████   ████████  ░███░███
    ░░█████████  ███░░███ ░░░░░███ ░░███░░███ ░███░███
     ░░░░░░░░███░███ ░░░   ███████  ░███ ░███ ░███░███
     ███    ░███░███  ███ ███░░███  ░███ ░███ ░░░ ░░░ 
     ░░█████████ ░░██████ ░░████████ ████ █████ ███ ███
       ░░░░░░░░░   ░░░░░░   ░░░░░░░░ ░░░░ ░░░░░ ░░░ ░░░ 
    """
    print(ART)
    # Access the same index you used in C
    IP = sys.argv[1] 
    Protocol = sys.argv[0]
    IPv6 = sys.argv[2]
    print(f"Internet Protocol Type: {IPv6}") 
    print(f"Protocol: {Protocol}") 
    print(f"IP address passed to script: {IP}")
    request(self="", IP=IP)
    