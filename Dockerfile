FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update &&\
    apt-get install -y --no-install-recommends \
            sudo \
            make cmake clang-15 \
            clang-format-15 &&\
    apt-get -y clean &&\
    rm -rf /var/lib/apt/lists/*

RUN adduser --disabled-password --gecos '' user
RUN echo 'user ALL=(root) NOPASSWD:ALL' > /etc/sudoers.d/user

USER user
WORKDIR /home/user
