#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int n) : vertices(n), adjacencyList(n) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(vertices, 0);
        for (int i = 0; i < vertices; ++i) {
            for (int neighbor : adjacencyList[i]) {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < vertices; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result; 
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int neighbor : adjacencyList[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};

int main() {
    int n, m; 
    cout << "Enter the number of duties (n): ";
    cin >> n;
    cout << "Enter the number of relationships (m): ";
    cin >> m;

    Graph graph(n);

    cout << "Enter the relationships (from to):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from - 1, to - 1); 
    }

    vector<int> order = graph.topologicalSort();

    if (order.size() == n) {
        cout << "Sandy can solve all his duties. The correct order is:" << endl;
        for (int task : order) {
            cout << task + 1 << " "; 
        }
        cout << endl;
    } else {
        cout << "Sandy cannot solve all his duties due to dependencies." << endl;
    }

    return 0;
}
