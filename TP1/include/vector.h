#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T> class VectorCustom {
private:
    T* arr;
    int size;
    int max;

public:
    VectorCustom() {
        arr = new T[1];
        size = 0;
        max = 1;
    };

    explicit VectorCustom(T data) {
        arr = new T[1];
        arr[0] = data;
        size = 1;
        max = 1;
    };

    void push(T data) {
        if (size == max) {
            T *temp = new T[2 * max];

            for (int i = 0; i < max; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            max *= 2;
            arr = temp;
        }
        arr[size] = data;
        size++;
    };

    void push(T data, int index) {
        if (index == max)
            push(data);
        else
            arr[index] = data;
    }

    T get(int index) {
        if (index < size) return arr[index];
    };

    void pop() {
        size--;
    };

    void pop(int index) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    };

    int length() const { return size; };

    bool empty() const { return size <= 0; };

    bool contains(T el) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == el)
                return true;
        }
        return false;
    };

    void sort() {
        for (int i = 1; i < size; i++) {
            T el = arr[i];
            int j = i - 1;
            while (el < arr[j] && j >= 0) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = el;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    };
};

#endif //VECTOR_H
