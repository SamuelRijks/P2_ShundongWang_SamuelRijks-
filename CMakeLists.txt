cmake_minimum_required(VERSION 3.26)
project(P2_ShundongWang_SamuelRijks)

set(CMAKE_CXX_STANDARD 23)

# Define the source files
set(Headers Contenidor.h Comodi.h Element.h Lletra.h Seleccio.h)

# Define the include directories where the header files are located
include_directories(Sources)

# Create the executable
add_executable(P2_ShundongWang_SamuelRijks
        Sources/main.cpp
        Sources/src/Comodi.cpp
        Sources/src/Contenidor.cpp
        Sources/src/Seleccio.cpp
        Sources/src/Lletra.cpp
        Sources/src/Element.cpp
)
