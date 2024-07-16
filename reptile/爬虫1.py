from urllib.request import urlopen
import requests
q="https://www.lrnic.cn/sr.jsp?skeyword=网卡"
dic={
    "user-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
}
res=requests.get(q,headers=dic)

print(res.text())