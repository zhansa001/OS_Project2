# OS_Project2

# Description (from Assignment doc):
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:



 
<img width="468" alt="osp2" src="https://github.com/user-attachments/assets/77220aa2-89c4-4517-87aa-868c85e31dda" />

Implement the Banker’s algorithm to answer the following question： 
1. Is the system in a safe state?
2. If Yes, then what is the safe sequence?

# Dependencies:
In the banker.hpp file, it includes the standard iostream, fstream, and vector needed for the assiagnment along with initializing the 5 processes and 3 resources.

The banker.cpp file have the Safe Algorithms, read the available, allocation/max matrix, and calculate the need (max - allocation).
Also, printing out the safe sequence.

The input file customized the format that stores the data provided in the table.

3 3 2

0 1 0

2 0 0

3 0 2

2 1 1

0 0 2

7 5 3

3 2 2

9 0 2

2 2 2

4 3 3

# Compilation:
To compile and the banker.cpp, use the following commands:
g++ banker.cpp -o banker

./banker

# Output:
The system is in Safe State!!! 

The Safe Sequence is: 

P1 -> P3 -> P4 -> P0 -> P2
