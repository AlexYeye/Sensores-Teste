// Mapeamento (Saida Analogica e Digital)
//#define pino_A0 2 // -> 0
#define pino_D0 3 // -> 1

// Variaveis Globais
unsigned int rpm;
//float km;
volatile byte pulsos;
unsigned long timeold;
unsigned int pulsos_por_volta = 20;

void contador()
{
  //Incrementa contador
  pulsos++;
}

void setup() {

  Serial.begin(9600);

  pinMode(pino_D0, INPUT);
  //pinMode(pino_A0,  INPUT);


  //Interrupcao 1 - pino 3
  //Aciona o contador a cada pulso
  attachInterrupt(1, contador, FALLING);
  pulsos = 0;
  rpm = 0;
  timeold = 0;

}

void loop() {
  
  //Atualiza contador a cada segundo
  if (millis() - timeold >= 1000)
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(1);
    rpm = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;

    //km = ((2*3.141593*0.01*rpm)/60)*3.6;

    //Mostra o valor de RPM no serial monitor
    Serial.print("RPM = ");
    Serial.println(rpm, DEC);

    //Mostra o valor de Km/h no serial monitor
    //Serial.print(" Km/h = ");
    //Serial.println(km, DEC);

    //Habilita interrupcao
    attachInterrupt(1, contador, FALLING);
  }

}
