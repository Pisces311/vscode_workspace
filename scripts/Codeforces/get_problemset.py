'''
Print every item on the first page of the problemset on CODEFORCES in
 ascending order of difficulty.
'''

from urllib import request
import re
import sys


class Spider():
    url = 'http://codeforces.com/problemset/page/1'
    root_pattern = r'<tr>([\s\S]*?)</tr>'
    name_pattern = r'<a href="/problemset/problem/[\s\S]*?">\r\n([\s\S]*?)</a>'
    diff_pattern = \
        r'<span title="Difficulty"class="ProblemRating">([\s\S]*?)</span>'

    def __fetch_content(self):
        r = request.urlopen(Spider.url)
        htmls = r.read()
        htmls = str(htmls, encoding='utf-8')
        return htmls

    def __analysis(self, htmls):
        root_html = re.findall(Spider.root_pattern, htmls)
        anchors = []
        for i in root_html:
            name = re.findall(Spider.name_pattern, i)
            diff = re.findall(Spider.diff_pattern, i)
            anchor = {'name': name, 'diff': diff}
            anchors.append(anchor)
        return anchors

    def __refine(self, anchors):
        def func(anchor): return {
            'name': (anchor['name'][1] if anchor['name'] else 'null').strip(),
            'diff': (anchor['diff'][0] if anchor['diff'] else '0')
        }
        return list(map(func, anchors))

    def __sort(self, anchors):
        anchors.sort(key=lambda x: int(x['diff']), reverse=True)
        return anchors

    def __show(self, anchors):
        sys.stdout = open('test.out', 'w')
        anchors = filter(lambda x: x['name'] != 'null', anchors)
        for i in anchors:
            print(i['name']+'----'+i['diff'])

    def go(self):
        htmls = self.__fetch_content()
        anchors = self.__analysis(htmls)
        anchors = self.__refine(anchors)
        anchors = self.__sort(anchors)
        self.__show(anchors)


spider = Spider()
spider.go()
