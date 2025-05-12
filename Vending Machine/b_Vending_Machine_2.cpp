#include<bits/stdc++.h>
using namespace std;
// ITEM CLASS
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
// MONEY MANAGER CLASS 
class MoneyManager{
    private:
        int insertedMoney; // money inserted to machine
        int totalEarnings; // total money made during the day
    public:
        // default constructor 
        MoneyManager(){
            insertedMoney=0;
            totalEarnings=0;
        }
        // function to insert money in the money manager class from the vending machine
        void insertMoney(int amnt){
            insertedMoney+=amnt;
        }
        // function to check if the money inserted is enough to purchase the selected item
        // the price will be passed as a parameter through the VendingMachine class 
        bool isSufficient(int price){
            if(insertedMoney>=price){
                return true;
            }else{
                return false;
            }
        }
        // function to deduct money from the insertedmoney and add that to totalearnings
        void deduct(int price){
            insertedMoney-=price;
            totalEarnings+=price;
        }
        // function to return change ( if any )
        int returnChange(){
            int change=insertedMoney;
            insertedMoney=0;
            return change;
        }
        // function to cancel the transaction, return the entire inserted money 
        void cancelTransaction(){
            cout << "RETURNING : " << insertedMoney << "\n";
            insertedMoney=0;
            return; 
        }
        // function to get the total earnings
        int getTotalEarnings() const {
            return totalEarnings;
        }
};
// VENDING MACHINE 
class VendingMachine{
    private:
        vector<Item>items; // list of items inside the machine
        MoneyManager moneyManager; // money manager for the machine will handle the logic of transaction
    public:
        // function to add item in the machine, will use a template of the item
        void addItem(Item &item){
            items.push_back(item);
        }
        // function to display all the items in machine 
        void displayItems(){
            cout << "DISPLAYING ITEMS" << "\n";
            cout << "[NAME][PRICE][QUANTITY]" << "\n";
            for(int i=0;i<items.size();i++){
                cout << items[i].getName() << " " << items[i].getPrice() << " " << items[i].getQuantity() << "\n";
            }
        }
        // function to insert money in the machine, will pass this to money manager
        void insertMoney(int amount){
            moneyManager.insertMoney(amount);
        }
        // function to select a particular item using the index
        void selectItem(int index){
            index--;
            // check if the index is within limits
            if(index<0 || index>items.size()){
                cout << "INVALID SELECTION" << "\n";
                cout << "RETURNING MONEY : " << moneyManager.returnChange() << "\n";
            }
            Item &selected = items[index]; // use a reference of the selected item, reason is that once the quantity is reduced , the quantity is reduced of the original item and not on copy
            // check if the item is available
            if(selected.getQuantity()<=0){
                cout << "UNFORTUNATELY ITEM NOT AVAILABLE" << "\n";
                cout << "RETURNING : " << moneyManager.returnChange() << "\n";
                return;
            }
            // check if we added enough money 
            if(moneyManager.isSufficient(selected.getPrice())==false){
                cout << "PLEASE ADD MORE MONEY TO PURCHASE THE ITEM" << "\n";
                cout << "RETURNING : " << moneyManager.returnChange() << "\n";
                return;
            }
            // proceed with the transaction
            cout << "PLEASE COLLECT YOUR ITEM" << "\n";
            cout << selected.getName() << " PRICE " << selected.getPrice() << "\n";  
            selected.reduceQuantity();
            moneyManager.deduct(selected.getPrice());
            int change = moneyManager.returnChange();
            if(change>0){
                cout << "PLEASE COLLECT YOUR CHANGE " << moneyManager.returnChange() << "\n"; 
                return;
            }
        }
        // cancel transaction
        void cancel(){
            moneyManager.cancelTransaction();
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