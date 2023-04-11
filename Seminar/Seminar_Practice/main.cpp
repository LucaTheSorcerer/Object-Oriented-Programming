#include <iostream>
using namespace std;

void add_plus_one_value(int a, int b) {
    a += 1;
    b += 1;
    cout << a << " " << b << endl;

}


void add_plus_one_reference(int &a, int &b) {
    a += 1;
    b += 1;
    cout << a << " " << b << endl;

}

void add_plus_one_pointer(int *a, int *b) {
    //this should output the value of a and b after adding 1
    *a += 1;
    *b += 1;
    cout << *a << " " << *b << endl;

}

void modify_array(int *a) {
    a[1] = 3;
    cout << a[1] << endl;
}

struct Composite {
    int array[5];
    int length;
};

void procedureI(Composite par) {
    par.array[0] = 7000;
    cout << par.array[0] << endl;
}
void procedureJ(Composite &par) {
    par.array[1] = 300;
}
void procedureK(Composite *par) {
    par->array[2] = 90;
}


int main() {
    int a = 1, b = 1;

    cout << "Pass by value" << endl;
    add_plus_one_value(a, b);
    cout << a << " " << b << endl;
    cout << "Finish pass by value" << endl;

    cout << "Pass by reference" << endl;
    add_plus_one_reference(a, b);
    cout << a << " " << b << endl;
    cout << "Finish pass by reference" << endl;

    cout << "Pass by pointer" << endl;
    add_plus_one_pointer(&a, &b);
    cout << a << " " << b << endl;
    cout << "Finish pass by pointer" << endl;

    int array[3] = {1, 2, 3};
    cout << "Pass array by pointer" << endl;
    modify_array(&array[0]);
    cout << array[1] << endl;
    cout << array[0] << " " << array[1] << " " << array[2] << endl;
    cout << "Finish pass array by pointer" << endl;

    Composite c{};
    c.array[0] = 1;
    c.array[1] = 2;
    c.array[2] = 3;
    c.array[3] = 4;
    c.array[4] = 5;
    c.length = 5;

    cout << "Pass struct by value " << endl;
    procedureI(c);
    cout << c.array[0] << endl;
    cout << c.array[0] << " " << c.array[1] << " " << c.array[2] << " " << c.array[3] << " " << c.array[4] << endl;
    cout << "Finish pass struct by value" << endl;

    cout << "Pass struct by reference " << endl;
    procedureJ(c);
    cout << c.array[1] << endl;
    cout << c.array[0] << " " << c.array[1] << " " << c.array[2] << " " << c.array[3] << " " << c.array[4] << endl;
    cout << "Finish pass struct by reference" << endl;

    cout << "Pass struct by pointer " << endl;
    procedureK(&c);
    cout << c.array[2] << endl;
    cout << c.array[0] << " " << c.array[1] << " " << c.array[2] << " " << c.array[3] << " " << c.array[4] << endl;
    cout << "Finish pass struct by pointer" << endl;

    double weights[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    double *p = weights;
    double w2 = *(p + 2);
    cout << w2 << endl;

    return 0;
}
