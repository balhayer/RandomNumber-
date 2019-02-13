#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[] )
{
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &rank);
  MPI_Comm_size( MPI_COMM_WORLD, &size);

  srand(time(NULL) * rank); // generating seed
  int value = rand() % 100; // random value from 0-99
  printf("I am %d of %d, printing out value: %d\n", rank, size, value);

  MPI_Finalize();
  return 0;
}
