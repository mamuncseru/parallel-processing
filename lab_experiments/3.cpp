// 3. Write a program in MPI to simulate simple calculator.Perform each operation using different process in parallel

#include<bits/stdc++.h>
#include<mpi.h>

int main(int agc, char **argv)
{

    int a=4,b=5;
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    // printf("%d %d\n", a, b);
    MPI_Init(NULL, NULL);

    int rank, num_process;

    MPI_Comm_size(MPI_COMM_WORLD, &num_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    if (rank == 0) printf("Sum: %d\n", a+b);
    else if (rank == 1) printf("Sub: %d\n", a-b);
    else if (rank == 2) printf("Mult: %d\n", a*b);
    else if (rank == 3) printf("Div: %d\n", a/b);
    else printf("no operations to perform\n");

    MPI_Finalize();
    return 0;


}