int flag[6]={0,0,0,0,0,0};

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  flag[2]=1;
  flag[3]=1;
  flag[4]=1;
  find_path();
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
Serial.print(minpath[m]);
Serial.print(" -> ");
}
Serial.print("0\n");

}
