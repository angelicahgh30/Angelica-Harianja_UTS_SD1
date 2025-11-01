/*
Nama  : Angelica Happy Grace Harianja
NIM   : 241401130
Soal  : Parul dan Misi Rahasia Mencari Ikan Segar
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
    vector<string> kotaNama = {
        "Ikan Bakar Pak Harry",     // A
        "Gudang Kaleng Bekas",      // B
        "Sushi Kucing Alya",        // C
        "Kedai IKLC",               // D
        "Pasar Ikan Tengah Malam"   // E
    };
    vector<char> kotaSimbol = {'A', 'B', 'C', 'D', 'E'};

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    // Tambahkan edge (graf tidak berarah berbobot)
    void addEdge(int i, int j, int w) {
        i--; j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = w;
            adjMatrix[j][i] = w;
        }
    }

    // =================== DFS ===================
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        vector<char> hasil;  // menyimpan urutan kota yang dikunjungi

        dfsUtil(startVertex, visited, hasil);

        cout << "PENJELAJAHAN PARUL (DFS dari " << kotaSimbol[startVertex] << "):" << endl;
        for (int i = 0; i < hasil.size(); i++) {
            cout << hasil[i];
            if (i < hasil.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited, vector<char>& hasil) {
        visited[currentVertex] = true;
        hasil.push_back(kotaSimbol[currentVertex]);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                dfsUtil(i, visited, hasil);
            }
        }
    }

    // =================== BFS ===================
    void bfsShortest(int startVertex, int endVertex) {
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == endVertex) break;

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[current][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    parent[i] = current;
                    q.push(i);
                }
            }
        }

        vector<int> path;
        int crawl = endVertex;
        int totalJarak = 0;

        while (crawl != -1) {
            path.push_back(crawl);
            int prev = parent[crawl];
            if (prev != -1)
                totalJarak += adjMatrix[crawl][prev];
            crawl = prev;
        }

        reverse(path.begin(), path.end());

        cout << "\nJALUR TERCEPAT PARUL (BFS):" << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << kotaNama[path[i]] << " (" << kotaSimbol[path[i]] << ")" << endl;
            if (i < path.size() - 1)
                cout << adjMatrix[path[i]][path[i + 1]] << "m" << endl;
        }

        cout << "\nJalur terpendek: ";
        for (int i = 0; i < path.size(); i++) {
            cout << kotaSimbol[path[i]];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;

        cout << "Total langkah: " << path.size() - 1 << " edge" << endl;
        cout << "Total jarak: " << totalJarak << " meter" << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(1, 2, 5); // A-B (5)
    g.addEdge(1, 3, 2); // A-C (2)
    g.addEdge(2, 4, 4); // B-D (4)
    g.addEdge(3, 4, 1); // C-D (1)
    g.addEdge(4, 5, 3); // D-E (3)

    g.dfs(0);            // DFS dari A
    g.bfsShortest(0, 4); // BFS dari A ke E

    return 0;
}
