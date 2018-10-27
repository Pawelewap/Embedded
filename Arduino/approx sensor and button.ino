#define trigPin 13 // pin for sensor trig 
#define echoPin 11 // pin for sensor echo
int led(12), button(8), state(0);
long duration, distance;
//----------------->SETUP<---------------------
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}
//------------------>LOOP<----------------------
void loop() 
{
  serialCm();
  power();
}

//---------------->power<-----------------------
void power()
{
 int buttonState = digitalRead(button);
 if (distance < 10 || buttonState == 1) 
 {
      do
      {
        serialCm();
        digitalWrite(led, HIGH);
      }while (distance < 10);
      
        state = (!state);
 }
 if(state == 1)
    digitalWrite(led, HIGH);

 else
    digitalWrite(led, LOW);
}
//---------------->serialCm<--------------------
void serialCm()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
 
  delay(100); //debouncing
  
if (distance >= 100 || distance <= 0)
    Serial.println("Out of range");
else 
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
}
