cmake_minimum_required(VERSION 3.27)
project(AiZO_projekt1)

set(CMAKE_CXX_STANDARD 17)

add_executable(AiZO_projekt1 Sources/main.cpp
        Headers/SortAlgorithm.h
        Headers/Array.h
        Headers/InsertionSort.h
        Headers/HeapSort.h
        Headers/ShellSort.h
        Headers/QuickSort.h
        Sources/Menu.cpp
        Headers/Menu.h
        Headers/SortingTester.h
)
