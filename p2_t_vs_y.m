% Parámetros del sistema
alpha = 0.262;               % [rad] 15°
L = 128;                     % [mm]
r = 58;                      % [mm]
deg2rad = pi / 180;

% Corrientes medidas [mA] en 6 posiciones
I = [5.43, 5.43, 5.41, 5.27, 4.96, 4.94]

% Cálculo de temperaturas [°C] con rango 0–500°C
T = 31.25 * (I - 4)  % T = (Tmax / 16) * (I - 4)

% Cálculo de ángulos: desde (216° − alpha) + 36° por paso
theta_deg = (216 - (alpha / deg2rad)) + (0:5) * 36
theta = theta_deg * deg2rad;

% Cálculo de altura y para cada theta
y = sqrt(L^2 - (r*sin(alpha + theta) - (L + r)*sin(alpha)).^2) ...
    + r*cos(alpha + theta) - (L + r)*cos(alpha)

% Gráfico
figure;
plot(y, T, '-o', 'LineWidth', 1.5);
xlabel('Altura [mm]');
ylabel('Temperatura [°C]');
grid on;

