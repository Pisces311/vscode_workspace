import re
import requests
import json


def login(stu, url):
    session = requests.Session()
    page = session.get(url)
    execution = re.findall('name="execution" value="(.+?)"', page.text)[0]
    data = {
        'username': stu['username'],
        'password': stu['password'],
        'execution': execution,
        '_eventId': 'submit',
        'geolocation': ''
    }
    page = session.post(page.url, data=data)
    return session, page


if __name__ == "__main__":

    # CAS登陆系统
    stu = {
        'username': '11712121',  # Here inputs your StudentID
        'password': '030715',  # Here inputs your password
    }
    url = 'http://ehall.sustech.edu.cn/amp-auth-adapter/login?service=http://ehall.sustech.edu.cn/login?service=http://ehall.sustech.edu.cn/new/index.html'
    session, page = login(stu, url)
    base_url = page.url.replace('new/index.html', 'xhxsfw/sys/xkgl/')
    page = session.get(
        base_url +
        '*default/index.do?t_s=1567343998613&amp_sec_version_=1&gid_=TEdJczZVektTMEQ4eEQxVEt1eEFJQWhmRGxwWlg1MFNZV1Joc0I1QTRuQ1VublFoRGphYVNEYVR0enNiOEcxZjFtQUlaYkZkN0ZjUmdJV1FRZlg5c3c9PQ&EMAP_LANG=zh&THEME=teal#/xkxx'
    )
    stu['username'] = input('Input student ID: ')
    stu_id = stu['username']
    semester = '2019-2020-2'
    weekcycle = '0'
    page = session.get(
        base_url +
        'curriculaVariable/getCurriculaVariableInfo.do?requestParamStr={"XH":"%s", "XNXQ":"%s","weekcycle":"%s"}'
        % (stu_id, semester, weekcycle))
    course_list = json.loads(page.text)['data']
    print(course_list[0]['XH'], course_list[0]['XM'])
    print('所选课程：', end='')
    for i in course_list:
        print(i['KCMC'], end=' ')
