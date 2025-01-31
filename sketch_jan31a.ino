#include <Servo.h>

Servo myservo;  // create Servo object to control a servoServo myservo
// twelve Servo objects can be created on most boards  

int pos = 0;    // variable to store the servo position
int command = ""; // variable for voice command

const int RELAY1_PIN = 6;  // Pin number for RELAY 1
const int RELAY2_PIN = 5;  // Pin number for RELAY 2
const int RELAY3_PIN = 4;  // Pin number for RELAY 3 

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
   myservo.write(0);   // Ensure that servo starts at 0 degrees

  // Initialize relay PINS as OUTPUT
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);

  // Set all relays to OFF initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
  digitalWrite(RELAY3_PIN, LOW);

  // Set up built-in LED for visual feedback
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  Serial.println("System initialized. Waiting for Commands...");
}

void loop() {
 if (Serial.available()) {
  String command = Serial.readStringUntil('\n'); // Read the incoming command
  command.trim();  // Remove extra spaces or newlines
    command.toLowerCase();  // Convert to lowercase for consistent comparison
    Serial.println("Received command: " + command);

  // Process the voice
  while(Serial.available()){
  char c = Serial.read();
  if (c == "\n") break; //End of command
  command+=c;}

  // Print received command for debugging
  Serial.println("Received command: ");

  if (command == "lamp") {
    digitalWrite(RELAY1_PIN, HIGH);  // Turn on RELAY 1
    Serial.println("Relay 1 turned ON");
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (command == "offline one") {
    digitalWrite(RELAY1_PIN, LOW);  // Turn off RELAY 1
    Serial.println("Relay 1 turned OFF");
    digitalWrite(LED_BUILTIN, LOW);
  } else if (command == "fun") {
    digitalWrite(RELAY2_PIN, HIGH);  // Turn on RELAY 2
     Serial.println("Relay 2 turned ON");
     digitalWrite(LED_BUILTIN, HIGH);
  } else if (command == "offline 2") {
     digitalWrite(RELAY2_PIN, LOW);  // Turn off RELAY 2
      Serial.println("Relay 2 turned OFF");
     digitalWrite(LED_BUILTIN, LOW);
  } else if (command == "lights") {
     digitalWrite(RELAY3_PIN, HIGH);  // Turn on RELAY 3
      Serial.println("Relay 3 turned ON");
     digitalWrite(LED_BUILTIN, HIGH);
  } else if (command == "offline 3") {
    digitalWrite(RELAY3_PIN, LOW);  // Turn off RELAY 3
     Serial.println("Relay 3 turned OFF");
    digitalWrite(LED_BUILTIN, LOW);
  } else if(command == "all on") {
    // Turn on all RELAY PINS
    digitalWrite(RELAY1_PIN, HIGH); 
    digitalWrite(RELAY2_PIN, HIGH);
    digitalWrite(RELAY3_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Relays turned ON");
    
  } else if(command == "all off") {
    // Turn off all RELAY PINS
    digitalWrite(RELAY1_PIN, LOW);
    digitalWrite(RELAY2_PIN, LOW);
    digitalWrite(RELAY3_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
     Serial.println("Relays turned OFF");
    
   }else if (command == "open door") {
  for (pos = 0; pos <= 180; pos += 1)  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                        // waits 15 ms for the servo to reach the position
    Serial.println("Door opened");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000);  // Wait 10 seconds before closing
   } else if (command == "close door"){
    Serial.println("Door closed");
    digitalWrite(LED_BUILTIN, LOW); 
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
}