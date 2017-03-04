#include <stdio.h>
int flag[6]={0,0,1,0,1,0};
void main()
{
    printf("hello");
    int p2=0,minpos=0,c=0;
int D[6][6]={
            {0,3,6,4,10,5},
            {3,0,2,5,7,6},
            {6,2,0,4,2,7},
            {4,5,4,0,5,2},
            {10,7,2,5,0,9},
            {5,6,7,2,9,0}
       };
int j=0,count=0,k=0;
int bins[6];
int minpath[6];
bins[0]=0;
int path[6];
for(k=1;k<=5;k++);
{
  if(flag[k]==0)
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
minpath[count]=0;
while(count!=nbins)
{
      for(i=1;i<=n;i++)
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
  bins[n+1]=0;
  for(c=minpos;c<=n;c++)
  {
    bins[c]=bins[c+1];
  }
  n--;
}  
int m=0;
for(m=0;m<nbins;m++)
printf("%d",bins[m]);

}

