// the number of the LED pin
const int ledPin = 5;  // 5 corresponds to GPIO5
const int vrPin = 35; // 35 corresponds to GPIO35

// setting PWM properties
const int freq = 5000;
const int resolution = 8;
 
void setup(){
  Serial.begin(115200);
  pinMode(vrPin, INPUT);

  ledcAttach(ledPin, freq, resolution);

}
 
void loop(){
  int vr_value = analogRead(vrPin);
  int dutyCycle = map(vr_value, 0, 4095, 0, 255);
  Serial.println(dutyCycle);

  ledcWrite(ledPin, dutyCycle);

  delay(100);
}