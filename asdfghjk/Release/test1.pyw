 # -*- coding: UTF-8 -*-
import urllib
' 获取web页面内容并返回'
#def getblogurl():

    
def getWebContent(url):

    f = urllib.urlopen(url)
     
     
     
    data = f.read()

    f.close()
    return data



def stripTags(s):

    intag = [False]

    def chk(c):
        if intag[0]:
            intag[0] = (c != '>')
            return False
        elif c == '<':
            intag[0] = True
            return False
        return True

    return ''.join(c for c in s if chk(c))


furl=open(r'content.txt','r')

fpath=open('path.txt') 

while 1:
    
    url=furl.readline()
    path = fpath.read( )

    if not url:
        break
    
    content= getWebContent(url) 
    tlf=content.find('titName SG_txta">',0);
    trt=content.find('</h2>',tlf);
    title=content[tlf+17:trt];
    f2 = file(path+"\\"+"download"+ '.txt', 'w') 
    clf=content.find('articalContent',trt);
    crt=content.find('</div>',clf);
    s=content[clf+18:crt];
    s=s.replace('&#65292;',',')
    s=s.replace('&#65311;','?')
    s=s.replace('&#65306;',':')
    s=s.replace('&#65307;',';')
    s=s.replace('&#65281;','!')
    s=s.replace('&nbsp;','!')
    s=stripTags(s)
    title=title.decode('UTF-8').encode('GBK')
    s=s.decode('UTF-8').encode('GBK')
    f2.write(title+'\n')
    f2.write(s) 
    f2.close();
    pass
fpath.close( )
furl.close();
#url = 'http://blog.sina.com.cn/twocold'
#content = getWebContent(url)

findurl=str.find("http://blog.sina.com.cn/s/blog_")

#f2 = file('urltest.shtml', 'w')  
#f2.write(content)  
#f2.close() 
