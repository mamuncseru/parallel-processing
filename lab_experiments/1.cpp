// Write a program in MPI to total number of process and rank of each process

// how to run
// mpicc 1.c -o a
// mpirun -np 5 ./a

#include<mpi.h>
#include<stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(int argc, char ** argv)
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of process
    int num_process;
    MPI_Comm_size(MPI_COMM_WORLD, &num_process);

    // Get the rank of the process
    int rank_process;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_process);

    // Get the number of processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;

    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n", processor_name, rank_process, num_process);

    int sum_result = sum(10, 15);
    printf("Value got from processor %s, rank %d out of %d processors is sum %d\n", processor_name, rank_process, num_process, sum_result);

    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}