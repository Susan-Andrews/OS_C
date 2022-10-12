//CODE

#include<stdio.h>
int main(){
           int i, p,sum=0, x, count=0, tq;
           int wt = 0, tt= 0, at[10], bt[10], temp[10];
           float awt, att;
           printf("Enter Total Number of Processes:");
           scanf("%d", &p);
           x = p;
           for(i=0; i<p; i++)
          {
            printf("Enter the Arrival time and Burst time of each Process\n");
            printf("Arrival Time:");
            scanf("%d", &at[i]);
            printf("Burst Time:");
            scanf("%d", &bt[i]);
 
             temp[i] = bt[i];
        }
        printf("Enter Time Quantum:");
        scanf("%d", &tq);
         printf("Process ID\t\t Burst Time\t\t Turnaround Time\t\t Waiting Time\t\t");
         for(sum=0,i=0; x!=0;)
         {
            if(temp[i] <= tq && temp[i] > 0)
            {
                  sum=sum+temp[i];
                  temp[i]=0;
                  count=1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - tq;
                  sum=sum+tq;
            }
        
            
            if(temp[i]==0 && count== 1)
            {
                  x--;
                  printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
                  wt= wt+sum- at[i]-bt[i];
                  tt=tt+sum-at[i];
                  count=0;
            }
            if(i==p-1)
            {
                  i=0;
            }
            else if(at[i+1]<=sum)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
        }
 
      awt= wt*1.0/p;
      att = tt*1.0/p;
      printf("\nAverage Waiting Time:%f", awt);
      printf("\nAvg Turnaround Time:%f\n", att);
      return 0;

}
