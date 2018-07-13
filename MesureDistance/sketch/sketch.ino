const int trig = 10;
const int echo = 9;
const int ledKirmizi = 2;
const int ledYesil = 3;
int frekans;
void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(9,INPUT);
    pinMode(10,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int i = mesafe();
    Serial.print("Mesafe: ");
    Serial.println(i);
    if(i == 0){
        noTone(8);
        digitalWrite(ledYesil, LOW);
        digitalWrite(ledKirmizi, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
    }else{
        /*frekans = map(i, 0, 15, 5000, 1000);
        tone(8,frekans);*/

        frekans = map(i, 0, 15, 0, 7);
        switch (frekans){
            case 0:
            tone(8,1915);
            break;
            case 1:
            tone(8,1700);
            break;
            case 2:
            tone(8,1519);
            break;
            case 3:
            tone(8,1432);
            break;
            case 4:
            tone(8,1275);
            break;
            case 5:
            tone(8,1136);
            break;
            case 6:
            tone(8,1014);
            break;
            case 7:
            tone(8,956);
            break;
        }
        digitalWrite(ledKirmizi, LOW);
        digitalWrite(ledYesil, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
    }
}

int mesafe(){
    delay(30);
    long sure, mesafe;
    digitalWrite(10, LOW);
    delayMicroseconds(2);
    digitalWrite(10, HIGH);
    delayMicroseconds(10);
    digitalWrite(10, LOW);
    sure = pulseIn(9, HIGH);
    mesafe = (sure/2) / 29.1;
    if(mesafe > 15){mesafe = 0;}
    return mesafe;
}
