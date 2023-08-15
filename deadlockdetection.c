#include <stdio.h>
#include<stdbool.h>
int main()
{


	int n, m, i, j, k, l;
	printf("\nEnter no. of process: ");
	scanf("%d",&n);
	printf("\nEnter no. of resources: ");
	scanf("%d",&m);
	int alloc[n][m],request[n][m],avail[m];
	
	
	printf("\nEnter allocation matrix\n");
	for (i = 0; i < n; i++)
	{
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }

	}
	printf("\nEnter request matrix\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

	printf("\nEnter available resource vector: ");

	int work[m];
	bool finish[n];

    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
        work[j]=avail[j];
    }

    for(i=0;i<n;i++)
    {
        finish[i] = true;
        for(j=0;j<n;j++)
        {
            if(alloc[i][j]!=0)
            {
                finish[i]= false;
                break;
            }
        }
    }
    int res[n], y=0;
    
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(!finish[i])
            {
                int flag=1;
                for(j=0;j<m;j++)
                {
                    if(request[i][j]>work[j])
                    {
                        flag=0;
                        break;
                    }
                }
            
                if(flag)
                {
                    for(l=0;l<m;l++)
                    {
                        work[l] += alloc[i][l];
                    }
                    finish[i] = true;
                    res[y++] = i;
                }
            }
        }
        
    }
    int x=0;
    for(i=0;i<n;i++)
    {
        if(finish[i]==false)
            printf("\nSystem is in Deadlock, P%d is the deadlocked process\n", i);
        
        else
            x++;
    }
    if(x==n)
    {
        printf("\nNo Deadlock!!\nSafe sequence: ");
       
        for(i=0;i<n;i++)
            printf("P%d,  ", res[i]);
        printf("\n");
    }

	return 0;
}
