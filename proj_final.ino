#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); 

int flag[6]={0,0,0,0,0,0};
String pth="";
void setup()
{
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop()
{
  flag[2]=fill();
  flag[3]=meth();
  flag[4]=digitalRead(5);

  pth="";
  find_path();
  Serial.println(pth);
  delay(5000);
}

int meth()
{
  int smoke=A0,smokeThres=300;
  int val=analogRead(smoke);
  return (val>smokeThres);
}


int fill()
{
  int trigPin=2,echoPin=3;
 long duration;
long distanceCm, distanceInch;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
if (distanceCm < 10 && distanceCm>0)
 return 1;
else
return 0;
}

void SendMessage(String message)
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918547167746\"\r"); // Replace x with mobile number
  delay(200);
  mySerial.println(message);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(200);
}



void find_path()
{
    int p2=0,minpos=0,c=0;
    int D[6][6]={
            {0,3,6,4,10,5},
            {3,0,2,5,7,6},
            {6,2,0,4,2,7},
            {4,5,4,0,5,2},
            {10,7,2,5,0,9},
            {5,6,7,2,9,0}   
			 };
int j=0,count=0;
int bins[6]={0,0,0,0,0,0};
int minpath[6];
int path[6];
int k=0;
for(k=1;k<6;k++)
{
  if(flag[k]==1)
  {
    j++;
    bins[j]=k;
  }

}
int nbins=j;
int i=0;
int n=nbins;
int min=12;/*assuming distances bwt any 2 nodes is less than 10 */
int p1=0;
int y=0;
minpath[count]=0;
while(count!=nbins)
{
      for(i=1;i<=n;i++)
  {
    p2=bins[i];
    if(p1!=p2)
    {
      if(D[p1][p2]<min)
      {
       min=D[p1][p2];
       minpos=bins[i];
       y=i;
    }
    }    
  }
  min=12;
  p1=minpos;
  count++;
  minpath[count]=minpos;
  for(c=y;c<=n;c++)
  {
    bins[c]=bins[c+1];
  }
  bins[n+1]=0;
  
  n--;
}  
int m=0;
for(m=0;m<=nbins;m++){
//Serial.print(minpath[m]);
pth+=String(minpath[m]);
//Serial.print(" -> ");
pth+=" -> ";
}
pth+="0";
//Serial.print("0\n");

}
