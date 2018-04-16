#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int b[20],p[20],w[20],tat[20],i,j,n,t=0,pos,temp,m;
    float avg_wt,avg_tat;
    int brust_time[10];
    
    printf("Enter only the positive number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&b[i]);
        p[i]=i+1;          
    }
    printf("press 0 for the continue the first come first serve and 1 for the exit\n");
    scanf("%d",&m);
    if(m==0)
    {
    printf("*****THIS IS FOR THE FIRST IN FIRST OUT*******");
    for(i=0;i<n;i++)
    {
    	if(pos=b[i])
    	{
    		brust_time[i]=pos+b[i];
		}
	}
	w[0]=0;          
    for(i=1;i<n;i++)
    {
        w[i]=0;
        for(j=0;j<i;j++)
            w[i]+=b[j];
 
        t+=w[i];
    }
    avg_wt=(float)t/n;      
    t=0;
     printf("\nProcess\t    Burst Time  \tWaiting Time \tTurnaround Time ");
    for(i=0;i<n;i++)
    {
        tat[i]=b[i]+w[i];    
        t+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],b[i],w[i],tat[i]);
    }
 
    avg_tat=(float)t/n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
else
{
	printf("you have get back \n");
}
int q;
printf("press 0 for the continuous for the shortest job first and 1 for the exit \n");
scanf("%d",&q);
    if(q==0)
    {
    printf("-----------------------------------------------------------\n");
    printf("*****THIS IS FOR THE SHOREST JOB FIRST PROCESS********\n");
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[pos])
                pos=j;
        }
 
        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    w[0]=0;          
    for(i=1;i<n;i++)
    {
        w[i]=0;
        for(j=0;j<i;j++)
            w[i]+=b[j];
 
        t+=w[i];
    }
    avg_wt=(float)t/n;      
    t=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=b[i]+w[i];    
        t+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],b[i],w[i],tat[i]);
    }
 
    avg_tat=(float)t/n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
else
{
	printf("you are selected to exit \n");
}
}

