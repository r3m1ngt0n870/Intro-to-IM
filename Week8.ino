
int cm = 0;
int triggerPin = 7;    // TRIG pin
int echoPin = 6;
int red = 12;
int yellow = 11;
int green = 10;    // ECHO pin
int ping = 0;
int close = 50;
int far = 100;

void setup()
{
  pinMode(red, INPUT);
  pinMode(yellow, INPUT);
  pinMode(green, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // measure duration of pulse from ECHO pin
  ping = pulseIn(echoPin, HIGH);

  // calculate the distance
  cm = 0.017 * ping;
  // measure the ping time in cm
  Serial.print(cm);
  Serial.println("cm ");
  Serial.print(ping);
  Serial.println("ms");
  delay(100); // Wait for 100 millisecond(s)
  
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  
  if(cm < close){
    digitalWrite(red, HIGH);
  }
  if(cm < far && cm > close){
    digitalWrite(yellow, HIGH);
  }
  if(cm > far){
    digitalWrite(green, HIGH);
  }
  
  delay(100);
}