#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
public:
    virtual void deposit(double amount)=0;
};
class WithdrawalAccount:public DepositOnlyAccount{
public:
    virtual void withdraw(double amount)=0;
};
class SavingsAccount:public WithdrawalAccount{
private:
    double balance;
public:
    SavingsAccount():balance(0){}

    void deposit(double amount) {
        balance+=amount;
        cout<<"Deposited "<<amount<<" in savings Account. new balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(amount<=balance){
            balance-=amount;
            cout<<"Withdrew "<<amount<<" from savings Account. new balance: "<<balance<<endl;
        }else{
            cout<<"Insufficient funds in savings Account."<<endl;
        }            
    }       
};
class CurrentAccount:public WithdrawalAccount{
private:
    double balance;
public:
    CurrentAccount():balance(0){}
    
    void deposit(double amount) {
        balance+=amount;
        cout<<"Deposited "<<amount<<" in current Account. new balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(amount<=balance){
            balance-=amount;
            cout<<"Withdrew "<<amount<<" from current Account. new balance: "<<balance<<endl;
        }else{
            cout<<"Insufficient funds in current Account."<<endl;
        }            
    }
};
class FixedDepositAccount:public DepositOnlyAccount{
private:
    double balance;
public:
    FixedDepositAccount():balance(0){}
    void deposit(double amount) {
        balance+=amount;
        cout<<"Deposited "<<amount<<" in fixed deposit Account. new balance: "<<balance<<endl;
    }
};
class BankClient{
private:
    vector<DepositOnlyAccount*>depositOnlyAccounts;
    vector<WithdrawalAccount*>withdrawalAccounts;
public:
    BankClient(vector<DepositOnlyAccount*> depAccounts,vector<WithdrawalAccount*> withAccounts){
        this->depositOnlyAccounts=depAccounts;
        this->withdrawalAccounts=withAccounts;
    }
    
    void processTransactions(){
        for(WithdrawalAccount* acc:withdrawalAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(DepositOnlyAccount* acc:depositOnlyAccounts){
            acc->deposit(500);
        }
    }
};
int main()
{
    vector<WithdrawalAccount*> withAccounts;
    withAccounts.push_back(new SavingsAccount());
    withAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depAccounts;
    depAccounts.push_back(new FixedDepositAccount());

    BankClient* client=new BankClient(depAccounts,withAccounts);
    client->processTransactions();
    
    return 0;
}