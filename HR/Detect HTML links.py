#https://www.hackerrank.com/challenges/detect-html-links/problem
#Solution:

import re
text=[]
for i in range(int(input())):
    text.append(input())
for i in text:
    a=list(re.findall('<a href="(.*?)\"{1}',i))
    b=list(re.findall('<a href=.*?>(.*?)</a>',i))
    if len(a)>0 and len(b)>0:
        for i in range(len(a)):
           print(a[i]+','+b[i])
