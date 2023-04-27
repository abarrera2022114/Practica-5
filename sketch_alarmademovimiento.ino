#include <Keypad.h>/*integramos la libreria del teclado*/

const int FILAS = 4;/*cremaos las variables*/
const int COLUMNAS= 4;/**/
char keys[FILAS][COLUMNAS]={/*matriz del teclado*/
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}/**/
};
byte pinesFila[FILAS]={9,8,7,6};/*ordenamos el como van las filas y columnas*/
byte pinesColumna[COLUMNAS]={5,4,3,2};/**/

Keypad teclado=Keypad(makeKeymap(keys), pinesFila, pinesColumna,FILAS,COLUMNAS);

char teclaPrecionada;

char pass[5]="2332"; //Poner en el arreglo 1 posicion mas a la que tendra la contraseña correcta
char ingresaPass[5]; // tiene que tener el mismo tamaño del arreglo de la contraseña correcta
int indice=0;

/* DECLARAMOS LAS VARIABLES QUE VAMOS A UTILIZAR*/
int Pin_Led = 13;
int Pin_Radar = 10;
int buzzer = 11;/**/
#define buzzon() tone(buzzer, 200)/*definimos los nombres de los nuevos codigos*/
#define buzzoff() noTone(buzzer)
#define time() delay(1500)/**/
 
void setup()
{
  Serial.begin(9600);/*activamos monitor serial*/
  pinMode(Pin_Led, OUTPUT);/*activamos entradas y salidas y el activar y desactivar del buzzer*/
  pinMode(Pin_Radar, INPUT);
  buzzon();
  buzzoff();/**/
}
 
void loop()
{
  teclaPrecionada=teclado.getKey(); //detecta que en el teclado se pulso un boton
  if(teclaPrecionada){
    ingresaPass[indice]=teclaPrecionada; // le asigna lo que ingresamos a el arreglo que va a ser comparado
    indice++; //cambiara la posicion del arreglo para poder asignar los caracteres
    Serial.print(teclaPrecionada);
  }
  
  int radar = digitalRead(Pin_Radar);/*guardamos el pulso del radar en una variable*/
 
  if (radar == HIGH) /*si el radar eciende activar lo de entre {  }*/
  {
    digitalWrite(Pin_Led, HIGH);/*encender pinLed*/
    buzzon();/*encender buzzer*/
  }

  if(indice==4){ //cuando se llegue al limite del arreglo verificara si esta correcta o no la contraseña
    if(strcmp(pass,ingresaPass)==0){ //Verifica que la contraseña esta correcta
      Serial.println(" Acceso permitido");
      buzzoff();/*apagar buzzer*/
      digitalWrite(Pin_Led, LOW);/*apagar pinLed*/
    }
    indice=0;/*reinicia el ciclo*/
  }
}