// Write a menu driven C++ program to construct an
// expression tree from the given prefix expression eg. +--a*bc/def and
// perform following operations:
// 1. Traverse it using post order traversal (non recursive)
// 2. Delete the entire tree
// 3. Change a tree so that the roles of the left and right pointers are
// swapped at every node


#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;

    Node(char v) {
        this->value = v;
        left = NULL;
        right = NULL;
    }

    friend class expressiontree;
};

class expressiontree {
public:
     void postOrderTraversal(Node* root) {
        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            Node* current = s2.top();
            s2.pop();
            cout << current->value << " ";
        }
    }

    void deleteTree(Node* node) {
        if (node == NULL)
            return;
        
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void swapPointers(Node* node) {
        if (node == NULL)
            return;

        swapPointers(node->left);
        swapPointers(node->right);

        swap(node->left, node->right);
    }
};

int main() {
    string s;
    cout << "Enter the prefix expression: ";
    cin >> s;

    stack<Node*> e;
    expressiontree a;
    Node *x, *y, *z;
    int l = s.length();
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            z = new Node(s[i]);
            x = e.top();  
            e.pop();      
            y = e.top();
            e.pop();
            z->left = y;
            z->right = x;
            e.push(z);
        } else {
            z = new Node(s[i]);
            e.push(z);
        }
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Traverse using post-order traversal\n";
        cout << "2. Delete the entire tree\n";
        cout << "3. Swap left and right pointers at every node\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Post-order traversal: ";
            a.postOrderTraversal(z);
            cout << endl;
            break;
        case 2:
            a.deleteTree(z);
            cout << "Tree deleted successfully.\n";
            break;
        case 3:
            a.swapPointers(z);
            cout << "Left and right pointers swapped at every node.\n";
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

