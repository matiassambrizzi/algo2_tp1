fileID = fopen('mediciones.txt','w');
n = 500000;
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
    a(j,:) = sort(a(j,:));
end
for h =1:100
    fprintf(fileID,'sensor1,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor2,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor3,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor4,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor5,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor6,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor7,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor8,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor9,%d,%d\n',a(h,1), a(h,2));
    fprintf(fileID,'sensor10,%d,%d\n',a(h,1), a(h,2));
end
fclose(fileID1);
