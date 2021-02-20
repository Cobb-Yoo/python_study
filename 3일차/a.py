import os
import pdfplumber

path = r'C:\Users\Yoo\Desktop\수능'
f = open("C:/Users/Yoo/Desktop/수능_data.txt",mode='wt', encoding='utf-8')

for item in os.listdir(path):
    item_path = os.path.join(path, item)
    pdf = pdfplumber.open(item_path)

    for page in range(len(pdf.pages)):
        text = pdf.pages[page].extract_text()
        if text :
            f.write(text)
        else :
            pass
    
    print(item + "(은)는 데이터 추출이 완료 되었습니다")


print('모든 데이터 추출이 종료 되었습니다')
f.close()