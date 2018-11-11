fileID = fopen('mediciones.txt','w');
% n = 26384;
% n = 16384;
n = 2048*2*2*2*2;
A = rand(n,10);
B = randi(50,n,1);
C = zeros(n,10);
for i =1:10
    C(:,i) = A(:,i).*B;
end
delim = ', ';
name = ['sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8,sensor9,sensor10'];


fprintf(fileID,'%s\n',name);
fprintf(fileID,'%3.3f,%3.3f,%3.3f,%3.3f,%3.3f,%3.3f,%3.3f,%3.3f,%3.3f,%3.3f\n',...
    C(:,1),C(:,2),C(:,3),C(:,4),C(:,5),C(:,6),C(:,7),C(:,8),C(:,9),C(:,10)) ;
fclose(fileID);
a = zeros(100,2);
fileID1 = fopen('querys.txt','w');
for j = 1:100
    a(j,:) = randperm(n,2);
end
for h =1:n
    fprintf(fileID,'sensor1,%d,%d\n',0,n);
    fprintf(fileID,'sensor2,%d,%d\n',0,n);
    fprintf(fileID,'sensor3,%d,%d\n',0,n);
    fprintf(fileID,'sensor4,%d,%d\n',0,n);
    fprintf(fileID,'sensor5,%d,%d\n',0,n);
    fprintf(fileID,'sensor6,%d,%d\n',0,n);
    fprintf(fileID,'sensor7,%d,%d\n',0,n);
    fprintf(fileID,'sensor8,%d,%d\n',0,n);
    fprintf(fileID,'sensor9,%d,%d\n',0,n);
    fprintf(fileID,'sensor10,%d,%d\n',0,n);
end
fclose(fileID1);
