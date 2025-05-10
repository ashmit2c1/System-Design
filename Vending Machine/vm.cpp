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
class VendingMachine{
    private:
    vector<Item>items;
    int insertedMoney;

    public:
    VendingMachine(){
        insertedMoney=0;
    }
    void addItem(const Item &item){
        items.push_back(item);
    }
    void displayItems(){
        cout << "Availabe items in the machine are as follows [NAME][PRICE][QUANTITY]" << "\n";
        for(int i=0;i<items.size();i++){
            cout << i+1 << " : " << items[i].getName() << " " << items[i].getPrice() << " " << items[i].getQuantity() << "\n";
        }
    }
    void insertMoney(int amount){
        insertedMoney+=amount;
    }
    void selectItem(int index){
        index--;
        if(index>=items.size() || index<0){
            cout << "Invalid Selection" << '\n';
            return;
        }
        Item &selected = items[index];
        if(selected.getQuantity()<=0){
            cout << "Sorry the item is not availabe at the moment" << "\n";
            cout << "Returning the amount you deposited " << insertedMoney <<  "\n";
            return;
        }
        if(insertedMoney<selected.getPrice()){
            cout << "Sorry, please add more money to purchase the item, cancelling transaction" << "\n";
            insertedMoney=0;
            return;
        }
        insertedMoney-=selected.getPrice();
        selected.reduceQuantity();
        cout << "Dispensing " << selected.getName() << "\n";
        if(insertedMoney>0){
            cout << "Returning the change " << insertedMoney << "\n";
            cout << "Thank you" << "\n";
            return;
        }
    }
    void cancelTransaction(){
        cout << "Transaction Cancelled" << "\n";
        insertedMoney=0;
    }
};


int main(){
    Item item1("Chips",20,10);
    Item item2("Juice",20,10);
    Item item3("Chocolate",30,1);
    VendingMachine vm;
    vm.addItem(item1);
    vm.addItem(item2);
    vm.addItem(item3);
    vm.displayItems();
    vm.insertMoney(90);
    vm.selectItem(3);
    vm.selectItem(3);
    vm.selectItem(3);
}