// The main function for the banking system program
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<exception>

#include"functions.hpp"
#include"Bank.hpp"
#include"BankAccount.hpp"

int main()
{
    std::cout<<"Welcome to the banking system program"<<std::endl;

    int input_value;

    std::set<int> allowed_values = {1, 2, 3, 4, 5, 6, 7};

    Bank *bank;

    // Try to get from backup file otherwise start from scratch
    try
    {
        bank = new Bank("");
    }
    catch(const std::ios_base::failure& e)
    {
        std::cout<<"Did not find a backup file, creating Bank from scratch"<<std::endl;

        bank = new Bank();
    }

    while (true)
    {
        bool break_while = false;

        // Overwrites input_value
        get_input(allowed_values, input_value);

        switch (input_value)
        {
        case 1:
            /* Open an Account */
            open_account(bank);

            break;

        case 2:
            /* Balance Enquiry */
            balance_enquiry(bank);

            break;

        case 3:
            /* Deposit */
            deposit(bank);

            break;

        case 4:
            /* Withdrawal */
            withdrow(bank);

            break;

        case 5:
            /* Close an Account */
            close_account(bank);
            
            break;

        case 6:
            /* Show all Accounts */
            bank->displayAccounts();

            break;

        case 7:
            /* Quit */
            break_while = true;

            break;
        
        default:
            std::cerr<<"Unexpected error!"<<std::endl;

            throw std::bad_exception();

            break;
        }

        if (break_while)
            break;
    }

    delete bank;

    std::cout<<"Program closed correctly"<<std::endl;

    return 0;
}