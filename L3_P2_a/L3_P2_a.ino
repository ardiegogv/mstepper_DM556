//----------PREÁMBULO-----------//

int PUL = 2;     //define PUL+ en el PIN 2
int subpaso = 400;   //define microstepping del driver
int pulsos = 40;    //define cuantos grados se moverá
int f = 100;     //define la velocidad (Hz)
float t_ms;       //periodo total (ms)
float r;     //tiempo en cada estado (HIGH=LOW)
float rpm;  // velocidad del movimiento
float mov_ang;   //ángulo de giro (°)
int c = 0;    //contador de pulsos

//---------CONFIGURACIÓN--------//

void setup() {

  Serial.begin(9600);  //comunicación
  pinMode(PUL, OUTPUT);
  t_ms = 1000.0 / f;
  r = t_ms / 2.0;
  rpm = (f * 60.0) / subpaso;
  mov_ang = pulsos * (360.0 / subpaso);


  Serial.print("Pulsos: "); Serial.println(pulsos);
  Serial.print("Frecuencia [Hz]: "); Serial.println(f);
  Serial.print("Periodo [ms]: "); Serial.println(t_ms);
  Serial.print("Tiempo por estado [ms]: "); Serial.println(r);
  Serial.print("Velocidad [rpm]: "); Serial.println(rpm);
  Serial.print("Giro [°]: "); Serial.println(mov_ang);

}

//-----------EJECUCIÓN----------//

void loop() {
  
  if (c < pulsos) {    //se detiene cuando alcanza los pulsos definidos

    digitalWrite(PUL, HIGH);
    delay(r);

    digitalWrite(PUL, LOW);
    delay(r);
    
    c = c + 1;

  }
}
