//Bibliotecas

#include Ultrasonic.h
#include <Servo.h>

//Hardware

#define pinButton 5
#define pinEcho 7 
#define pinTrigger 3
#define pinServo 6
#define pinLED 4


//Objetos e variaveis

Servo servo; //Motor
Ultrasonic ultrasonic(pinTrigger, pinEcho); 

boolean tmp = 0;
volatile uint16_t tmp2 = 0;
volatile byte cicles;
volatile byte i ;

//Funcoes
uint16_t readSensorandCompare();
void alcoolT(byte maxAngle, byte minAngle);
void interface();

void setup(){
  Serial.begin(9600);
  servo.attach(pinServo);
  servo.write(100); //setando a posição inicial do motor;

  //Ent e Saida digital

  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  //Interrupção Externa (ISR0)

  attachInterrupt(digitalPinToInterrupt(pinButton), ISR0, FALLING);
}

void ISR0(){
  tmp2++;
  
  if(tmp2 > 2)tmp2 = 0;
  
  if(tmp2 == 0) cicles = 1;
  if(tmp2 == 1) cicles = 2;
  if(tmp2 == 2) cicles = 3;
  
  i = 0; 
}


void loop(){
  readSensorandCompare();
  interface();

  delay(400);
}

//Sensor Ultrassônico

uint16_t readSensorandCompare(){

  uint16_t distCM = ultrasonic.convert(ultrasonic.timing(), Ultrasonic :: CM); //distância
  Serial.print(tmp2 : );
  Serial.print(tmp2);
  Serial.print( Cicles :);
  Serial.print(cicles);
  Serial.print(distCM :);
  Serial.print(distCM);


if (distCM < 10 && tmp == 0 && tmp2 == 0){alcoolT(100, 80);}

if (distCM < 10 && tmp == 0 && tmp2 == 1){alcoolT(100, 70);}

if(distCM < 10 && tmp == 0 && tmp2 == 2){alcoolT(100, 60);}

if(distCM > 16){tmp = 0;}

return distCM;
}


void alcoolT(byte maxAngle, byte minAngle){
  digitalWrite(pinLED, HIGH);
  servo.write(maxAngle);
  delay(200);
  
  servo.write(minAngle);
  delay(200);
  
  servo.write(maxAngle);
  digitalWrite(pinLED, LOW);
  
  tmp = 1;
}


void interface(){
    if (i < cicles){
      digitalWrite(pinLED, HIGH);
      delay(100);
      digitalWrite(pinLED, LOW);
      delay(100);
      i++;
      }
    }
