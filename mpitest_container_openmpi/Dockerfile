FROM ubuntu:18.04

RUN mkdir -p /opt
COPY mpitest.c /opt/.

ENV OMPI_DIR=/opt/ompi
ENV PATH="$OMPI_DIR/bin:$PATH"
ENV LD_LIBRARY_PATH="$OMPI_DIR/lib:$LD_LIBRARY_PATH"
ENV MANPATH="$OMPI_DIR/share/man:$MANPATH"

RUN apt-get update && apt-get install -y wget git bash gcc gfortran g++ make file

RUN echo "Installing Open MPI" && \
    export OMPI_DIR=/opt/ompi && \
    export OMPI_VERSION=4.0.5 && \
    export OMPI_URL="https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-$OMPI_VERSION.tar.bz2" && \
    mkdir -p /tmp/ompi && \
    mkdir -p /opt && \
    cd /tmp/ompi && wget -O openmpi-$OMPI_VERSION.tar.bz2 $OMPI_URL && tar -xjf openmpi-$OMPI_VERSION.tar.bz2 && \
    cd /tmp/ompi/openmpi-$OMPI_VERSION && ./configure --prefix=$OMPI_DIR && make -j8 install

RUN export PATH=$OMPI_DIR/bin:$PATH && \
    export LD_LIBRARY_PATH=$OMPI_DIR/lib:$LD_LIBRARY_PATH && \
    echo "Compiling the MPI application..." && \
    cd /opt && mpicc -o mpitest mpitest.c