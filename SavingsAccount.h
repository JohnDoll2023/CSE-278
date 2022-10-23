/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.h
 * Author: cse278
 * Copyright 2020 John Doll
 * Created on September 30, 2020, 7:44 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <string>

using namespace std;

#endif /* SAVINGSACCOUNT_H */

class SavingsAccount: public BankAccount {
public:
    SavingsAccount(const string name = "", const double money = 0,
            const string street = "", const double rate = 0);
    void setInterestRate(const double);
    double getInterestRate();
private:
    double rate;
};
