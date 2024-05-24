const int buzzerPin = 13;
void setup()
{
pinMode(buzzerPin,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);
}
void loop()
{ 
int val = analogRead(A0);
int sal=analogRead(A5);
if(val>400)
{
digitalWrite(buzzerPin,HIGH);
digitalWrite(8,LOW);
digitalWrite(10,HIGH);
Serial.println(val);
delay(40);   
}
if(sal>400)
{
buzzDifferentSound('G');
digitalWrite(8,LOW);
digitalWrite(10,HIGH);
Serial.println(val);
delay(40);   
}
else
{
digitalWrite(13,LOW);
digitalWrite(8,HIGH);
digitalWrite(10,LOW);
Serial.println("no Smoke");
delay(10);
}
} 
void buzzDifferentSound(char sensorType)
{
if (sensorType == 'S')
{
// Sound pattern for smoke detected
tone(buzzerPin, 1000); // 1 kHz sound
delay(500);
noTone(buzzerPin);
delay(500);
} 
else if (sensorType == 'G')
{
tone(buzzerPin, 2000); // 2 kHz sound
delay(250);
noTone(buzzerPin);
delay(250);
tone(buzzerPin, 2000);
delay(250);
noTone(buzzerPin);
delay(250);
}
}

