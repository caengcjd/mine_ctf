import requests
import subprocess
import time

url = "http://10.60.0.212:10865/d9e09f3462dfff0be50e44a1222ed8d42b8f9906/task.php"
N = 10

session = [None] * N;
rands = [None] * N
hashes = [None] * N

for i in xrange(len(session)):
    session[i] = requests.session()
    p = session[i].get(url+"?generate")
    r=p.text
    #md5 = p.text[len(p.text)-32:]
    #r = p.text[:len(p.text)-32]
    rands[i] = r
    #hashes[i] = md5
    print i, r

start_time=time.time()
proc = subprocess.Popen(["./rand"]+rands, stdout=subprocess.PIPE)
for output in iter(proc.stdout.readline,''):
    print output
    _,i,s = output.split(" ")
    if time.time()-start_time > 120 :
    	print 'chao shi'
    	proc.kill()
    	break
    r_output = subprocess.Popen(["php", "md5.php", s], stdout=subprocess.PIPE).communicate()[0]
    print   r_output.split("\n")
    g_rand,g_hash,g_d,_ = r_output.split("\n")
   # print hashes[int(i)], g_hash
    #print g_d
    text1=session[int(i)].get(url+"?check="+g_d).text
    if   "CTF"  in text1:
    	print text1
   	proc.kill()
    	break
    elif  "timeout"  in text1:
    	print text1
    	proc.kill()
    	break
    else :
    	print text1
