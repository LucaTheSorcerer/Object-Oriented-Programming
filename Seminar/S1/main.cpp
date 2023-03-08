#include <iostream>
using namespace std;


/*
 * Function for first coding problem
 */
void ex1()
{
    string last_name;
    string first_name;

    cout << "Enter your family name here: ";
    cin >> first_name;

    cout << "Enter your first name here: ";
    cin >> last_name;
    cout << endl;

    int size_name = first_name.size() + last_name.size();
    cout << "Hello " << first_name << " " << last_name << "! " << "Your name has " << size_name << " characters!" << endl;
    cout << "\n";
}

/*
 * Struct for the second coding problem
 */
struct Customer {
    int number;
    string name;
    int zipCode;
    string cityName;
};

int main() {
    /*
     * Code for first problem
     */
    ex1();

    /*
     * Code for second problem
     */
    const int ARRAY_SIZE = 10;
    Customer customer[ARRAY_SIZE];

    //Add the data for the first customer to the array
    customer[0].number = 1;
    customer[0].name = "Luca";
    customer[0].zipCode = 12345;
    customer[0].cityName = "Arad";

    customer[1].number = 2;
    customer[1].name = "Tudor";
    customer[1].zipCode = 6789;
    customer[1].cityName = "Cluj";


    //Print the data for the first customer of the array
    cout << "First customer's number: " << customer[0].number << endl;
    cout << "First customer's name: " << customer[0].name << endl;
    cout << "First customer's zip code: " << customer[0].zipCode << endl;
    cout << "First customer's city name: " << customer[0].cityName << endl;

    cout << "\n";


    //Print the data for the second customer of the array
    cout << "Second customer's number: " << customer[1].number << endl;
    cout << "Second customer's name: " << customer[1].name << endl;
    cout << "Second customer's zip code: " << customer[1].zipCode << endl;
    cout << "Second customer's city name: " << customer[1].cityName << endl;


    return 0;
}
