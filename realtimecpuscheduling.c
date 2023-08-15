#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#define MAX_TASKS 100

int main()
{
    int ch;
    printf("Real-Time CPU Scheduling\n");
    while(1)
    {
        printf("\n1.Rate Monotonic\n2.Earliest Deadline First\n3.Proportional Scheduling\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            {
                
                int n;
                float e[20],p[20];
                int i;
                float ut,u,x,y; 
 

                printf("\n Enter Number of Processes :: ");
                scanf("%d",&n); 
                for(i=0;i<n;i++)
                {

                    printf("\n Enter Execution Time for P%d ::",(i+1)); 
                    scanf("%f",&e[i]);
                    printf("\n Enter Period for P%d ::",(i+1)); 
                    scanf("%f",&p[i]);
                }
                 
                for(i=0;i<n;i++)
                {
                    x=e[i]/p[i];
                    ut+=x;
                } 
                
                y=(float)n;
                y=y*((pow(2.0,1/y))-1);
                u=y; 
 
                if(ut<u)
                { 
                    printf("\n As %f < %f ,",ut,u);
                    printf("\n The System is surely Schedulable");
                }
                else
                    printf("\n Not Sure....."); 
    
            }
                    break;
            case 2:
            {
                typedef struct
                {
                    int task_id;
                    int arrival_time;
                    int execution_time;
                    int deadline;
                    int is_completed;
                } Task;

                float calculate_cpu_utilization(Task process[], int n)
                {
                    float total_utilization = 0.0;
                    for (int i = 0; i < n; i++)
                    {
                        float task_utilization = (float)process[i].execution_time / process[i].deadline;
                        total_utilization += task_utilization;
                    }
                    float cpu_utilization = total_utilization * 100;
                    return cpu_utilization;
                }

                int n, i;
                printf("Enter the number of processes: ");
                scanf("%d", &n);
                Task process[MAX_TASKS];
                for (i = 0; i < n; i++)
                {
                    printf("Process % d\n", i + 1);
                    printf("Enter execution time:");
                    scanf("%d", &process[i].execution_time);
                    printf("Enter deadline:");
                    scanf("%d", &process[i].deadline);
                    process[i].task_id = i + 1;
                    process[i].is_completed = 0;
                }
                float cpu_utilization = calculate_cpu_utilization(process, n);
                printf("CPU Utilization: %0.2f% ", cpu_utilization);
	            if(cpu_utilization<=100)
		            printf("\n EDF Scheduling possible\n");
	            else
		            printf("\n EDF Scheduling not possible\n");
    
            }
                    break;
            case 3:
            {
                int i,n,T;
                printf("\nEnter total vale of share T: ");
                scanf("%d",&T);
                printf("\nEnter no. of processes: ");
                scanf("%d",&n);
                int N[n];
                double NT=0;
    
                for(i=0;i<n;i++)
                {
                    printf("Enter share of P%d: ", i+1);
                    scanf("%d",&N[i]);
                    NT += (double)N[i]/T;
                }
    
                if(NT<=1)
                    printf("\nProportionalShareSchedule is possible.\n");
                else
                    printf("\nProportionalShareSchedule is not possible.\n");
                    
            }
                    break;
            case 4: printf("\nExiting program......\n");
                    exit(0);
                    break;
        }
    }
    return 0;
}
