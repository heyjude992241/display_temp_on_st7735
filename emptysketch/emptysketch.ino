void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Program is successfully initialized!");
  Serial.println("Exit code is 1");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(F("On"));
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(F("Off"));
  delay(2000);
}
