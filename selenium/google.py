from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

dataFile = open("mergedData.txt", 'r')
writeFile = open("translatedData.txt", 'w',encoding="UTF8")

driver = webdriver.Chrome()
driver.get("https://papago.naver.com/")
driver.implicitly_wait(10)

engArea = driver.find_element_by_name("txtSource")
print('engArea를 찾았습니다.')

cnt = 0

while 1:
    line = dataFile.readline()
    if not line : break
    data = line.split()[0]
    value = line.split()[1]

    engArea.send_keys(data)
    engArea.send_keys(Keys.RETURN)
    time.sleep(1.5)
    transData = driver.find_element_by_xpath("//div[@id='txtTarget']/span").text
    inputData = '{0} {1} {2}\n'.format(data,transData,value)
    writeFile.write(inputData)
    engArea.clear()
    cnt = cnt+1
    print('{0}번째 단어 {1} 완료'.format(cnt, data))

print("번역이 완료되었습니다")

dataFile.close()
writeFile.close()
driver.close()

#dataFile에 있는 데이터 중에 앞에꺼 변수에 넣기 [o]
#영어창 누르기 [o]
#변수에 넣었던 데이터 영어창에 넣기 [o]
#번역하기 누르기 [o]
#한글창 누르기 [o]
#한글창에 있는 데이터 복사하기 [o]
#새로운 파일에 [영어 한글 횟수] 순으로 저장하기 [o]