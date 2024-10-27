#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Item {
private:
    string name;
    string type;
    double price;
public:
    Item(string name, string type, double price) {
        this->name = name;
        this->type = type;
        this->price = price;
    }

    string getName() {
        return name;
    }

    string getType() {
        return type;
    }

    double getPrice() {
        return price;
    }
};

class Shop {
private:
    vector<Item*> items;
public:
    void addItem(Item* item) {
        items.push_back(item);
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    void displayItems() {
        cout << "Shop Inventory:" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << i << ". " << items[i]->getName() << " - " << items[i]->getType() << " - $" << items[i]->getPrice() << endl;
        }
    }

    Item* getItem(int index) {
        if (index >= 0 && index < items.size()) {
            return items[index];
        }
        return nullptr;
    }

    int getSize() {
        return items.size();
    }
};

void space(){
    for(int i=0;i<=30;i++){
        cout<<endl<<endl;
    }
}

int main() {
    Item* item1 = new Item("Shirt", "Clothing", 19.99);
    Item* item2 = new Item("Pants", "Clothing", 29.99);
    Item* item3 = new Item("Hat", "Accessories", 9.99);
    Item* item4 = new Item("Sunglasses", "Accessories", 10.99);
    Item* item5 = new Item("Credit Card", "Miscellaneous", 250);
    Item* item6 = new Item("Glock 19", "Gun", 499.99);
    Item* item7 = new Item("Double Barrel Shotgun", "Gun", 789.99);
    Item* item8 = new Item("Chiken Sandwich", "Food", 8.60);
    Item* item9 = new Item("Lolipop", "Food", 0.60);

    Shop shop;
    shop.addItem(item1);
    shop.addItem(item2);
    shop.addItem(item3);
    shop.addItem(item4);
    shop.addItem(item5);
    shop.addItem(item6);
    shop.addItem(item7);
    shop.addItem(item8);
    shop.addItem(item9);
    
    
    vector<Item*> inventory;
    double balance = 100.0;
    Item* item;
    
    int choice;
    bool quit = false;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display Inventory" << endl;
        cout << "2. Shop" << endl;
        cout << "3. Sell Item" << endl;
        cout << "4. Add New Item " << endl;
        cout << "5. Remove Item" << endl;
        cout << "6. Order your inventory" << endl;
        cout << "7. Add Balance" << endl;
        cout << "8. Remove Balance" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        string name, type;
        double price;
        Item* newItem;
        int index;

        switch (choice) {
        case 1:
            space();
            cout << "Your Inventory:" << endl;
            for (int i = 0; i < inventory.size(); i++) {
                cout << i << ". " << inventory[i]->getName() << " - " << inventory[i]->getType() << " - $" << inventory[i]->getPrice() << endl;
            }
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        case 2:
            space();
            shop.displayItems();
            cout << "Your balance: $" << balance << endl;
            cout << "Enter the index of the item you want to buy: ";
            int index;
            cin >> index;
            item = shop.getItem(index); // assign value to item
            if (item != nullptr && balance >= item->getPrice()) {
                balance -= item->getPrice();
                inventory.push_back(item);
                    cout << "Item purchased successfully" << endl;
            } else {
                cout << "Unable to purchase item" << endl;
            }
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            space();
            cout << "Your Inventory:" << endl;
            for (int i = 0; i < inventory.size(); i++) {
                cout << i << ". " << inventory[i]->getName() << " - " << inventory[i]->getType() << " - $" << inventory[i]->getPrice() << endl;
            }
            cout << "Enter the index of the item you want to sell:";
            cin >> index;
            if (index >= 0 && index < inventory.size()) {
                Item* item = inventory[index];
                balance += item->getPrice();
                inventory.erase(inventory.begin() + index);
                cout << "Item sold successfully" << endl;
            } else {
                cout << "Invalid index" << endl;
            }
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        case 9:
            quit = true;
            break;
        case 4:
            space();
            cout << "Enter the name of the item: ";
            cin >> name;
            cout << "Enter the type of the item: ";
            cin >> type;
            cout << "Enter the price of the item: ";
            cin >> price;
            newItem = new Item(name, type, price);
            shop.addItem(newItem);
            cout << "Item added successfully" << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;

        case 5:
            shop.displayItems();
            space();
            cout << "Enter the index of the item you want to remove: ";
            cin >> index;
            shop.removeItem(index);
            cout << "Item removed successfully" << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;

        case 6:
            space();
            sort(inventory.begin(), inventory.end(), [](Item* a, Item* b) {
                return a->getPrice() < b->getPrice();
            });
            cout << "Your Inventory (ordered by price):" << endl;
            for (int i = 0; i < inventory.size(); i++) {
                cout << i << ". " << inventory[i]->getName() << " - " << inventory[i]->getType() << " - $" << inventory[i]->getPrice() << endl;
            }
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        case 7: 
            space();
            cout<<"Desired amount to add to your balance:";
            double balancenew;
            cin>>balancenew;
            balance=balance+balancenew;
            cout<<"Your new balance is now: $"<<balance<<endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        case 8: 
            space();
            balance=0;
            cout<<"Your new balance is now: 0$"<<endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        default:
            cout << "Invalid choice" << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        space();
    } while (!quit);

    return 0;
}