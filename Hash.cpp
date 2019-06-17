//
// Created by Christian Rivera on 2019-06-15.
//

#include "Hash.h"

Hash::Hash() {
    for(int i=0; i<tableSize; i++){
        hashTable[i] = new Receipt();
    }
}

Hash::~Hash() {
    Receipt *ptr;
    for (int i = 0; i < tableSize; i++)
    {
        while (hashTable[i] != NULL)
        {
            ptr = hashTable[i];
            hashTable[i] = hashTable[i]->next;
            delete ptr;
        }
    }
}

int Hash::hashFunction(int key) {
    int hash = 0;
    int index;

    std::string str = std::to_string(key);

    for (int i = 0; i < str.length(); i++)
    {
        hash = (hash)+(int)str[i];
    }

    index = hash % tableSize;
    return index;
}

void Hash::addItem(Receipt *_Receipt) {
    int index = hashFunction(_Receipt->getReceiptNumber());
    //case receiptNumber ==0;
    if(hashTable[index]->getReceiptNumber() == 0){
        hashTable[index] = _Receipt;
    }else{
        Receipt *tmp = hashTable[index];
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = _Receipt;
    }
}

int Hash::numberOfItems(int _index) {
    int counter = 0;
    if(hashTable[_index]->getReceiptNumber() == 0){
        return counter;
    }else{
        Receipt *tmp = hashTable[_index];
        while (tmp != nullptr){
            counter++;
            tmp = tmp->next;
        }
        return counter;
    }

}

void Hash::printHashtable() {
    int number;
    for(int i=0; i< tableSize;i++){
        number = numberOfItems(i);
        cout << "-------------\n";
        cout << "Index: " << i << endl;
        cout << hashTable[i]->getReceiptNumber() << endl;
        cout << hashTable[i]->getReceiptName() << endl;
        cout << hashTable[i]->getReceiptAmount() << endl;
        cout << "Number of items: " << number << endl;
    }

}

void Hash::printBucketItems(int _index) {
    Receipt *temp = hashTable[_index];
    if(temp->getReceiptNumber() == 0){
        cout << "Bucket " << index << " is Empty"<<endl;
    }else{
        cout << "Bucket " << index << " contains following items"<<endl;
        while( temp != nullptr){
            cout << "-------------\n";
            cout << temp->getReceiptNumber() << endl;
            cout << temp->getReceiptName() << endl;
            cout << temp->getReceiptAmount() << endl;
            temp = temp->next;
        }
    }
}

void Hash::removeItem(int _receiptNumber) {
    int index = hashFunction(_receiptNumber);

    Receipt *deltemp;
    Receipt *temp;
    Receipt *temp2;

    //Case 0 Bucket is Empty;
    if (hashTable[index]->getReceiptNumber() == 0) {
        cout << "Receipt number not found\n";
    }
        //Case 1 Bucket only has 1 item;
    else if (hashTable[index]->getReceiptNumber() == _receiptNumber && hashTable[index]->next == nullptr) {
        hashTable[index] = new Receipt();
        cout << _receiptNumber << " was removed from hashtable\n";
    }
        //case 2 First item match but contains more items
    else if (hashTable[index]->getReceiptNumber() == _receiptNumber && hashTable[index]->next != nullptr) {
        deltemp = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete deltemp;
        cout << _receiptNumber << " was removed from hashtable\n";
    }
        //case 3 Bucket contain items but first item doesn't match
    else{
        temp = hashTable[index]->next;
        temp2 = hashTable[index];
        while(temp != nullptr && temp2->getReceiptNumber() != _receiptNumber){
            temp2 = temp;
            temp = temp->next;
        }
        // case 3.1 look through all but no match
        if(temp == nullptr){
            cout << "Receipt number not found\n";
        }//case 3.2 look through all items and there's a match
        else{
            deltemp = temp;
            temp = temp->next;
            temp2->next = temp;
            delete deltemp;
            cout << _receiptNumber << " was removed from hashtable\n";
        }
    }
}
