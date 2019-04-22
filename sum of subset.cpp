//sum of subset
//back tracking
//O()
#include<stdio.h>
#include<stdlib.h>
int x[4];//solution array 
         //actually shoud be initialized to 0 (by int x[4]={0}, but since its global therefore no need

int subset[4]={2,7,8,15} ;//must be in sorted order,non negative
int m=17; //solution sum

void sum_of_subset(int s,int k,int r)
{
                  x[k]=1;
                  if (s+subset[k]==m)
                     {
                       printf("\n");
                       for (int i=0;i<4;i++)
                       {
                           if (x[i]==1)
                              printf("%d \t",subset[i]);
                       }
                     }
                  else if ((s+subset[k]+subset[k+1])<=(m))
                       sum_of_subset(s+subset[k],k+1,r-subset[k]);
                  if ((s+r-subset[k]>=m)  &&  (s+subset[k+1]<=m))
                  {
                     x[k]=0;
                     sum_of_subset(s,k+1,r-subset[k]);
                  }                  
}                  

int main()
{ 
    sum_of_subset(0,0,32); // intial total sum, first no, left out sum
    system("Pause");
}
