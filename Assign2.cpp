#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>

using namespace std;

class CollegeGraph {
private:
    static const int MAX_VERTICES = 100;
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    unordered_map<string, int> vertexIndices;
    vector<string> vertexNames;
    unordered_map<string, list<string>> adjacencyList;

public:
    CollegeGraph() {
        numVertices = 0;
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addVertex(const string& vertex) {
        if (numVertices < MAX_VERTICES) {
            vertexIndices[vertex] = numVertices;
            vertexNames.push_back(vertex);
            ++numVertices;
        } else {
            cout << "Maximum number of vertices reached." << endl;
        }
    }

    void addEdge(const string& source, const string& destination) {
        if (vertexIndices.find(source) != vertexIndices.end() && vertexIndices.find(destination) != vertexIndices.end()) {
            int sourceIndex = vertexIndices[source];
            int destIndex = vertexIndices[destination];
            adjMatrix[sourceIndex][destIndex] = 1;

            // Add edge to the adjacency list
            adjacencyList[source].push_back(destination);
        } else {
            cout << "One or both of the vertices do not exist." << endl;
        }
    }

    void displayMatrix() const {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayAdjacencyList() const {
        cout << "Adjacency List:" << endl;
        for (const auto& pair : adjacencyList) {
            cout << pair.first << " -> ";
            for (const string& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void dfs(int startVertex) const {
    vector<bool> visited(numVertices, false);
    stack<int> s;
    s.push(startVertex);

    cout << "DFS: ";
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            cout << vertexNames[vertex] << " ";
            visited[vertex] = true;

            for (int i = numVertices - 1; i >= 0; --i) {
                if (adjMatrix[vertex][i] && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
    cout << endl;
}

void bfs(int startVertex) const {
    vector<bool> visited(numVertices, false);
    queue<int> q;
    q.push(startVertex);

    cout << "BFS: ";
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (!visited[vertex]) {
            cout << vertexNames[vertex] << " ";
            visited[vertex] = true;

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[vertex][i] && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }
    cout << endl;
}

};

int main() {
    CollegeGraph college;
    int choice;

    do {
        cout << "\n1. Add Vertex\n"
             << "2. Add Edge\n"
             << "3. Display Adjacency Matrix\n"
             << "4. Display Adjacency List\n"
             << "5. Perform DFS\n"
             << "6. Perform BFS\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string vertexName;
                cout << "Enter the name of the vertex: ";
                cin >> vertexName;
                college.addVertex(vertexName);
                break;
            }
            case 2: {
                string source, destination;
                cout << "Enter the source vertex: ";
                cin >> source;
                cout << "Enter the destination vertex: ";
                cin >> destination;
                college.addEdge(source, destination);
                break;
            }
            case 3:
                college.displayMatrix();
                break;
            case 4:
                college.displayAdjacencyList();
                break;
            case 5: {
                int startVertex;
                cout << "Enter the starting vertex for DFS: ";
                cin >> startVertex;
                college.dfs(startVertex);
                break;
            }
            case 6: {
                int startVertex;
                cout << "Enter the starting vertex for BFS: ";
                cin >> startVertex;
                college.bfs(startVertex);
                break;
            }
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}