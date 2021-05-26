#!/bin/bash
#SBATCH --job-name=mpitest_container_openmpi
#SBATCH --cpus-per-task=1
#SBATCH --tasks-per-node=1
#SBATCH --nodes=4
#SBATCH --output=mpitest_container_openmpi.out
#SBATCH --error=mpitest_container_openmpi.err
#SBATCH --partition=cluster

export OMP_NUM_THREADS=1
module load openmpi
mpirun -np 4 singularity run -B /scratch test.sif /opt/mpitest

jobinfo
