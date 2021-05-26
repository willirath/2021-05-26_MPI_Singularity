## Build

```shell
$ docker build . -t localreg/mpitest_container_openmpi
$ docker pull kathoef/docker2singularity:latest
$ docker run --rm -v /var/run/docker.sock:/var/run/docker.sock -v ${PWD}:/output \
    kathoef/docker2singularity singularity -v build \
    test.sif docker-daemon://localreg/mpitest_container_openmpi:latest
```
