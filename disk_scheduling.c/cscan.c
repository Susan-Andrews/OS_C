//CSCAN
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[100],i,j,n,pos=0,cp,size,move;
     printf("Enter total disk size\n");
    scanf("%d",&size);
     printf("Enter initial head position\n");
    scanf("%d",&cp);
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
   
    printf("Enter the head movement direction for high  value: 1 and for low  value: 0\n");
    scanf("%d",&move);
    
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(cp<req[i])
        {
            index=i;
            break;
        }
    }

    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            pos=pos+abs(req[i]-cp);
            cp=req[i];
        }
      
        pos=pos+abs(size-req[i-1]-1);
       
        pos=pos+abs(size-1-0);
        cp=0;
        for( i=0;i<index;i++)
        {
             pos=pos+abs(req[i]-cp);
             cp=req[i];
            
        }
    }
 
    else
    {
        for(i=index-1;i>=0;i--)
        {
            pos=pos+abs(req[i]-cp);
            cp=req[i];
        }
 
        pos=pos+abs(req[i+1]-0);
       
        pos=pos+abs(size-1-0);
        cp =size-1;
        for(i=n-1;i>=index;i--)
        {
             pos=pos+abs(req[i]-cp);
             cp=req[i];
            
        }
    }
    
    printf("Total head movement is %d\n",pos);
    return 0;
}

