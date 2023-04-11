//
// Created by Luca Tudor on 05.04.2023.
//
#include "DSM.h"
#include <string>

/**
 * @brief Constructor with one parameter
 * @details It creates a matrix with the number of elements specified by the user.
 * If the number of elements is negative, it throws an exception.
 * It sets elementCount to the number of elements and capacity to the number of elements multiplied by 2 plus 1.
 * It allocates memory for the matrix and for the array of names.
 * It initializes the matrix with 0.
 * It initializes the array of names with empty strings.
 * @param _elementCount: the number of elements
 * @tparam T: the type of the elements
 */
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


/**
 * @brief Copy constructor
 * @details It creates a matrix with the same number of elements as the other matrix.
 * It sets elementCount to the number of elements and capacity to the number of elements multiplied by 2 plus 1.
 * It allocates memory for the matrix and for the array of names.
 * It copies the elements from the other matrix to the new matrix.
 * It copies the names of the elements from the other matrix to the new matrix.
 * @tparam T: the type of the elements
 * @param other: the matrix that will be copied
 */
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

/**
 * @brief Constructor with two parameters
 * @details It creates a matrix with the number of elements specified by the user.
 * If the number of elements is negative, it throws an exception.
 * It sets elementCount to the number of elements and capacity to the number of elements multiplied by 2 plus 1.
 * It allocates memory for the matrix and for the array of names.
 * It gets as parameter the names of the elements and copies them to the array of names.
 * @tparam T: the type of the elements
 * @param _elementNames: the names of the elements
 * @param _elementCount: the number of elements
 */
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

/**
 * @method countAllLinks()
 * @brief It counts the number of links in the matrix
 * @tparam T: the type of the elements
 * @return the number of links in the matrix
 */
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

/**
 * @method countFromLinks()
 * @brief It counts the number of links that come from the element. It first checks if the element exists in the matrix.
 * @param element: the element from which the links come
 * @return: the number of links that come from the element
 */
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


/**
 * @method countToLinks()
 * @brief It counts the number of links that go to the element. It first checks if the element exists in the matrix.
 * @param element: the element from which the links come
 * @return: the number of links that come from the element
 */
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

/**
 * @method hasElement()
 * @brief the method is a bool that returns true if the element exists in the matrix and false if it doesn't
 * @param element: the element that will be checked
 * @return: true if the element exists in the matrix and false if it doesn't
 */
template<typename T>
bool DSM<T>::hasElement(const string &element) {
    //The function asserts to true even if an element does not exist in the matrix. It should return false.
    //Check if the element exists in the matrix
    return getIndexOfElement(element) != -1;
}

/**
 * @method linkWeight()
 * @brief the method returns the weight of the link between two elements. It first checks if the elements exist in the matrix.
 * The function is defined with a T because the weight can be a double or an int.
 * @tparam T: the type of the elements
 * @param fromElement
 * @param toElement
 * @return
 */
template<typename T>
T DSM<T>::linkWeight(const string &fromElement, const string &toElement) {
    int counter = 2;
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

/**
 * @method hasLink()
 * @brief the method returns true if there is a link between two elements and false if there isn't.
 * It first checks if the elements exist in the matrix.
 * @param fromElement: the element from which the link comes
 * @param toElement: the element to which the link goes
 * @return true if there is a link between the two elements and false if there isn't
 */
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

    return matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)] != 0;
}

/**
 * @method deleteLink()
 * @brief the method deletes the link between two elements. It first checks if the elements exist in the matrix.
 * @param fromElement: the element from which the link comes
 * @param toElement: the element to which the link goes
 */
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

    matrix[getIndexOfElement(fromElement)][getIndexOfElement(toElement)] = 0;
}

/**
 * @method addLink()
 * @brief the method adds a link between two elements. It first checks if the elements exist in the matrix.
 * @tparam T: the type of the element's weight
 * @param fromElement: the element from which the link comes
 * @param toElement: the element to which the link goes
 * @param weight: the weight of the link
 */
template<typename T>
void DSM<T>::addLink(const string &fromElement, const string &toElement, T weight) {
    int counter = 2;

    if (fromElement == toElement)
        return;

    //Check if the weight is valid
    if (weight < 0)
        return;


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

/**
 * @method setElementName()
 * @brief the method sets the name of an element in the matrix. It first checks if the index is out of bounds.
 * @param index: the index of the element in the matrix
 * @param name: the name of the element
 * @throw: std::invalid_argument if the index is out of bounds
 */
template<typename T>
void DSM<T>::setElementName(int index, const string &name) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("The index is out of bounds!");
    elementNames[index] = name;
}

/**
 * @method getName()
 * @brief the method returns the name of an element in the matrix. It first checks if the index is out of bounds.
 * @throw: std::invalid_argument if the index is out of bounds
 * @param index: the index of the element in the matrix
 * @return the name of the element
 */
template<typename T>
string DSM<T>::getName(int index) {
    if (index < 0 || index >= elementCount)
        throw std::invalid_argument("The index is out of range!");
    return string(elementNames[index]);
}

/**
 * @method getCapacity()
 * @brief the method returns the capacity of the matrix
 * @return: the capacity of the matrix
 */
template<typename T>
int DSM<T>::getCapacity() {
    return capacity;
}

/**
 * @method size()
 * @brief the method returns the number of elements in the matrix
 * @return: the number of elements in the matrix
 */
template<typename T>
int DSM<T>::size() {
    return elementCount;
}

/**
 * @method getIndexOfElement()
 * @brief the method returns the index of an element in the matrix
 * @param element: the element for which we want to find the index
 * @return the index of the element in the matrix
 */
template<typename T>
int DSM<T>::getIndexOfElement(const string &element) {
    //The function returns the index of the element in the matrix
    //If the element is not in the matrix, the function returns -1
    //Check if the element is in the matrix
    for (int i = 0; i < elementCount; i++) {
        if (elementNames[i] == element)
            return i;
    }
    return -1;
}

/**
 * @method autoResize()
 * @brief the method resizes the matrix and the elementNames array depending on the size of the matrix
 */
template<typename T>
void DSM<T>::autoResize() {
    //This function resizes the matrix upwards or downwards depending on the size of the matrix
    //The function also resizes the elementNames array upwards or downwards depending on the size of the array
    if(elementCount == capacity) {
        resizeElements(capacity * 2);
        resizeMatrix(capacity * 2);
    }
    else if(elementCount == capacity / 4)
    {
        resizeElements(capacity / 2);
        resizeMatrix(capacity / 2);
    }

}

/**
 * @method resizeMatrix()
 * @brief the method resizes the matrix
 * @details: the method resizes the matrix and copies the old elements in the new matrix. The new elements are set to
 * the old elements otherwise they are set to 0.
 * It also checks if the new capacity is smaller than the current capacity. If it is, it throws an exception. At the end
 * it deletes the old matrix and sets the new matrix to be the old one.
 * @param newCapacity: the new capacity of the matrix
 * @throw: std::invalid_argument if the new capacity is smaller than the current capacity
 */
template<typename T>
void DSM<T>::resizeMatrix(int newCapacity) {
    //Check if the new capacity is less than the current capacity
    if (newCapacity < elementCount)
        throw std::invalid_argument("The new capacity is smaller than the current capacity!");

    //This function resizes the matrix
    auto **temp = new T *[newCapacity];
    for (int i = 0; i < newCapacity; i++) {
        temp[i] = new T[newCapacity];
        for (int j = 0; j < newCapacity; j++) {
            if(i < elementCount && j < elementCount) {
                temp[i][j] = matrix[i][j];
            }
            else {
                temp[i][j] = 0;
            }
        }
    }
    //Delete the old matrix
    for (int i = 0; i < elementCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    //Set the new matrix to the old matrix
    matrix = temp;
    capacity = newCapacity;

}

/**
 * @method resizeElements()
 * @brief the method resizes the elementNames array
 * @details: the method resizes the elementNames array and copies the old elements in the new array
 * The new element are set to elementNames[i]. It also checks if the new capacity is smaller than the current capacity.
 * If it is, it throws an exception. At the end it deletes the old array and sets the new array to be the old one.
 * @param newCapacity: the new capacity of the elementNames array
 * @throw: std::invalid_argument if the new capacity is smaller than the current capacity
 */
template<typename T>
void DSM<T>::resizeElements(int newCapacity) {
    //Check if the new capacity is less than the current capacity
    if (newCapacity < elementCount)
        throw std::invalid_argument("The new capacity is smaller than the current capacity!");

    //This function resizes the elementNames array
    auto *temp = new string[newCapacity];
    for (int i = 0; i < elementCount; i++) {
        temp[i] = elementNames[i];
    }
    //Delete the old array
    delete[] elementNames;
    //Set the new array to the old array
    elementNames = temp;
    capacity = newCapacity;

}

/**
 * @method: Destructor
 * @brief: the destructor deletes the matrix and the elementNames array
 * @details: the destructor deletes the matrix and the elementNames array. It first deletes the matrix and then the
 * elementNames array
 */
template<typename T>
DSM<T>::~DSM() {
    for (int iterator = 0; iterator < capacity; iterator++) {
        delete[] matrix[iterator];
    }

    delete[] matrix;
    delete[] elementNames;
}

template class DSM<int>;
template class DSM<double>;
template class DSM<float>;
template class DSM<char>;
template class DSM<bool>;