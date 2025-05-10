#include<bits/stdc++.h>
using namespace std;


//ITEM CLASS 
class Item{
    private:
    string name;
    int price;
    int quantity;

    public:
    // constructor
    Item(string name,int price,int quantity){
        this->name=name;
        this->price=price;
        this->quantity=quantity;
    }
    string getName()const{
        return name;
    }
    int getPrice() {
        return price;
    }
    int getQuantity(){
        return quantity;
    }
    void reduceQuantity(){
        quantity--;
    }
    void addQuantity(int count){
        quantity+=count;
    }
};
// VENDING MACHINE CLASS 
