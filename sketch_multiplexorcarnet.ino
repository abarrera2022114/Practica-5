int digitos; //creamos variables
int digitos2;
int digitos3 = 0;
int contador = 0;
void mostrarNumero (int x); 

void setup()
{
  Serial.begin(9600);//encendemos el monitor serial
  for(int i=2; i<9;i++)
    pinMode(i, OUTPUT);//activamos las salidas
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  
}

void loop()
{
  
  digitos = digitalRead(9);/*creamos toda la funcion del if contador*/
  Serial.println(digitos);
  delay(50);
  if(digitos == HIGH){
contador++;
Serial.println(contador);/**/
delay(200);
}
 
  if(contador  == 0){ /*creamos el creamos los patrones de como se veran los numeros*/
    mostrarNumero (2);
  digitalWrite(A1,LOW);
  digitalWrite(A0,HIGH);
  delay(50);
  
  mostrarNumero (0);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,LOW);
  delay(50);
  }

 if(contador == 1){
     mostrarNumero (2);
  digitalWrite(A1,LOW);
  digitalWrite(A0,HIGH);
  delay(50);
  
  mostrarNumero (2);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,LOW);
  delay(50);
  }
  if(contador == 2){
      mostrarNumero (1);
  digitalWrite(A1,LOW);
  digitalWrite(A0,HIGH);
  delay(50);
  
  mostrarNumero (1);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,LOW);
  delay(50);
    }
if(contador == 3){
    mostrarNumero (4);
  digitalWrite(A1,LOW);
  digitalWrite(A0,HIGH); /**/
  delay(50);
  }
  if(contador == 4){
   contador = contador-4; //reiniciamos el contador
delay(50);  }

}



void mostrarNumero (int x)//mostrara el numero esta funcion
{
   switch(x){
    case 0:
      digitalWrite(2,HIGH);//mostrara 0 
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      break;
    
  case 1:
    digitalWrite(2,LOW);//mostrara 1
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    break;
    
   case 2:
    digitalWrite(2,HIGH);//mostrara 2
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
     break;
     
        
   case 4:
    digitalWrite(2,LOW);//mostrara 4
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    

  }
  
}