#!/bin/bash
#SBATCH --job-name=mpitest_bare
#SBATCH --cpus-per-task=1
#SBATCH --tasks=4
#SBATCH --output=mpitest_bare.out
#SBATCH --error=mpitest_bare.err
#SBATCH --partition=cluster

export OMP_NUM_THREADS=1
module load intel/20.0.4 intelmpi/20.0.4
mpicc mpitest.c -o mpitest.x
mpirun -np 4 ./mpitest.x
