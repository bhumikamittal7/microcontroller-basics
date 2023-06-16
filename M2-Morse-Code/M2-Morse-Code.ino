const int ledPin = 15;  // Pin number for the LED
const int dotDuration = 200;  // Duration of a dot in milliseconds

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is available to read
    char input = Serial.read();  // Read the incoming data
    blinkMorseCode(input);  // Call the function to blink Morse code
  }
}

void blinkMorseCode(char letter) {
  // Convert the letter to Morse code pattern
  String morseCode = getMorseCode(letter);

  // Blink the LED based on the Morse code pattern
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode[i] == '.') {
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      delay(dotDuration);  // Duration for a dot
    } else if (morseCode[i] == '-') {
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      delay(dotDuration * 3);  // Duration for a dash (3 times a dot)
    }
    digitalWrite(ledPin, LOW);  // Turn off the LED
    delay(dotDuration);  // Pause between dots and dashes
  }
}

String getMorseCode(char letter) {
  // Define the Morse code patterns for each letter
  // You can add more letters and symbols as needed
  switch (letter) {
    case 'A':
    case 'a':
      return ".-";
    case 'B':
    case 'b':
      return "-...";
    case 'C':
    case 'c':
      return "-.-.";
    case 'D':
    case 'd':
      return "-..";
    case 'E':
    case 'e':
      return ".";
    case 'F':
    case 'f':
      return "..-.";
    case 'G':
    case 'g':
      return "--.";
    case 'H':
    case 'h':
      return "....";
    case 'I':
    case 'i':
      return "..";
    case 'J':
    case 'j':
      return ".---";
    case 'K':
    case 'k':
      return "-.-";
    case 'L':
    case 'l':
      return ".-..";
    case 'M':
    case 'm':
      return "--";
    case 'N':
    case 'n':
      return "-.";
    case 'O':
    case 'o':
      return "---";
    case 'P':
    case 'p':
      return ".--.";
    case 'Q':
    case 'q':
      return "--.-";
    case 'R':
    case 'r':
      return ".-.";
    case 'S':
    case 's':
      return "...";
    case 'T':
    case 't':
      return "-";
    case 'U':
    case 'u':
      return "..-";
    case 'V':
    case 'v':
      return "...-";
    case 'W':
    case 'w':
      return ".--";
    case 'X':
    case 'x':
      return "-..-";
    case 'Y':
    case 'y':
      return "-.--";
    case 'Z':
    case 'z':
      return "--..";
    case '0':
      return "-----";
    case '1':
      return ".----";
    case '2':
      return "..---";
    case '3':
      return "...--";
    case '4':
      return "....-";
    case '5':
      return ".....";
    case '6':
      return "-....";
    case '7':
      return "--...";
    case '8':
      return "---..";
    case '9':
      return "----.";
    // Add more cases for other letters or symbols
    default:
      return "";  // Return an empty string for unsupported characters
  }
}


