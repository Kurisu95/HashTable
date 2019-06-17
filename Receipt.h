//
// Created by Christian Rivera on 2019-06-15.
//

#ifndef PRACTICEHASH_RECEIPT_H
#define PRACTICEHASH_RECEIPT_H

#include <string.h>
#include <iostream>;
using namespace std;

class Receipt {
private:
    int receiptNumber;
    string name;
    double amount;
public:
    Receipt();
    Receipt(int _receiptNumber, string _name, double _amount);
    void setReceiptNumber(int _receiptNumber);
    int getReceiptNumber();
    void setReceiptName(string _name);
    string getReceiptName();
    void setReceiptAmount(double _amount);
    double getReceiptAmount();
    Receipt *next;


};


#endif //PRACTICEHASH_RECEIPT_H
