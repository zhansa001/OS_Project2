//Sandy Zhang
//4/21/25

#include "banker.hpp"

int main() {
    std::ifstream in;
    in.open("input.txt");
    if(!in) {
        std::cerr << "File not found: test.txt" << std::endl;
        exit(1);
    }

    int n = processes;
    int m = resources;

    std::vector<int> available(m);

    // Read available
    for(int i = 0; i < m; ++i) {
        in >> available[i];
    }

    std::vector<std::vector<int>> max(n, std::vector<int>(m));
    std::vector<std::vector<int>> allocation(n, std::vector<int>(m));
    std::vector<std::vector<int>> need(n, std::vector<int>(m));

    // Read allocation matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> allocation[i][j];
        }
    }

    // Read max matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> max[i][j];
        }
    }

    // Calculate need = max - allocation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //Safe Algorithm
    std::vector<int> work = available;
    std::vector<bool> finish(n, false);
    std::vector<int> safeSequence;
    
    for(int k = 0; k < n; ++k) {
        bool found = false;
        for(int i = 0; i < n; ++i) {
            if(!finish[i]){
                bool safe = true;
                for(int j = 0; j < m; ++j){
                    if(need[i][j] > work[j]) {
                        safe = false;
                        break;
                    }
                }
    
                if(safe) {
                    for(int j = 0; j < m; ++j) {
                        work[j] += allocation[i][j];
                    }
    
                    finish[i] = true;
                    safeSequence.push_back(i);
                    found = true;
                }
            }
        }
        if (!found) break; // exit if no safe process was found this round
    }
    
    bool safe = true;
    for(int i = 0; i < n; ++i) {
        if(!finish[i]) {
            safe = false;
            std::cout << "Not in Safe State!" << std::endl;
            break;
        } 
    }
    
    if(safe) {
        std::cout << "The system is in Safe State and the safe sequence is: ";
        for(size_t i = 0; i < safeSequence.size(); ++i) {
            std::cout << "P" << safeSequence[i];
            if (i != safeSequence.size() - 1) std::cout << " -> ";
        }
        std::cout << std::endl;
    }
    

    in.close();
    return 0;
}
