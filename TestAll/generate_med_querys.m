% fileID = fopen('mediciones.txt','w');
cantidadDeDatos = 500;

n = 0;
cantidadDeConsultas=0;

for jada = 1:cantidadDeDatos
 filesss = sprintf('mediciones%d.txt',jada);
 fileID = fopen(filesss,'w');  
 
n = 10+n;

vector = 1:n;
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
% fileID1 = fopen('querys.txt','w');
for j = 1:100
    a(j,:) = randperm(n,2);
end
% vector(randi(length(vector)))

cantidadDeConsultas = 10 + cantidadDeConsultas;
% cantArchivos = 40;

% for f = 1:cantArchivos
    filess = sprintf('querys%d.txt',jada);
    fileID1 = fopen(filess,'w');
    
    for h =1:cantidadDeConsultas
        fprintf(fileID1,'sensor1,%d,%d\n',0,n);
    end
%     cantidadDeConsultas = cantidadDeConsultas+100;
% end

fclose(fileID1);

end
