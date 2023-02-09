% Given arrays x=[-1,-1,0,0,0,0,2,3,3,1] (between n=-4 and n=5) and h=[1,2,1,2,1,0,-1] (between n=-2 and n=4) find the convolution y[n] of x[n] and h[n]
diary myDiaryFile.txt;
x = [-1 -1 0 0 0 0 2 3 3 1]; h = [1 2 1 2 1 0 -1]; 
y = conv(x,h)

diary off;
type myDiaryFile.txt;


