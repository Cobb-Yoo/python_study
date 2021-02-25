from selenium import webdriver
from selenium.webdriver.common.keys import Keys

#dataFile = open("merge_data.txt", 'r')
#writeFile = open("end_data.txt", 'w')

#print(dataFile.read())

data = 'test'

driver = webdriver.Chrome()
driver.get("https://papago.naver.com/")
driver.implicitly_wait(3)


elem = driver.find_element_by_name("txtSource")
elem.send_keys(data)
elem.send_keys(Keys.RETURN)


#dataFile에 있는 데이터 중에 앞에꺼 변수에 넣기
#영어창 누르기
#변수에 넣었던 데이터 영어창에 넣기
#번역하기 누르기
#한글창 누르기
#한글창에 있는 데이터 복사하기
#새로운 파일에 [영어 한글 횟수] 순으로 저장하기

print("번역이 완료되었습니다")