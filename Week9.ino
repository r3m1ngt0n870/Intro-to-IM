int brightness = 0;
int buttonState = 0;


void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(11, brightness);
    delay(30);
  }

   buttonState = digitalRead(2);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(12, HIGH);
  } else {
    // turn LED off
    digitalWrite(12, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}