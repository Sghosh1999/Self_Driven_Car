#define LeftMotorFwd 6
#define LeftMotorBck 7      //Left Side MOtor
#define LeftMotorEnable 5


#define RightMotorFwd 8
#define RightMotorBck 9     //Right Side Motor
#define RightMotorEnable 10
#define RightLed 11
#define LeftLed A0


const int D0 = 2;  //Raspberry pin 29 LSB
const int D1 = 3;  //Raspberry Pin 31 
const int D2 = 4;  //raspberry pin 33
const int D3 = 12; //raspberry pin 35 MSB

int a,b,c,d,data;

void setup() 
{
  pinMode(LeftMotorFwd,OUTPUT);
  pinMode(LeftMotorBck,OUTPUT);
  pinMode(LeftMotorEnable,OUTPUT);
  pinMode(RightLed,OUTPUT);
  pinMode(LeftLed,OUTPUT);

  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);

}

void Data()
 {
   a = digitalRead(D0);
   b = digitalRead(D1);
   c = digitalRead(D2);
   d = digitalRead(D3);

   data = 8*d+4*c+2*b+a;   // converting binary to decimal
   }

 void Forward()
 {
    analogWrite(LeftMotorEnable,55);
    analogWrite(RightMotorEnable,55);
    digitalWrite(LeftMotorFwd,LOW);
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(LeftMotorBck,HIGH);
    digitalWrite(RightMotorBck,HIGH);
 }
void Backward()
 {
    analogWrite(LeftMotorEnable,55);
    analogWrite(RightMotorEnable,55);
    digitalWrite(LeftMotorFwd,HIGH);
    digitalWrite(RightMotorFwd,HIGH);
    digitalWrite(LeftMotorBck,LOW);
    digitalWrite(RightMotorBck,LOW);

 }

 void Stop()
 {
    analogWrite(LeftMotorEnable,0);
    analogWrite(RightMotorEnable,0);
    digitalWrite(LeftMotorFwd,HIGH);
    digitalWrite(RightMotorFwd,HIGH);
    digitalWrite(LeftMotorBck,LOW);
    digitalWrite(RightMotorBck,LOW);

 }

//------------------------------------Right--------------------------------------------------------
 void MoveRight1()
 {
    analogWrite(LeftMotorEnable,90);
    analogWrite(RightMotorEnable,20);
    digitalWrite(LeftMotorFwd,LOW);
    digitalWrite(LeftMotorBck,HIGH);
    
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(RightMotorBck,HIGH);
 }
 void MoveRight2()
 {
    analogWrite(LeftMotorEnable,120);
    analogWrite(RightMotorEnable,20);
    digitalWrite(LeftMotorFwd,LOW);
    digitalWrite(LeftMotorBck,HIGH);
    
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(RightMotorBck,HIGH);
 }
 void MoveRight3()
 {
    analogWrite(LeftMotorEnable,140);
    analogWrite(RightMotorEnable,20);
    digitalWrite(LeftMotorFwd,LOW);
    digitalWrite(LeftMotorBck,HIGH);
    
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(RightMotorBck,HIGH);
 }

//------------------------------------Left----------------------------------------------
 
 void MoveLeft1()
 {
    analogWrite(LeftMotorEnable,20);
    analogWrite(RightMotorEnable,80);
    digitalWrite(LeftMotorFwd,LOW);
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(LeftMotorBck,HIGH);
    digitalWrite(RightMotorBck,HIGH);
 }
 void MoveLeft2()
 {
    analogWrite(LeftMotorEnable,20);
    analogWrite(RightMotorEnable,100);
    digitalWrite(LeftMotorFwd,HIGH);
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(LeftMotorBck,LOW);
    digitalWrite(RightMotorBck,HIGH);
 }
 void MoveLeft3()
 {
    analogWrite(LeftMotorEnable,20);
    analogWrite(RightMotorEnable,120);
    digitalWrite(LeftMotorFwd,HIGH);
    digitalWrite(RightMotorFwd,LOW);
    digitalWrite(LeftMotorBck,LOW);
    digitalWrite(RightMotorBck,HIGH);
 }
 //-------------------------------------------------------------------------------------------------------------
void loop() {
 
//Backward();
//delay(1000);
//Forward();
//delay(1000);
//
//MoveRight1();
//delay(1000);
//
//MoveRight2();
//delay(1000);

//MoveRight3();
//delay(1000);




  
  Data();      // ------->->->->->->-> reading data




  //------------------------------------------start of main-----------------------------------------------

  if(data==0)
  {
    Forward();
      digitalWrite(RightLed,1);
      analogWrite(LeftLed,255);
    
 }
   else if(data==1)
   {
     MoveRight1();
     analogWrite(LeftLed,0);
     digitalWrite(RightLed,HIGH);
  
   }
    
  else if(data==2)
   {
     MoveRight2();
     analogWrite(LeftLed,0);
     digitalWrite(RightLed,HIGH);
    
   
   }
     
  else if(data==3)
   {
     MoveRight3();
     analogWrite(LeftLed,0);
     digitalWrite(RightLed,HIGH);
   
   }
     
  else if(data==4)
   {
     MoveLeft1();
              digitalWrite(RightLed,LOW);
              analogWrite(LeftLed,255);

     delay(600);
  
   }
  else if(data==5)
   {
     MoveLeft2();
     analogWrite(LeftLed,255);
           digitalWrite(RightLed,LOW);

     delay(600);
   }
    
  else if(data==6)
   {
     MoveLeft3();
     analogWrite(LeftLed,255);
            digitalWrite(RightLed,LOW);

     delay(600);
  }
  
  else if (data==7)
   {
     Stop();
     digitalWrite(RightLed,0);
     analogWrite(LeftLed,0);
   }
  // -------------------------------------end of mian-------------------------------------------------- 
  

}
