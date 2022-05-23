// system and timing
#include <iostream>
#include <chrono>

// data structure imports
#include <deque>
#include <vector>
#include <iterator>
#include <utility> // pair

using std::cout;    using std::endl;

// count_occurrences
template <typename Input, typename Find>
int count_occurrences(Input begin, Input end, Find val) {
    int count = 0;
    for (Input it = begin; it != end; ++it) {
        if (*it == val) ++count;
    }
    return count;
}

int main() {

    // vector of strings
    std::vector<std::string> lands = {"Xadia", "Drakewood", "Innean"};
    // how can we count the number of times "Xadia" appears in this?
    int appear1 = count_occurrences(lands.begin(), lands.end(), "Xadia");
    cout << appear1 << endl;
    
    // string itself (array of chars)
    std::string str = "Xadia";
    // how can we count the number of times 'a' appears in this?
    int appear2 = count_occurrences(str.begin(), str.end(), 'a');
    cout << appear2 << endl;

    return 0;
}

