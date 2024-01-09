#include <iostream>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

vector<Product> inventory;

void addProduct(int id, string name, double price, int quantity) {
    Product product = {id, name, price, quantity};
    inventory.push_back(product);
}

void removeProduct(int id) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].id == id) {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

int main() {
    addProduct(1, "Product 1", 10.99, 100);
    addProduct(2, "Product 2", 20.99, 50);
    addProduct(3, "Product 3", 30.99, 25);

    cout << "Inventory before removal:" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].id << " " << inventory[i].name << " " << inventory[i].price << " " << inventory[i].quantity << endl;
    }

    removeProduct(2);

    cout << "Inventory after removal:" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].id << " " << inventory[i].name << " " << inventory[i].price << " " << inventory[i].quantity << endl;
    }

    return 0;
}

