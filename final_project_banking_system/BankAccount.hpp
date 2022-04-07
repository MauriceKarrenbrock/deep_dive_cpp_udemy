// Header file of the BankAccount class
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<exception>

class BankAccount
{
protected:
    long int account_num;
    std::string name_surname;
    float balance;
    float miminum_allowed_balance = 0.f;
    std::string account_type; //Like personal, company, ...

public:
    BankAccount();
    BankAccount(long int account_num,
                std::string name_surname,
                float balance,
                std::string account_type);
    BankAccount(std::string input_string);

    std::string toString();

    void display();

    float getBalance();
    void setBalance(float balance);

    void deposit(float amount);

    void withdrow(float amount);

    void setMinimumAlloedBalance(float value);
    float getMinimumAlloedBalance();

    std::string getAccountType();
    void setAccountType(std::string type);

    long int getAccountNum();

    void setNameSurname(std::string name_surname);
    std::string getNameSurname();
};

#endif
