FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update &&\
    apt-get install -y --no-install-recommends \
            sudo \
            make cmake clang-15 \
            clang-format-15 doxygen graphviz &&\
    apt-get -y clean &&\
    rm -rf /var/lib/apt/lists/*

RUN ln -s clang-15        /usr/bin/clang
RUN ln -s clang++-15      /usr/bin/clang++
RUN ln -s clang-format-15 /usr/bin/clang-format

RUN adduser --disabled-password --gecos '' user
RUN echo 'user ALL=(root) NOPASSWD:ALL' > /etc/sudoers.d/user

USER user
WORKDIR /home/user
