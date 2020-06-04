import urllib.request, json, requests

insta = 'https://www.instagram.com/{}/?__a=1'

with urllib.request.urlopen(insta.format(input('Enter Username:'))) as url:
    data = json.loads(url.read().decode())
    pic_link = data['graphql']['user']['profile_pic_url_hd']
    
    with open('insta_img.jpg', 'wb') as pic:
        pic_link = requests.get(pic_link).content
        pic.write(pic_link)