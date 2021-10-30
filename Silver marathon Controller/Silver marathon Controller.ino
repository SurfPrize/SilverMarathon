// constants won't change. They're used here to set pin numbers:
const int blueButtonPin = 2;     // the number of the pushbutton pin
const int greenButtonPin = 3;     // the number of the pushbutton pin
const int redButtonPin = 4;     // the number of the pushbutton pin

int shakeSensor;

//joystick
#define joyX A0
#define joyY A1
float  xValue, yValue; 
// 0-red, 1-green, 2-blue
int btnpressed[3];

// buttons to change colors of the weapon
int buttonState[3];// variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(blueButtonPin, INPUT);
  digitalWrite(blueButtonPin, HIGH);
  pinMode(greenButtonPin, INPUT);
  digitalWrite(greenButtonPin, HIGH);
  pinMode(redButtonPin, INPUT);
  digitalWrite(redButtonPin, HIGH);
  digitalWrite(A2, HIGH);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState[2] = digitalRead(blueButtonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState[2] == HIGH) {
    //digitalWrite(ledPin, HIGH);
    //Serial.println("Btn off");
    if(btnpressed[2]==1){
      Serial.println("blue chosen");
      btnpressed[2] = 0;
    }
  } else {
    btnpressed[2] = 1;
    //digitalWrite(ledPin, LOW);
    //Serial.println("Btn on");
  }
  // read the state of the pushbutton value:
  buttonState[1] = digitalRead(greenButtonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState[1] == HIGH) {
    //digitalWrite(ledPin, HIGH);
    //Serial.println("Btn off");
    if(btnpressed[1]==1){
      Serial.println("green chosen");
      btnpressed[1] = 0;
    }
  } else {
    btnpressed[1] = 1;
    //digitalWrite(ledPin, LOW);
    //Serial.println("Btn on");
  }
  // read the state of the pushbutton value:
  buttonState[0] = digitalRead(redButtonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState[0] == HIGH) {
    //digitalWrite(ledPin, HIGH);
    //Serial.println("Btn off");
    if(btnpressed[0]==1){
      Serial.println("red chosen");
      btnpressed[0] = 0;
    }
  } else {
    btnpressed[0] = 1;
    //digitalWrite(ledPin, LOW);
    //Serial.println("Btn on");
  }
  AnalogControl();
  ShakeSensor();
}
void AnalogControl(){
  xValue = analogRead(joyX);
  //yValue = analogRead(joyY);
  xValue-=487;
  /*Serial.print("StickX ");
  Serial.print(xValue);
  Serial.print("\n");
  Serial.print("StickY ");
  Serial.print(yValue);
  Serial.print("\n");*/
  if(xValue>200){
    Serial.println("StickX 1");
  }
  if(xValue<-200){
    Serial.println("StickX -1");
  }
}
void ShakeSensor(){
  shakeSensor = analogRead(A2);
  shakeSensor-=1013;
	//While sensor is not moving, analog pin receive 1023~1024 value
	if (shakeSensor<-20){
    //Serial.println("Sensor stopped");
    Serial.println("attack");
		//Serial.println(shakeSensor);
	} 
}
void BtnPress(){
  
}