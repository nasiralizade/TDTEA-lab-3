#include <iostream>
namespace Miun {
    /**
     * @brief en compile-time power funktion
     * @tparam exponent exponenten
     * @tparam T typen
     * @tparam enable en template parameter som används för att aktivera eller inaktivera delar av koden under kompilering
     * Substitution Failure Is Not An Error (SFINAE) is a C++ technique used to enable or disable parts of the code during compilation.
     */
    template<int exponent, typename T=double, typename enable=void>
    struct pow {
        constexpr T operator()(T base) {
            pow<exponent - 1, T> next;
            return next(base) * base;
        }
        /*
        template<typename T1>
        void checkIfArithmetic(T1 value) {
            if (!std::is_arithmetic<T1>::value) {
                throw std::invalid_argument("Base must be an arithmetic type.");
            }
        }*/
    };
    template<typename T>
    struct pow<0, T> {
        constexpr T operator()(T base) {
            if (base == (T)0) {
                return (T)0;
            } else {
                return (T)1;
            }
        }
    };
   // en specialisering av pow för negativa exponenter som använder sig av SFINAE
    template<int exponent, typename T>
    struct pow<exponent, T, typename std::enable_if_t<exponent < 0>>{
        constexpr T operator()(T base) {
            pow<exponent + 1, T> next;
            return next(base) * 1 / base;
        }
    };

}

int main() {
    std::cout<<std::pow(2,2)<<std::endl;
    Miun::pow<2> b;
    std::cout << b(2) << std::endl;

    return 0;
}
