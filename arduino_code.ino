#include<SoftwareSerial.h>
SoftwareSerial SoftSerial(13, 12); // rx/tx


//s0 - s3 = d2 - d5
//c0 = thumb low
//a0 = input
//0 - tx(bluetooth)
//1 - rx(bluetooth)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SoftSerial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
}

int flex_data[10];
int reff_val;   // reading at 180deg

void print_()
{
  
}

void toAngle()
{
  for(int i = 0; i < 10; ++i)
  {
    
  }
}

void read_data()
{
  /*
  digitalWrite(5, LOW); digitalWrite(4, LOW); digitalWrite(3, LOW); digitalWrite(2, LOW); 
  delay(10);
  flex_data[0] = analogRead(A0);
  */
  for(int i = 0;i<10;++i)
  {
    digitalWrite(5, i&8); digitalWrite(4, i&4); digitalWrite(3, i&2); digitalWrite(2, i&1); 
    delay(10);
    flex_data[i] = analogRead(A0);
  }


  toAngle();
}

void to_ch(int n, char *ch)
{
  ch[0] = '0' + n/100;
  n %= 100;
  ch[1] = '0' + n/10;
  n %= 10;
  ch[2] = '0' + n;
}

void send_data()
{
  char ch[3];
  SoftSerial.write('$');
  for(int i = 0;i<10;++i)
  {
    to_ch(flex_data[i], ch);
    for(int j = 0;j<3;++j)
    {
      SoftSerial.write(ch[j]);
    
      Serial.print(ch[j]);
    }
  }
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  read_data();
    
  send_data();
}
