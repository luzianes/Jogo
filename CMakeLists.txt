# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto e a linguagem utilizada
project(JogoPif C)

# Define o padrão da linguagem utilizada
set(CMAKE_C_STANDARD 99)

# Adiciona a pasta libs/cli-lib/include à lista de diretórios de cabeçalho
include_directories(libs/cli-lib/include)

# Cria a biblioteca a partir dos arquivos (screen, keyboard e timer)
add_library(cli-lib STATIC
        libs/cli-lib/src/screen.c
        libs/cli-lib/src/keyboard.c
        libs/cli-lib/src/timer.c
)

# Adiciona o executável do projeto
add_executable(JogoPif main.c)

# Conecta a biblioteca ao projeto
target_link_libraries(JogoPif cli-lib)
