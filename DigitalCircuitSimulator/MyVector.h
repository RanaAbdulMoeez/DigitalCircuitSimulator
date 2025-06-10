#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {
private:
    T* arr;
    int len;
    int cap;

    void double_capacity();

public:
    // Constructors & Destructor
    MyVector();
    MyVector(int count, const T& value);
    MyVector(const MyVector& other);
    ~MyVector();

    // Operators
    MyVector& operator=(const MyVector& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    bool operator==(const MyVector& other) const;
    bool operator!=(const MyVector& other) const;
    MyVector operator+(const MyVector& other) const;
    MyVector& operator+=(const MyVector& other);

    // Modifiers
    void push(const T& value);
    void pop();
    void insert_at(int index, const T& value);
    void delete_at(int index);
    void reserve(int new_capacity);
    void clear();
    void swap(MyVector& other);
    void shrink_to_fit();
    void reverse();

    // Accessors
    bool empty() const;
    int size() const;
    T& at(int index);
    const T& at(int index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    int find(const T& value) const;
};

// Implementation must be in header for templates
#include "MyVector.cpp"

#endif