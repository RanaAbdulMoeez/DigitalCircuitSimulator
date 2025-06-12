#ifndef MYVECTOR_CPP
#define MYVECTOR_CPP

#include "MyVector.h"
#include <iostream>

template <typename T>
void MyVector<T>::double_capacity() {
    int new_cap = (cap == 0) ? 1 : cap * 2;
    T* new_arr = new T[new_cap];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

// Constructors & Destructor
template <typename T>
MyVector<T>::MyVector() : arr(nullptr), len(0), cap(0) {}

template <typename T>
MyVector<T>::MyVector(int count, const T& value) : len(count), cap(count) {
    arr = new T[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = value;
    }
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : len(other.len), cap(other.cap) {
    arr = new T[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

// Operators
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] arr;
        len = other.len;
        cap = other.cap;
        arr = new T[cap];
        for (int i = 0; i < len; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
    return arr[index];
}

template <typename T>
bool MyVector<T>::operator==(const MyVector& other) const {
    if (len != other.len) return false;
    for (int i = 0; i < len; i++) {
        if (arr[i] != other.arr[i]) return false;
    }
    return true;
}

template <typename T>
bool MyVector<T>::operator!=(const MyVector& other) const {
    return !(*this == other);
}

template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector& other) const {
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

template <typename T>
MyVector<T>& MyVector<T>::operator+=(const MyVector& other) {
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
template <typename T>
void MyVector<T>::push(const T& value) {
    if (len == cap) double_capacity();
    arr[len++] = value;
}

template <typename T>
void MyVector<T>::pop() {
    if (len > 0) len--;
}

template <typename T>
void MyVector<T>::insert_at(int index, const T& value) {
    if (index < 0 || index > len) return;

    if (len == cap) double_capacity();

    for (int i = len; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    len++;
}

template <typename T>
void MyVector<T>::delete_at(int index) {
    if (index < 0 || index >= len) return;

    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
}

template <typename T>
void MyVector<T>::reserve(int new_capacity) {
    if (new_capacity <= cap) return;

    T* new_arr = new T[new_capacity];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    cap = new_capacity;
}

template <typename T>
void MyVector<T>::clear() {
    len = 0;
}

template <typename T>
void MyVector<T>::assign_at(int index, const T& value) {
    if (index < 0 || index >= len) return;
    arr[index] = value;
}

template <typename T>
void MyVector<T>::swap(MyVector& other) {
    // Swap pointers
    T* temp_arr = arr;
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

template <typename T>
void MyVector<T>::shrink_to_fit() {
    if (cap == len) return;

    T* new_arr = new T[len];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    cap = len;
}

template <typename T>
void MyVector<T>::reverse() {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Accessors
template <typename T>
bool MyVector<T>::empty() const {
    return len == 0;
}

template <typename T>
int MyVector<T>::size() const {
    return len;
}

template <typename T>
T& MyVector<T>::at(int index) {
    return arr[index];
}

template <typename T>
const T& MyVector<T>::at(int index) const {
    return arr[index];
}

template <typename T>
T& MyVector<T>::front() {
    return arr[0];
}

template <typename T>
const T& MyVector<T>::front() const {
    return arr[0];
}

template <typename T>
T& MyVector<T>::back() {
    return arr[len - 1];
}

template <typename T>
const T& MyVector<T>::back() const {
    return arr[len - 1];
}

template <typename T>
int MyVector<T>::find(const T& value) const {
    for (int i = 0; i < len; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

#endif