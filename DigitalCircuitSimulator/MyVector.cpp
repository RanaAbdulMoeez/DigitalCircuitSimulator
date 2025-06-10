#include "MyVector.h"
#include <iostream>

void MyVector::double_capacity() {
    int new_cap = (cap == 0) ? 1 : cap * 2;
    int* new_arr = new int[new_cap];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

// Constructors & Destructor
MyVector::MyVector() : arr(nullptr), len(0), cap(0) {}

MyVector::MyVector(int count, int value) : len(count), cap(count) {
    arr = new int[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = value;
    }
}

MyVector::MyVector(const MyVector& other) : len(other.len), cap(other.cap) {
    arr = new int[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = other.arr[i];
    }
}

MyVector::~MyVector() {
    delete[] arr;
}

// Operators
MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] arr;
        len = other.len;
        cap = other.cap;
        arr = new int[cap];
        for (int i = 0; i < len; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

int& MyVector::operator[](int index) {
    return arr[index];
}

const int& MyVector::operator[](int index) const {
    return arr[index];
}

bool MyVector::operator==(const MyVector& other) const {
    if (len != other.len) return false;
    for (int i = 0; i < len; i++) {
        if (arr[i] != other.arr[i]) return false;
    }
    return true;
}

bool MyVector::operator!=(const MyVector& other) const {
    return !(*this == other);
}

MyVector MyVector::operator+(const MyVector& other) const {
    MyVector result;
    result.reserve(len + other.len);
    result.len = len + other.len;
    for (int i = 0; i < len; i++) {
        result.arr[i] = arr[i];
    }
    for (int i = 0; i < other.len; i++) {
        result.arr[len + i] = other.arr[i];
    }
    return result;
}

MyVector& MyVector::operator+=(const MyVector& other) {
    int old_len = len;
    len += other.len;
    if (len > cap) {
        reserve(len);
    }
    for (int i = 0; i < other.len; i++) {
        arr[old_len + i] = other.arr[i];
    }
    return *this;
}

// Modifiers
void MyVector::push(int value) {
    if (len == cap) double_capacity();
    arr[len++] = value;
}

void MyVector::pop() {
    if (len > 0) len--;
}

void MyVector::insert_at(int index, int value) {
    if (index < 0 || index > len) return;

    if (len == cap) double_capacity();

    for (int i = len; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    len++;
}

void MyVector::delete_at(int index) {
    if (index < 0 || index >= len) return;

    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
}

void MyVector::reserve(int new_capacity) {
    if (new_capacity <= cap) return;

    int* new_arr = new int[new_capacity];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    cap = new_capacity;
}

void MyVector::clear() {
    len = 0;
}

void MyVector::swap(MyVector& other) {
    // Swap pointers
    int* temp_arr = arr;
    arr = other.arr;
    other.arr = temp_arr;

    // Swap lengths
    int temp_len = len;
    len = other.len;
    other.len = temp_len;

    // Swap capacities
    int temp_cap = cap;
    cap = other.cap;
    other.cap = temp_cap;
}

void MyVector::shrink_to_fit() {
    if (cap == len) return;

    int* new_arr = new int[len];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    cap = len;
}

void MyVector::reverse() {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Accessors
bool MyVector::empty() const {
    return len == 0;
}

int MyVector::size() const {
    return len;
}

int& MyVector::at(int index) {
    return arr[index];
}

const int& MyVector::at(int index) const {
    return arr[index];
}

int& MyVector::front() {
    return arr[0];
}

const int& MyVector::front() const {
    return arr[0];
}

int& MyVector::back() {
    return arr[len - 1];
}

const int& MyVector::back() const {
    return arr[len - 1];
}

int MyVector::find(int value) const {
    for (int i = 0; i < len; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}