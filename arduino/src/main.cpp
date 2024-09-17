#include <Arduino.h>

int counter = 1;

/**
 * @brief Initializes the serial communication at 115200 bps.
 *
 * This function is automatically called once at the beginning of each program
 * execution. It is used to initialize the serial communication, which is
 * necessary for the communication between the Raspberry Pi and the Arduino.
 *
 * @details The serial communication is set up to use a baud rate of 115200
 * bps. The function waits until the serial communication is ready before
 * returning.
 */
void setup() {
  Serial.begin(115200);
  while (!Serial) {}
}

/**
 * @brief Listens for messages from the Raspberry Pi and responds with a
 *        message indicating how many times the message was received.
 *
 * This function is automatically called repeatedly after `setup()` has
 * completed. It continuously checks the serial communication for available
 * messages from the Raspberry Pi. If a message is available, it is read and
 * responded to by sending a message back to the Raspberry Pi. The response
 * message is a string containing the original message and the number of times
 * the message has been received.
 */
void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message = "Received message \"" + message + "\" " + String(counter) + " times.";
    counter++;

    Serial.println(message);
  }
}
