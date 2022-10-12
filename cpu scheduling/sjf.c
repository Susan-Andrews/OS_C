//CODE

#include<stdio.h>
void main(){
    int bt[20],p[20],wt[20],tt[20],pr,i,j,pos,temp;
    float awt,att;
    int sum=0;
    printf("enter the number of processes:");
    scanf("%d",&pr);
    
    printf("enter the burst time:");
    for(i=0;i<pr;i++){
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;    
    
    }
    for(i=0;i<pr;i++)
    {
       pos=i;
        for(j=i+1;j<pr;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
                
        }
   
     temp=bt[i];
     bt[i]=bt[pos];
     bt[pos]=temp;
     
     temp=p[i];
     p[i]=p[pos];
     
     }
     wt[0]=0;
     for(i=1;i<pr;i++)
     { 
         wt[i]=0;
         for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
         sum=sum+wt[i];

     }
      awt=(float)sum/pr;    
      sum=0;
      printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
       for(i=0;i<pr;i++)
       {
        tt[i]=bt[i]+wt[i];    
        sum=sum+tt[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
      }
 
    att=(float)sum/pr;     
    printf("\n\nAverage Waiting time=%f",awt);
    printf("\nAverage Turnaround time=%f\n",att);

}

