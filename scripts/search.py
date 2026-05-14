import urllib.parse
import requests
import sys
import re
from bs4 import BeautifulSoup
def search(html_content, string):
 print("test")
 encoded_query = urllib.parse.quote_plus(string)                      
 #for page_num in range(1, 51):
 url = f"http://google.com/search?q={encoded_query}&num=1"                      
 headers = {
   "User-Agent": "Mozilla/5.0 (Window NT 10.0; Win64; x64) AppleWebkit/547.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
 }
 response = requests.get(url, headers=headers)                     
 if response.status_code == 200:
    html_content = response.text
    soup = BeautifulSoup(html_content, 'html.parser')
    image = soup.find_all('img', src=re.compile(r'.*\.(jpg|png)'))
 else:
  print(f"Failded to Access Google. Status Code: {response.status_code}")



if __name__=="__main__":
 string = sys.argv[1]
 Protocol = sys.argv[0]
 IPv6 = sys.argv[2]
 
 print(f"String: {string}, Protocol: {Protocol}, IPv6: {IPv6},")
 search(html_content="", string=string)
