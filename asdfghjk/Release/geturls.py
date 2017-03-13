
fin = open( 'list.htm', 'r' );
fcon=open('content.txt','w'); 
content = fin.read();
pos = 0
while True:

    lf = content.find('http://blog.sina.com.cn/s/blog_', pos);

   
    rt = content.find('html', lf);
    pos = rt;
    uuurl=content[lf : rt + 4];
    print uuurl;

    fcon.write(uuurl+'\n');

    if lf == -1:
        break
fcon.close();
fin.close();
