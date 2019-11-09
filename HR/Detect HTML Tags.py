#Problem: Detect HTML Tags
#https://www.hackerrank.com/challenges/detect-html-tags/problem

import re
text=[]
example={''}
for i in range(int(input())):
    text.append(input())
for i in text:
    z=re.findall('<\s*(\w*)\s{0,1}\S',i)
    for i in z:
        example.add(i)
for i in range(len(example)):
    example.discard('')
example=list(example)
z=''
for i in sorted(example):
    z+=i+';'
print(z[:len(z)-1],end='')
