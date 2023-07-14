int ldrPin = A2;  // LDR pin connected to analog pin A0

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read the analog value from the LDR
  Serial.println(ldrValue);  // Print the LDR value to the serial monitor

  if(ldrValue > 700){
    digitalWrite(13,HIGH);
  }else if(ldrValue < 700){
     digitalWrite(13,LOW);
  }

//  delay(500);  // Wait for 500 milliseconds before reading again
}
