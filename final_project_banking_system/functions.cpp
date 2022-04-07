// All the small functions for the program
#include<iostream>
#include<set>

#include"Bank.hpp"

// Displays all the input options
void display_options()
{
    std::cout<<"\tSelect one option below"<<std::endl;
    std::cout<<"\t1 Open an Account"<<std::endl;
    std::cout<<"\t2 Balance Enquiry"<<std::endl;
    std::cout<<"\t3 Deposit"<<std::endl;
    std::cout<<"\t4 Withdrawal"<<std::endl;
    std::cout<<"\t5 Close an Account"<<std::endl;
    std::cout<<"\t6 Show all Accounts"<<std::endl;
    std::cout<<"\t7 Quit"<<std::endl;
}


void get_input(std::set<int> & allowed_values, int & input_value)
{
    display_options();

    std::cin>>input_value;

    std::cin.ignore();

    // Check if allowed
    // if not get input again
    if (auto value = allowed_values.find(input_value); value == allowed_values.end())
        get_input(allowed_values, input_value);
}

void balance_enquiry(Bank * bank)
{
    std::cout<<"Insert your account number : ";

    long int tmp_account_number;
    std::string tmp_account_string;

    std::getline(std::cin, tmp_account_string);

    tmp_account_number = std::stol(tmp_account_string);

    try
    {
        bank->displayAccount(tmp_account_number);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
    }
}

void open_account(Bank *bank)
{
    std::string name_surname;
    std::string balance_string;
    std::string account_type;

    std::cout<<"Insert name and surname: ";

    std::getline(std::cin, name_surname);

    std::cout<<"How much do you want to deposit? : ";

    std::cin>>balance_string;

    std::cin.ignore();

    std::cout<<"Is it a personal or a business account? : ";

    std::cin>>account_type;

    std::cin.ignore();

    float balance = std::stof(balance_string);

    try
    {
        auto account_num = bank->createAccount(name_surname,
                                        balance,
                                        account_type);

        std::cout<<"Created account N "<<account_num<<std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
    }
}

void deposit(Bank *bank)
{
    long int account_num;
    float ammount;

    std::cout<<"What is yout account number? : ";

    std::cin>>account_num;

    std::cin.ignore();

    std::cout<<"How much do you want to deposit? : ";

    std::cin>>ammount;

    std::cin.ignore();

    try
    {
        auto account = bank->getAccount(account_num);

        try
        {
            account->deposit(ammount);
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
        }

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
    }
}

void withdrow(Bank * bank)
{
    long int account_num;
    float ammount;

    std::cout<<"What is yout account number? : ";

    std::cin>>account_num;

    std::cin.ignore();

    std::cout<<"How much do you want to withdrow? : ";

    std::cin>>ammount;

    std::cin.ignore();

    try
    {
        auto *account = bank->getAccount(account_num);

        try
        {
            account->withdrow(ammount);
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
        }

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
    }
}

void close_account(Bank *bank)
{
    long int account_num;

    std::cout<<"Which account N do you want to close? : ";

    std::cin>>account_num;

    std::cin.ignore();

    try
    {
        bank->deleteAccount(account_num);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr<< "The operation is impossible because of: " << e.what() << std::endl;
    }
}