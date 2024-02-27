//
// Created by Nasir Alizade on 2023-05-02.
//

#ifndef MYFUNCTIONS_MYFUNCTIONS_H
#define MYFUNCTIONS_MYFUNCTIONS_H

#include <iostream>
#include <vector>
#include <numeric>

namespace nasir {
    template<typename T>
    T add(T first, T second) {
        return first + second;
    }

    template<typename T>
    T multiple(T first, T second) {
        return first * second;
    }

    bool is_prime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    double average(T begin, T end) {
        return (std::accumulate(begin, end, 0.0) / (std::distance(begin, end)));
    }

    template<typename T>
    double calculate_std_dev(T begin, T end) {
        double mean = average(begin, end);
        double sum = 0.0;
        for (auto i = begin; i != end; i++) {
            sum += std::pow(static_cast<double>(*i - mean), 2);
        }
        return std::sqrt(sum / static_cast<double>(std::distance(begin, end)));
    }

    template<typename Iterator, typename T>
    int linear_search(Iterator begin, Iterator end, const T &target) {
        int index = 0;
        for (auto it = begin; it != end; ++it) {
            if (*it == target) {
                return index;
            }
            ++index;
        }
        return -1;
    }

    template<typename Iterator, typename T>
    int binary_search(Iterator begin, Iterator end, const T &target) {
        Iterator left = begin;
        Iterator right = end - 1;

        while (left <= right) {
            Iterator mid = left + (right - left) / 2;
            if (*mid == target) {
                return static_cast<int>(std::distance(begin, mid));
            } else if (*mid < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

//fakultet (!)
    unsigned long long factorial(unsigned int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    //största gemensamma delare
    unsigned int gcd(unsigned int a, unsigned int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    //0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
    unsigned int fibonacci(unsigned int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    bool is_palindrome(const std::string &str) {
        std::string reversed_str = str;
        std::reverse(reversed_str.begin(), reversed_str.end());
        return str == reversed_str;
    }

//fixa en för när exp ligger mellan 0<exp<1
    template<typename T>
    T pow(T base, T exponent) {
        if (exponent == 0 && base != 0) {
            return 1;
        }
        if (base == 0) {
            return 0;
        } else if (exponent < 0) {
            return 1 / (pow(base, -exponent));
        } else if (exponent > 0) {
            return base * pow(base, exponent - 1);
        }
        return 0;
    }

    template<typename T>
    void print_vec(std::vector<T> &data) {
        for (auto e: data) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    template<typename T>
    void print(T print) {
        std::cout << print << "\n";
    }

}
#endif //MYFUNCTIONS_MYFUNCTIONS_H