#pragma once

#include <vector>

namespace lib::dsa {
    class Graph {
    private:
        int m = 0;
        int n = 0;
        int **graph;
    public:
        inline explicit Graph(int m, int n) {
            this->m = m;
            this->n = n;
            this->graph = reinterpret_cast<int **>(new int[m * n][8]);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 8; k++) {
                        this->graph[i * j][k] = 1;
                    }
                }
            }
        }

        inline ~Graph() {
            delete[] this->graph;
        }
    };
}