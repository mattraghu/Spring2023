diary myDiaryFile2.txt;
x = [1 2 -1 1]; h = [1 1]; 
y = conv(x,h);
disp(y);

diary off;
type myDiaryFile2.txt;