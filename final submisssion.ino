const int analogInPin0 = A0; 
const int analogInPin1 = A1; 
int sensorValue1 = 0;               
int sensorValue2 = 0;
int i=0;
int people=0;
int flag=0;
int sec;
int relay = 8;

void setup() 
{
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600);
    sec=1;
    pinMode(relay, OUTPUT);
digitalWrite(relay, HIGH);
}

void loop() 
{
 
  sensorValue1 = analogRead(analogInPin0);
  sensorValue2 = analogRead(analogInPin1);
  if(sensorValue1 < 600&&sensorValue2 > 600)     
  { 
   for(i=0;i<sec*1000;i++)
   {
    delay(1);
    sensorValue2 = analogRead(analogInPin1);
    if(sensorValue2<600)
     {
      flag=1;
     }
     
   }

   if(flag==1)
    {
        flag=0;
        people++;
    }
    
  }

  else if(sensorValue2 < 600&&sensorValue1 > 600)     
  {
   for(i=0;i<sec*1000;i++)
   {
    delay(1);
    sensorValue1 = analogRead(analogInPin0);
    if(sensorValue1<600)
     {
      flag=1;
      
     }
   }
   if(flag==1)
   {flag=0;
    people--;
    
   }
    
  }
 delay(1);
// Serial.println(people); 
   if(people<0)
   {
   people=0;
   }
    if(people>0)
   {
    digitalWrite(LED_BUILTIN, HIGH); 
  
        digitalWrite(relay, LOW);
 
    Serial.println("ON");
   }
   else 
   {
       digitalWrite(relay, HIGH);
        Serial.println("OFF");
       digitalWrite(LED_BUILTIN, LOW);
   }

}
