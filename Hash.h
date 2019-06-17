//
// Created by Christian Rivera on 2019-06-15.
//

#ifndef PRACTICEHASH_HASH_H
#define PRACTICEHASH_HASH_H

#include "Receipt.h";

class Hash {
private:
    static const int tableSize = 5;
    Receipt *hashTable[tableSize];
public:
    Hash();
    ~Hash();
    int hashFunction(int key);
    void addItem(Receipt *_Receipt);
    int numberOfItems(int _index);
    void printHashtable();
    void printBucketItems(int _index);
    void removeItem(int _receiptNumber);
};


#endif //PRACTICEHASH_HASH_H
