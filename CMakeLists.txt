cmake_minimum_required(VERSION 3.10)
project(InterestPointProcessing)

# Ativar suporte ao C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Diretórios de include
include_directories(include)

# Adicionar os arquivos do projeto
file(GLOB SOURCES src/*.cpp)

# Criar o executável
add_executable(${PROJECT_NAME} ${SOURCES})

# Encontrar e linkar bibliotecas do OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
