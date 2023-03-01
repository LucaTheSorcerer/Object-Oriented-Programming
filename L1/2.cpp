//
// Created by Luca Tudor on 01.03.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> nums = {2, 3, 5, 7, 10, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int n = nums.size();

    int max_len = 1; // initialize result

    for (int i = 0; i < n; i++) {
        int len = 1;
        for (int j = i + 1; j < n; j++) {
            int diff = abs(nums[j] - nums[j-1]);
            if (is_prime(diff)) {
                len++;
            } else {
                break;
            }
        }
        max_len = max(max_len, len);
    }

    cout << "The length of the longest subsequence with prime differences is: " << max_len << endl;

    return 0;
}
