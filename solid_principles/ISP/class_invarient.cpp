#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BankAccount{
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0) throw invalid_argument("balance can not be negative");
        balance=b;
    }
    virtual void withdraw(double amount){
        if(balance-amount<0){
            throw runtime_error("Insufficient Funds");
        }
        balance-=amount;
        cout<<"Amount withdraw. Remaining balance is:"<<balance<<endl;
    }
};
class CheatAccount:public BankAccount{
public:
    CheatAccount(double b):BankAccount(0){}
    virtual void withdraw(double amount) override{
        balance-=amount;
        cout<<"Amount withdraw. Remaining balance is:"<<balance<<endl;
    }
};



int main()
{
    BankAccount* bankAccount=new BankAccount(100);
    bankAccount->withdraw(100);
    return 0;
}