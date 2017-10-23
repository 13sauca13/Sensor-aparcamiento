const int EchoPin = 5;
const int TriggerPin = 6;
const int led = 12;

int ledState = LOW;

unsigned long previousMillis = 0;

const int intervaloLargo = 1000;
const int intervaloCorto = 500;
 
void setup() {
   Serial.begin(9600);
   pinMode(led, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
   unsigned long currentMillis = millis();
   int cm = ping(TriggerPin, EchoPin);
   while(currentMillis - previousMillis >= intervaloLargo){
         previousMillis = currentMillis;
         Serial.print("Distancia: ");
         Serial.println(cm);
      }
   
   if (cm >=15 && cm <= 30) {
      if (currentMillis - previousMillis >= intervaloLargo){
         previousMillis = currentMillis;
         if (ledState==LOW) {
            ledState=HIGH;
         }
         else {
            ledState=LOW;
         }
      }
   }
   //else if (cm >= 5 && cm < 15) {
   //	if (currentMillis - previousMillis >= intervaloCorto){
   //      previousMillis = currentMillis;
     //    if (ledState==LOW) {
       //     ledState=HIGH;
       //  }
         else {
            ledState=LOW;
         }
      }
   }
   else {
   	digitalWrite(led, HIGH);
   }
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);
   
   distanceCm = duration * 10 / 292/ 2;
   return distanceCm;
}
