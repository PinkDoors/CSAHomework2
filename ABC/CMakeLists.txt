cmake_minimum_required(VERSION 3.20)
project(ABC)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABC main.cpp CyclicShiftEncryption.h SymbolsEncryption.h NumbersEncryption.h container.cpp container.h Encryption.cpp Encryption.h NumbersEncryption.cpp SymbolsEncryption.cpp CyclicShiftEncryption.cpp)
