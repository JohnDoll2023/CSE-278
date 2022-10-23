/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BankAccount.h
 * Author: cse278
 * Copyright 2020 John Doll
 * Created on September 30, 2020, 7:13 PM
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

using namespace std;

#endif /* BANKACCOUNT_H */

class BankAccount {
public:
    BankAccount(const string name = "", const double money = 0, 
            const string street = "");
    void depositMoney(const double);
    void withdrawMoney(const double);
    void updateAddress(const string);
    double getBalance();
    string getAddress();
private:
    string name;
    double money;
    string street;
};
