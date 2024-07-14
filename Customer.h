//Farhin Bhuiyan
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <cstdlib>

// Customer class declaration.
class Customer {
public:
    // Constructor that initializes a Customer with a given name and sets the priority level.
    Customer(const std::string& name);

    // Set the priority level to a random integer between 0 and 100.
    void SetPriorityLevel();

    // Set the service time to a random integer between 0 and 60.
    void SetServiceTime();

    // Get the name of the customer.
    std::string GetName() const;

    // Get the service time of the customer.
    int GetServiceTime() const;

    // Get the priority level of the customer.
    int GetPriorityLevel() const;

    // Overload the > operator to compare customers based on priority level.
    bool operator>(const Customer& other) const;

private:
    // Member variables for the customer's name, service time, and priority level.
    std::string name_;
    int service_time_;
    int priority_level_;
};

// Constructor that initializes a Customer with a given name and sets the priority level.
Customer::Customer(const std::string& name) : name_(name) {
    SetPriorityLevel();
}

// Set the priority level to a random integer between 0 and 100.
void Customer::SetPriorityLevel() {
    priority_level_ = std::rand() % 101;
}

// Set the service time to a random integer between 0 and 60.
void Customer::SetServiceTime() {
    service_time_ = std::rand() % 61;
}

// Get the name of the customer.
std::string Customer::GetName() const {
    return name_;
}

// Get the service time of the customer.
int Customer::GetServiceTime() const {
    return service_time_;
}

// Get the priority level of the customer.
int Customer::GetPriorityLevel() const {
    return priority_level_;
}

// Overload the > operator to compare customers based on priority level.
bool Customer::operator>(const Customer& other) const {
    return priority_level_ > other.priority_level_;
}

#endif // CUSTOMER_H