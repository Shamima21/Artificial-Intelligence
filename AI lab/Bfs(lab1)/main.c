#include <stdio.h>
#include <stdlib.h>


 int i,j,n,s,cost[10][10],start,goal,trace[20],q=1,path[10]   ;

    BFS( int s)
    {
        i=start;
        for(j=0;j<n;j++)
        {
        if(cost[i][j]&&(trace[i]!=1))
        {

            trace[q]=1;
             q++;

        }
        path[q]=j;
        }


    BFS(j);


    }

int main()
{

    printf("Enter the number of nodes!\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        {

        }
        else{
                trace[q]=1;
        }


    }
     // printf(" \n");
     for(i=0;i<n;i++)
      {for(j=0;j<n;j++)
       {
           printf(" %d   ",cost[i][j]);
       }
         printf(" \n");
      }


                printf("Enter the start and goal node!\n");
                scanf("%d%d",&start,&goal);
                BFS(start);


    for(i=0;i<n;i++)
        printf("\n path=%d",path[i]);

    return 0;
}
