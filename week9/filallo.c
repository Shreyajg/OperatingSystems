//program to implement file allocation sequential in c:
#include<stdio.h>
#include<stdlib.h>
#define Max 10
int main()
{
    int files,found;
    int memory[Max]={0};

    printf("enter the number of files:\n");
    scanf("%d",&files);
    for(int i=0;i<files;i++)
    {
        int start,length;
        found=0;
        printf("enter the starting index and lngth of the file\n");
        scanf("%d%d",&start,&length);
        for(int j=start;j<start+length;j++)
        {
            if(memory[j]==1)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            for(int j=start;j<start+length;j++)
            {
                memory[j]=1;
            }
            printf("allocated memory for file %d\n",i+1);
            for(int j=start;j<start+length;j++)
            {
                printf("%d ",j);
            }
            printf("\n");
        }
        else{
            printf("memory cannot be allocated for file %d\n",i+1);
        }
    }
    printf("final memory allocation\n");
    for(int i=0;i<Max;i++)
    {
        printf("Block:%d -> %s\n",i+1,memory[i]?"Occupied":"empty");
    }
}