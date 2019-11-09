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
        for i in range(len(b)):
            z=b[i]
            if bool(re.search('<',b[i]))==True:
                z=list(re.findall('<.>(.*?)<.*>',z))
                if len(z)>0:
                    z=z.pop()
            if len(z)>0:
                z=z.lstrip()
            
            b[i]=z
        for i in range(len(a)):
            z=a[i]+','
            if b[i]==[]:
                print(z)
            else:
                print(z+str(b[i]))
