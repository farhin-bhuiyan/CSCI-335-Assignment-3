//Farhin Bhuiyan
// MaxHeap.h
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <stdexcept>

// MaxHeap class template definition
template <typename T>
class MaxHeap {
public:
    // Default constructor
    MaxHeap() = default;
    
    // Constructor that builds the heap from an existing vector of items
    explicit MaxHeap(const std::vector<T>& items);
    
    // Check if the heap is empty
    bool IsEmpty() const;
    
    // Get the maximum element in the heap
    const T& GetMax() const;
    
    // Insert a new item into the heap
    void Insert(const T& item);
    
    // Remove and return the maximum element in the heap
    T DeleteMax();

private:
    // Helper function to percolate a node down the heap
    void PercolateDown(size_t hole);
    
    // Helper function to percolate a node up the heap
    void PercolateUp(size_t hole);

    // Vector to store the heap elements
    std::vector<T> heap_;
};

// Constructor that builds the heap from an existing vector of items
template <typename T>
MaxHeap<T>::MaxHeap(const std::vector<T>& items) : heap_(items) {
    for (size_t i = heap_.size() / 2; i > 0; --i) {
        PercolateDown(i);
    }
}

// Check if the heap is empty
template <typename T>
bool MaxHeap<T>::IsEmpty() const {
    return heap_.empty();
}

// Get the maximum element in the heap
template <typename T>
const T& MaxHeap<T>::GetMax() const {
    if (IsEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap_[0];
}

// Insert a new item into the heap
template <typename T>
void MaxHeap<T>::Insert(const T& item) {
    heap_.push_back(item);
    PercolateUp(heap_.size() - 1);
}

// Remove and return the maximum element in the heap
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

// Helper function to percolate a node down the heap
template <typename T>
void MaxHeap<T>::PercolateDown(size_t hole) {
    size_t child;
    T tmp = heap_[hole];

    for (; hole * 2 + 1 < heap_.size(); hole = child) {
        child = hole * 2 + 1;
        if (child != heap_.size() - 1 && heap_[child + 1] > heap_[child]) {
            ++child;
        }
        if (heap_[child] > tmp) {
            heap_[hole] = heap_[child];
        } else {
            break;
        }
    }
    heap_[hole] = tmp;
}

// Helper function to percolate a node up the heap
template <typename T>
void MaxHeap<T>::PercolateUp(size_t hole) {
    T tmp = heap_[hole];
    for (; hole > 0 && tmp > heap_[(hole - 1) / 2]; hole = (hole - 1) / 2) {
        heap_[hole] = heap_[(hole - 1) / 2];
    }
    heap_[hole] = tmp;
}

#endif // MAX_HEAP_H