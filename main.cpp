#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include "Expenses.h"
#include "FileManager.h"
#include "Functions.h"
using namespace std;

int main(){
    vector<Expense>expenses;
    loadExpense(expenses);
    int choice;
    do {
        displayMenu();
        cin>>choice;
        if(choice==1){
            addexpense(expenses);
        }
        else if(choice==2){
            viewexpense(expenses);
        }
        else if(choice==3){
            deleteExpense(expenses);
        }
        else if(choice==4){
            totalSpendings(expenses);
        }
        else if(choice==5){
            categorySpendings(expenses);
        }
        else if(choice==6){
            editExpense(expenses);
        }
        else if(choice==7){
            searchExpense(expenses);
        }
        else if(choice==8){
            sortExpenses(expenses);
        }
        else if(choice<1 || choice>9){
            cout<<"Invalid Choice!"<<endl;
        }
    }
    while(choice!=9);
    return 0;
}