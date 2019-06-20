FROM ubuntu:18.04
WORKDIR /data
RUN apt update && \
    apt upgrade -y && \
    apt install -y build-essential gcc-multilib g++-multilib && \
    rm -rf /var/lib/apt/lists/*
