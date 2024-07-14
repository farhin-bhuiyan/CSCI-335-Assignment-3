//Farhin Bhuiyan
#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomerMaxHeap.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Create a CustomerMaxHeap object.
    CustomerMaxHeap heap;

    // Create some Customer objects.
    std::vector<std::string> customer_names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

    // Insert the customers into the heap.
    for (const auto& name : customer_names) {
        Customer customer(name);
        heap.Insert(customer);
    }

    // Print the name of the customer with the highest priority before servicing.
    std::cout << "Max customer before servicing: " << heap.GetMax().GetName() << std::endl;

    // Serve all customers and print the details.
    while (!heap.IsEmpty()) {
        Customer served_customer = heap.DeleteMax();
        std::cout << "Served customer: " << served_customer.GetName()
                  << " with service time: " << served_customer.GetServiceTime() << " minutes" << std::endl;
    }

    // Get the history of served customers
    auto history = heap.GetHistory();

    // Sort history based on service time
    std::sort(history.begin(), history.end(), [](const Customer& a, const Customer& b) {
        return a.GetServiceTime() < b.GetServiceTime();
    });

    // Print sorted history based on service time.
    std::cout << "\nCustomers sorted by service time:\n";
    for (const auto& customer : history) {
        std::cout << "Name: " << customer.GetName() 
                  << ", Priority Level: " << customer.GetPriorityLevel() 
                  << ", Service Time: " << customer.GetServiceTime() 
                  << " minutes\n";
    }

    return 0;
}