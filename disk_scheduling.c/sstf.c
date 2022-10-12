//SSTF
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[100],i,n,pos=0,cp,count=0;
     printf("Enter current head position\n");
    scanf("%d",&cp);
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
  
    
   
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(req[i]-cp);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        pos=pos+min;
        cp=req[index];
       
        req[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d",pos);
    return 0;
}





