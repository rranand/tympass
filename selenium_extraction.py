from selenium import webdriver
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.by import By
import time, re, sqlite3

connection = sqlite3.connect('MANAGEMENT_FINAL.db')
cur = connection.cursor()
cur.execute('''DROP TABLE IF EXISTS college_management; ''')
cur.execute('''DROP TABLE IF EXISTS course_details; ''')
connection.commit()

cur.execute('''CREATE TABLE college_management (
	"c_id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"c_name"	TEXT NOT NULL,
	"c_type"	TEXT NOT NULL,
	"c_address"	TEXT NOT NULL,
	"women"	TEXT NOT NULL,
	"state"	TEXT NOT NULL
); ''')
cur.execute('''CREATE TABLE "course_details" (
	"level"	TEXT NOT NULL,
	"course"	TEXT NOT NULL,
	"intake"	INTEGER NOT NULL,
	"c_id"	INTEGER NOT NULL,
	FOREIGN KEY("c_id") REFERENCES "college_management"("c_id")
); ''')
connection.commit()
college_query = '''insert into college_management (c_name, c_type, c_address, women, state) values (?,?,?,?,?) '''
course_query = '''insert into course_details (level, course, intake, c_id) values (?,?,?,?) '''


def get_inner_page(id):
    page = float(re.findall('[\d]+', str(driver.find_element(By.ID, 'coursetable_info').text))[2])/10
    if page!=int(page):
        page = int(page)+1
    else:
        page = int(page)
    for ip in range(1,page+1):
        driver.find_element(By.XPATH ,"//*[@id='coursetable_paginate']/span/a["+str(ip)+"]").click()
        time.sleep(1)
        for r in range(1,len(driver.find_elements_by_xpath("//*[@id='coursetable']/tbody/tr"))+1):
            connection.execute(course_query, (str(driver.find_element(By.XPATH, "//*[@id='coursetable']/tbody/tr["+str(r)+"]/td[3]").text), str(driver.find_element(By.XPATH, "//*[@id='coursetable']/tbody/tr["+str(r)+"]/td[4]").text), driver.find_element(By.XPATH, "//*[@id='coursetable']/tbody/tr["+str(r)+"]/td[7]").text, id))
        connection.commit()


driver = webdriver.Chrome(executable_path='chromedriver')
driver.maximize_window()

driver.get('************************')  #Website name is hidden due to privacy
time.sleep(1)

year = Select(driver.find_element(By.ID,"year"))
year.select_by_index(0)

program = Select(driver.find_element(By.ID,"program"))
program.select_by_index(7)

#level = Select(driver.find_element(By.ID, "level"))
#level.select_by_index(2)

state = Select(driver.find_element(By.ID, 'state'))

for i in range(len(state.options)):
    state.select_by_index(i)
    driver.find_element_by_xpath("//*[@id='load']").click()
    time.sleep(1)
    Select(driver.find_element(By.NAME, 'jsontable_length')).select_by_index(3)
    
    pages = float(re.findall('[\d]+', str(driver.find_element(By.ID, 'jsontable_info').text))[2])/50
    if pages!=int(pages):
        pages = int(pages)+1
    else:
        pages = int(pages)
        
          
    for j in range(1,pages+1):
        driver.find_element(By.LINK_TEXT , str(j)).click()
        time.sleep(0.5)
        driver.execute_script("window.scrollTo(0, 0);", "")
        
        if len(driver.find_elements_by_xpath("//*[@id='jsontable']/tbody/tr"))==1:
            
            connection.execute(college_query, (str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[2]").text), str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[5]").text), str(str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[3]").text)+', '+str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[4]").text)), str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[6]").text), str(state.first_selected_option.text)))
            connection.commit()
            cur.execute('''select c_id from college_management where c_name=?;''', (driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[2]").text, ))
            result=cur.fetchall()
            driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr/td[8]/button").click()
            time.sleep(1)
            get_inner_page(result[0][0])
            driver.find_element_by_xpath("//*[@id='courses1']/button").click()
            
        else:
            
            for r in range(1,len(driver.find_elements_by_xpath("//*[@id='jsontable']/tbody/tr"))+1):
                if bool(re.search('(S.R. M INSTITUTE OF SCIENCE AND TECHNOLOGY|ANNA UNIVERSITY)', str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[2]").text))):
                    continue
                connection.execute(college_query, (str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[2]").text), str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[5]").text), str(str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[3]").text)+', '+str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[4]").text)), str(driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[6]").text), str(state.first_selected_option.text)))
                connection.commit()
                cur.execute('''select c_id from college_management where c_name=?;''', (driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[2]").text, ))
                
                driver.find_element_by_xpath("//*[@id='jsontable']/tbody/tr["+str(r)+"]/td[8]/button").click()
                time.sleep(1)
                get_inner_page(cur.fetchall()[0][0])
                driver.find_element_by_xpath("//*[@id='courses1']/button").click()
        print('------------------********************-------------------')
        
connection.close()
