/*
 * LM35 SENSOR
 * 
 */
const int inPin = 0;
const int ledRed = 11;
const int ledBlue = 10;
const int ledYellow = 9;
const int ledMlt = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Led
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT); 
  pinMode(ledMlt,OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  int value = analogRead(inPin);
  
  int valueR = analogRead(ledRed);
  int valueY = analogRead(ledYellow);
  int valueB = analogRead(ledBlue);
  int valueM = analogRead(ledMlt);
  
  Serial.print(value);Serial.print(" > ");
  float millivolts = (value/1024.0)*5000;
  float celsius = millivolts/10 ; //sensor output is 10mV per degree C
  float feren = (celsius *9)/5 +32;
    if(feren > 80.0){
    //LED HOT
      digitalWrite(ledRed, HIGH);   
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledBlue, LOW); 
    }else if(feren < 80.0 && feren > 75.0){
  //LED neut
      digitalWrite(ledRed, LOW);   
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledBlue, LOW); 
      //digitalWrite(ledMlt, HIGH); 
    }else{
      digitalWrite(ledRed, LOW);   
      digitalWrite(ledYellow, LOW); 
      digitalWrite(ledBlue, HIGH); 
    }
 
  Serial.print(celsius);
  Serial.print(" Deg Celcius, ");
  Serial.print(feren); //converts to F
  Serial.println( " degrees F" );
  delay(2000);//wait two seconds

}
