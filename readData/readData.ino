void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello");
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

String data;
void loop() {
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    Serial.println(data);
    if (data[0] == '<') {
      String pin = "", val = "";
      int i;
      for (i = 2; data[i] != ','; i++) {
        pin += data[i];
      }
      for (++i; data[i] != '>'; i++) {
        val += data[i];
      }
      int p = pin.toInt(), v = val.toInt();
      Serial.println("==");
      Serial.println(p);
      Serial.println(v);
      Serial.println("==");
      if (data[1] == 'a') {
        analogWrite(p, v);
      } else {
        digitalWrite(p, v);
      }
    }
  }
}
