#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Graph
{
    int n, m;
    int** adjMatrix;
    Node** adjList;
    char** cities;

public:
    Graph()
    {
        n = m = 0;
        adjMatrix = nullptr;
        adjList = nullptr;
        cities = nullptr;
    }


    
    bool isValidCityIndex(int index)
    {
        return index >= 1 && index <= n;
    }

   
    void initArrays(int size)
    {
        n = m = size;
        adjMatrix = new int*[n];
        adjList = new Node*[n];
        cities = new char*[n];

        for (int i = 0; i < n; ++i)
        {
            adjMatrix[i] = new int[n](); 
            adjList[i] = nullptr;
            cities[i] = new char[50];
        }
    }

    int input()
    {
        cout << "Enter the number of cities: " << endl;
        cin >> n;
        cout << "Enter the number of flight paths: " << endl;
        cin >> m;

        initArrays(n);

        cout << "Enter the names of the cities:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << "City " << i + 1 << ": ";
            cin >> cities[i];
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, weight;
            cout << "Enter the indices of cities for flight path " << i + 1 << " and its weight (time or fuel):" << endl;
            cin >> u >> v >> weight;

           
            if (!isValidCityIndex(u) || !isValidCityIndex(v))
            {
                cout << "Invalid city indices. Please enter valid indices.\n";
                --i; 
                continue;
            }

            adjMatrix[u - 1][v - 1] = weight; 
            addEdge(u, v);
        }

        return 0;
    }

    void displayMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayList()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "City " << cities[i] << " is connected to: ";
            displayList(adjList[i]);
            cout << endl;
        }
    }

    void addEdge(int u, int v)
    {
        Node *newNode = new Node;
        newNode->data = v - 1; 
        newNode->next = adjList[u - 1];  
        adjList[u - 1] = newNode; 
    }

    void displayList(Node *head)
    {
        while (head != nullptr)
        {
            cout << cities[head->data] << " ";
            head = head->next;
        }
    }

    bool isConnected(int source, int dest)
    {
        Node *current = adjList[source - 1];  // Adjust to zero-based index
        while (current != nullptr)
        {
            if (current->data == dest - 1)  // Adjust to zero-based index
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main()
{
    Graph g;
    int choice;
    do
    {
        cout << "\n1. Take input for flight paths\n"
             << "2. Display the adjacency matrix\n"
             << "3. Display the adjacency list\n"
             << "4. Check if cities are connected through flights\n"
             << "5. Exit\n"
             << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            g.input();
            cout << "---------------------------------------------------------------------------------------" << endl;
            break;

        case 2:
            cout << "The adjacency matrix of the given flight paths is:\n";
            g.displayMatrix();
            cout << "---------------------------------------------------------------------------------------" << endl;
            break;

        case 3:
            cout << "The adjacency list of the given flight paths is:\n";
            g.displayList();
            cout << "---------------------------------------------------------------------------------------" << endl;
            break;

        case 4:
            int source, dest;
            cout << "Enter source city index: ";
            cin >> source;
            cout << "Enter destination city index: ";
            cin >> dest;

            if (g.isConnected(source, dest))
                cout << "Cities are connected through flights.\n";
            else
                cout << "Cities are not connected through flights.\n";
            cout << "---------------------------------------------------------------------------------------" << endl;
            break;

        case 5:
            break;
        }
    } while (choice != 5);

    return 0;
}

