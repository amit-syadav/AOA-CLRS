#include<stdio.h>
#include<stdlib.h> //required for absolute function

int x[10];//solution array to store the column no. of all queen

int place(int k,int i)
{
    for (int j=1;j<k;j++)//check thw position of kth queen wrt rest of placed queen

        if ((x[j]==i)||((abs(x[j]-i))==(abs(j-k))))
           return 0;
    return 1;
}

void n_queen(int k,int n)
{
            
            for (int i=1;i<=4;i++)//placing kth queen in ith column(ie. column1 column2...)
            {
                //printf("\n Check queen %d at column %d",k,i);

                if (place(k,i))//if kth queen can successfully place it on ith column
                {
                                  x[k]=i;//mark the column no. of kth queen
                                  //printf("Queen %d placed at %d",k,i);
                                  
                                  if (k==n) //check if this was the last queen to be placed
                                     {
                                            printf("\n");
                                            for (int j=1;j<=n;j++)
                                                  printf("%d \t",x[j]);
                                     }
                                  else
                                      n_queen(k+1,n);// find column for k+1th queen
                }
           }
}

int main()
{
     n_queen(1,4);//k=1,n=4
     system("Pause");
     return 0;

}
