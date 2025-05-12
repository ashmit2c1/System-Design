#include<bits/stdc++.h>
using namespace std;
//ITEM CLASS 
class Item{
    private:
        string name; // name of the item
        int price; // price of the item 
        int quantity; // quantity of the item
    public:
        // default  constructor
        Item(){
            name="";
            price=0;
            quantity=0;
        }
        // parameterised constructor 
        Item(string name,int price,int quantity){
            this->name=name;
            this->price=price;
            this->quantity=quantity;
        }
        // getter function to get the name of the item 
        string getName()const{
            return name;
        }
        // getter function to get the price of the item, const function since it returns constant value 
        int getPrice()const{
            return price;
        }
        // getter function to get the quantity of the item 
        int getQuantity()const{
            return quantity;
        }
        // function to increase the quantity of a particular item
        void increaseQuantity(int count){
            quantity+=count;
        }
        // function to reduce the quantity of item, post purchase 
        void reduceQuantity(){
            quantity--;
        }
};
// VENDING MACHINE CLASS 
class VendingMachine{
    private:
    vector<Item>items; // list of items
    int insertedMoney; // money inserted in the machine 

    public:
    // default constructor 
    VendingMachine(){
        insertedMoney=0;
    }
    // function to add item in the machine
    void addItem(const Item &item){
        items.push_back(item);
    }
    // function to display all the items in the machine
    void displayItems(){
        cout << "Availabe items in the machine are as follows [NAME][PRICE][QUANTITY]" << "\n";
        for(int i=0;i<items.size();i++){
            cout << i+1 << " : " << items[i].getName() << " " << items[i].getPrice() << " " << items[i].getQuantity() << "\n";
        }
    }
    // function to add money in the machine
    void insertMoney(int amount){
        insertedMoney+=amount;
    }
    // function to select an item using the index
    void selectItem(int index){
        index--;
        // check if index is within limits
        if(index>=items.size() || index<0){
            cout << "Invalid Selection" << '\n';
            return;
        }
        // use a reference to the item, if not using refernce, the changes will be made to the copy and not to the original item 
        Item &selected = items[index];
        // check if the item is available
        if(selected.getQuantity()<=0){
            cout << "Sorry the item is not availabe at the moment" << "\n";
            cout << "Returning the amount you deposited " << insertedMoney <<  "\n";
            return;
        }
        // check if we have added enough money 
        if(insertedMoney<selected.getPrice()){
            cout << "Sorry, please add more money to purchase the item, cancelling transaction" << "\n";
            insertedMoney=0;
            return;
        }
        // proceed with the transaction
        insertedMoney-=selected.getPrice();
        selected.reduceQuantity();
        cout << "Dispensing " << selected.getName() << "\n";
        if(insertedMoney>0){
            cout << "Returning the change " << insertedMoney << "\n";
            cout << "Thank you" << "\n";
            return;
        }
    }
    // function to cancel the transaction
    void cancelTransaction(){
        cout << "Transaction Cancelled" << "\n";
        insertedMoney=0;
    }
};


int main(){
    Item item1("Chips,",10,1);
    Item item2("Juice",10,1);
    Item item3("Chocolate",10,1);
    VendingMachine vm;
    vm.addItem(item1);
    vm.addItem(item2);
    vm.addItem(item3);
    vm.insertMoney(8);
    vm.selectItem(1);// output : PLEASE ADD MORE MONEY -> RETURNING 
    vm.insertMoney(10); // 
    vm.selectItem(1); // output : PLEASE COLLECT ITEM -> ITEM INFORMATION
    vm.insertMoney(10);
    vm.selectItem(1); // output : ITEM NOT AVAILABLE -> RETURNING
}