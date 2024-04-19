#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* left;
    Node* right;

    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key, int value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = remove(node->right, temp->key);
            }
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "(" << node->key << ", " << node->value << ") ";
            inorder(node->right);
        }
    }

    void reverseInorder(Node* node) {
        if (node != nullptr) {
            reverseInorder(node->right);
            cout << "(" << node->key << ", " << node->value << ") ";
            reverseInorder(node->left);
        }
    }

    int findHelper(Node* node, int key, int& comparisons) {
        if (node == nullptr) {
            return -1; // key not found
        }
        comparisons++;
        if (key == node->key) {
            return node->value;
        } else if (key < node->key) {
            return findHelper(node->left, key, comparisons);
        } else {
            return findHelper(node->right, key, comparisons);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    bool find(int key, int& value, int& comparisons) {
        comparisons = 0;
        value = findHelper(root, key, comparisons);
        return value != -1;
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void displayAscending() {
        inorder(root);
        cout << endl;
    }

    void displayDescending() {
        reverseInorder(root);
        cout << endl;
    }

    int getMaxComparisons() {
        int maxComparisons = 0;
        getMaxComparisonsHelper(root, maxComparisons);
        return maxComparisons;
    }

    void getMaxComparisonsHelper(Node* node, int& maxComparisons, int currentComparisons = 0) {
        if (node != nullptr) {
            currentComparisons++;
            if (currentComparisons > maxComparisons) {
                maxComparisons = currentComparisons;
            }
            getMaxComparisonsHelper(node->left, maxComparisons, currentComparisons);
            getMaxComparisonsHelper(node->right, maxComparisons, currentComparisons);
        }
    }
};

int main() {
    BST dictionary;
    int choice, key, value;
    int comparisons;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display Ascending\n";
        cout << "5. Display Descending\n";
        cout << "6. Max Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                if (dictionary.find(key, value, comparisons)) {
                    cout << "Value found: " << value << endl;
                    cout << "Comparisons required: " << comparisons << endl;
                } else {
                    cout << "Key not found.\n";
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.remove(key);
                break;
            case 4:
                cout << "Dictionary in ascending order: ";
                dictionary.displayAscending();
                break;
            case 5:
                cout << "Dictionary in descending order: ";
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons() << endl;
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
