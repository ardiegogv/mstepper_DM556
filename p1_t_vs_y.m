% Parámetros del sistema
alpha = 0.262;               % [rad] 15°
L = 128;                     % [mm]
r = 58;                      % [mm]
deg2rad = pi / 180;

% Valores digitales (extraídos del ADC en cada posición)
val_digital = [279, 281, 280, 277, 270, 252] 

% Resolución del ADC
resolucion_mV = 4.97;              % mV por bit
resolucion_V = resolucion_mV / 1000;  % V por bit

% Conversión a voltaje
V = val_digital * resolucion_V   

% Conversión de voltaje a corriente (0–5V,0–20mA)
I = (V / 5) * 20  % [mA]

% Cálculo de temperaturas [°C] con rango 0–500°C
T = 31.25 * (I - 4)

% Cálculo de ángulos: desde (180° − alpha) + 36° por paso
theta_deg = (180 - (alpha / deg2rad)) + (0:5) * 36
theta = theta_deg * deg2rad;

% Cálculo de altura y para cada theta
y = sqrt(L^2 - (r*sin(alpha + theta) - (L + r)*sin(alpha)).^2) ...
    + r*cos(alpha + theta) - (L + r)*cos(alpha)

% Gráfico
figure;
plot(y, T,'r-o', 'LineWidth', 1.5);
xlabel('Altura [mm]');
ylabel('Temperatura [°C]');
grid on;
legend('Datos procesados desde ADC', 'Location', 'best');
