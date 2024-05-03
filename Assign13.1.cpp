#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> dictionary;
    int choice;
    string key;
    int value;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add an entry" << endl;
        cout << "2. Remove an entry" << endl;
        cout << "3. Display all entries" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary[key] = value;
                cout << "Entry added successfully!" << endl;
                break;
            case 2:
                cout << "Enter key to remove: ";
                cin >> key;
                if (dictionary.find(key) != dictionary.end()) {
                    dictionary.erase(key);
                    cout << "Entry removed successfully!" << endl;
                } else {
                    cout << "Key not found!" << endl;
                }
                break;
            case 3:
                cout << "Current entries:" << endl;
                for (const auto& entry : dictionary) {
                    cout << entry.first << ": " << entry.second << endl;
                }
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}

