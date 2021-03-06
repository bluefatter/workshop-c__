#include <iostream>
#include <cstddef>
#include <vector>
#include <memory>

template<class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_type;
    typedef T value_type;

    Vec() {
        create();
    }

    explicit Vec(size_type n, const T& val = T()) {
        create(n, val);
    }

    /**
     * Copy Constructor
     */
    Vec(const Vec& v) {
        create(v.begin(), v.end());
    }

    /**
     * Destructor: cleanup involves releasing resources, such as memory, that the constructor has allocated
     */
    ~Vec() {
        uncreate();
    }

    /**
     * Assign Operator
     */
    Vec& operator=(const Vec& vec) {
        /**
         * First check if self-assign
         * The this keyword is valid only inside a member function, where it denotes a pointer to the object on which the member function is operating.
         */
        if (&vec == this) {
            return *this;
        }
        uncreate();
        create(vec.begin(), vec.end());
    }

    size_type size() const {
        return last - first;
    }

    /**
     * We can return two type by operator index function:
     * 1. The value (like the commented lines up this function)
     * 2. The reference of the value
     *
     * They Has The Same Implementation!!!
     * Value return by COPY VALUE, But Reference return by address!!!
     */
    T& operator[](size_type i) {
        return first[i];
    }

    const T& operator[](size_type i) const {
        return first[i];
    }

    iterator begin() {
        return first;
    }

    const_iterator begin() const {
        return first;
    }

    iterator end() {
        return last;
    }

    const_iterator end() const {
        return last;
    }

    void push_back(const T& val) {
        if (current == last)
            grow();
        uncheck_append(val);
    }

private:
    iterator first;
    iterator current;
    iterator last;

    void create();
    void create(size_type n, const T& val);
    void create(iterator begin, iterator end);

    void grow();
    void uncheck_append(const T& val);

    void uncreate();
};
