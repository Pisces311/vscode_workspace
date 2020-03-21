import xlrd
from selenium import webdriver

path = 'C:/Users/Hello/Desktop/Student_number.xlsx'


def get_student_list(loc: str) -> list:
    raw_data = xlrd.open_workbook(loc).sheets()[0]
    data = [str(int(i)) for i in raw_data.col_values(0)[2:]]
    return data


browser = webdriver.Chrome()
studentIDs = get_student_list(path)
url = 'https://acm.sustech.edu.cn/onlinejudge/registerpage299792458.php'

for i in studentIDs:
    browser.get(url)
    browser.find_element_by_name('user_id').send_keys(i)
    browser.find_element_by_name('password').send_keys('123456')
    browser.find_element_by_name('rptpassword').send_keys('123456')
    browser.find_element_by_name('submit').click()
    try:
        alert = browser.switch_to.alert
        alert.accept()
        print('user exists: %s' % (i))
    except Exception:
        print('success: %s' % (i))
