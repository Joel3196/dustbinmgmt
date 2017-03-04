int j=0,count=0;
int bins[6];
bins[0]=0;int path[6];
for(int i=1;i<=5;i++);
{
  if(flag[i]==0)
  {
    j++;
    bins[j]=i;
  }
}
int nbins=j;
int n=nbins;
min=12;/*assuming distances bwt any 2 nodes is less than 10 */
p1=count;
minpath[count]=0;
while(count!=nbins)
{
      for(int i=1;i<=n;i++)
  {
    p2=bins[i];
    while(p1!=p2)
    {
      if(D[p1][p2]<min)
      {
       min=D[p1][p2];
       minpos=bins[i];
      }
    }    
  }p1=minpos;
  count++;
  minpath[count]=minpos;
  bin[n+1]=0;
  for(int c=minpos;c<=n;c++)
  {
    bins[c]=bins[c+1];
  }
  n--;
  
}

