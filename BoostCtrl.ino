const int myTOP = 1000;  // 大約 0.5 秒 when Prescaler == 1024

void setup() {
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(115200);
  
  cli();  // 禁止中斷
  TCCR1A = 0;
  TCCR1B = 0; 
  TCCR1B |= (1<<WGM12);  // CTC mode; Clear Timer on Compare
  TCCR1B |= (1<<CS10) | (1<<CS12);  // Prescaler == 1024
  OCR1A = myTOP;  // TOP count for CTC, 與 prescaler 有關
  TCNT1=0;  // counter 歸零 
  TIMSK1 |= (1 << OCIE1A);  // enable CTC for TIMER1_COMPA_vect
  sei();  // 允許中斷
}

long delayTime = 128;
float voltageLevel = 2;
float voltage = 0;
void loop() {
  int sensorValue = analogRead(A0);
  voltage = sensorValue * (5.0 / 1023.0);
  if( voltage>=voltageLevel ){
    delayTime -= 1;
    if( delayTime<=0 ){
      delayTime = 0;
    }
  }else{
    delayTime += 1;
    if( delayTime>=254 ){
      delayTime = 254;
    }
  }
  analogWrite(11, delayTime);
}

ISR(TIMER1_COMPA_vect)
{
  Serial.print(delayTime);
  Serial.print(',');
  Serial.print(voltage);
  Serial.println(" Volt");
}

String strVlotage = "";
void serialEvent()
{
  while (Serial.available())   //時刻讀取硬體串列埠資料
  {
    char charRead = "";
    charRead = Serial.read();
    if( charRead=='\n' ){
      voltageLevel = strVlotage.toFloat();
      Serial.print("Setting Voltage at ");
      Serial.print(strVlotage.toFloat());
      Serial.println(" Volt");
      strVlotage = "";
    }else{
      strVlotage += charRead;
    }
  }
  while (Serial.read() >= 0) {} //清除串列埠快取
}
