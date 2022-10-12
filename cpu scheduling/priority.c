//CODE

#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tt[20],prio[20],pr,i,j,pos,temp;
    int sum=0;
    float awt,att;
    printf("Enter Total Number of Process:");
    scanf("%d",&pr);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<pr;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        p[i]=i+1;          
    }
    
    for(i=0;i<pr;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Priority:");
        scanf("%d",&prio[i]);
        p[i]=i+1;          
    }
    
    for(i=0;i<pr;i++)
    {
        pos=i;
        for(j=i+1;j<pr;j++)
        {
            if(prio[j]<prio[pos])
                pos=j;
        }
 
        temp=prio[i];
        prio[i]=prio[pos];
        prio[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0; 
 
   
    for(i=1;i<pr;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        sum+=wt[i];
    }
 
    awt=(float)sum/pr;    
    sum=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<pr;i++)
    {
        tt[i]=bt[i]+wt[i];    
        sum+=tt[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
    }
 
    att=(float)sum/pr;     
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",att);
 
return 0;
}    
    
