//program to implement diningb philosophers problem in c:
#include<stdio.h>
#include<stdlib.h>
#define thinking 0
#define hungry 1
#define eating 2
#define Max 10

int state[Max];
int total;
void test(int i)
{
    
    if(state[i]==hungry && state[(i+total-1)%total]!=eating && state[(i+1)%total]!=eating)
    {
        state[i]=eating;
        printf("%d philosopher is granted to eat\n",i);
    }
}

void wait(int i)
{
    state[i]=hungry;
    printf("%d philosopher is hungry\n",i);
    test(i);
    if(state[i]!=eating)
    {
        printf("philosopher %d is waiting\n",i);
    }
}

void signal(int i)
{
    state[i]=thinking;
    printf("philosopher %d has finished eating\n",i);
    test((i+total-1)%total);
    test((i+1)%total);
}

int main()
{
    printf("SHREYA JG 1BM23CS352\n");
    printf("enter the number of philosophers\n");
    scanf("%d",&total);
    printf("enter the number of hungry philosophers\n");
    int count;
    scanf("%d",&count);
    printf("enter the positions of the hungry philosphers from 0-%d",total-1);
    int p[Max];
    for(int i=0;i<count;i++)
    {
        scanf("%d",&p[i]);
    }
    int c;
    while(1)
    {
        printf("1.one eats at a time\n2.two eat at a time\n3.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                for(int i=0;i<count;i++)
                {
                    wait(p[i]);
                    signal(p[i]);
                }
                break;
            }
            case 2:
            {
                int i=0;
                while(i<count)
                {
                    wait(p[i]);
                    if(i+1<count)
                    {
                        wait(p[i+1]);
                    }

                    signal(p[i]);
                    if(i+1<count)
                    {
                        signal(p[i+1]);
                    }

                    i+=2;
                }
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


