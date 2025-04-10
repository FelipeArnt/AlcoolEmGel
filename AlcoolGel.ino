//Bibliotecas
#include <Ultrasonic.h>
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
volatile byte cicles = 1;
volatile byte i = 0;

void setup(){
  Serial.begin(9600);
  servo.attach(pinServo);
  servo.write(100); //posição inicial
  
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(pinButton), ISR0, FALLING);
}

void ISR0(){
  tmp2++;
  if(tmp2 > 2) tmp2 = 0;
  
  cicles = tmp2 + 1; // 1, 2 ou 3 ciclos
  i = 0;
}

uint16_t readSensorandCompare(){
  uint16_t distCM = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM);
  
  Serial.print("tmp2: ");
  Serial.print(tmp2);
  Serial.print(" Cicles: ");
  Serial.print(cicles);
  Serial.print(" distCM: ");
  Serial.println(distCM);

  if(distCM < 10 && tmp == 0){
    switch(tmp2){
      case 0: alcoolT(100, 80); break;
      case 1: alcoolT(100, 70); break;
      case 2: alcoolT(100, 60); break;
    }
  }
  
  if(distCM > 16){
    tmp = 0;
  }
  
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
