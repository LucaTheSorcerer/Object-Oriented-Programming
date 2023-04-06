/**
 _____________________________________________________________________________________________________
/ @Author: Luca Tudor, group 713, Faculty of Computer Science                                         \
| **************************************************************************************************** |
| Dependency Structured Matrix Implementation                                                          |
| **************************************************************************************************** |
| Methods:                                                                                             |
|     - getIndexOfElement                                                                              |
|     - setElementName                                                                                 |
|     - addLink                                                                                        |
|     - deleteLink                                                                                     |
|      - hasLink                                                                                       |
|      - linkWeight                                                                                    |
|      - hasElement                                                                                    |
|      - countToLinks                                                                                  |
|      - countFromLinks                                                                                |
\      - countAllLinks                                                                                 /
 ------------------------------------------------------------------------------------------------------
  \
   \   \_\_    _/_/
    \      \__/
           (oo)\_______
           (__)\       )\/\
               ||----w |
               ||     ||
*/

#pragma once
#include <string>
using namespace std;

template <typename T>
class DSM {
private:
    int elementCount;
    int capacity;
    T **matrix;
    string *elementNames;

public:
    void resizeElements(int newCapacity);

    void resizeMatrix(int newCapacity);

    void autoResize();

    int getIndexOfElement(const string &element);

    explicit DSM(int _elementCount = 10);

    //Constructor with two parameters
    DSM(string *_elementNames, int _elementCount);

    //Copy constructor
    DSM(const DSM<T> &other);


    ~DSM();

    int size();

    int getCapacity();

    string getName(int index);

    void setElementName(int index, const string &name);

    void addLink(const string &fromElement, const string &toElement, T weight);

    void deleteLink(const string &fromElement, const string &toElement);

    bool hasLink(const string &fromElement, const string &toElement);

    T linkWeight(const string &fromElement, const string &toElement);

    bool hasElement(const string &element);

    int countToLinks(const string &element);

    int countFromLinks(const string &element);

    int countAllLinks();
};









