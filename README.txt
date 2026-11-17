UNIVERSITY LAB RESOURCE ALLOCATION - BANKER'S ALGORITHM

Files:
- bankers_algorithm.c : C source code to calculate a safe sequence.

Compile (GCC):
    gcc bankers_algorithm.c -o bankers_algorithm

Run:
    ./bankers_algorithm
On Windows:
    bankers_algorithm.exe

Input order:
1. Number of processes
2. Number of resource types
3. Allocation matrix
4. Maximum matrix
5. Available resources

The program calculates Need = Maximum - Allocation and applies the
Banker's safety algorithm to display a safe sequence or report an
unsafe state. Matrix dimensions are limited to 10 x 10.
