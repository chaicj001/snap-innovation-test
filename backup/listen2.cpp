#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the Order structure
struct Order {
    int orderid;
    string symbol;
    double price;
    int quantity;
};

int main() {
    vector<Order> orders;

    // Add orders to the vector
    orders.push_back({1, "AAPL", 100.0, 10});
    orders.push_back({2, "AAPL", 110.0, 1});
    orders.push_back({3, "GOOG", 2000.0, 7});
    orders.push_back({4, "AAPL", 110.0, 5});

    // Searching for orders with a specific symbol and price
    string searchSymbol = "AAPL";
    double searchPrice = 110.0;

for (auto it = orders.begin(); it != orders.end();) {
    if (it->symbol == searchSymbol && it->price == searchPrice) {
        it->quantity = it->quantity - 1;
        cout << "Found Order - Order ID: " << it->orderid << ", Quantity: " << it->quantity << endl;
        
        if (it->quantity == 0) {
            // If quantity reaches 0, erase the element
            it = orders.erase(it);
        } else {
            ++it; // Move to the next element
    }
    } else {
        ++it; // Move to the next element
    }
}

    for (Order& order : orders) {
        cout << "Found Order - Order ID: " << order.orderid << ", Quantity: " << order.quantity << endl; 
    }

    return 0;
}