int pot_res = A0;
int pot_res_reading;
int led_pin = 9;
float brightness;

int trigpin = 5;
int echopin = 6;
long duration;
float distance;
int delay_time = 200;

void setup() {
  // put your setup code here, to run once:
pinMode(pot_res, INPUT);
pinMode(led_pin, OUTPUT);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_res_reading = analogRead(pot_res);
  brightness = (255. / 1023.) * pot_res_reading;
//Serial.print("The current reading from the photoresistor is:\t");


digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);

duration = pulseIn(echopin, HIGH);
distance = duration *(0.034 / 2);

Serial.print("The current brightness level is \t");
Serial.print(brightness);
Serial.print(" The nearest object is: \t");
Serial.print(distance);
Serial.println(" cm ahead");


if(brightness <= 60){
  digitalWrite(led_pin, LOW);
  
}
else if(brightness > 70){
  if(distance <= 20){
    digitalWrite(led_pin, HIGH);
    delay(3000);
  }
  else{
    analogWrite(led_pin, 65);
  }
}


delay(delay_time);
}
