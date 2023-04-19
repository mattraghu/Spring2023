function   jpg2raw()


img=imread('MINIRAT.jpeg');

[sx,sy,sz]=size(img);

r=zeros(sx,sy); g=zeros(sx,sy); b=zeros(sx,sy);   % initialization
r=img(:,:,1); g=img(:,:,2); b=img(:,:,3);

y=r*0.299+g*0.587+b*0.114;

fid = fopen('RAT.raw','w');


count = fwrite(fid,y','uchar');

fclose(fid);     
