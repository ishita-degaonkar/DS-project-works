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

// Remove Product
void deleteProduct()
{
    int id;

    cout << "Enter Product ID to delete: ";
    cin >> id;

    int index = hashFunction(id);

    // Search in Hash Table
    Product* temp = hashTable[index];
    Product* prev = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            break;
        }

        prev = temp;
        temp = temp->hashNext;
    }

    if (temp == NULL)
    {
        cout << "Product not found!\n";
        return;
    }

    // Delete from Hash Table
    if (prev == NULL)
    {
        hashTable[index] = temp->hashNext;
    }
    else
    {
        prev->hashNext = temp->hashNext;
    }

    // Delete from Linked List
    if (head == temp)
    {
        head = temp->next;
    }
    else
    {
        Product* current = head;

        while (current != NULL && current->next != temp)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            current->next = temp->next;
        }
    }

    delete temp;

    cout << "Product deleted successfully!\n";
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
        cout << "2. Remove Product\n";
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
                deleteProduct();
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
