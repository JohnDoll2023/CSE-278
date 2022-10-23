/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BankAccount.cpp
 * Author: cse278
 * Copyright 2020 John Doll
 * Created on September 30, 2020, 7:13 PM
 */

#include "BankAccount.h"
#include <string>

using namespace std;

BankAccount::BankAccount(const string name, const double money, 
        const string street) {
    this->name = name;
    this->money = money;
    this->street = street;
}

void BankAccount::depositMoney(const double money) {
    this->money += money;
}

void BankAccount::withdrawMoney(const double money) {
    this->money -= money;
}

void BankAccount::updateAddress(const string street) {
    this->street = street;
}

double BankAccount::getBalance() {
    return this->money;
}

string BankAccount::getAddress() {
    return this->street;
}
