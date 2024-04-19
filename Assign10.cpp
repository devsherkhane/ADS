#include <iostream>
#include <list>
#include <string>
using namespace std;

class Dictionary {
private:
    static const int TABLE_SIZE = 10;
    list<pair<int, string>> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insertItem(int key, const string& value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                cout << "Key already exists. Cannot insert.\n";
                return;
            }
        }
        table[index].push_back(make_pair(key, value));
    }

    string findItem(int key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; 
            }
        }
        return "Key not found"; 
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](auto& pair) { return pair.first == key; });
    }

    void displayDictionary() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (auto& pair : table[i]) {
                    cout << "(" << pair.first << ", " << pair.second << ") ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary dict;
    int choice, key;
    string value;

    do {
        cout << "\nDictionary Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                dict.insertItem(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                cout << "Value: " << dict.findItem(key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.deleteItem(key);
                cout << "Key deleted.\n";
                break;
            case 4:
                cout << "Dictionary Contents:\n";
                dict.displayDictionary();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
