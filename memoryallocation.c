//CODE


#include<stdio.h>
void main()
{
int bsize[10],choice,temp, psize[10], bno, pno, flags[10], allocation[10], i, j;
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
printf("Enter no. of blocks: ");
scanf("%d", &bno);
printf("\nEnter size of each block: ");
for(i = 0; i < bno; i++)
scanf("%d", &bsize[i]);
 
printf("\nEnter no. of processes: ");
scanf("%d", &pno);
printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++)
scanf("%d", &psize[i]);

printf("Menu : 1.best fit 2.first fit 3.worst fit 4.exit\n");
printf("enter the choice: ");
scanf("%d",&choice);
switch(choice){    
case 1: 
 for(i = 0; i < pno; i++)       
		   for(j = 0; j < bno; j++)
		     if(bsize[i]>bsize[i+1])
		      {
			temp=bsize[i];
			bsize[i]=bsize[i+1];
			bsize[i+1]=temp;
	              }	
	              
	              for(i = 0; i < pno; i++)       
		   for(j = 0; j < bno; j++)
		     if(flags[j] == 0 && bsize[j] >= psize[i])
		      {
			allocation[j] = i;
			flags[j] = 1;
			break;
	              }
	
		
		     
break; 
case 2: 
	  
		for(i = 0; i < pno; i++)       
		   for(j = 0; j < bno; j++)
		     if(flags[j] == 0 && bsize[j] >= psize[i])
		      {
			allocation[j] = i;
			flags[j] = 1;
			break;
	              }   
break; 
case 3:  	
           for(i = 0; i < pno; i++)       
		   for(j = 0; j < bno-i-1; ++j)
		     if(bsize[j]<bsize[j+1])
		      {
			temp=bsize[j];
			bsize[j]=bsize[j+1];
			bsize[j+1]=temp;
	              }	
	              
	              for(i = 0; i < pno; i++)       
		   for(j = 0; j < bno; j++)
		     if(flags[j] == 0 && bsize[j] >= psize[i])
		      {
			allocation[j] = i;
			flags[j] = 1;
			break;
	              }
	
break; 
case 4: 
    printf("Exited\n"); 
break; 
    
default:     
   printf("select any choice\n"); 
} 
                printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
		for(i = 0; i < bno; i++)
		{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
		printf("%d\t\t\t%d\n",allocation[i]+1,psize[allocation[i]]);
		else
		printf("Not allocated\n");
		}   


}

