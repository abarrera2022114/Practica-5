#include <Adafruit_NeoPixel.h> /*añadimos librerias*/
#include <Keypad.h>
#include <Servo.h>/**/
#define time() delay(1500)/*definimos nuevos nombres para codigos*/
#define FILAS 4
#define COLUMNAS 4/**/

Adafruit_NeoPixel tira = Adafruit_NeoPixel(12,13);/*ponemos la cantidad de leds del neopixel y el pin al que va*/

char keys[FILAS][COLUMNAS] = {/*matriz del teclado*/
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}/**/
};

char key;
byte Filas[FILAS]={9,8,7,6};/*orden de filas y columnas de los pines*/
byte Columnas[COLUMNAS] = {5,4,3,2};/**/

Keypad teclado = Keypad(makeKeymap(keys),Filas, Columnas,FILAS,COLUMNAS);

Servo cito;/*nombre del servo*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);/*activar monitor serial*/
  tira.begin();/*encender tira*/
  tira.show();/*mostrar en tira*/
  cito.attach(10);/*pin al que ira el servo*/

}

void loop() {
  // put your main code here, to run repeatedly:
  key = teclado.getKey();

  if(key){
  Serial.println(key);
  }else{
    tira.clear();/*apagar tira o neopixel*/
  }
  switch(key){/*creamos que hara al presionar 0*/
    case '0':
      cito.write(0);
      time();/**/
    break;

    case '1':/*creamos que hara al presionar 1*/
      cito.write(20);
      time();/**/
    break;

    case '2':/*creamos que hara al presionar 2*/
      cito.write(40);
      time();/**/
    break;

    case '3':/*creamos que hara al presionar 3*/
      cito.write(60);
      time();/**/
    break;

    case '4':/*creamos que hara al presionar 4*/
      cito.write(80);
      time();/**/
    break;

    case '5':/*creamos que hara al presionar 5*/
      cito.write(100);
      time();/**/
    break;

    case '6':/*creamos que hara al presionar 6*/
      cito.write(120);
      time();/**/
    break;

    case '7':/*creamos que hara al presionar 7*/
      cito.write(140);
      time();/**/
    break;

    case '8':/*creamos que hara al presionar 8*/
      cito.write(160);
      time();/**/
    break;

    case '9':/*creamos que hara al presionar 9*/
      cito.write(180);
      time();/**/
    break;

    case 'A':/*creamos que hara al presionar A*/
      for(int i = 0; i<12; i = i+2 ){/*patron de led para el neopixel*/
        tira.setBrightness(100);
        tira.setPixelColor(i, 0,255,255);
        tira.show();
          delay(100);/**/
      }
    break;

    case 'B':/*creamos que hara al presionar B*/
      for(int i = 0; i<12; i++) {/*patron de led para el neopixel*/
        tira.setBrightness(100);
        tira.setPixelColor(i, 255,201,0);
        tira.show();
          delay(100);/**/
     }
    break;

    case 'C':/*creamos que hara al presionar C*/
     for(int i = 12; i>=-1; i = i-2) {/*patron de led para el neopixel*/
       tira.setBrightness(100);
       tira.setPixelColor(i, 0,0,255);
       tira.show();
          delay(100);/**/
     } 
    break;

    case 'D':/*creamos que hara al presionar D*/
      for(int i = 0; i<12; i = i+3) {/*patron de led para el neopixel*/
       tira.setBrightness(100);
       tira.setPixelColor(i, 255,0,0);
       tira.show();
         delay(100);/**/
     }
    break;

    case '*' :/*creamos que hara al presionar *  */
      for(int i=0;i<12 ;i++){/*patron de led para el neopixel*/
        tira.setBrightness(100);
        tira.setPixelColor(i, 255,100,150);
        tira.show();
         delay(100);/**/
      }
    break;

    case '#':/*creamos que hara al presionar #*/
      for(int i = 0; i<12; i = i+2 ){/*patron de led para el neopixel*/
        tira.setBrightness(100);
        tira.setPixelColor(i, 200,25,55);
        tira.show();
         delay(100);/**/
      }
    break;
}

}
