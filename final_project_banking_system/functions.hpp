// Header for all the small functions for the program
#include"Bank.hpp"

void display_options();

void get_input(std::set<int> & allowed_values, int & input_value);

void balance_enquiry(Bank *bank);

void open_account(Bank *bank);

void deposit(Bank *bank);

void withdrow(Bank *bank);

void close_account(Bank *bank);
