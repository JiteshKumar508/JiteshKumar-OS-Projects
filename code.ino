const int trigPin=9; 
const int echoPin=10;
const int pb=3;
const int led=13;
void setup()
{
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(pb,INPUT);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
Serial.begin(9600); 
}
void loop()
{
int state = digitalRead(pb);
if(state==HIGH)
{
for(int i=0;i<1;i++)
{
long duration,cm;           //DECLARE VARIABLES TO STORE SENSOR O/P
digitalWrite(trigPin,LOW);  //MAKE THE TRIG PIN LOW
delayMicroseconds(2);       //WAIT FOR FEW MICROSECONDS
digitalWrite(trigPin,HIGH); //NOW SET THE TRIG PIN
delayMicroseconds(5);       //WAIT FOR FEW MICROSECONDS UNTIL THE TRIG PULSE IS SENT
digitalWrite(trigPin,LOW);  //MAKE THE TRIG PIN LOW AGAIN
duration=pulseIn(echoPin,HIGH); //MAKE ECHO PIN HIGH AND STORE THE BOUNCED PULSE IN VARIABLE DURATION
cm=microsecondsToCentimeters(duration); //CONVERT DURATION INTO CM
long inch= cm/2.54;//PRINT THE CM"s IN SERIAL MONITOR
duration=pulseIn(echoPin,LOW); 
Serial.print("DATA,TIME,");
Serial.println(inch);
digitalWrite(led,HIGH);
delay(100);
digitalWrite(led,LOW);
}
}
else
{
  digitalWrite(trigPin,LOW);
  digitalWrite(led,LOW);
}
}
long microsecondsToCentimeters(long microseconds) //SPEED OF SOUND IS 29 uSEC PER CM
{
return microseconds/29/2;  //THE PULSE TRAVELS FROM THE SENSOR AND AGAIN COMES BACK SO WE DIVIDE IT BY 2 TO TAKE ONLY HALF OF THE TOTAL DISTANCE
}

