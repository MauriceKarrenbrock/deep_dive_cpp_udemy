// Bank class, it acts like a container of BankAccount
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<exception>
#include<map>
#include<sstream>
#include<vector>

#include"Bank.hpp"
#include"BankAccount.hpp"

std::string Bank::file_name = "Backup_bank_file.bkp";

long int Bank::last_account_num = 0;

Bank::Bank()
{
    this->accounts = new std::map<long int, BankAccount *>();
}

Bank::Bank(std::string file_name)
{
    if (file_name.empty())
    {
        file_name = Bank::file_name;
    }
    
    // Overwrite the default value
    this->file_name = file_name;

    this->accounts = new std::map<long int, BankAccount *>();

    std::fstream file;

    file.open(file_name, std::ios::in);

    if (file.is_open())
    {
        std::string account_string;

        // Bank info are on the first line
        std::getline(file, account_string);

        std::stringstream ss(account_string);
        std::vector<std::string> tmp_list;

        int num_of_parameters = 2;

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

        this->last_account_num = std::stol(tmp_list[0]);
        this->file_name = tmp_list[1];

        // Get account info
        while (std::getline(file, account_string))
        {
            if (! account_string.empty())
                this->createAccountFromString(account_string);
        }
    }
    else
        throw std::ios_base::failure("File not found = " + file_name);

    file.close();
}

void Bank::toFile(std::string file_name)
{
    std::fstream file;

    file.open(file_name, std::ios::out);
   
    file << std::to_string(Bank::last_account_num) << "," << this->file_name << std::endl;

    if (! this->accounts->empty())
    {
        //Iterate through the accounts
        for (std::map<long int, BankAccount *>::iterator it = this->accounts->begin();
            it != this->accounts->end();
            it ++)
        {
            //Get account to string and write one string per line
            file << it->second->toString() << std::endl;
        }
    }

    file.close();
}

void Bank::displayAccounts()
{
    std::cout<<"List of all the bank accounts"<<std::endl;

    for (std::map<long int, BankAccount *>::iterator it = this->accounts->begin();
        it != this->accounts->end();
        it ++)
    {
        it->second->display();
        std::cout<<std::endl;
    }
}
void Bank::displayAccount(int account_num)
{
    if (auto account = this->accounts->find(account_num); account != this->accounts->end())
        account->second->display();
    
    else
        throw std::invalid_argument("Account number " + std::to_string(account_num) + " is not a valid accopunt value");
}

BankAccount * Bank::getAccount(long int account_num)
{
    if (auto account = this->accounts->find(account_num); account != this->accounts->end())
        return account->second;
    
    else
        throw std::invalid_argument("Account number " + std::to_string(account_num) + " is not a valid accopunt value");
}

long int Bank::createAccount(std::string name_surname,
                float balance=0.f,
                std::string account_type="personal")
{
    auto tmp_account_num = this->last_account_num + 1;

    auto * account = new BankAccount(tmp_account_num,
                            name_surname,
                            balance,
                            account_type);

    if (auto tmp_pair = this->accounts->insert({tmp_account_num, account}); !tmp_pair.second)
    {
        throw std::runtime_error("Could not insert the new account with account number" + std::to_string(tmp_account_num));
    }

    this->last_account_num += 1;

    return this->last_account_num;
}

int Bank::createAccountFromString(std::string input_string)
{
    auto *account = new BankAccount(input_string);

    this->accounts->insert({account->getAccountNum(), account});

    return account->getAccountNum();
}

void Bank::deleteAccount(int account_num)
{
    if (!this->accounts->erase(account_num))
        throw std::invalid_argument("Account number " + std::to_string(account_num) + " is not a valid accopunt value");
}


Bank::~Bank()
{
    toFile(this->file_name);


    for (std::map<long int, BankAccount *>::iterator it = this->accounts->begin();
        it != this->accounts->end();
        it ++)
    {
        delete it->second;
    }


    delete this->accounts;
}

