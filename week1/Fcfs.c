//program to implement First Come first Serve in c:
#include<stdio.h>
#include<stdlib.h>
#define Max 10
int p[Max];
int at[Max];
int bt[Max];
int ct[Max];
int wt[Max];
int tat[Max];

int main()
{
    printf("SHREYA J G 1BM23CS352\n");
    printf("enter the number of processes:\n");
    int n;
    scanf("%d",&n);
    printf("enter the arrival times and burst times\n");
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        printf("enter the arrival time for process:%d\n",i);
        scanf("%d",&at[i]);
        printf("enter the burst time for the process:%d\n",i);
        scanf("%d",&bt[i]);
    }
    //sort them based on the arrival times:
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(at[j]>at[j+1])
            {
                int t=at[j];
                at[j]=at[j+1];
                at[j+1]=t;
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    ct[0]=bt[0];
    for(int i=1;i<n;i++)
    {
        if(at[i]<=ct[i-1])
        {
            ct[i]=ct[i-1]+bt[i];
        }
        else{
            ct[i]=at[i]+bt[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    float wtavg=0.0,tatavg=0.0;
    for(int i=0;i<n;i++)
    {
        wtavg+=wt[i];
        tatavg+=tat[i];

    }
    wtavg/=n;
    tatavg/=n;
    printf("the average wait time:%f\n",wtavg);
    printf("the average turn around time:%f\n",tatavg);
}