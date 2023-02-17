const int ledPin1=9;// initialize the input pin of LED1
const int ledPin2=10;//initialize the input pin of LED2
const int pushButtonPin1=4;//initialize the input pin of pushbutton switch1
const int pushButtonPin2=5;//initialize the input pin of pushbutton switch2
int  pushButtonState1=0;//assign the state of pushbutton switch1
int  pushButtonState2=0;//assign the state of pushbutton switch2
//Last Name:ALAGARSAMY  First five alphabets of surname A=1,L=12,A=1,G=7, A=1
int a = 100;// parameter 'a' calculated as first letter*100 = 1*100 = 100            
int inv = 4900;// parameter used in mode '2' where we reverse the signal, hence highest value is a+(c-1)*b 100+(5-1)*1200=4900 
int b = 1200;// parameter 'b' calculated as second letter*100 = 12*100 = 1200
int c =5; // parameter 'c' calculated as third letter+4 = 1+4=5
int d = 3500;// parameter 'd' calculated as fourth letter*500 = 7*500 = 3500
// mode is calculated as rem(fifth letter/4) + 1 = rem(1/4) + 1 = 2. Hence we use mode 2
void setup()
{
  pinMode (pushButtonPin1, INPUT );
  pinMode (pushButtonPin2, INPUT );
  pinMode (ledPin1,OUTPUT);
  pinMode (ledPin2,OUTPUT);
 }
 void loop() {
 pushButtonState1=digitalRead(pushButtonPin1);
 pushButtonState2=digitalRead(pushButtonPin2);
 if(pushButtonPin1== HIGH)//condition if switch1 is high the LEDs are in OFF condition
 {
   digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
   }
   else
   {
   if(pushButtonPin2 == LOW)//condition if switch2 is low the output waveform is normal.
   {
     digitalWrite(ledPin2, HIGH);
     delay(50);
     digitalWrite(ledPin2, LOW);
     }
     if(pushButtonPin2 == HIGH)//condition if switch2 is high the new output waveform is generated.
     {
      digitalWrite(ledPin1, HIGH);
      delay(a);// parameter a=width of the first pulse
      c=c-3;
      digitalWrite(ledPin1, LOW);
      delay(b);
      a = a+50;//parameter b=a+50us 
      digitalWrite(ledPin1, LOW);
      delay(d);
      }
      else
      {
        digitalWrite(ledPin2, HIGH);
        delay(50);
        digitalWrite(ledPin2, LOW);
        for(int i =0; i<c;i++)
        {
          digitalWrite(ledPin1, HIGH);
          digitalWrite(ledPin2, LOW);
          delay(inv);
          digitalWrite(ledPin1, LOW);
          delay(b);
          inv = inv-50;
          digitalWrite(ledPin2, LOW);
          }
          digitalWrite(ledPin1, LOW);
          delay(d);
          d=d/2;b=b/2;
          digitalWrite(ledPin2, LOW);
          }
          }
          }
