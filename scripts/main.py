"""
Copyright (c) 2026 Nora Rose. All rights reserved.

DUAL-LICENSING NOTICE:
This software is licensed under two separate license agreements:

1. PROPRIETARY LICENSE: For commercial use, income generation, or
   distribution for profit. This use is strictly prohibited without
   prior written consent from Nora Rose.

2. MIT LICENSE: For personal, educational, or non-commercial use.
   See LICENSE-MIT for the full license text.

SPDX-License-Identifier: MIT OR LicenseRef-Proprietary-Nora-Rose

DISCLAIMER:
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
"""

import socket
import time
import sys
from concurrent.futures import ThreadPoolExecutor

def request(IP, Protocol, IPv6, port):
 #for Port in range(1, total_ports + 1):
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
    result = scan.connect_ex((IP, port))
    if result == 0:
     print(f"OPEN: IP: {IP}", f"Port:{port}")
    #else:
     #print(f"CLOSE: IP: {IP}", f"Port: {port}")  
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
    total_ports = 1024
    
    print(f"Internet Protocol Type: {IPv6}") 
    print(f"Protocol: {Protocol}") 
    print(f"IP address passed to script: {IP}")
    ##request(self="", IP=IP)
    print(sys._is_gil_enabled())
    with ThreadPoolExecutor(max_workers=100) as executor:
        for port in range(1, total_ports + 1):
         executor.submit(request, IP, Protocol, IPv6, port)
     
