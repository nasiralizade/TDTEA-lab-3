//
// Created by Nasir Alizade on 2024-02-22.
//

#ifndef LABB3_TEST_H
#define LABB3_TEST_H

#include <iostream>
#include <complex>

namespace math {
    template<int EXP, typename T = double, typename enable = void>
    struct pow {
        constexpr T operator()(T mantissa) {
            pow<EXP - 1, T> next;
            return next(mantissa) * mantissa;
        }
    };

    //std::complex är icke aritmetisk enligt C++
    /*template<int EXP, typename T>
    struct pow<EXP, T, typename std::enable_if_t<!std::is_arithmetic<T>::value>> {
        constexpr T operator()(T mantissa) {
            throw std::invalid_argument("Please provide an arithmetic type");
        }
    };*/

    template<int EXP, typename T>
    struct pow<EXP, T, typename std::enable_if_t<EXP < 0>> {
        constexpr double operator()(T mantissa) {
            pow<EXP + 1, T> next;
            return next(mantissa) * 1 / mantissa;
        }
    };

    template<typename T>
    struct pow<0, T> {
        constexpr T operator()(T mantissa) {
            return mantissa == (T)0 ? (T)0 : (T)1;
        }
    };
}

template<int N, char from = 'A', char to = 'C', char aux = 'B'>
struct hanoi{
    [[maybe_unused]] hanoi<N - 1, from, aux, to> before;
    [[maybe_unused]] hanoi<N - 1, aux, to, from> after;
    hanoi() {
        std::cout << "Move disk " << N << " from " << from << " to " << to << std::endl;
    }
};

template<char from, char to, char aux>
struct hanoi<0, from, to, aux>{};



int main(){
    math::pow<-3> t;
    std::cout << t(2) << std::endl;

    std::complex<int> c(3, 4);
    math::pow<3, std::complex<int>> p;
    std::cout << std::real(p(c)) << ((std::imag(p(c)) > 0) ? "+":"")  << std::imag(p(c)) << "i" << std::endl;

    hanoi<2> h{};

    return 0;
}

#endif //LABB3_TEST_H
