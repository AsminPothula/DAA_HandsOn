#include <iostream>
#include <cstddef> // for size_t

class Vector {
private:
    int* data;          // Pointer to the data array
    size_t sz;          // Number of elements in the vector
    size_t cap;         // Allocated capacity of the array

    // Private method to resize the internal array
    void resize(size_t new_cap) {
        std::cout << "Resizing from capacity " << cap << " to " << new_cap << std::endl;
        int* new_data = new int[new_cap]; // Allocate new memory
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];        // Copy existing elements
        }
        delete[] data;                    // Free old memory
        data = new_data;                  // Update data pointer
        cap = new_cap;                    // Update capacity
    }

public:
    // Default constructor
    Vector() : data(nullptr), sz(0), cap(0) {}

    // Destructor to clean up memory
    ~Vector() {
        delete[] data;
    }

    // Method to add an element at the end
    void push_back(int val) {
        if (sz == cap) {                  // Need to resize
            size_t new_cap = cap == 0 ? 1 : cap * 2;
            resize(new_cap);
        }
        data[sz++] = val;                 // Add new element
    }

    // Method to remove the last element
    void pop_back() {
        if (sz > 0) {
            --sz;                         // Decrease size
        }
    }

    // Overloaded subscript operators for element access
    int& operator[](size_t index) {
        return data[index];
    }

    const int& operator[](size_t index) const {
        return data[index];
    }

    // Method to get the current size
    size_t size() const {
        return sz;
    }

    // Method to get the current capacity
    size_t capacity() const {
        return cap;
    }

    // Method to print the elements in the array
    void print() const {
        for (size_t i = 0; i < sz; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40); // This will trigger a resize

    std::cout << "Array elements: ";
    vec.print();
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    vec.pop_back();
    std::cout << "Array elements after pop_back: ";
    vec.print();
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    return 0;
}
