#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector {
private:
    int* arr;
    int len;
    int cap;

    void double_capacity();

public:
    // Constructors & Destructor
    MyVector();
    MyVector(int count, int value);
    MyVector(const MyVector& other);
    ~MyVector();

    // Operators
    MyVector& operator=(const MyVector& other);
    int& operator[](int index);
    const int& operator[](int index) const;
    bool operator==(const MyVector& other) const;
    bool operator!=(const MyVector& other) const;
    MyVector operator+(const MyVector& other) const;
    MyVector& operator+=(const MyVector& other);

    // Modifiers
    void push(int value);
    void pop();
    void insert_at(int index, int value);
    void delete_at(int index);
    void reserve(int new_capacity);
    void clear();
    void swap(MyVector& other);
    void shrink_to_fit();
    void reverse();

    // Accessors
    bool empty() const;
    int size() const;
    int& at(int index);
    const int& at(int index) const;
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;
    int find(int value) const;
};

#endif