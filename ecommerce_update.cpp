#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Product
{
    int id;
    string name;
    float price;
    int quantity;

    Product* next;
    Product* hashNext;
};

Product* head = NULL;

const int SIZE = 10;
Product* hashTable[SIZE] = {NULL};

// Hash Function
int hashFunction(int id)
{
    return id % SIZE;
}

// Add Product
void addProduct()
{
    Product* p = new Product;

    cout << "Enter Product ID: ";
    cin >> p->id;

    int index = hashFunction(p->id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == p->id)
        {
            cout << "Product ID already exists!\n";
            delete p;
            return;
        }

        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Product Name: ";
    getline(cin, p->name);

    cout << "Enter Product Price: ";
    cin >> p->price;

    cout << "Enter Product Quantity: ";
    cin >> p->quantity;

    // Insert into Linked List
    p->next = head;
    head = p;

    // Insert into Hash Table
    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Product added successfully!\n";
}

// Update Product
void updateProduct()
{
    int id;

    cout << "Enter Product ID to update: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Product Name: ";
            getline(cin, temp->name);

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Enter New Quantity: ";
            cin >> temp->quantity;

            cout << "Product updated successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Product not found!\n";
}

// Display Products
void displayProducts()
{
    Product* temp = head;

    if (temp == NULL)
    {
        cout << "No products available!\n";
        return;
    }

    cout << "\n----- PRODUCT CATALOG -----\n";

    while (temp != NULL)
    {
        cout << "\nProduct ID: " << temp->id << endl;
        cout << "Product Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;

        temp = temp->next;
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== ONLINE SHOPPING PRODUCT CATALOG =====\n";

        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Display All Products\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                updateProduct();
                break;

            case 3:
                displayProducts();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    // Free Memory
    while (head != NULL)
    {
        Product* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
