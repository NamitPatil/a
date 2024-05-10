#include<stdio.h>

int deline[5]={-1}; 
int profit[5]={0};
int job[5]={0};
int max=0;
int tp=0;
int arr[5]={0};

void sort(int c,int de,int jo) 
{
    int i;
    if (deline[0]==-1) 
	{
        profit[0]=c;
        deline[0]=de;
        job[0]=jo;
    } 
	else 
	{
        for (i=4;i>=0;i--) 
		{
            if (c>profit[i]) 
			{
                if (i<4) 
				{ 
                    profit[i+1]=profit[i];
                    deline[i+1]=deline[i];
                    job[i+1]=job[i];
                }
            }
			else
			{
                break;
            }
        }
        profit[i+1]=c; 
        deline[i+1]=de;
        job[i+1]=jo;
    }
}

int main() 
{
    int i, j = 1,r,k=0,n=1;
    int pro[5], del[5], dmax=0;
    int slot[5] = {-1}; 
    int count=0, prof=0,a;
    printf("Enter the maximum deline is: ",i+1);
    scanf("%d", &max);
    r=max;

    for(i=0;i<5;i++) 
	{
        printf("\nEnter the profit of %d Job: ",i+1);
        scanf("%d", &pro[i]);
        printf("Enter the deline of %d Job: ",i+1);
        scanf("%d", &del[i]);
        sort(pro[i],del[i],j);
        j++;
    }
    printf("\nJob\t\tProfit\t\tDeadline\n");
	for(i=0;i<5;i++) 
	{
        printf("\nJ%d\t\t%d\t\t%d",job[i],profit[i],deline[i]);
    }
    
    do
    {
    	if(max>=deline[k])
    	{
    		tp+=profit[k];
    		max-=deline[k];
    		arr[n]=job[k];
    		n++;
    		k++;
		}
		else
		{
			k++;
		}
	}while(max!=0 || k==5);
    
//    for(i=0; i<5;i++) 
//	{
//        if(del[i]>dmax) 
//		{
//            dmax=del[i];
//        }
//    }
//
//    
//    for(i=1;i<=dmax; i++)
//	{
//        slot[i]=-1;
//    }

    
//    for(i=0;i<5;i++) 
//	{
//        for(r=del[i];r>= 1;r--)
//		{
//            if(slot[r]==-1) 
//			{
//                slot[r] = i;
//                prof += profit[i];
//                count++;
//                break;
//            }
//        }
//        if(count==dmax) 
//		{
//            break;
//        }
//    }

    printf("\n\nTotal profit is: %d", tp);
    printf("\nMaximum deline is: %d", r);
    printf("\nThe Jobs excuted are: ");
    for(a=1;a<n;a++)
    {
    	printf("J%d",arr[a]);
	}
    return 0;
}