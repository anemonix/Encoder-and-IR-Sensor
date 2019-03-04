int LEDPin = 13;
int inputPin = 12; 
int fwdpin = 10; // pins designated for backwards and forward motion
int bckwdpin = 9;
int coastClear = LOW; 
int countStates = 0;
int numberOfTicks;
long startRotation;
long endRotation;
long totalTime;
float ticksPerSecond = 0.0;

void setup() 
{
  pinMode(LEDPin, OUTPUT);
  pinMode(fwdpin, OUTPUT);
  pinMode(bckwdpin, OUTPUT);
  pinMode(inputPin, INPUT);
  analogWrite(fwdpin, 127); // keep this at 127, swap with below if you wanna change dir
  analogWrite(bckwdpin, 230); //range is like 190 - 255
  Serial.begin(9600);
  }
void loop() 
{
  if(numberOfTicks == 0)
  {
    startRotation = (millis());
  }

  coastClear=digitalRead(inputPin);
  if (coastClear)
  {
    digitalWrite(LEDPin, LOW);
  }
  else
  {
    countStates++;
    digitalWrite(LEDPin, HIGH);
  }
  if(countStates == 2)
  {
    numberOfTicks++;
    countStates = 0;
  }
  if(numberOfTicks == 75)
  {
    numberOfTicks = 0;
    endRotation = (millis());
    totalTime = (endRotation - startRotation);
    ticksPerSecond = ((1.0)/((float)totalTime))*1000;
    Serial.print("System running at ");
    Serial.print(ticksPerSecond, 6);
    Serial.println(" ticks per s");
  }
  delay(5);
}
