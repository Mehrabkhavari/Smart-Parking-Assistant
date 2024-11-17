const int trigPin = 9;  // TRIG pin of the ultrasonic sensor
const int echoPin = 10; // ECHO pin of the ultrasonic sensor
const int buzzerPin = 8; // Buzzer pin
const int greenLedPin = 7; // Green LED pin
const int yellowLedPin = 6; // Yellow LED pin
const int redLedPin = 5;   // Red LED pin

void setup() 
  {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    Serial.begin(9600); // For debugging (optional)
  }

void loop() 
  {
    long duration, distance;
    int beepDelay; 
    
    // Send an ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Measure the duration of the echo
    duration = pulseIn(echoPin, HIGH);
  
    // Calculate the distance in cm
    distance = duration * 0.034 / 2;
  
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  
    // Logic to control the LEDs and buzzer
    if (distance < 16 && distance >= 13) 
      { 
        // Green: Keep going
        digitalWrite(greenLedPin, HIGH); // Turn on the green LED (common anode)
        digitalWrite(yellowLedPin, LOW); // Turn off the yellow LED
        digitalWrite(redLedPin, LOW); // Turn off the red LED
        beepDelay = 900; // Longer delay between beeps
      } 
    else if (distance >= 11) 
      { 
        // Green: Keep going
        digitalWrite(greenLedPin, HIGH); // Turn on the green LED (common anode)
        digitalWrite(yellowLedPin, LOW); // Turn off the yellow LED
        digitalWrite(redLedPin, LOW); // Turn off the red LED
        beepDelay = 700; // Longer delay between beeps
      } 
    else if (distance >= 9) 
      { 
        // Yellow: Slow down
        digitalWrite(greenLedPin, LOW); // Turn off the green LED
        digitalWrite(yellowLedPin, HIGH); // Turn on the yellow LED
        digitalWrite(redLedPin, LOW); // Turn off the red LED
        beepDelay = 400; // Longer delay between beeps
      } 
    else if (distance >= 7) 
      { 
        // Yellow: Slow down
        digitalWrite(greenLedPin, LOW); // Turn off the green LED
        digitalWrite(yellowLedPin, HIGH); // Turn on the yellow LED
        digitalWrite(redLedPin, LOW); // Turn off the red LED
        beepDelay = 250; // Longer delay between beeps
      } 
    else if (distance >= 4) 
      { 
        // Red: Slow down
        digitalWrite(greenLedPin, LOW); // Turn off the green LED
        digitalWrite(yellowLedPin, LOW); // Turn off the yellow LED
        digitalWrite(redLedPin, HIGH); // Turn on the red LED
        beepDelay = 100;  // Shorter delay between beeps
      }
    else if (distance <= 3) 
      { 
        // Red: Stop 
        digitalWrite(greenLedPin, LOW); // Turn off the green LED
        digitalWrite(yellowLedPin, LOW); // Turn off the yellow LED
        digitalWrite(redLedPin, HIGH); // Turn on the red LED
        tone(buzzerPin, 1000); // Continuous beep at the last level
      }
    else 
      { 
        // Green: Keep going
        digitalWrite(greenLedPin, HIGH); // Turn on the green LED (common anode)
        digitalWrite(yellowLedPin, LOW); // Turn off the yellow LED
        digitalWrite(redLedPin, LOW); // Turn off the red LED
        noTone(buzzerPin); // No sound
      } 

    // Generate intermittent beep with variable delay
    if (distance > 3 && distance <= 16)
      { // Only beep if not in the green or red (stop) zone
        tone(buzzerPin, 1000); // Beep at a constant frequency
        delay(100); // Beep duration
        noTone(buzzerPin); // Stop beep
        delay(beepDelay); // Variable pause between beeps 
      }
  
    delay(5); // Short delay for stability
  }
