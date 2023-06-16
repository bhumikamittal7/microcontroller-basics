#include <random>

int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  count++;

  Serial.print(count);
  
  Serial.println();  // Print a new line after transmitting all the numbers

  delay(1000);  // Delay between each batch of random number transmissions
}
