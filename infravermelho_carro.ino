int sensorEsq = A0;
int sensorDir = A1;

int leituraEsq = 0;
int leituraDir = 0;

unsigned long media_sensorEsq = 0;
unsigned long media_sensorDir = 0;

int ref_sensorEsq = 0;
int ref_sensorDir = 0;

int cont = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  leituraEsq = analogRead(sensorEsq);
  leituraDir = analogRead(sensorDir);

  if( cont < 1000){
    media_sensorEsq = media_sensorEsq + leituraEsq;
    media_sensorDir = media_sensorDir + leituraDir;

    cont = cont + 1;
  } else {
    cont = 0;

    ref_sensorEsq = media_sensorEsq / 1000;
    ref_sensorDir = media_sensorDir / 1000;

    media_sensorEsq = 0;
    media_sensorDir = 0;
  }

  Serial.print(leituraEsq, DEC);
  Serial.print("\t");
  Serial.print(leituraDir, DEC);
  Serial.print("\t");
  Serial.print(media_sensorEsq, DEC);
  Serial.print("\t");
  Serial.print(media_sensorDir, DEC);
  Serial.print("\t");
  Serial.print(ref_sensorEsq, DEC);
  Serial.print("\t");
  Serial.print(ref_sensorDir, DEC);
  Serial.print("\t");
  Serial.print(cont, DEC);
  Serial.print("\t");
  Serial.print("\n");
}
