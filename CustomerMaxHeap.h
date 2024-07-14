//Farhin Bhuiyan
#ifndef CUSTOMER_MAX_HEAP_H
#define CUSTOMER_MAX_HEAP_H

#include <algorithm>
#include <vector>
#include "MaxHeap.h"
#include "Customer.h"

// CustomerMaxHeap class declaration, derived from MaxHeap<Customer>.
class CustomerMaxHeap : public MaxHeap<Customer> {
public:
    // Delete the maximum customer (highest priority) from the heap, set their service time, and add to history.
    Customer DeleteMax();

    // Get the history of served customers.
    const std::vector<Customer>& GetHistory() const { return history_; }

private:
    // Vector to store the history of served customers.
    std::vector<Customer> history_;
};

// Delete the maximum customer (highest priority) from the heap, set their service time, and add to history.
Customer CustomerMaxHeap::DeleteMax() {
    // Call base class DeleteMax() to get the customer with the highest priority.
    Customer max_customer = MaxHeap::DeleteMax();

    // Set the service time for the deleted customer.
    max_customer.SetServiceTime();

    // Add the deleted customer to the history.
    history_.push_back(max_customer);

    // Return the deleted customer.
    return max_customer;
}

#endif // CUSTOMER_MAX_HEAP_H