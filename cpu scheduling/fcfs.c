//CODE

#include<stdio.h>
int main(){
   int p,i,j,k,sum=0;
   float w=0,t=0;
   int at[10]={0},bt[10]={0},ct[10]={0},wt[10]={0},tt[10]={0};
   printf("enter the number of processes");
   scanf("%d",&p);
   printf("Enter arrival time and burst time for each process\n");
   printf("Arrival time of process");
   for(i=0;i<p;i++){
	scanf("%d",&at[i]);
   
        }
        printf("Burst time of process");
        for(i=0;i<p;i++){
	scanf("%d",&bt[i]);
	}
   for(j=0;j<p;j++)
              {
		sum=sum+bt[j];
		ct[j]+=sum;
	  }

   for(k=0;k<p;k++)
	{
		tt[k]=ct[k]-at[k];
		t+=tt[k];
	}
	
   for(k=0;k<p;k++)
	{
		wt[k]=tt[k]-bt[k];
		w+=wt[k];
	}				
printf("Solution :\n\n");
printf("Process time\t Arrival time\t Burst time\tWaiting time\tTurnaround time\n");
for(i=0;i<p;i++){
  printf("p%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t \n",i,at[i],bt[i],wt[i],tt[i]);
  }		
	printf("Average waiting time=%f\n",w/p);
	printf("Average turnaround time=%f\n",t/p);
}
