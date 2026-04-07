int brightness = 0;
int buttonState = 0;


void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

//timing the yellow LED
void loop()
{
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(11, brightness);
    delay(30);
  }

  //triggering the red LED when button is pressed
   buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  delay(10);
}
