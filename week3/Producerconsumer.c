//program to implement producer consumer in c:
#include<stdio.h>
#include<stdlib.h>
#define N 10
int mutex=1,empty=N,full=0,item=0;
void wait(int *s)
{
    while(*s<=0);
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void producer()
{
    wait(&mutex);
    signal(&full);
    wait(&empty);
    item++;
    printf("produced item:%d\n",item);
    signal(&mutex);
}

void consumer()
{
    wait(&mutex);
    signal(&empty);
    wait(&full);
    printf("consumed item:%d\n",item);
    item--;
    signal(&mutex);
}

int main()
{
    int c;
    while(1)
    {
        printf("enter the operation you want to perform:\n");
        printf("1.Produce\n");
        printf("2.consumer\n");
        printf("3.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                producer();
                break;
            }
            case 2:
            {
                consumer();
                break;
            }
            case 3:
            {
                return 0;
            }
        }
    }
    return 0;
}