#include <Keypad.h> //añadimos la libreria del teclado
#define FILAS 4 //creamos y definimos variables
#define COLUMNAS 4
const int g = 2;
const int f = 3;
const int a = 4;
const int b = 5;
const int e = 6;
const int d = 7;
const int c = 8;
#define out(pin) pinMode(pin,OUTPUT)//le ponemos nombres diferentes a codigos para mejor uso
#define ence(pin) digitalWrite(pin,HIGH)
#define apag(pin) digitalWrite(pin,LOW)


char keys[FILAS][COLUMNAS] = {//creamos una matriz del teclado
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char key;
byte Filas[FILAS]={17,16,15,14};//creamos el orden de los pines para su respectiva caracteristica
byte Columnas[COLUMNAS] = {9,10,11,12};

Keypad teclado = Keypad(makeKeymap(keys),Filas, Columnas,FILAS,COLUMNAS);

void setup()
{
  Serial.begin(9600);//activamos el monitor serial
 out(g);//definimos como salidas a cada led del display
 out(f);
 out(a);
 out(b);
 out(e);
 out(d);
 out(c);

}

void loop(){
  key = teclado.getKey(); 
  
  if(key){
  Serial.println(key);
  }else{
    apag(a);//apagamos todas las leds del display
    apag(b);
    apag(c);
    apag(d);
    apag(e);
    apag(f);
    apag(g);
    delay(100);
  }

  switch(key){
    case '0'://encendemos 0 en el display con la tecla 0
    ence(a);
    ence(b);
    ence(c);
    ence(d);
    ence(e);
    ence(f);
    apag(g);
    delay(500);
   break;

  case '1'://encendemos 1 en el display con la tecla 1
    ence(c);
    ence(b);
    apag(a);
    apag(d);
    apag(e);
    apag(f);
    apag(g);
    delay(500);
   break;
   
  case '2'://encendemos 2 en el display con la tecla 2
    ence(g);
    ence(e);
    ence(d);
    ence(b);
    ence(a);
    apag(c);
    apag(f);
    delay(500);
   break;
  
  case '3'://encendemos 3 en el display con la tecla 3
    ence(g);
    apag(e);
    ence(d);
    ence(b);
    ence(a);
    ence(c);
    apag(f);
    delay(500);
    break;
  
  case '4'://encendemos 4 en el display con la tecla 4
    ence(g);
    apag(e);
    apag(d);
    ence(b);
    apag(a);
    ence(c);
    ence(f);
    delay(500);
    break;

  case '5'://encendemos 5 en el display con la tecla 5
    ence(g);
    apag(e);
    ence(d);
    apag(b);
    ence(a);
    ence(c);
    ence(f);
    delay(500);
    break;

  case '6'://encendemos 6 en el display con la tecla 6
    ence(g);
    ence(e);
    ence(d);
    apag(b);
    ence(a);
    ence(c);
    ence(f);
    delay(500);
    break;

  case '7'://encendemos 7 en el display con la tecla 7
    ence(a);
    ence(b);
    ence(c);
    apag(d);
    apag(e);
    apag(f);
    apag(g);
    delay(500);
    break;

  case '8'://encendemos 8 en el display con la tecla 8
    ence(a);
    ence(b);
    ence(c);
    ence(d);
    ence(e);
    ence(f);
    ence(g);
    delay(500);
    break;

  case '9'://encendemos 9 en el display con la tecla 9
    ence(a);
    ence(b);
    ence(c);
    ence(d);
    apag(e);
    ence(f);
    ence(g);
    delay(500);
    break;

  case 'A'://encendemos A en el display con la tecla A
    ence(a);
    ence(b);
    ence(c);
    apag(d);
    ence(e);
    ence(f);
    ence(g);
    delay(500);
    break;

  case 'B'://encendemos B en el display con la tecla B
    ence(g);
    ence(e);
    ence(d);
    apag(b);
    apag(a);
    ence(c);
    ence(f);;
    delay(500);
    break;

  case 'C'://encendemos C en el display con la tecla C
    ence(a);
    apag(b);
    apag(c);
    ence(d);
    ence(e);
    ence(f);
    apag(g);
    delay(500);
    break;

  case 'D'://encendemos D en el display con la tecla D
    apag(a);
    ence(b);
    ence(c);
    ence(d);
    ence(e);
    apag(f);
    ence(g);
    delay(500);
    break;

  case '#'://encendemos F en el display con la tecla #
    ence(a);
    apag(b);
    apag(c);
    ence(d);
    ence(e);
    ence(f);
    ence(g);
    delay(500);
    break;

  case '*'://encendemos E en el display con la tecla *
    ence(a);
    apag(b);
    apag(c);
    apag(d);
    ence(e);
    ence(f);
    ence(g);
    delay(500);
    break;

  }

  
}