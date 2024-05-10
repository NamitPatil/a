#include<stdio.h>
void first(int m[],int j[]);

int j[5];
int m[5];
int f[5]={100,500,200,300,600};
int i=0,k=0,a[5];

int main()
{
    for(i=0;i<5;i++)
    {
        printf("\nEnter the process name: ");
        scanf("%d",&j[i]);
        printf("\nEnter the memory required to process: ");
        scanf("%d",&m[i]);
    }
    printf("\nJob\t\tMemory\t\tFrame");
    for(i=0;i<5;i++)
    {
        printf("\nJ%d \t\t%d \t\t%d",j[i],m[i],f[i]);
    }
    first(m,j);
    return 0;
}

void first(int m[],int j[])
{
    i=0;
    do{
        if(m[i]<=f[k])
        {
            a[i]=f[k];
            f[k]=0;
            i++;
        }
        else
        {
            k++;
        }
    }while(i<5 && k<5);
    printf("\nMemory \t\t Frame");
    for(i=0;i<5;i++)
    {
        printf("\n%d \t\t%d",m[i],a[i]);
    }
}