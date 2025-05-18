//program to implement Rate Monotonic Scheduling in c:
#include<stdio.h>
#include<stdlib.h>

struct rms{
    int id;
    int execution;
    int period;
    int remaining;
    int nextarrival;
};

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(a,a%b);
}

int findlcm(int a[],int n)
{
    int res=a[0];
    for(int i=0;i<n;i++)
    {
        res=(res*a[i])/(gcd(res,a[i]));
    }
    return res;
}
int main()
{
    printf("SHREYA J G 1BM23CS352\n");
    printf("enter the number of processes\n");
    int n;
    scanf("%d",&n);
    struct rms tasks[n];
    for(int i=0;i<n;i++)
    {
        tasks[i].id=i+1;
        printf("enter the execution and period of tasks:%d",i+1);
        scanf("%d%d",&tasks[i].execution,&tasks[i].period);
        tasks[i].nextarrival=0;
        tasks[i].remaining=0;

        
    }
    int period[n];
    for(int i=0;i<n;i++)
    {
        period[i]=tasks[i].period;

    }
    int lcm=findlcm(period,n);
    for(int time=0;time<lcm;time++)
    {
       
    printf("RMS scheduling for %d time \n",lcm);
    for(int i=0;i<n;i++)
    {
        if(time==tasks[i].nextarrival)
        {
            tasks[i].remaining=tasks[i].execution;
            tasks[i].nextarrival+=tasks[i].period;
        }
    }

    int min=999,selected=-1;
    for(int i=0;i<n;i++)
    {
        if(tasks[i].remaining>0 && tasks[i].period<min)
        {
            min=tasks[i].period;
            selected=i;
        }
    }

    if(selected!=-1)
    {
        printf("time %2d: task %d running\n",time,tasks[selected].id);
        tasks[selected].remaining--;
        if(tasks[selected].remaining==0)
        {
            printf("time %d task:%d FINISHED",time,tasks[selected].id);
        }
    }
    else{
        printf("time %d: idle\n",time);
    }
    }

}