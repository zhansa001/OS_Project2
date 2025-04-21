# OS_Project2

# Description (from Assignment doc):
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:



 
<img width="468" alt="osp2" src="https://github.com/user-attachments/assets/77220aa2-89c4-4517-87aa-868c85e31dda" />

Implement the Banker’s algorithm to answer the following question： 
1. Is the system in a safe state?
2. If Yes, then what is the safe sequence?

# Compilation:
g++ banker.cpp -o banker
./banker

# Output:
The system is in Safe State!!! 

The Safe Sequence is: 

P1 -> P3 -> P4 -> P0 -> P2
