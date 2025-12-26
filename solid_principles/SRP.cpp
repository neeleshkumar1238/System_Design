#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Product{
public:
    string name;
    double price;

    Product(string name,double price){
        this->name=name;
        this->price=price;
    }

};
class ShoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};
class ShoppingCartPrinter{
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }

    void printInvoice(){
        cout<<"Shopping cart invoice"<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};
class shoppingCartStorage{
private:
    ShoppingCart* cart;
public:
    shoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
    }
  
    void saveToDatabase(){
        cout<<"Saving shopiing cart to databse..."<<endl;
    }
};
int main()
{
    ShoppingCart* cart=new ShoppingCart();

    cart->addProduct(new Product("Laptop",75000));
    cart->addProduct(new Product("LCD",10000));

    ShoppingCartPrinter* printer=new ShoppingCartPrinter(cart);
    printer->printInvoice();

    shoppingCartStorage* db=new shoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;
}