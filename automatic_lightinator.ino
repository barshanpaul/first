const int analogInPin0 = A0; 
const int analogInPin1 = A1; 
int sensorValue1 = 0;               
int sensorValue2 = 0;
int flag=0;
int exitflag=0;
int people=0;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  sensorValue1 = analogRead(analogInPin0);
  sensorValue2 = analogRead(analogInPin1);   
  if(sensorValue1 < 600)     
  {
    flag=1;
  }
  else if(sensorValue2< 600)     
  {
    exitflag=1;
  }
  if(sensorValue2<600&&flag==1)
  {
        people++;
        flag=0;
       
  } 
if(sensorValue1<600&&exitflag==1)
   {
    people--;
    exitflag=0;
 
   }
   
   if(people>0)
   {
    digitalWrite(LED_BUILTIN, HIGH); 
   }
   else 
   {
       digitalWrite(LED_BUILTIN, LOW);
   }
    
  
}
