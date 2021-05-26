#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int rc;
        int size;
        int myrank;

        rc = MPI_Init(&argc, &argv);
        if (rc != MPI_SUCCESS)
        {
                fprintf(stderr, "MPI_Init() failed");
                return EXIT_FAILURE;
        }

        rc = MPI_Comm_size(MPI_COMM_WORLD, &size);
        if (rc != MPI_SUCCESS)
        {
                fprintf(stderr, "MPI_Comm_size() failed");
                goto exit_with_error;
        }

        rc = MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
        if (rc != MPI_SUCCESS)
        {
                fprintf(stderr, "MPI_Comm_rank() failed");
                goto exit_with_error;
        }

        fprintf(stdout, "Hello, I am rank %d/%d\n", myrank, size);

        MPI_Finalize();

        return EXIT_SUCCESS;

exit_with_error:
        MPI_Finalize();
        return EXIT_FAILURE;
}

// copied from https://sylabs.io/guides/3.7/user-guide/mpi.html?highlight=mpi
// Copyright (c) 2017, SingularityWare, LLC. All rights reserved.
// Copyright (c) 2018-2020, Sylabs, Inc. All rights reserved.