int num=0;
int done;//To store units place
int dten;//To store tens place
int button = 2;
int button1=3;
int state = 0;
int state1=0;
//BCD 1

int a1 = 4;
int a2 = 5;
int a3 = 6;
int a4 = 7;

//BCD 2
int b1 = 8;
int b2 = 9;
int b3 = 10;
int b4 = 11;

void setup()
{
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(button,INPUT);
pinMode(button1,INPUT);
}

void loop()
{
  state = digitalRead(button);
  state1 = digitalRead(button1);
  if(state == HIGH)
  {
    num++;
  }
  if(state1==HIGH)
  {
    num--;
  }
  if(num==100)
  {
    num=0;
  }
  if(num==-1)
  {
    num=99;
  }
  done=num%10;
  dten=num/10;
  disp1(done);
  disp2(dten);
  delay(100);
}
void disp1(int num)
{
  if(num==0)//0000
  {
    digitalWrite(a1, LOW); 
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 1)//0001
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 2)//0010
  {
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, LOW);//0
  }
  if(num == 3)//0011
  {
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, LOW);//0
  }
  if(num == 4)//0100
  {
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 5)//0101
  {
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 6)//0110
  {
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 7) //0111
  {
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 8) //1000
  {
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, HIGH);//1
  }
  if(num == 9)//1001
  {
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, HIGH);//1
  }
}

void disp2(int num)
{
  if(num==0)
  {
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 1)//0001
  {
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 2)//0010
  {
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 3)//0011
  {
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 4)//0100
  {
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 5) //0101
  {
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 6) //0110
  {
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 7) //0111
  {
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 8) //1000
  {
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, HIGH);//1
  }
  if(num == 9)//1001
  {
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, HIGH);//1
  }
}