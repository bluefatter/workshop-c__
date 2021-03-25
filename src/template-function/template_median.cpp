#include <vector>
#include <exception>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

template <class T>
T median(vector<T> v) {
    typedef vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0) {
        throw domain_error("vector has zero elements")
    }

    sort(v.begin(), v.end())

    vec_sz mid = size / 2;
    return mid % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    median(v);
}
