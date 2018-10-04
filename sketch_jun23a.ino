char data = 0;                //Variable for storing received data
const int motorA1=13;
const int motorA2=12;
const int motorB1=9;
const int motorB2=10;
void left();
void right();
void forward();
void backward();
void stop1();
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)  // Send data only when you receive data:
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
   if(data == '1')            //Checks whether value of data is equal to 1 
      forward();  //If value is 1 move forward
   else if(data == '2')       //Checks whether value of data is equal to 2
      backward();
   else if (data=='3')
      left();
   else if(data=='4')
      right();
   else if(data=='5')
     stop1();
      
  }                            
 
}

void left()
{
  digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
}

void right()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);
}

void forward()
{
  digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);
}

void backward()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);
}
void stop1()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
}


