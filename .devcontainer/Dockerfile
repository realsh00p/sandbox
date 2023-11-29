FROM debian:bookworm-slim

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get update && \
    apt-get install -y \
    autoconf \
    ccache \
    cmake \
    gcc-11 \
    g++-11 \
    valgrind \
    kcachegrind \
    gdb \
    git \
    gnupg \
    libpciaccess-dev \
    libtool \
    ninja-build \
    libssl-dev \
    ruby \
    ruby-dev \
    rubygems \
    software-properties-common \
    sudo \
    python3 \
    python3-pip \
    vim \
    wget

WORKDIR /tmp
RUN wget --no-check-certificate 'https://apt.llvm.org/llvm-snapshot.gpg.key'
RUN apt-key add llvm-snapshot.gpg.key
RUN apt-add-repository "deb http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-15 main"

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get update && \
    apt-get install -y \
    # Clang and co \
    clang-15 \
    clang-tidy-15 \
    clang-format-15 \
    clangd-15

RUN pip3 install --break-system-packages conan==1.60.1
RUN gem install cucumber

RUN useradd -m -s /bin/bash -G sudo -p 'user' user
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER user
WORKDIR /home/user

RUN conan profile new clang ; \
    conan profile update settings.os=Linux clang && \
    conan profile update settings.os_build=Linux clang && \
    conan profile update settings.arch=x86_64 clang && \
    conan profile update settings.arch_build=x86_64 clang && \
    conan profile update settings.compiler=clang clang && \
    conan profile update settings.compiler.version=15 clang && \
    conan profile update settings.compiler.libcxx=libstdc++11 clang && \
    conan profile update env.CC=/usr/bin/clang-15 clang && \
    conan profile update env.CXX=/usr/bin/clang++-15 clang

RUN conan profile new gnu ; \
    conan profile update settings.os=Linux gnu && \
    conan profile update settings.os_build=Linux gnu && \
    conan profile update settings.arch=x86_64 gnu && \
    conan profile update settings.arch_build=x86_64 gnu && \
    conan profile update settings.compiler=gcc gnu && \
    conan profile update settings.compiler.version=11 gnu && \
    conan profile update settings.compiler.libcxx=libstdc++11 gnu && \
    conan profile update env.CC=/usr/bin/gcc-11 gnu && \
    conan profile update env.CXX=/usr/bin/g++-11 gnu

RUN cd /home/user/.conan/profiles && \
      ln -s gnu default && \
    cd -

