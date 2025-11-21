// Arduino Code

const int PIN_LED_MERAH = 2;
const int PIN_LED_HIJAU = 3;
const int PIN_LED_KUNING = 4;
const int PIN_TRIG = 5;
const int PIN_ECHO = 6;
const int PIN_LDR = A0;
const int BATAS_GELAP = 300;
const int BATAS_JARAK_DEKAT = 60;

void setup() {
 pinMode(PIN_LED_MERAH, OUTPUT);
 pinMode(PIN_LED_HIJAU, OUTPUT);
 pinMode(PIN_LED_KUNING, OUTPUT);
 pinMode(PIN_TRIG, OUTPUT);
 pinMode(PIN_ECHO, INPUT);
 Serial.begin(9600);
}

void loop() {
 int nilaiCahaya = analogRead(PIN_LDR);
 long jarakCm = ukurJarak();
 Serial.print("Nilai Cahaya: ");
 Serial.print(nilaiCahaya);
 Serial.print(" | Jarak: ");
 Serial.print(jarakCm);
 Serial.println(" cm");
 if (nilaiCahaya > BATAS_GELAP) {
 setLED(LOW, LOW, HIGH);
 Serial.println("Status: MALAM HARI");
 }
 else {
 if (jarakCm > 0 && jarakCm < BATAS_JARAK_DEKAT) {
 setLED(HIGH, LOW, LOW);
 Serial.println("Status: TERISI");
 } else {
 setLED(LOW, HIGH, LOW);
 Serial.println("Status: KOSONG");
 }
 }
 delay(250);
}

long ukurJarak() {
 digitalWrite(PIN_TRIG, LOW);
 delayMicroseconds(2);
 digitalWrite(PIN_TRIG, HIGH);
 delayMicroseconds(10);
 digitalWrite(PIN_TRIG, LOW);
 long durasi = pulseIn(PIN_ECHO, HIGH);
 long jarak = durasi * 0.034 / 2;
 return jarak;
}

void setLED(bool merah, bool hijau, bool kuning) {
 digitalWrite(PIN_LED_MERAH, merah);
 digitalWrite(PIN_LED_HIJAU, hijau);
 digitalWrite(PIN_LED_KUNING, kuning);
}
