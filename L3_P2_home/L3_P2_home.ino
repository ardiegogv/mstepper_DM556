//----------PREÁMBULO-----------//

int PUL = 2;     //define PUL+ en el PIN 2
int BOTON = 4;   //define PIN 3
int BOTON_home = 5;  //define PIN 5
int subpaso = 400;   //define microstepping del driver
int pulsos = 40;    //define cuantos grados se moverá
int f = 100;     //define la velocidad (Hz)
float t_ms;       //periodo total (ms)
float r;     //tiempo en cada estado (HIGH=LOW)
int c = 0;    //contador de pulsos
int pos = 0;  //cuenta posición

//---------CONFIGURACIÓN--------//

void setup() {

  pinMode(PUL, OUTPUT);
  pinMode(BOTON, INPUT);   //entrada digital
  pinMode(BOTON_home, INPUT); //home

  t_ms = 1000.0 / f;
  r = t_ms / 2.0;

}

//-----------EJECUCIÓN----------//

void loop() {

  if (digitalRead(BOTON) == HIGH) {
    c = 0;
    while (c < pulsos) {
      digitalWrite(PUL, HIGH);
      delay(r);
      digitalWrite(PUL, LOW);
      delay(r);
      c = c + 1;
    }
    pos = pos + pulsos;
    if (pos >= subpaso) {
      pos = pos - subpaso;
    }
    while (digitalRead(BOTON) == HIGH);
  }

  if (digitalRead(BOTON_HOME) == HIGH) {
    int home = subpaso - pos;
    c = 0;
    while (c < home) {
      digitalWrite(PUL, HIGH);
      delay(r);
      digitalWrite(PUL, LOW);
      delay(r);
      c = c + 1;
    }
    pos = 0;
    while (digitalRead(BOTON_HOME) == HIGH);
  }
}