#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
template<class T>
class DynamicArray {

private:
    T* data;
    int size;

public:
    DynamicArray();
    DynamicArray(T arr[], int size);
    DynamicArray(const DynamicArray& o);

    void print();
    void insert(T value, int pos);
    void pushBack(T value);
    void remove(int pos);

    ~DynamicArray();

};

#endif
