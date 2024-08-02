#define ledR 2
#define ledG 4
#define ledB 3
#define botao 7
#define maximo 3

int btnclicado=0;
int btnliberado=0;
int ciclo=0;

void vermelho(){
  digitalWrite(ledR,1);
  digitalWrite(ledG,0);
  digitalWrite(ledB,0);
}
void verde(){
  digitalWrite(ledR,0);
  digitalWrite(ledG,1);
  digitalWrite(ledB,0);
}
void azul(){
  digitalWrite(ledR,0);
  digitalWrite(ledG,0);
  digitalWrite(ledB,1);
}
void trocaLed(){
  if(ciclo == 0){
    vermelho();
  }else if(ciclo == 1){
    verde();
  }else if(ciclo == 2){
    azul();
  }
  ciclo++;
  if(ciclo> maximo-1){
    ciclo = 0;
  }
}
void verificarBtn(){
  if(digitalRead(botao)==1){
    btnclicado = 1;
    btnliberado = 0;
  }else{
    btnliberado = 1;
  }
  if((btnclicado == 1) and (btnliberado == 1)){
    btnclicado = 0;
    btnliberado = 0;
    trocaLed();
  }
}


void setup() {
 pinMode(ledR,OUTPUT);
 pinMode(ledG,OUTPUT);
 pinMode(ledB,OUTPUT);
 pinMode(botao,INPUT);

}

void loop(){
 verificarBtn();

}
