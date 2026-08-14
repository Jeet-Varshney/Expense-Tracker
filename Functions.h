#include<iostream>
#include <vector>
#include <string>
using namespace std;
#include "Expenses.h"

void displayExpense(const Expense&Exp);
void displayMenu();
void addexpense(vector<Expense>&expenses);
void viewexpense(vector<Expense>&expenses);
void deleteExpense(vector<Expense>&expenses);
void totalSpendings(vector<Expense>&expenses);
void categorySpendings(vector<Expense>&expenses);
void editExpense(vector<Expense>&expenses);
void searchExpense(vector<Expense>&expenses);
void sortExpenses(vector<Expense>expenses);
