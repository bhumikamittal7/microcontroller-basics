// Potentiometer is connected to GPIO (Analog ADC1_CH6)
const int potPin = 34;

// variable for storing potentiometer value
int potValue = 0;

void setup(){
  // Set up baud rare
  Serial.begin(115200);
  // 1 Second Delay
  delay(1000);
}

void loop(){
  // Reading potentiometer value
  potValue = analogRead(potPin);
  Serial.println(potValue);
  delay(500);
}