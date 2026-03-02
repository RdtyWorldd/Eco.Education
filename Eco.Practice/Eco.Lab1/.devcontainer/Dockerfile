# syntax=docker/dockerfile:1.4
# Используем официальный образ Ubuntu для x86 архитектуры
FROM --platform=linux/amd64 ubuntu:22.04

# Предотвращаем интерактивные запросы при установке пакетов
ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем необходимые базовые пакеты
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    curl \
    wget \
    nano \
    sudo \
    x11-apps \         
    libx11-dev \         
    libxext-dev \        
    libxrender-dev \     
    libxtst-dev \        
    libxi-dev \          
    libxrandr-dev \      
    libgl1-mesa-glx \    
    libgl1-mesa-dri \    
    mesa-utils \        
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Создаем директории для библиотек (они будут точками монтирования)
RUN mkdir -p /opt/eco_framework /opt/eco_framework_rt

# Устанавливаем переменные окружения
ENV ECO_FRAMEWORK=/opt/eco_framework
ENV ECO_FRAMEWORK_RT=/opt/eco_framework_rt

# Создаем пользователя vscode
RUN useradd -m -s /bin/bash vscode && \
    echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Возвращаем интерактивный режим обратно
ENV DEBIAN_FRONTEND=

# Устанавливаем рабочую директорию
WORKDIR /workspace

# Команда по умолчанию
CMD ["/bin/bash"]
