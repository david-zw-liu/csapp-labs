FROM ubuntu:18.04
WORKDIR /data
RUN apt update && \
    apt upgrade -y && \
    apt install -y build-essential gcc-multilib g++-multilib && \
    apt install -y gdb && \
    apt install -y curl git && \
    git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && ~/.fzf/install && \
    rm -rf /var/lib/apt/lists/*
