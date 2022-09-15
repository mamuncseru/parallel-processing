#include <stdio.h>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("testcase.txt", "r", stdin);
    int m, n;
    set <int> forbidden_latency; 
    int transition_diag[10][10];

    int latency_arr[n];
    scanf("%d%d",&m,&n);

    int reservation_table[m][n] = {0};
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         reservation_table[i][j] = 0;
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        latency_arr[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&reservation_table[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (reservation_table[i][j] == 1)
            {
                for (int k = j+1; k < n; k++)
                {
                    if (reservation_table[i][k] == 1)
                    {
                        forbidden_latency.insert(k-j);
                    }

                }
            }
        }
    }

    printf("forbidden latency:\n");

    for(auto& latency: forbidden_latency)
    {
        latency_arr[latency-1] = 1;
        printf("%d ", latency);
    }

    printf("\n\n Permissible Latency:\n");
    int permissible_lat[8];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%d ",latency_arr[i]);
        if (latency_arr[i] == 0)
        {
            permissible_lat[l++] = i+1;
            printf("%d ", i+1);
        
        }
            
    }
    printf("\n");

    printf("\n\n Collision vector:\n");


    for (int i = 0; i < n; i++)
    {
        printf("%d ",latency_arr[i]);
            
    }
    printf("\n");


    for (int i = 0; i < l; i++ )
    {
        printf("%4d",permissible_lat[i]);
        int initial_point = permissible_lat[i];
        int k = 0;
        for (int j = 0 ; j < 8; j++)
        {
            if (initial_point > j)
            {
                transition_diag[i][j] = latency_arr[j];
            }
            else if (latency_arr[j] == 1 || latency_arr[j - initial_point] == 1)
            {
                transition_diag[i][j] = 1;

            }
            else {
                transition_diag[i][j] = 0;
            }
            // printf("%d %d %d\n",j, latency_arr[j], latency_arr[j - initial_point]);
            printf("%4d", transition_diag[i][j]);
        }
        printf("\n");
    }





    // int newtask_entrypoint;
    // scanf("%d",&newtask_entrypoint);

    // for (int i = 0; i < m; i++)
    // {
    //     int k = 0;
    //     for (int j = newtask_entrypoint; j < n; j++)
    //     {
    //         if (reservation_table[i][k] == 1 && reservation_table[i][j] == 1)
    //         {
    //             printf("row %d column %d has collision.\n", i, j);
    //         }

    //         k += 1;
    //     }
    // }

    

    return 0;
}