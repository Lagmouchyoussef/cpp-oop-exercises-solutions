#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    
    // Static - same for ALL products
    static double vat;

public:
    Product() {
        id = 0;
        name = "No Name";
        price = 0;
    }
    
    Product(int newId, string newName, double newPrice) {
        id = newId;
        name = newName;
        price = newPrice;
    }
    
    // Static function - works on class, not object
    static void setVAT(double newVat) {
        vat = newVat;
        cout << "VAT changed to " << (vat * 100) << "%" << endl;
    }
    
    // Calculate price with VAT
    double getPriceWithVAT() {
        return price + (price * vat);
    }
    
    void show() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "VAT: " << (vat * 100) << "%" << endl;
        cout << "Total: $" << getPriceWithVAT() << endl;
        cout << "----------" << endl;
    }
    
    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    
    void setId(int newId) { id = newId; }
    void setName(string newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
};

// Initialize static variable
double Product::vat = 0.20;  // 20% VAT

class Store {
private:
    Product* products;  // Dynamic array
    int count;
    int capacity;

public:
    Store() {
        capacity = 10;
        count = 0;
        products = new Product[capacity];
        cout << "Store created with capacity " << capacity << endl;
    }
    
    ~Store() {
        delete[] products;
        cout << "Store closed" << endl;
    }
    
    // Add product
    void addProduct(Product p) {
        if (count >= capacity) {
            cout << "Store is full! Can't add more." << endl;
            return;
        }
        products[count] = p;
        count++;
        cout << "Added: " << p.getName() << endl;
    }
    
    // Remove product by ID
    void removeProduct(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i].getId() == id) {
                cout << "Removing: " << products[i].getName() << endl;
                // Shift all products after this one
                for (int j = i; j < count - 1; j++) {
                    products[j] = products[j + 1];
                }
                count--;
                return;
            }
        }
        cout << "Product ID " << id << " not found!" << endl;
    }
    
    // Modify product
    void modifyProduct(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i].getId() == id) {
                string newName;
                double newPrice;
                
                cout << "Current product:" << endl;
                products[i].show();
                
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                
                cout << "Enter new price: $";
                cin >> newPrice;
                
                products[i].setName(newName);
                products[i].setPrice(newPrice);
                
                cout << "Product updated!" << endl;
                return;
            }
        }
        cout << "Product ID " << id << " not found!" << endl;
    }
    
    // Show all products
    void showAll() {
        cout << "\n=== STORE PRODUCTS (" << count << " items) ===" << endl;
        if (count == 0) {
            cout << "Store is empty!" << endl;
        } else {
            for (int i = 0; i < count; i++) {
                products[i].show();
            }
        }
    }
    
    // Calculate total VAT
    double calculateTotalVAT() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += products[i].getPrice() * 0.20;  // Using VAT rate
        }
        return total;
    }
};

int main() {
    cout << "=== PRODUCT STORE SYSTEM ===" << endl;
    
    Store myStore;
    
    // Create some products
    Product p1(101, "Laptop", 1000);
    Product p2(102, "Mouse", 25);
    Product p3(103, "Keyboard", 50);
    
    // Add to store
    myStore.addProduct(p1);
    myStore.addProduct(p2);
    myStore.addProduct(p3);
    
    // Show all
    myStore.showAll();
    
    // Change VAT
    cout << "\n=== CHANGING VAT ===" << endl;
    Product::setVAT(0.10);  // Change to 10%
    
    // Show again with new VAT
    myStore.showAll();
    
    // Modify a product
    cout << "\n=== MODIFY PRODUCT ===" << endl;
    myStore.modifyProduct(102);
    
    // Show again
    myStore.showAll();
    
    // Remove a product
    cout << "\n=== REMOVE PRODUCT ===" << endl;
    myStore.removeProduct(103);
    
    // Final show
    cout << "\n=== FINAL INVENTORY ===" << endl;
    myStore.showAll();
    cout << "Total VAT to pay: $" << myStore.calculateTotalVAT() << endl;
    
    return 0;
}
