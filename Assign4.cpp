#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;

    BST()
    {
        data = 0;
        left = right = NULL;
    }

    BST(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    BST *insert(BST *root, int value)
    {
        BST *newNode = new BST(value);
        if (root == NULL)
        {
            root = newNode;
            return root;
        }

        BST *current = root;
        while (true)
        {
            if (value > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = newNode;
                    return root;
                }
                current = current->right;
            }
            else
            {
                if (current->left == NULL)
                {
                    current->left = newNode;
                    return root;
                }
                current = current->left;
            }
        }
    }

    BST *findMin(BST *root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }
    BST *search(BST *root, int key)
    {
        while (root != NULL && root->data != key)
        {
            if (root->data < key)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }

    int printAsorder(BST *node)
    {
        if (node == NULL)
            return 0;

        printAsorder(node->left);

        cout << node->data << " ";

        printAsorder(node->right);
    }

    int printDsorder(BST *node)
    {
        if (node == NULL)
            return 0;

        printDsorder(node->right); 

        cout << node->data << " ";

        printDsorder(node->left); 
    }
};

int main()
{
    BinaryTree tree;
    BST *root = NULL;
    int choice, value;

    do
    {
        cout << "1. Insert new node" << endl;
        cout << "2. Minimum data value found in the tree" << endl;
        cout << "3. Search a value" << endl;
        cout << "4. Print values in ascending order" << endl;
        cout << "5. Print values in descending order" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = tree.insert(root, value);
            break;
        case 2:
            if (root == NULL)
                cout << "Tree is empty." << endl;
            else
                cout << "Minimum data value found in the tree: " << tree.findMin(root)->data << endl;
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(root, value) == NULL)
                cout << value << " not found" << endl;
            else
                cout << value << " found" << endl;
            break;
        case 4:
            cout << "Values in ascending order: ";
            tree.printAsorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Values in descending order: ";
            tree.printDsorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
