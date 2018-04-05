#define interruptPin 3
#define outputPin1 5
#define outputPin2 6
#define outputPin3 7
#define outputPin4 8
#define systemTime micros()
#define ONE_DOWN_TIME 1125

volatile unsigned long calculatedTime;        // Stores the systemTime return value
volatile unsigned long downTime;              // Stores the calculated down time from interupts
volatile unsigned long firstCountOfOnes;      // Stores the 8 ones before the code
unsigned int currentState;                    // Value for tracking the state in the loop state machine
unsigned int countOfBitsRead;                 // Tracks the current number of bits that have been processed in the message

//=========================== Prototypes =======================================

/**
 * This is the interupt call function for the FALLING of the pin.
 * On call it will set the time to the current systemTime function and attach the
 * onUp function to interupt on RISING
 */
void onDown();
/**
 * This is the interupt call function for the RISING of the pin.
 * On call it will set the downTime to be the time since the falling of the pin
 */
void onUp();
/**
 * This is the function that will calculate the downTime of the burst by firing
 * on the CHANGE interupt and checking for HIGH or LOW on the pin and storing
 * the system time in using systemTime
 */
void onChange();
/**
 * This will write to the output pin the given value
 */
void writeToLed(int led, bool highOrLow);

//=========================== Lifecycle Functions ==============================

void setup()
{
  // Attach to start listening for the Falling of the long burst
  attachInterrupt(digitalPinToInterrupt(interruptPin), onChange, CHANGE);
  calculatedTime = 0;
  currentState = 0;
  countOfBitsRead = 0;
  firstCountOfOnes = 0;
  Serial.begin(9600);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
  digitalWrite(outputPin1, LOW);
  digitalWrite(outputPin2, LOW);
  digitalWrite(outputPin3, LOW);
  digitalWrite(outputPin4, LOW);
}

void loop()
{
  static int message[] = {0,0,0};
  static int measure[] = {0,0,0};

  /**
   * This is a state machine that will handle parsing the message's waveform
   * @param currentState The state of the machine where each state is described
   *                     below
   */
   
  switch (currentState)
  {
    case 0:
      if(downTime !=0 && downTime > ONE_DOWN_TIME)
      {
        ++firstCountOfOnes;
      }
      if(firstCountOfOnes >= 8)
      {
        currentState = 1;
      }
      break;
    // Handles waiting until after the space of 4.5ms following the inital burst
    case 1:
      if(downTime > 3000 && downTime < 6000 && downTime != 0)
      {
        currentState = 2;
        downTime = 0;
      }
      break;

    // Handles the first five logical zeros that are sent in the message
    case 2:
      if(downTime != 0 && downTime < ONE_DOWN_TIME)
      {
        ++countOfBitsRead;
        downTime = 0;
      }

      if(countOfBitsRead >= 5)
      {
        currentState = 3;
      }
      break;

    // Handles Reading the actual message being sent
    case 3:
      if(downTime != 0 && downTime < ONE_DOWN_TIME)
      {
        measure[countOfBitsRead-5] = downTime;
        downTime = 0;
        ++countOfBitsRead;
      } else if(downTime != 0){
        measure[countOfBitsRead-5] = downTime;
        downTime = 0;
        ++countOfBitsRead;
      }

      if(countOfBitsRead >= 8)
      {
        currentState = 4;
        for(int i = 0; i < 3; ++i)
        {
          if(measure[i] > ONE_DOWN_TIME)
          {
            writeToLed(i+1, HIGH);
            message[i]= 1;
            Serial.print(1);
            Serial.print(" ");
          } else {
            writeToLed(i+1, LOW);
            message[i]= 0;
            Serial.print(0);
            Serial.print(" ");
          }
          
        }
        Serial.println();
      }
      break;

    // Handles the ending of the pulse and resets the variables
    case 4:
      digitalWrite(outputPin4, HIGH);
      if(downTime > 9000)
      {
        currentState = 0;
        countOfBitsRead = 0;
        downTime = 0;
      }
      break;
  }
  
}

//=========================== Function Definitions =============================

void onDown()
{
  calculatedTime = systemTime;
  downTime = 0;
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  attachInterrupt(digitalPinToInterrupt(interruptPin), onUp,  RISING);
}

void onUp()
{
  downTime = systemTime - calculatedTime;
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  attachInterrupt(digitalPinToInterrupt(interruptPin), onDown, FALLING);
}

void onChange()
{
  if(digitalRead(interruptPin)) {
    downTime = systemTime - calculatedTime;
  } else {
    calculatedTime = systemTime;
  }
}

void writeToLed(int led, bool highOrLow)
{
  switch(led)
  {
    case 1:
      digitalWrite(outputPin1, highOrLow);
      break;
    case 2:
      digitalWrite(outputPin2, highOrLow);
      break;
    case 3:
      digitalWrite(outputPin3, highOrLow);
      break;
  }
}

