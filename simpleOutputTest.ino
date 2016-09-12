static char strSensor1[15];
static char strSensor2[15];
static char strSensor3[15];
static char strSensor4[15];
static char outputBuffer[63];

void setup() {
  Serial.begin(9600);
}

void loop() {
  // gather sensor values
  float sensor1 = random(300);
  float sensor2 = random(300);
  float sensor3 = random(300);
  float sensor4 = random(300);
  
  // convert sensors values to char arrays
  dtostrf(sensor1, 7, 3, strSensor1);
  dtostrf(sensor2, 7, 3, strSensor2);
  dtostrf(sensor3, 7, 4, strSensor3);
  dtostrf(sensor4, 7, 4, strSensor4);
  
  // construct output row
  sprintf(outputBuffer, "%s,%s,%s,%s", strSensor1, strSensor2, strSensor3, strSensor4);
  
  // write to serial
  Serial.println(outputBuffer);
  
  // artifical delay of 1 second
  delay(1000);
}
