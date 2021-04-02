#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;
using std::size_t;
using std::ptrdiff_t;

template <class It, class Pred>
It find_if_2(It begin, It end, Pred pred) {
    while (begin != end && !pred(*begin))
        ++begin;
    return begin;
}

bool is_negative(int n) {
    return n < 0;
}

int main() {
    static const int array[] = {1, 2, 3};
    /**
     * sizeof(array) compute how much memory array consumes.
     * sizeof(*array) compute how much memory single element of array consumes.
     *
     * So sizeof(array) / sizeof(*array) result is element count of array!!!
     */
    const size_t array_size = sizeof(array) / sizeof(*array);
    cout << array_size << endl;

    const size_t size = 4;
    static vector<int> v {1, 2, 3, -1};

    const ptrdiff_t value = v.end() - v.begin();
    cout << value << endl;

    auto i = find_if_2(v.begin(), v.end(), is_negative);
    cout << *i << endl;
    return 0;
}

