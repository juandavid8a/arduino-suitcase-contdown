#include <Keypad.h>

//inicia codigo para teclado
const byte filas = 4;
const byte columnas = 3;
byte pinsFilas[filas] = {8, 7, 6, 5};
byte pinsColumnas[columnas] = {4, 3, 2};

String stringOne=String("NO");
String stringTwo=String("NO");

char teclas[filas][columnas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

Keypad teclado = Keypad(makeKeymap(teclas),pinsFilas,pinsColumnas, filas, columnas);
//termina codigo para teclado

const int a = 30;
const int b = 31;
const int c = 32;
const int d = 33;
const int e = 34;
const int f = 35;
const int g = 36;
const int h = 37;
const int i = 40;
const int j = 41;
const int k = 42;
const int l = 43;
const int m = 44;
const int n = 45;
const int o = 46;
const int p = 47;


char tecla;
char numero1;
char numero2;
long varDiv;

long varSegundos;
int varMinutos;

void setup(){
  Serial.begin(9600);
   pinMode(11, OUTPUT); 
   pinMode(12, OUTPUT);
   
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
   pinMode(h, OUTPUT);
   pinMode(i, OUTPUT);
   pinMode(j, OUTPUT);
   pinMode(k, OUTPUT);
   pinMode(l, OUTPUT);
   pinMode(m, OUTPUT);
   pinMode(n, OUTPUT);
   pinMode(o, OUTPUT);
   pinMode(p, OUTPUT);
}

void loop (){
  tecla = teclado.getKey();
  if(tecla != NO_KEY){ //si se presiono una tecla
    switch (tecla) {
      case '*':
        if(stringOne == "NO"){
          Serial.println("No ha ingresado tiempo");
        }else{
          tecla = NO_KEY;
          pito();
          reloj();
        }
        break;
      case '#':
        Serial.println("Tiempo borrado");
        stringOne = String("NO");
        stringTwo = String("NO");
        break;
      default:
        if(stringTwo == "NO"){
          if(stringOne == "NO"){
            stringOne = String(tecla);
            numero1 = stringOne.toInt();
            Serial.print("Uno: ");
            Serial.println(stringOne);
            casoI();
          }else{
            stringTwo = String(tecla);
            numero2 = stringTwo.toInt();
            Serial.print("Dos: ");
            Serial.println(stringTwo);
            casoD();
            numero1 = stringOne.toInt();
            numero2 = stringTwo.toInt();
            stringOne += stringTwo;
            Serial.print("Numero: ");
            Serial.println(stringOne);  
           }
         } 
        break;
    }
  }
}

void reloj(){
  Serial.print("Reloj puesto a ");
  varMinutos = stringOne.toInt(); 
  Serial.print(varMinutos);
  Serial.print(" Minutos");
  Serial.println(".");
  Serial.println("el juego inicia en ");
  for (int i=5; i >= 1; i--){
      Serial.println(i);
      //ledVerde();
      pito();
      delay(1000);
   }
  Serial.println("!!JUEGO!!"); 
  pitoLargo(); 
  varSegundos = 60 * varMinutos;
  varDiv = varSegundos - 60;      
   for (varSegundos; varSegundos >= 0; varSegundos--){
     if(varSegundos < 10){ nueveSegundos(); }
     if(varSegundos == varDiv){
       if(numero2 == 0){
         if(numero1 > 0){
           numero1--;
           actualizaUno();
         }else{
           numero1 = 0;
           actualizaUno();
         }
         if(varSegundos == 0){
           numero2 = 0;
           actualizaDos();
         }else{
           numero2 = 10;
           actualizaDos();
         }  
       }
       numero2--;
       actualizaDos();
       varDiv = varDiv - 60;
     } 
      Serial.println(varSegundos);
      delay(1000);
   }
 Serial.println("!! FIN DEL JUEGO !!");  
 Serial.println("StringOne: " + stringOne); 
 Serial.println("StringTwo: " + stringTwo);
 pitoLargo();
}

void numeroCeroI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  pito();
}
void numeroUnoI(){  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  pito();
}
void numeroDosI(){  
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  pito();
}
void numeroTresI(){  
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  pito();
}
void numeroCuatroI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  pito();
}
void numeroCincoI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  pito();
}
void numeroSeisI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  pito();
}
void numeroSieteI(){  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  pito();
}
void numeroOchoI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  pito();
}
void numeroNueveI(){  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  pito();
}

void numeroCeroD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, HIGH);
  digitalWrite(k, HIGH);
  digitalWrite(l, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(n, LOW);
  digitalWrite(o, HIGH);
  pito();
}
void numeroUnoD(){  
  digitalWrite(i, LOW);
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, LOW);
  digitalWrite(n, LOW);
  digitalWrite(o, HIGH);
  pito();
}
void numeroDosD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
  digitalWrite(l, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(n, HIGH);
  digitalWrite(o, LOW);
  pito();
}
void numeroTresD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, HIGH);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}
void numeroCuatroD(){  
  digitalWrite(i, LOW);
  digitalWrite(j, HIGH);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, LOW);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}
void numeroCincoD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, HIGH);
  digitalWrite(k, LOW);
  digitalWrite(l, LOW);
  digitalWrite(m, HIGH);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}
void numeroSeisD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, HIGH);
  digitalWrite(k, LOW);
  digitalWrite(l, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}
void numeroSieteD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, LOW);
  digitalWrite(n, LOW);
  digitalWrite(o, HIGH);
  pito();
}
void numeroOchoD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, HIGH);
  digitalWrite(k, HIGH);
  digitalWrite(l, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}
void numeroNueveD(){  
  digitalWrite(i, HIGH);
  digitalWrite(j, HIGH);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, LOW);
  digitalWrite(n, HIGH);
  digitalWrite(o, HIGH);
  pito();
}

void casoI(){
  
switch(tecla){
  case '0':
    numeroCeroI();
  break;
   case '1':
    numeroUnoI();
  break;
   case '2':
    numeroDosI();
  break;
   case '3':
    numeroTresI();
  break;
   case '4':
    numeroCuatroI();
  break;
   case '5':
    numeroCincoI();
  break;
   case '6':
    numeroSeisI();
  break;
   case '7':
    numeroSieteI();
  break;
   case '8':
    numeroOchoI();
  break;
   case '9':
    numeroNueveI();
  break; 
}  
}


void casoD(){
  
switch(tecla){
  case '0':
    numeroCeroD();
  break;
   case '1':
    numeroUnoD();
  break;
   case '2':
    numeroDosD();
  break;
   case '3':
    numeroTresD();
  break;
   case '4':
    numeroCuatroD();
  break;
   case '5':
    numeroCincoD();
  break;
   case '6':
    numeroSeisD();
  break;
   case '7':
    numeroSieteD();
  break;
   case '8':
    numeroOchoD();
  break;
   case '9':
    numeroNueveD();
  break; 
}  
}  

void nueveSegundos(){
  
switch(varSegundos){
  case 0:
    numeroCeroD();
  break;
   case 1:
    numeroUnoD();
  break;
   case 2:
    numeroDosD();
  break;
   case 3:
    numeroTresD();
  break;
   case 4:
    numeroCuatroD();
  break;
   case 5:
    numeroCincoD();
  break;
   case 6:
    numeroSeisD();
  break;
   case 7:
    numeroSieteD();
  break;
   case 8:
    numeroOchoD();
  break;
   case 9:
    numeroNueveD();
  break; 
}  
}  

void pito(){
  digitalWrite(12,HIGH);
  delay(10);
  digitalWrite(12,LOW); 
}

void pitoLargo(){
  digitalWrite(11,HIGH);
  delay(6000);
  digitalWrite(11,LOW); 
}

void actualizaUno(){
  switch(numero1){
    case 0:
        numeroCeroI();
    break;
     case 1:
        numeroUnoI();
    break;
     case 2:
        numeroDosI();
    break;
     case 3:
        numeroTresI();
    break;
     case 4:
        numeroCuatroI();
    break;
     case 5:
        numeroCincoI();
    break;
     case 6:
        numeroSeisI();
    break;
     case 7:
        numeroSieteI();
    break;
     case 8:
        numeroOchoI();
    break;
     case 9:
        numeroNueveI();
    break; 
  }  
}  

void actualizaDos(){
  switch(numero2){
    case 0:
        numeroCeroD();
    break;
     case 1:
        numeroUnoD();
    break;
     case 2:
        numeroDosD();
    break;
     case 3:
        numeroTresD();
    break;
     case 4:
        numeroCuatroD();
    break;
     case 5:
        numeroCincoD();
    break;
     case 6:
        numeroSeisD();
    break;
     case 7:
        numeroSieteD();
    break;
     case 8:
        numeroOchoD();
    break;
     case 9:
        numeroNueveD();
    break; 
  }  
} 
