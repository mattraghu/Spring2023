function   raw2jpg()
ncols = 2419;
nrows = 1814;

fid = fopen('output.raw','rb');

[x,count] = fread(fid, [ncols,nrows],'uchar');
if (count ~= (nrows*ncols) )
  error('dimensions dont match file contents---load aborted');
end
fclose(fid);     

imwrite(x'/256,'output.jpg','jpg');

