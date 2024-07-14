# CSCI-335-Assignment-3

# Customer Service Simulation Project

## Project Overview

This project simulates a customer service scenario at a problem-solving store. Customers arrive at the store with problems, each assigned a priority level. Customers are then served based on their priority levels by the store's clerk. After servicing, the clerk records the service time for each customer and maintains a history of all served customers. At the end of the day, the clerk sorts the history based on service time in ascending order.

## Implementation Details

### MaxHeap Template Class

1. **MaxHeap Template Class**: 
    - A `MaxHeap` template class was created to maintain the heap order property where every node is greater than or equal to its two children. The provided code for `MinHeap` was modified to create this `MaxHeap`.

    ```cpp
    template <typename T>
    class MaxHeap {
    public:
        MaxHeap() = default;
        explicit MaxHeap(const std::vector<T>& items);
        bool IsEmpty() const;
        const T& GetMax() const;
        void Insert(const T& item);
        T DeleteMax();

    private:
        void PercolateDown(size_t hole);
        void PercolateUp(size_t hole);
        std::vector<T> heap_;
    };
    ```

### Customer Class

2. **Customer Class**:
    - A `Customer` class was created with member variables `std::string name`, `int service_time`, and `int priority_level`.

    ```cpp
    class Customer {
    public:
        Customer(const std::string& name);
        void SetPriorityLevel();
        void SetServiceTime();
        std::string GetName() const;
        int GetServiceTime() const;
        int GetPriorityLevel() const;
        bool operator>(const Customer& other) const;

    private:
        std::string name_;
        int service_time_;
        int priority_level_;
    };
    ```

3. **SetPriorityLevel() Function**:
    - This member function uses `rand()` from `<cstdlib>` to set the priority level to a random integer between 0 and 100. It is called in the constructor.

    ```cpp
    void Customer::SetPriorityLevel() {
        priority_level_ = std::rand() % 101;
    }

    Customer::Customer(const std::string& name) : name_(name) {
        SetPriorityLevel();
    }
    ```

4. **SetServiceTime() Function**:
    - This member function sets the service time to a random integer between 0 and 60. It is not called in the constructor.

    ```cpp
    void Customer::SetServiceTime() {
        service_time_ = std::rand() % 61;
    }
    ```

5. **Comparison Based on Priority Level**:
    - The `Customer` class overloads the `>` operator to compare customers based on their priority levels.

    ```cpp
    bool Customer::operator>(const Customer& other) const {
        return priority_level_ > other.priority_level_;
    }
    ```

### MaxHeap Template Class Function Modification

6. **DeleteMax() Function**:
    - The `MaxHeap` template class function `DeleteMax()` was modified to return the `Customer` object being deleted.

    ```cpp
    template <typename T>
    T MaxHeap<T>::DeleteMax() {
        if (IsEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        T max_item = heap_[0];
        heap_[0] = heap_.back();
        heap_.pop_back();
        if (!IsEmpty()) {
            PercolateDown(0);
        }
        return max_item;
    }
    ```

### Simulation in main.cpp

7. **Run the Simulation**:
    - In `main.cpp`, a bunch of random customers are created and inserted into a `MaxHeap` (customers arriving at the store).

    ```cpp
    std::vector<std::string> customer_names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    for (const auto& name : customer_names) {
        Customer customer(name);
        heap.Insert(customer);
    }
    ```

8. **Remove All Elements and Update Service Time**:
    - A loop is used to remove all elements from the `MaxHeap` (the clerk servicing the customers). When a `Customer` is removed from the heap, the object being removed updates its service time and is moved to `history`.

    ```cpp
    while (!heap.IsEmpty()) {
        Customer served_customer = heap.DeleteMax();
        std::cout << "Served customer: " << served_customer.GetName()
                  << " with service time: " << served_customer.GetServiceTime() << " minutes" << std::endl;
    }
    ```

9. **Sort History Based on Service Time**:
    - After all customers are served, `history` is sorted based on service time in ascending order.

    ```cpp
    auto history = heap.GetHistory();
    std::sort(history.begin(), history.end(), [](const Customer& a, const Customer& b) {
        return a.GetServiceTime() < b.GetServiceTime();
    });
    ```

## Running the Project

1. **Ensure all files are in the same directory**: Place `main.cpp`, `MaxHeap.h`, `Customer.h`, and `CustomerMaxHeap.h` in the same directory.
2. **Open a terminal or command prompt**: Navigate to the directory containing these files.
3. **Compile the code**:
    ```sh
    g++ -std=c++11 -o customer_simulation main.cpp
    ```
4. **Run the executable**:
    - On Linux or macOS:
      ```sh
      ./customer_simulation
      ```
    - On Windows:
      ```sh
      customer_simulation.exe
      ```

## Expected Output

The expected output will show the name of the customer with the highest priority before servicing, details of each served customer, and a sorted history of served customers based on service time.

