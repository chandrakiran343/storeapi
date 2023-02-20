import requests
import json

string = input()

output = ""
string = string.split(" ")
for i in string:
    url = f"http://130.185.118.141/tech_savishkaar?word={i}"
    response = requests.get(url)
    if(response.ok):
        data = json.loads(response.content)
        output += data["encoded"]   
    output+=" "
output = output.rstrip()
print(output)
     