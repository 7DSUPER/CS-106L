// system and timing
#include <iostream>
#include <chrono>

// data structure imports
#include <deque>
#include <vector>
#include <iterator>
#include <utility> // pair
#include <string>

using std::cout;    using std::endl;

// myMin function from lecture
template <typename T>
T myMin(T a, T b) {
    return a > b? b : a;
}

int main() {

    /*
     * explicit instantiation of template function (3, 4), (3.2, 3.1), (Frankie, Sathya)
     */
    int mymin1 = myMin<int> (3, 4);
    float mymin2 = myMin<float> (3.2, 3.1);
    std::string mymin3 = myMin<std::string> ("Frankie", "Sathya");
    cout << mymin1 << endl;
    cout << mymin2 << endl;
    cout << mymin3 << endl;

    /*
     * implicit (type-deduced) instantiation of template function (4, 5), (4, 3.2)
     */
    int mymin4 = myMin<int> (5, 4);
    float mymin5 = myMin<float> (3.2, 4);    
    cout << mymin4 << endl;
    cout << mymin5 << endl;
    // string literals like the ones below are c-strings, with a "char *" data type.
    // char *'s are pointers, which means myMin is comparing the addresses of these two strings,
    // and not the letters themselves! this is a danger of type deduction.
    std::string mymin6 = myMin("Frankie", "Sathya");
    cout << mymin6 << endl;

    return 0;
}

