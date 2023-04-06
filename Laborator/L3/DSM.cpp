//
// Created by Luca Tudor on 05.04.2023.
//
#include "DSM.h"
#include <string>

template<typename T>
DSM<T>::DSM(int _elementCount) {
    if (_elementCount < 0)
        throw std::invalid_argument("The count of elements cannot be negative!");
    elementCount = _elementCount;
    capacity = (elementCount * 2 + 1);
    matrix = new T *[capacity];
    for (int iterator = 0; iterator < capacity; iterator++) {
        matrix[iterator] = new T[capacity];

        for (int j = 0; j < capacity; j++) {
            matrix[iterator][j] = 0;
        }
    }

    elementNames = new string[capacity];
}


//posibil sa fie elementCount in loc de capacity
template<typename T>
DSM<T>::DSM(const DSM<T> &other) {
    elementCount = other.elementCount;
    capacity = other.capacity;
    matrix = new T *[capacity];
    for (int iterator = 0; iterator < capacity; iterator++) {
        matrix[iterator] = new T[capacity];

        for (int j = 0; j < capacity; j++) {
            matrix[iterator][j] = other.matrix[iterator][j];
        }
    }

    elementNames = new string[capacity];
}

template<typename T>
DSM<T>::DSM(string *_elementNames, int _elementCount) {
    if (_elementCount < 0)
        throw std::invalid_argument("The count of the elements cannot be negative!");

    elementCount = _elementCount;
    capacity = (elementCount * 2 + 1);

    //Allocate memory for the matrix
    matrix = new T *[capacity];
    for(int i = 0; i < capacity; i++) {
        matrix[i] = new T[capacity];

        for(int j = 0; j < capacity; j++) {
            matrix[i][j] = 0;
        }
    }

    elementNames = new string[capacity];

    //Copy the names of the elements
    for(int i = 0; i < elementCount; i++) {
        elementNames[i] = _elementNames[i];
    }
}


template<typename T>
int DSM<T>::countAllLinks() {
    //It counts the number of links in the matrix
    int count = 0;
    for (int i = 0; i < elementCount; i++) {
        for (int j = 0; j < elementCount; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
    }
    return count;
}

template<typename T>
int DSM<T>::countFromLinks(const string &element) {
    //It counts the number of links that come from the element
    int counter = 2;
    //First check if the element exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == element) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = element;
    }

    //Then count the number of links that come from the element
    int count = 0;
    for (int i = 0; i < elementCount; i++) {
        if (matrix[getIndexOfElement(element)][i] != 0)
            count++;
    }
    return count;
}

template<typename T>
int DSM<T>::countToLinks(const string &element) {
    //First check if the element exists in the matrix
    int counter = 2;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == element) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = element;
    }

    //Then the function checks to see how many link go to the element
    int count = 0;
    for (int i = 0; i < elementCount; i++) {
        if (matrix[i][getIndexOfElement(element)] != 0)
            count++;
    }
    return count;
}

template<typename T>
bool DSM<T>::hasElement(const string &element) {
    return getIndexOfElement(element) != -1;
}

template<typename T>
T DSM<T>::linkWeight(const string &fromElement, const string &toElement) {
    int counter;
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = fromElement;
    }

    //Then check if the toElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == toElement) {
            counter--;
            break;
        }
    }

    //Determine the weight between the two elements in the matrix
    return matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)];
}

template<typename T>
bool DSM<T>::hasLink(const string &fromElement, const string &toElement) {
    int counter = 2;
    //First check if the fromElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = fromElement;
    }

    //Then check if the toElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == toElement) {
            counter--;
            break;
        }
    }

    return matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)] != nullptr;
}

template<typename T>
void DSM<T>::deleteLink(const string &fromElement, const string &toElement) {
    int counter = 2;
    //First check if the fromElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = fromElement;
    }

    //Then check if the toElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == toElement) {
            counter--;
            break;
        }
    }

    matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)] = nullptr;
}

template<typename T>
void DSM<T>::addLink(const string &fromElement, const string &toElement, T weight) {
    int counter = 2;

    //First check if the fromElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == fromElement) {
            counter--;
            break;
        }
    }

    if (counter == 1) {
        elementCount++;
        autoResize();
        elementNames[elementCount - 1] = fromElement;
    }

    //Then check if the toElement exists in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == toElement) {
            counter--;
            break;
        }
    }

    //Add the link between the two elements in the matrix
    matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)] = weight;
}

template<typename T>
void DSM<T>::setElementName(int index, const string &name) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("The index is out of bounds!");
    elementNames[index] = name;
}

template<typename T>
string DSM<T>::getName(int index) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("The index is out of range!");
    return string(elementNames[index]);
}

template<typename T>
int DSM<T>::getCapacity() {
    return capacity;
}

template<typename T>
int DSM<T>::size() {
    return elementCount;
}


template<typename T>
int DSM<T>::getIndexOfElement(const string &element) {
    //The function returns the index of the element in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == element)
            return i;
    }
}

template<typename T>
void DSM<T>::autoResize() {

}

template<typename T>
void DSM<T>::resizeMatrix(int newCapacity) {
    //Check if the new capacity is less than the current capacity
    if (newCapacity < capacity)
        throw std::invalid_argument("The new capacity is smaller than the current capacity!");

    //This function resizes the matrix
    auto **temp = new T *[newCapacity];
    for (int i = 0; i < elementCount; i++) {
        temp[i] = new T[newCapacity];
        for (int j = 0; j < elementCount; j++) {
            temp[i][j] = matrix[i][j];
        }
    }
    //Delete the old matrix
    for (int i = 0; i < capacity; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    //Set the new matrix to the old matrix
    matrix = temp;

}

template<typename T>
void DSM<T>::resizeElements(int newCapacity) {
    //Check if the new capacity is less than the current capacity
    if (newCapacity < capacity)
        throw std::invalid_argument("The new capacit is smaller than the current capacity!");

    //This function resizes the elementNames array
    auto *temp = new string[newCapacity];
    for (int i = 0; i < elementCount; i++) {
        temp[i] = elementNames[i];
    }
    //Delete the old array
    delete[] elementNames;
    //Set the new array to the old array
    elementNames = temp;

}


template<typename T>
DSM<T>::~DSM() {
    for (int iterator = 0; iterator < capacity; iterator++) {
        delete[] matrix[iterator];
    }

    delete[] matrix;
    delete[] elementNames;
}