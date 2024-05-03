#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Client
{
    string name;
    string phoneNumber;

    Client(const string &n, const string &num) : name(n), phoneNumber(num) {}
};

class SeparateChaining
{
private:
    static const int TS = 10;
    vector<list<Client>> table;

    int hashFunction(const string &key)
    {
        return key.length() % TS;
    }

public:
    SeparateChaining() : table(TS) {}

    void insertItem(const string &name, const string &phoneNumber)
    {
        int index = hashFunction(name);
        table[index].push_back(Client(name, phoneNumber));
    }

    string findItem(const string &name)
    {
        int index = hashFunction(name);

        for (const auto &client : table[index])
        {

            if (client.name == name)
            {
                return client.phoneNumber;
            }
        }
        return "Client not found";
    }

    void displayTable()
    {
        for (int i = 0; i < TS; ++i)
        {
            cout << i << ": ";
            if (table[i].empty())
            {
                cout << "Empty";
            }
            else
            {
                for (const auto &client : table[i])
                {
                    cout << "(" << client.name << ", " << client.phoneNumber << ")";
                }
            }
            cout << endl;
        }
    }
};

class LinearProbing
{
private:
    static const int TS = 10;
    vector<pair<string, string>> table;

    int hashFunction(const string &key)
    {
        return key.length() % TS;
    }

public:
    LinearProbing() : table(TS) {}

    void insertItem(const string &name, const string &phoneNumber)
    {
        int index = hashFunction(name);
        while (!table[index].first.empty())
        {
            index = (index + 1) % TS;
        }
        table[index] = make_pair(name, phoneNumber);
    }

    string findItem(const string &name)
    {
        int index = hashFunction(name);

        while (!table[index].first.empty())
        {

            if (table[index].first == name)
            {
                return table[index].second;
            }
            index = (index + 1) % TS;
        }
        return "Client not found";
    }

    void displayTable()
    {
        for (int i = 0; i < TS; ++i)
        {
            cout << i << ": ";
            if (table[i].first.empty())
            {
                cout << "Empty";
            }
            else
            {
                cout << "(" << table[i].first << ", " << table[i].second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice;
    SeparateChaining sc;
    LinearProbing lp;

    do
    {
        cout << "\nTelephone Book Opns :\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string nm, pno;
            cout << "Enter name: ";
            cin >> nm;
            cout << "Enter phone number: ";
            cin >> pno;
            sc.insertItem(nm, pno);
            lp.insertItem(nm, pno);
            break;
        }
        case 2:
        {
            string nm;
            cout << "Enter name to find: ";
            cin >> nm;

            string pnoSC = sc.findItem(nm);
            string pnoLP = lp.findItem(nm);
            cout << "Separate Chaining - Phone Number: " << pnoSC << endl;
            cout << "Linear Probing - Phone Number: " << pnoLP << endl;
            break;
        }
        case 3:
            cout << "Separate Chaining Hash Table:\n";
            cout<<"Table Size :10"<<endl;
            sc.displayTable();
            cout << "\nLinear Probing Hash Table:\n";
            cout<<"Table Size :10"<<endl;
            lp.displayTable();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
