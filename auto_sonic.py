from selenium import webdriver
import time
import urllib.request, ssl

'''
This script is created by Rohit Anand
'''

driver = None

with open('auth.txt') as f:
    lines = f.readlines()
    
def login(driver, lines):
    
    driver.get('http://122.0.0.254/dynPolLoginRedirect.html')
        
    if 'Policy Login Redirect' in driver.title:
        driver.find_element_by_xpath('/html/body/div[2]/div[1]/div[3]/a').click()
        if driver.current_url == 'https://122.0.0.254/dynLoginLockout.html':
            raise ValueError('You are locked out for sometime...')
        
        assert 'SonicWALL - Authentication' in driver.title
        
        driver.switch_to.frame("authFrm")
        username = driver.find_element_by_xpath("//*[@id='userName']")
        password = driver.find_element_by_xpath("/html/body/form/div/div[6]/div[2]/input")
        username.send_keys(lines[0])
        password.send_keys(lines[1])

        driver.find_element_by_xpath("/html/body/form/div/div[10]/div[2]/input").click()
        cur = driver.current_window_handle
        for i in driver.window_handles:
            if cur != i:
                driver.switch_to.window(i)
                time.sleep(1)
                driver.switch_to.frame("frm2")
                driver.find_element_by_xpath("/html/body/form/center/table/tbody/tr/td[1]/input").click()
        time.sleep(2)
        driver.switch_to.window(cur)
        print('You are successfully connected to SonicWALL')
        time.sleep(0.5)
        driver.exit()
        start()

    elif driver.current_url == 'https://122.0.0.254/dynLoggedOut.html?didLogout=yes':
        login(driver, lines)

    elif driver.current_url == 'https://122.0.0.254/dynLoginLockout.html':
        print('You are locked out for sometime...')
        exit()

def start():
    
    global driver
    while True:
        try:
            urllib.request.urlopen('https://google.com')
            print('You are connected to INTERNET!!!')
        except urllib.request.HTTPError:
            try:
                urllib.request.urlopen(url='http://122.0.0.254/dynPolLoginRedirect.html', context=ssl.SSLContext())
                if len(driver.window_handles)>0:
                    driver.quit()
                login(driver=webdriver.Firefox(executable_path='geckodriver'), lines=lines)
            except urllib.request.HTTPError:
                print('Connect to sonicWALL')
        time.sleep(1)

start()
