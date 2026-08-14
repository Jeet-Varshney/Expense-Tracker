
#include <iostream>
#include <vector>
#include <fstream>
#include "Expenses.h"

using namespace std;

void saveExpense(vector<Expense>&expenses){
    ofstream f("expenses.txt");
    if(f.is_open()){
        for(const auto &Exp:expenses){
            f<<Exp.amount<<"|";
            f<<Exp.category<<"|";
            f<<Exp.description<<"|";
            f<<Exp.date<<"\n";
        }
        f.close();
        cout<<"Expenses saved successfully!\n";
    }
    else{
        cout<<"Failed to open file!\n";
    }
}
void loadExpense(vector<Expense>&expenses){
    ifstream f("expenses.txt");
    if(f.is_open()){
        string line;
        while(getline(f,line,'|')){
            Expense Exp;
            Exp.amount=stoi(line);
            getline(f,Exp.category,'|');
            getline(f,Exp.description,'|');
            getline(f,Exp.date);
            expenses.push_back(Exp);
        }
    }
}