#include <iostream>

#include "Hash.h"
#include "Receipt.h"
#include <string>

using namespace std;

int main()
{

    Hash h;
    bool exit = false;

    while(!exit){
        cout << "1. Add Item" << endl;
        cout << "2. Print Hash Table" << endl;
        cout << "3. Print Bucket of Items" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        int option = 0;
        cout << ">>> ";
        cin >> option;
        switch(option){
            case 1:{

                int invoice;
                string name;
                double amount;
                cout << "Type Receipt Number >>> ";
                cin >> invoice;
                cout << "Type Client Name >>> ";
                cin >> name;
                cout << "Type Receipt Amount >>> ";
                cin >> amount;
                Receipt *item = new Receipt(invoice, name, amount);
                h.addItem(item);
                continue;
            }
            case 2:{

                h.printHashtable();
                continue;
            }
            case 3:{

                int index;
                cout << "Type Index to print  >>> ";
                cin >> index;
                h.printBucketItems(index);
                continue;
            }
            case 4:{

                int number;
                cout << "Type Receipt number to remove  >>> ";
                cin >> number;
                h.removeItem(number);
                continue;
            }
            case 5:{
                exit = true;
                continue;
            }
        }
    }

}