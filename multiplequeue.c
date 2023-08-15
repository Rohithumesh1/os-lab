#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int n,pid[10],burst[10],type[10],arr[10],wt[10],ta[10],i,j;
    float avgwt=0,avgta=0;
    printf("Enter the total number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        pid[i]= i+1;
        printf("\nFor Process%d:-\n", pid[i]);
        printf("Enter the type of process(user-0 and system-1)\n");
        scanf("%d",&type[i]);
        printf("Enter the arrival time\n");
        scanf("%d",&arr[i]);
        printf("Enter the burst time\n");
        scanf("%d",&burst[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&burst[j],&burst[j+1]);
                swap(&type[j],&type[j+1]);

            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]==arr[j+1] && type[j]<type[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&burst[j],&burst[j+1]);
                swap(&type[j],&type[j+1]);
            }
        }
    }
    wt[0]=0;
    int d,t=0;
    i=0;
    t += burst[i]+arr[i];
    ta[i] = t - arr[i];
    wt[i] = ta[i] - burst[i];
    i++;

        while(i!=n)
        {
            if(t>=arr[i])
            {


                t += burst[i];
                ta[i] = t - arr[i];
                wt[i] = ta[i] - burst[i];
            }
            else
            {
                d = arr[i]-t;
                t +=d;
                t += burst[i];
                ta[i] = t - arr[i];
                wt[i] = ta[i] - burst[i];
            }
            i++;
        }

    printf("Process id\tType\tarrival time\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++)
    {
        avgta+=ta[i];
        avgwt+=wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],type[i],arr[i],burst[i],wt[i],ta[i]);
    }
    printf("average waiting time =%f",avgwt/n);
    printf("average turnaround time =%f",avgta/n);

}
