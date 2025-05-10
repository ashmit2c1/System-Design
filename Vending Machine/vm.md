#### Problem Statement 
*Design a vending machine that allows user to view items, insert, money, select an item, and get change back, it should also handle out-of-stock items and insufficient funds*

#### Requirements 
The features that our vending machine should have are as follows
- Show the available products 
- Insert Money 
- Select a product 
- Dispense the product and return the change 
- Handle errors : out of stock, insufficient funds
- Admin functionality : adding new items, refill the stock 

#### Core Classes
- Item / Product 
- Vending Machine 
- Slot 
- Money Manager 

#### `Item` class 
The item class is going to have the following attributes
- Item name - The name of the item 
- price  - The price of the item
- quantity - The number of units of the item in the machine 

```cpp 
class Item{
private:
	string name;
	int price;
	int quantity;
public:
// CONSTRUCTOR
	Item(string name,int price,int quantity){
		this->name=name;
		this->price=price;
		this->quantity=quantity;
	}
};
```

Now we are going to add some methods for the items

- `getPrice()` - will fetch the price of a given item
- `getQuantity()` - will fetch the number of units available of a given item
- `reduceQuantity()` - will reduce the quantity of a given item after purchase is made 
- `addQuantity()` - will add more quantity of the particular item


```cpp 
string getName() const {
	return name
}
void reduceQuantity(){
	if(quantity>0){
		quantity--;
	}
}
void addQuantity(int count){
	quantity+=count;
}
```

#### `VendingMachine`class 
This is going to be the brain class of the program, this will handle the entire logic, the core features of this class are going to be as follows

- A list of items 
- Showing the available items 
- Taking money from the user 
- Handling the selection and purchase logic 
- Giving back the change if needed 

Designing the class as follows

```cpp 
class VendingMachine{
private:
	vector<Item>items;
	int insertedMoney;
public:
	VendingMachine(){
		insertedMoney=0;
	}
};
```

Now that we have defined the data members of the class, we are going to add the methods, the vending machine will have the following methods for now 

- `addItem()` - to add an item in the machine 
- `displayItems()` - to display all the available items in the machine 
- `insertMoney()` - to insert money in the machine to make the purchase
- `selectItem()` - to select an item that is present
- `cancelTransaction()` - to cancel the transaction

```cpp 
void addItem(const Item &item){
	items.push_back(item);
}
void displayItems(){
	cout << "Available items are as follows" << "\n";
	for(int i=0;i<items.size();i++){
		cout << i+1 << << " : " << items[i].getName() <<"\n";
		.... // add all the item information here  
	}
}
void insertMoney(int amount){
	insertedMoney+=amount;
	cout << "You inserted the amount " << amount << " in the machine." << "\n";
}
void selectItem(int index){
	if(index>items.size() || index<0){
		cout << "Invalid Selection" << "\n";
		return;
	}
	Item selected = items[index];
	if(selected.getQuantity()<=0){
		.....
	}
	if(insertedMoney<selected.getPrice()){
		.....
	}
	insertedMoney-=selected.getPrice();
	selected.reduceQuantity();
	cout << "Dispensing" << selected.getName() << "\n";
	if(insertedMoney>0){
		cout << "Returning Change :" << insertedMoney << "\n";
		insertedMoney=0;
		return;
	}
	void cancelTransaction(){
		cout << "Transaction Cancelled" << "\n";
	}
}
```

Now we can test this code in the `main` function 


