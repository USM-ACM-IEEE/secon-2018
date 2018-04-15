/*     Arduino Color Sensing Tutorial
 *      Daniel Magee
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 *  
 */
 
#define S0 4 // pin S0 on the Sensor to pin 4 on the arduino
#define S1 5 // pin S1 on the Sensor to Pin 5 on hte arduino
#define S2 6
#define S3 7
#define sensorOut 8 // the output pin on the ardunio to pin 8 on the arduino
unsigned int frequency1 = 0;
unsigned int frequency2 =0;
unsigned int frequency3 =0;
char R;
char G;
char B;
char Y;
int finalColor;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  
      digitalWrite(S2,LOW);// Setting red filtered photodiodes to be read
      digitalWrite(S3,LOW);
      frequency1 = pulseIn(sensorOut, LOW);// Reading the output frequency
     /* Serial.print("R= ");//printing name 
      Serial.print(frequency1);//printing RED color frequency
      Serial.print("  ");
      delay(100);
      */
      
      digitalWrite(S2,HIGH); // Setting Green filtered photodiodes to be read
      digitalWrite(S3,HIGH);
      frequency2 = pulseIn(sensorOut, LOW); // Reading the output frequency
      /*Serial.print("G= ");//printing name
      Serial.print(frequency2);//printing RED color frequency
      Serial.print("  ");
      delay(100);
      */
      
      digitalWrite(S2,LOW);// Setting Blue filtered photodiodes to be read
      digitalWrite(S3,HIGH);
      frequency3 = pulseIn(sensorOut, LOW);// Reading the output frequency
      /*Serial.print("B= ");//printing name
      Serial.print(frequency3);//printing RED color frequency
      Serial.println("  ");
      delay(100);
      */
 // The following code is for determining the actual color of the RGB LED Based off of the Wave Length
 // The code will show a smaller value for the color that it is sensing.  So if R = 100 B= 200 and G = 20 Then the Green is the color that is being shown.
 // The yellow is not one of the primary color that the Color sensor is set to read so the average value for yellow was derived through testing.
 
  if (frequency1 < 110 && frequency1 > 40 && frequency2 < 200 && frequency3 > 200)
  {
  finalColor = Y;
  Serial.print(" Y");
  Serial.println("");
  }
  
      else if (frequency1 < frequency2 && frequency1 < frequency3)
      {
        finalColor = R;
        Serial.print( " R ");
        Serial.println ("");
      }
      
      else if (frequency2 < frequency1 && frequency2 < frequency3)
      {
        finalColor = G;
        Serial.print( " G ");
        Serial.println ("");
      }
      else if (frequency3 < frequency1 && frequency3 < frequency2)
      {
        finalColor = B;
        Serial.print(" B");
        Serial.println ("");
      }
      }
