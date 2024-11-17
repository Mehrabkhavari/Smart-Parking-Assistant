# Smart Parking Assistant with Arduino and Ultrasonic Sensor

This project helps you build a smart parking assistant using an Arduino board, an ultrasonic sensor, LEDs, and a buzzer. The system guides you into a parking space by providing visual and auditory cues based on your distance from obstacles.

## Features:

* **Distance Measurement:** Accurately measures the distance to obstacles using an ultrasonic sensor (HC-SR04).
* **Visual Guidance:**  Uses LEDs to indicate proximity (green for safe distance, yellow for caution, red for stop).
* **Audible Feedback:**  A buzzer provides intermittent beeps with varying delays depending on the distance to the obstacle. The closer you get, the faster the beeps!
* **Customizable:** Easily adjust distance thresholds and beep delays to match your parking environment.


## Table of Contents:

  - [Hardware Components](#Hardware-Components)
  - [Software](#Software)
  - [Wiring Diagram](#Wiring-Diagram)
  - [Code](#Code)
  - [How it Works](#How-it-Works)
  - [Applications](#Applications)
  - [Contributing](#Contributing)

## Hardware Components:

* Arduino board (e.g., Arduino Uno)
* HC-SR04 Ultrasonic Sensor
* LEDs (green, yellow, red)
* Buzzer
* Resistors (for LEDs)
* Jumper wires
* Breadboard (optional)

## Software:

* Arduino IDE

## Wiring Diagram:

![image](https://github.com/user-attachments/assets/1c86deb7-fbdb-4eb1-b78d-9f90ef0733dc)


## How it Works:

The ultrasonic sensor measures the distance to an obstacle. Based on this distance, the Arduino controls the LEDs and the buzzer to provide feedback to the user. The LEDs change color to indicate proximity, and the buzzer beeps with varying delays to provide an audible warning.


## Code:

The Arduino code for this project is provided in the `smart_parking_assistant.ino` file. You can easily modify the code to adjust the distance thresholds, beep frequency, and LED behavior.

## Description:


```c++
const int trigPin = 9;  // TRIG pin of the ultrasonic sensor
const int echoPin = 10; // ECHO pin of the ultrasonic sensor
const int buzzerPin = 8; // Buzzer pin
const int greenLedPin = 7; // Green LED pin
const int yellowLedPin = 6; // Yellow LED pin
const int redLedPin = 5;   // Red LED pin
```
*This section defines the pins used to connect the different components to your Arduino board.*

`trigPin`: Digital pin 9 is used to trigger the ultrasonic sensor.

`echoPin`: Digital pin 10 receives the echo from the ultrasonic sensor.

`buzzerPin`: Digital pin 8 controls the buzzer.

`greenLedPin`, `yellowLedPin`, `redLedPin`: Digital pins 7, 6, and 5 control the green, yellow, and red LEDs, respectively.

You can change these pin numbers if you need to, but make sure they match your actual wiring.

```c++
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
```

 *The `setup()` function is called once when your Arduino starts up. Here's what it does:*

`pinMode(pin, mode)`: This configures each pin as either an input (`INPUT`) or an output (`OUTPUT`).

The `trigPin` is an output because it sends a signal to the sensor.

The `echoPin` is an input because it receives a signal from the sensor.

The LED and buzzer pins are outputs because the Arduino controls them.

`Serial.begin(9600)`: This line initializes serial communication, which can be useful for debugging your code by printing messages to the Serial Monitor.


```c++
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

    // ... (rest of the code) ...
}
```

The `loop()` function runs repeatedly after the `setup()` function. This is where the main logic of your program goes.

* **Distance Measurement:**
  * It sends an ultrasonic pulse from the `trigPin`.
  * It measures how long it takes for the echo to return to the `echoPin` using `pulseIn()`.
  * It calculates the distance to the object in centimeters based on the time it took for the echo to return.
* **Serial Monitor Output:**
  * It prints the measured distance to the Serial Monitor (if you have it open). This is helpful for debugging and seeing the sensor readings in real-time.

**The rest of the code within the `loop()` function handles the logic for controlling the LEDs and the buzzer based on the measured distance**







## Applications:

* Garage parking assistant
* Robotics obstacle avoidance
* Distance measurement projects

## Contributing:

Feel free to fork this repository and contribute your own improvements or modifications. 


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Disclaimer**: This code is provided "as is", without warranty of any kind. Use it at your own risk.
