#ifndef _RealVector_
#define _RealVector_

#include <string>
#include <algorithm>



template<class T> class RealVector {
private:
    void grow();
    T *elems;
    size_t logical_size;
    size_t array_size;
public:
    const size_t kInitialSize = 2;
    
    RealVector();
    RealVector(size_t n, const T &val);
    ~RealVector();

    using iterator = T*;
    using const_iterator = const T*;


    size_t size() const;
    bool empty() const;

    T& at(size_t indx);

    void insert(size_t pos, const T& elem);
    void push_back(const T& elem);

    iterator begin(); // T* begin()
    iterator end();
    const_iterator c_begin() const; // const T* c_begin()
    const_iterator c_end() const;
};

#include "realvector.cpp"

#endif