//Code meant to toggle the led every time a button is pressed.

#define PRESSED 1
#define NOT_PRESSED 0
#define ON 1
#define OFF 0

const int ledPin = 12;
const int buttonPin = 8;
bool isLedOn = false;
bool pinAlreadyGoneToZero = false;

void setup(){
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
}

void loop(){
  int buttonState = digitalRead(buttonPin);

  if(buttonState == PRESSED && pinAlreadyGoneToZero == true){
    pinAlreadyGoneToZero = false;
    if(isLedOn){
      digitalWrite(ledPin, OFF);
      isLedOn = false;
    }else{
      digitalWrite(ledPin, ON);
      isLedOn = true;
    }
  }else if(buttonState == NOT_PRESSED){
    pinAlreadyGoneToZero = true;
  }

  
}