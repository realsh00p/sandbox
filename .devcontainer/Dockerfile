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
    software-properties-common \
    sudo \
    python3 \
    python3-pip \
    python3-venv \
    vim \
    wget \
    texlive \
    latexmk \
    texlive-latex-extra \
    texlive-fonts-extra \
    pkg-config

WORKDIR /tmp
RUN wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && ./llvm.sh 19

RUN pip3 install --break-system-packages conan==1.60.1

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
    conan profile update settings.compiler.version=19 clang && \
    conan profile update settings.compiler.libcxx=libstdc++11 clang && \
    conan profile update settings.cucumber-cpp:build_type=Release clang && \
    conan profile update env.CC=/usr/bin/clang-19 clang && \
    conan profile update env.CXX=/usr/bin/clang++-19 clang

RUN conan profile new gnu ; \
    conan profile update settings.os=Linux gnu && \
    conan profile update settings.os_build=Linux gnu && \
    conan profile update settings.arch=x86_64 gnu && \
    conan profile update settings.arch_build=x86_64 gnu && \
    conan profile update settings.compiler=gcc gnu && \
    conan profile update settings.compiler.version=11 gnu && \
    conan profile update settings.compiler.libcxx=libstdc++11 gnu && \
    conan profile update settings.cucumber-cpp:build_type=Release gnu && \
    conan profile update env.CC=/usr/bin/gcc-11 gnu && \
    conan profile update env.CXX=/usr/bin/g++-11 gnu

RUN cd /home/user/.conan/profiles && \
      ln -s gnu default && \
    cd -

