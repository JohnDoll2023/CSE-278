/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.cpp
 * Author: cse278
 * Copyright 2020 John Doll
 * Created on September 30, 2020, 7:44 PM
 */

#include "SavingsAccount.h"
#include <string>

using namespace std;

SavingsAccount::SavingsAccount(const string name, const double money, 
        const string street, const double rate): 
        BankAccount(name, money, street), rate(rate) {
    this->rate = rate;
}

void SavingsAccount::setInterestRate(const double rate) {
    this->rate = rate;
}

double SavingsAccount::getInterestRate() {
    return this->rate;
}
