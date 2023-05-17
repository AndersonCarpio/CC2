#include "DynamicArray.h"
using namespace std;


template<class T>
DynamicArray<T>::DynamicArray() {
    this->size = 0;
    data = new T[0];
}

template<class T>
DynamicArray<T>::DynamicArray(T arr[], int size) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = arr[i];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& o) {
    this->size = o.size;
    data = new T[o.size];
    for (int i = 0; i < size; i++)
        data[i] = o.data[i];
}

template<class T>
void DynamicArray<T>::print() {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << "]" << endl;
}

template<class T>
void DynamicArray<T>::insert(T value, int pos) {
    size++;
    T* newData = new T[size];
    for (int i = 0; i < pos; i++)
        newData[i] = data[i];
    newData[pos] = value;
    for (int i = pos + 1; i < size; i++)
        newData[i] = data[i - 1];
    delete[] data;
    data = newData;
}

template<class T>
void DynamicArray<T>::pushBack(T value) {
    size++;
    T* newData = new T[size];
    for (int i = 0; i < size - 1; i++)
        newData[i] = data[i];
    newData[size - 1] = value;
    delete[] data;
    data = newData;
}

template<class T>
void DynamicArray<T>::remove(int pos) {
    size--;
    T* newData = new T[size];
    for (int i = 0; i < pos; i++)
        newData[i] = data[i];
    for (int i = pos; i < size; i++)
        newData[i] = data[i + 1];
    delete[] data;
    data = newData;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}
