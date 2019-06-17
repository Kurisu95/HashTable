//
// Created by Christian Rivera on 2019-06-15.
//

#include "Receipt.h"

Receipt::Receipt() {
    setReceiptNumber(0);
    setReceiptName("empty");
    setReceiptAmount(0.00);
    next = nullptr;
}

Receipt::Receipt(int _receiptNumber, string _name, double _amount) {
    setReceiptNumber(_receiptNumber);
    setReceiptName(_name);
    setReceiptAmount(_amount);
    next = nullptr;
}

void Receipt::setReceiptNumber(int _receiptNumber) {
    receiptNumber = _receiptNumber;
}

int Receipt::getReceiptNumber() {
    return receiptNumber;
}

void Receipt::setReceiptName(string _name) {
    name = _name;
}

string Receipt::getReceiptName() {
    return name;
}

void Receipt::setReceiptAmount(double _amount) {
    amount = _amount;
}

double Receipt::getReceiptAmount() {
    return amount;
}