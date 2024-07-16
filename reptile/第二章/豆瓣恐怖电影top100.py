import random
import time
import requests
import re
url = "https://movie.douban.com/top250"
headers= {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
  "Cookie":"bid=P-LHsP9BXME; dbcl2=256574693:y5p6W8nI0PY; ck=t_ia; push_doumail_num=0; __utma=30149280.1073515073.1720855231.1720855231.1720855231.1; __utmc=30149280; __utmz=30149280.1720855231.1.1.utmcsr=open.weixin.qq.com|utmccn=(referral)|utmcmd=referral|utmcct=/; __utmv=30149280.25657; __utma=223695111.2140756205.1720855302.1720855302.1720855302.1; __utmb=223695111.0.10.1720855302; __utmc=223695111; __utmz=223695111.1720855302.1.1.utmcsr=douban.com|utmccn=(referral)|utmcmd=referral|utmcct=/; _pk_ref.100001.4cf6=%5B%22%22%2C%22%22%2C1720855302%2C%22https%3A%2F%2Fwww.douban.com%2F%3Ftag%3DKalafina%26from%3Dmdouban%22%5D; _pk_id.100001.4cf6=8212eab1ae329647.1720855302.; _pk_ses.100001.4cf6=1; push_noty_num=0; __yadk_uid=5sEPH1kdQXlIRCXhhibwGgWgVjguF7Th; _vwo_uuid_v2=DF7E660B1DEC2D50BF2463852DD62C3EC|d2103461c5890ba2ce158b79ed9295a1; frodotk_db=2bc4b7882ae8ceb8834e269880ba6c28; __utmb=30149280.4.10.1720855231"
}
try:
    resp = requests.get(url, headers=headers)
    if resp.status_code == 200:
        content = resp.text

    else:
        print(f"请求失败，状态码: {resp.status_code}")
        time.sleep(random.randint(3, 8))  # 随机延迟 3 - 8 秒
except requests.exceptions.RequestException as e:
    print(f"请求时发生错误: {e}")
resp=requests.get(url,headers=headers)
content =resp.text
#re解析
obj = re.compile(r'<li>.*?<span class="title">(?P<name>.*?)</span>.*?'
                 r' <p class="">(?P<director>.*?)<br>'
                 r'(?P<year>.*?)</p>.*?'
                 r'<span class="rating_num" property="v:average">(?P<sore>.*?)</span>',re.S)
result =obj.finditer(content)
count = 0
for i in result:
    count += 1
    print(f"第 {count}部电影是 : {i.group('name')}")
    print( i.group('name'))
    print(i.group('name'))
    print(f"第 {count}部电影是 : {i.group('name')}")