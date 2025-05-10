#include<bits/stdc++.h>
using namespace std;


//ITEM CLASS 
class Item{
    private:
    string name;
    int price;
    int quantity;

    public:
    // constructro 
    Item(){
        name="";
        price=0;
        quantity=0;
    }
    // constructor ( parameterised)
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
class MoneyManager{
    private:
    int insertedMoney;
    int totalEarnings;
    public:
    MoneyManager(){
        insertedMoney=0;
        totalEarnings=0;
    }
    void insertMoney(int amount){
        insertedMoney+=amount;
        cout << "Inserted " << amount << " in the vending machine" << "\n";
    }
    bool isSufficient(int price)const {
        if(insertedMoney>=price){
            return true;
        }else{
            return false;
        }
    }
    void deduct(int price){
        insertedMoney-=price;
        totalEarnings+=price;
    }
    int returnChange(){
        int change=insertedMoney;
        insertedMoney=0;
        return change;
    }
    void cancelTransaction(){
        cout << "Returning : " << insertedMoney << "\n";
        insertedMoney=0;
    }
    int getTotalEarnings()const{
        return totalEarnings;
    }
};
class Slot{
    private:
    Item item;
    public:
    Slot(Item item){
        this->item=item;
    }
    Item& getItem(){
        return item;
    }
    void refill(int quantity){
        item.addQuantity(quantity);
    }
    bool isEmpty(){
        if(item.getQuantity()<=0){
            return true;
        }else{
            return false;
        }
    }
};
// VENDING MACHINE CLASS 
class VendingMachine{
    private:
    vector<Slot>slots;
    MoneyManager moneyManager;
    public:
    void addSlot(const Slot&slot){
        slots.push_back(slot);
    }
    void displayItems(){
        cout << "Displaying Items [NAME][PRICE][QUANTITY]" << "\n";
        for(int i=0;i<slots.size();i++){
            Item &item = slots[i].getItem();
            cout << i+1 << item.getName() << " " << item.getPrice() << " " << item.getQuantity() << "\n"; 
        }
    }
    void insertMoneyVM(int amount){
        moneyManager.insertMoney(amount);
    }
    void selectItem(int index){
        index--;
        if(index<0 || index>=slots.size()){
            cout << "Invalid selection" << "\n";
            cout << "Returning the amount " << moneyManager.returnChange() << "\n";
        }
        Item &selected = slots[index].getItem();
        if(selected.getQuantity()<=0){
            cout << "Item is not available at the moment" << "\n";
            cout << "Returning money " << moneyManager.returnChange() << "\n";
            return;
        }
        if(moneyManager.isSufficient(selected.getPrice())==false){
            cout << "Please add more money" << "\n";
            cout << "Returning money" << " " << moneyManager.returnChange() << "\n";
            return;
        }
        moneyManager.deduct(selected.getPrice());
        selected.reduceQuantity();
        cout << "Dispensing " << selected.getName() << "\n";
        int change = moneyManager.returnChange();
        if(change>0){
            cout << "Returning change " << change << "\n";
        }
    }
    void showTotalEarnings(){
        cout <<  moneyManager.getTotalEarnings() << "\n";
    }
};


int main(){
    Item item1("Chips",10,1);
    Item item2("Juice",25,2);
    Item item3("Chocolates",25,1);
    Slot s1(item1);
    Slot s2(item2);
    Slot s3(item3);
    VendingMachine vm;
    vm.addSlot(s1);
    vm.addSlot(s2);
    vm.addSlot(s3);
    vm.insertMoneyVM(25);
    vm.selectItem(2);

}