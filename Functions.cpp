#include<iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include "Functions.h"  
#include "Expenses.h"
#include "FileManager.h"
#include <string>

using namespace std;


void displayExpense(const Expense&Exp){
    cout<<"Amount: "<<Exp.amount<<endl;
    cout<<"Category: "<<Exp.category<<endl;
    cout<<"Description: "<<Exp.description<<endl;
    cout<<"Date: "<<Exp.date<<endl;
    cout<<"\n";
}
void displayMenu(){
    cout << "\n=== Expense Tracker ==="<<endl;
    cout << "1. Add Expense"<<endl;
    cout << "2. View Expenses"<<endl;
    cout << "3. Delete Expense"<<endl;
    cout << "4. Total Spendings"<<endl;
    cout << "5. Category Spendings"<<endl;
    cout << "6. Edit Expense"<<endl;
    cout << "7. Search Expense"<<endl;
    cout << "8. Sort Expense"<<endl;
    cout << "9. Exit"<<endl;
    cout << "Enter your choice: ";
}
void addexpense(vector<Expense>&expenses){
    Expense Exp;
    cout<<"Enter Amount: ";
    cin>>Exp.amount;
    while(cin.fail()||Exp.amount<=0||cin.peek()!='\n'){
        cout<<"Invalid input! Amount must be a positive number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin>>Exp.amount;
    }
    cout<<"Enter Category: ";
    cin>>Exp.category;
    cin.ignore();
    cout<<"Enter Date(DD-MM-YYYY): ";
    getline(cin,Exp.date);
    //check if date is valid
    if(Exp.date.length()!=10||Exp.date[2]!='-'||Exp.date[5]!='-'||!isdigit(Exp.date[0])||!isdigit(Exp.date[1])||!isdigit(Exp.date[3])||!isdigit(Exp.date[4])||!isdigit(Exp.date[6])||!isdigit(Exp.date[7])||!isdigit(Exp.date[8])||!isdigit(Exp.date[9])){
        cout<<"Invalid Date! format must be DD-MM-YYYY!!"<<endl;
        return;
    }
    cout<<"Enter Description: ";
    getline(cin, Exp.description);
    expenses.push_back(Exp);
    cout<<"Expense added successfully!"<<endl;
    saveExpense(expenses);
}
void viewexpense(vector<Expense>&expenses){
    if (expenses.size() == 0){
        cout<<"No expenses found!"<<endl;
        return;
    }
    for(int i=0;i<expenses.size();i++){
        cout<<"Expense "<<i+1<<": \n";
        displayExpense(expenses[i]);
    }
}
void deleteExpense(vector<Expense>&expenses){
    if(expenses.size()==0){
        cout<<"No expenses found!"<<endl;
        return;
    }
    int n;
    cout<<"Enter the Expense number to be deleted: ";
    cin>>n;
    if(n<=0||n>expenses.size()){
        cout<<"Invalid Expense number!"<<endl;
        return;
    }
    expenses.erase(expenses.begin()+(n-1));
    saveExpense(expenses);
    cout<<"Expense Deleted"<<endl;
}
void totalSpendings(vector<Expense>&expenses){
    int total=0;
// Use const auto& to avoid copying each Expense while ensuring it cannot be modified
    for(const auto& Exp : expenses){
        total+=Exp.amount;
    }
    cout<<"Total Spendings: "<<total<<endl;
}
void categorySpendings(vector<Expense>&expenses){
    int total=0,f=0;
    string x;
    cout<<"Enter the Category: ";
    cin>>x;
    for(const auto& e:expenses){
        if(e.category==x){
            total+=e.amount;
            f++;
        }
    }
    if(f==0){
        cout<<"No expenses found in Category "<<x<<endl;
    }
    else{
        cout<<"Total Spendings in Category "<<x<<": "<<total<<endl;
    }
}
void editExpense(vector<Expense>&expenses){
    cout<<"Enter Expense:";
    int n,f=0;
    cin>>n;
    if(n>expenses.size()||n<=0){
        cout<<"Invalid Expense number!"<<endl;
        return;
    }
    else{
        int c;
        cout<<"Expense "<<n<<endl;
        cout<<"1.Edit Amount"<<endl;
        cout<<"2.Edit Category"<<endl;
        cout<<"3.Edit Description"<<endl;
        cout<<"4.Edit Date"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>c;
        if(c==1){
            cout<<"Enter New Amount: ";
            cin>>expenses[n-1].amount;
            f=1;
        }
        else if (c==2){
            cout<<"Enter New Category: ";
            cin>>expenses[n-1].category;
            f=1;
        }
        else if (c==3){
            cout<<"Enter New Description: ";
            cin.ignore();
            getline(cin,expenses[n-1].description);
            f=1;
        }
        else if (c==4){
            cout<<"Enter New Date: ";
            cin>>expenses[n-1].date;
            f=1;
        }
        else{
            cout<<"Invalid Choice!"<<endl;
        }
        if(f==1){
            cout<<"Expense Edited Successfully!"<<endl;
        }
    }
}
void searchExpense(vector<Expense>&expenses){
    cout<<"1.Search by category"<<endl;
    cout<<"2.Search by description"<<endl;
    cout<<"3.Search by date"<<endl;
    cout<<"Enter your choice: ";
    int c;
    bool found=false;
    cin>>c;
    if(c==1){
        string s;
        cout<<"Enter Category: ";
        cin>>s;
        for(int i=0;i<expenses.size();i++){
            if(expenses[i].category==s){
                cout<<"Expense: "<<i+1<<":\n";
                displayExpense(expenses[i]);
                found=true;
            }
        }
        if(found==false){
            cout<<"No expenses found in Category "<<s<<endl;
        }
    }
    else if (c==2){
        string s;
        cout<<"Enter Description: ";
        cin.ignore();
        getline(cin,s);
        for(int i=0;i<expenses.size();i++){
            if(expenses[i].description==s){
                cout<<"Expense: "<<i+1<<":\n";
                displayExpense(expenses[i]);
                found=true;
            }
        }
        if(found==false){
            cout<<"No expenses found in Description "<<s<<endl;
        }
    }
    else if (c==3){
        string s;
        cout<<"Enter Date: ";
        cin>>s;
        for(int i=0;i<expenses.size();i++){
            if(expenses[i].date==s){
                cout<<"Expense: "<<i+1<<":\n";
                displayExpense(expenses[i]);
                found=true;
            }
        }
        if(found==false){
            cout<<"No expenses found in Date "<<s<<endl;
        }
    }
    else{
        cout<<"Invalid Choice!"<<endl;
    }
}
void sortExpenses(vector<Expense>expenses){
    int n;
    cout<<"Enter order to be sorted: \n";
    cout<<"1.Highest to Lowest"<<endl;
    cout<<"2.Lowest to Highest"<<endl;
    cin>>n;
        
    if(n==1){
        sort(expenses.begin(),expenses.end(),[] ( const Expense &a,const Expense &b){return a.amount>b.amount;});
        for(int i=0;i<expenses.size();i++){
            cout<<"Expense: "<<i+1<<":\n";
            displayExpense(expenses[i]);
        }
    }
    else if (n==2){
        sort(expenses.begin(),expenses.end(),[] ( const Expense &a,const Expense &b){return a.amount<b.amount;});
        for(int i=0;i<expenses.size();i++){
            cout<<"Expense: "<<i+1<<":\n";
            displayExpense(expenses[i]);
        }
    }
    else{
        cout<<"Invalid Choice!\n";
    }
}