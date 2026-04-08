# Do-An-TH-HSA-I

Welcome to the **Do-An-TH-HSA-I** repository! This project focuses on implementing, generating data for, and testing sorting algorithms in C++. It provides a hands-on approach to understanding data structures and algorithmic performance.

## 📁 Repository Structure

The project is structured around three main C++ files:

* **`Sorting.cpp`**: Contains the core logic and implementations of various sorting algorithms.
* **`Data_Generator.cpp`**: A utility designed to generate arrays of data. It is typically used to create datasets of varying sizes and arrangements (e.g., random, sorted, reverse-sorted) to test how different sorting algorithms handle different edge cases.
* **`test2.cpp`**: Acts as a testing suite or main driver program to execute the sorting algorithms against the generated data and observe the results.

## 🚀 Getting Started

### Prerequisites
To compile and run this project, you will need a C++ compiler installed on your system, such as `g++` (GCC) or `clang++`.

### Compilation
Open your terminal, navigate to the repository directory, and compile the source code. Depending on how your headers and `main` functions are structured, your compilation command might look like this:

```bash
g++ test2.cpp Sorting.cpp Data_Generator.cpp -o sorting_project
