clear all;close all;clc;

%Complejidad algoritmica TP1 alg2:

% tiempos = dlmread('complejidad.txt');
% 
% tp1 = find(tiempos == 1);
% tp0 = find(tiempos == 0);
% 
% tiempoTp1 = tiempos(tp1+1:tp0-1);
% tiempoTp0 = tiempos(tp0+1:end);
% 
% consultas(1) = 10;
% 
% for i = 2:length(tiempoTp0)
%     consultas(i) = consultas(i-1) + 100;
% end

% unix('./complejidad.sh 501');
tiemposDatos = dlmread('complejidad.txt');

tp1 = find(tiemposDatos == 1);
tp0 = find(tiemposDatos == 0);

tiempoTp1Datos = tiemposDatos(tp1+1:tp0-1);
tiempoTp0Datos = tiemposDatos(tp0+1:end);

datos(1) = 10;

for i = 2:length(tiempoTp0Datos)
    datos(i) = datos(i-1) + 10;
end

figure();
scatter(datos,tiempoTp0Datos);
hold on
scatter(datos,tiempoTp1Datos);
grid minor
xlabel('Datos [Cantidad]')
ylabel('tiempo[s]')
print('Complejidad150Muestras','-dpng')
