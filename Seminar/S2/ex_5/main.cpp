#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;

double estimate_pi(int num_points) {
    int num_in_circle = 0;
    for(int i = 0; i < num_points; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        double squared = x * x + y * y;
        if(squared <= 1)
            num_in_circle++;
    }
    return 4.0 * num_in_circle / num_points;
}

int main() {
    //current time. ticks since epoch -> srand that generates randomness between 0-99
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(seed);
    int num_points = 10000000;
    double pi = estimate_pi(num_points);
    cout << "Estimated value of pi is: " << pi << endl;
    cout << "Error from actual value of pi is: " << abs(M_PI - pi) << endl;
    return 0;
}
