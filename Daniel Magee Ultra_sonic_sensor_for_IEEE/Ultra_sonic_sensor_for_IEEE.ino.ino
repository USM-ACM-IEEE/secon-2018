#define trigPin1 13
#define echoPin1 12

#define trigPin2 11
#define echoPin2 10

#define trigPin3 9
#define echoPin3 8

#define trigPin4 7
#define echoPin4 6

#define trigPin5 5
#define echoPin5 4

#define trigPin6 3
#define echoPin6 2

#define trigPin7 A5
#define echoPin7 A4

#define trigPin8 A3
#define echoPin8 A2


void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
  pinMode(trigPin7, OUTPUT);
  pinMode(echoPin7, INPUT);
  pinMode(trigPin8, OUTPUT);
  pinMode(echoPin8, INPUT);
  
}
void loop() 
{
  long duration1, duration2, duration3, duration4, duration5, duration6, duration7, duration8,side1, side2, side3, side4;
  float D1,D2,D3,D4,D5,D6,D7,D8;
  
  Serial.println("S1");
  digitalWrite(trigPin1, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  D1= (duration1/2) / 29.1;
  
  Serial.println("S2");
  digitalWrite(trigPin2, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  D2 = (duration2/2) / 29.1;
  
 
  Serial.println("S3");
  digitalWrite(trigPin3, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  D3 = (duration3/2) / 29.1;
 
  Serial.println("S4");
  digitalWrite(trigPin4, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  D4 = (duration4/2) / 29.1;
  

  Serial.println("S5");
  digitalWrite(trigPin5, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  D5 = (duration5/2) / 29.1;
     
  Serial.println("S6");
  digitalWrite(trigPin6, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  D6 = (duration6/2) / 29.1;
  
     
  Serial.println("S7");
  digitalWrite(trigPin7, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin7, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin7, LOW);
  duration7 = pulseIn(echoPin7, HIGH);
  D7 = (duration7/2) / 29.1;
  
  Serial.println("S8");
  digitalWrite(trigPin8, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin8, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin8, LOW);
  duration8 = pulseIn(echoPin8, HIGH);
  D8 = (duration8/2) / 29.1;

    side1 = ((D1+D2)/2); 
    side2 = ((D3+D4)/2);
    side3 = ((D5+D6)/2);
    side4 = ((D7+D8)/2);
  
    

    Serial.print(side1);
    Serial.print (", ");
    Serial.print (side2);
    Serial.print (", ");
    Serial.print (side3);
    Serial.print (", ");
    Serial.print (side4);
    Serial.print (", ");
    Serial.print (D1);
    Serial.print (", ");
    Serial.print (D2);
    Serial.print (", ");
    Serial.print (D3);
    Serial.print (", ");
    Serial.println (D4);
   
  delay(500);
  
}
