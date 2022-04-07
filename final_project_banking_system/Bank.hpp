// Header of the Bank class, it acts like a container of BankAccount
#ifndef BANK_H
#define BANK_H

#include<map>
#include<cstring>
#include<string>

#include"BankAccount.hpp"

class Bank
{
protected:
    std::map<long int, BankAccount *> *accounts;

    static std::string file_name;
    static long int last_account_num;

public:
    // From scratch or from file
    Bank();
    Bank(std::string file_name);

    void toFile(std::string file_name);

    void displayAccounts();
    void displayAccount(int account_num);

    BankAccount * getAccount(long int account_num);

    long int createAccount(std::string name_surname,
                float balance,
                std::string account_type);
    int createAccountFromString(std::string input_string);
    void deleteAccount(int account_num);

    ~Bank();
};

#endif