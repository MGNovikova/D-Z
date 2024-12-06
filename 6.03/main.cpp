#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> sequence;
    int n;

    std::cout << "Enter the sequence of natural numbers (enter -1 to stop): ";
    while (true) {
        std::cin >> n;
        if (n == -1) {
            break;
        }
        sequence.push_back(n);
    }

    bool hasPrime = false;

    for (int number : sequence) {
        if (isPrime(number)) {
            hasPrime = true;
            break;
        }
    }

    if (hasPrime) {
        (sequence.begin(), sequence.end());

        std::cout << "Sorted sequence:";
        for (int number : sequence) {
            std::cout << " " << number;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No prime numbers found in the sequence." << std::endl;
    }

    return 0;
}
