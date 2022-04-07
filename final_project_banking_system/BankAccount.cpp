// BankAccount implementation from BankAccount.hpp
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
#include<exception>
#include<vector>

#include"BankAccount.hpp"

BankAccount::BankAccount()
{
    this->account_num = -1;
    this->setNameSurname("Not defined");
    this->setBalance(0);
    this->setAccountType("Not defined");
}

BankAccount::BankAccount(long int account_num,
            std::string name_surname,
            float balance=0.f,
            std::string account_type="personal")
{
    this->account_num = account_num;
    this->setNameSurname(name_surname);
    this->setBalance(balance);
    this->setAccountType(account_type);
}

BankAccount::BankAccount(std::string input_string)
{
    if (input_string.empty()) 
        throw std::invalid_argument("Can not create a BankAccount with an empty string");

    std::stringstream ss(input_string);
    std::vector<std::string> tmp_list;

    int num_of_parameters = 4;

    // Comma separated list
    while( ss.good() )
    {
        std::string substr;

        std::getline( ss, substr, ',' );

        tmp_list.push_back( substr );
    }

    if ((int) tmp_list.size() != num_of_parameters)
        throw std::invalid_argument("The comma separated string should contain " +
            std::to_string(num_of_parameters) +
            " paremeters, but instead there are " + std::to_string(tmp_list.size()));

    /* Input parameters:
    long int account_num
    std::string name_surname
    float balance
    std::string account_type
    */

    this->account_num = std::stoi(tmp_list[0]);
    this->setNameSurname(tmp_list[1]);
    this->setBalance(std::stof(tmp_list[2]));
    this->setAccountType(tmp_list[3]);
}

std::string BankAccount::toString()
{
    /* Order:
    long int account_num
    std::string name_surname
    float balance
    std::string account_type
    */
   
   return (std::to_string(this->getAccountNum()) +
        "," +
        this->getNameSurname() +
        "," +
        std::to_string(this->getBalance()) +
        "," +
        this->getAccountType());
}

void BankAccount::display()
{
    std::cout<<"*Bank Account*"<<std::endl;
    std::cout<<"Account number = "<<this->getAccountNum()<<std::endl;
    std::cout<<"Name and surname = "<<this->getNameSurname()<<std::endl;
    std::cout<<"Balance = "<<this->getBalance()<<std::endl;
    std::cout<<"Account type = "<<this->getAccountType()<<std::endl;
    std::cout<<"Min allowed balance = "<<this->getMinimumAlloedBalance()<<std::endl;
}

float BankAccount::getBalance()
{
    return this->balance;
}

void BankAccount::setBalance(float balance)
{
    if (balance < this->getMinimumAlloedBalance())
    {
        throw std::invalid_argument("The minimum allowed balance for this type of account is " + 
        std::to_string(this->getMinimumAlloedBalance()) +
        "but you are trying to deposit less");
    }
    
    this->balance = balance;
}

void BankAccount::deposit(float amount)
{
    if (amount <= 0.f)
    {
        throw std::invalid_argument("You have to deposit more than zero");
    }

    this->setBalance(amount + this->getBalance());
}

void BankAccount::withdrow(float amount)
{
    auto balance_after = this->getBalance() - amount;

    if (balance_after < this->getMinimumAlloedBalance())
    {
       throw std::invalid_argument("You are trying to withdrow too much"); 
    }

    this->setBalance(balance_after);
}

void BankAccount::setMinimumAlloedBalance(float value)
{
    this->miminum_allowed_balance = value;
}

float BankAccount::getMinimumAlloedBalance()
{
    return this->miminum_allowed_balance;
}

std::string BankAccount::getAccountType()
{
    return this->account_type;
}

void BankAccount::setAccountType(std::string type)
{
    this->account_type = type;
}

long int BankAccount::getAccountNum()
{
    return this->account_num;
}

void BankAccount::setNameSurname(std::string name_surname)
{
    if (name_surname.empty())
    {
        throw std::invalid_argument("You can not imput an empty string as name and surname"); 
    }

    this->name_surname = name_surname;
}

std::string BankAccount::getNameSurname()
{
    return this->name_surname;
}
