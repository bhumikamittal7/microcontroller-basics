#define trigPin 5
#define echoPin 18

//define sound speed in cm
#define SOUND_SPEED 0.034

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  //define trigpin and echopin - which is input, which is output?
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // Clears the trigPin - to unsure we get rid of noise
  digitalWrite(trigPin, LOW);
  delay(0.002);
  // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delay(0.01);
    digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  // Hint - use pulseIn() - which returns the length of the pulse in microseconds. 
  // The pulse length corresponds to the time it took to travel to the object plus the time traveled on the way back.
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * 0.034/2;

  
  // Prints the distance in the Serial Monitor
  Serial.print(distanceCm);

  delay(1000);
}

