%Record steps using diary
% Delete the diary file if it exists
if exist('DiaryFile.txt', 'file')
    delete('DiaryFile.txt');
end


diary DiaryFile.txt;

disp("--------------------------------------------");
disp("Part 1");
disp("--------------------------------------------");

IMG=readjpg('RAT.jpeg');

% Get x,y info from IMG
[x,y,z]=size(IMG);

% Print size of img in one line
disp("Size of image is: "+x+"x"+y+"x"+z);

r=zeros(x,y); g=zeros(x,y); b=zeros(x,y); % initialization
r=IMG(:,:,1); g=IMG(:,:,2); b=IMG(:,:,3);

% create a new matrix Y which is the luminance component from “r”, “g” and “b” matrices

Y=0.299*r+0.587*g+0.114*b;
disp("Calculating luminance component from r,g,b matrices by using formula Y=0.299*r+0.587*g+0.114*b");

ySize = size(Y);
disp("Luminance component is a matrix of size: "+ySize(1)+"x"+ySize(2));

% Use “dispimg” function to display Y, and print out this gray level image
dispimg(Y);

% Seperator For Part 2 
disp("--------------------------------------------");
disp("Part 2");
disp("--------------------------------------------");

% Define the parameters
n = 8; % number of rows
p = [0.15 0.10 0.05 0.05 0.10 0.15 0.25 0.15]; % probability values
s = 7; % scaling factor

% Create the 2D array
r = zeros(n, 2);
for i = 1:n
    r(i, 1) = i - 1;

    r(i, 2) = s * sum(p(1:i));
end

stem(r(:, 1), r(:, 2));
title("2D array");
xlabel("x");
ylabel("y");

% Recreate the graph but label each value
for i = 1:n
    text(r(i, 1), r(i, 2), num2str(r(i, 2)));
end



% Print the 2D array
disp("2D array is: ");
disp(r); 

diary off;
dispimg(Y);