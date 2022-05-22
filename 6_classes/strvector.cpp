//dont forget to include the .h file!
#include "strvector.h"
//implementation for strvector.cpp goes here!

StrVector::StrVector() :
    logicalSize(0), allocatedSize(kInitialSize)
{
    elems = new std::string[allocatedSize];
}
 
StrVector::StrVector(size_t n, const std::string &str) :
    logicalSize(n), allocatedSize(2 * n)
{
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), str);
}

StrVector::~StrVector() {
    delete [] elems;
}

bool StrVector::empty() const {
    if (size() == 0) {
        return true;
    }
    return false;
}

size_t StrVector::size() const {
    return logicalSize;
}

std::string &StrVector::operator[] (size_t index) {
    return *(begin() + index);
}

std::string StrVector::at(size_t index) {
    if (index >= size()) {
        std::__throw_out_of_range("Out of bounds access of vector");
    } else {
        return *(begin() + index);
    }
}

StrVector::iterator StrVector::insert(iterator pos, const std::string &elem) {
    int tmp = pos - begin();
    if (size() == allocatedSize) {
        grow();
    }
    pos = tmp + begin();
    std::copy_backward(pos, end(), end() + 1);
    *pos = elem;
    ++logicalSize;
    return pos;
}

void StrVector::push_back(const std::string &elem) {
    if (size() == allocatedSize) {
        grow();
    }
    *end() = elem;
    ++logicalSize;
}

StrVector::iterator StrVector::begin() {
    return elems;
}


StrVector::iterator StrVector::end() {
    return elems + size();
}


void StrVector::grow() {
    std::string *new_elem = new std::string[allocatedSize * 2];
    std::copy(begin(), end(), elems);
    delete[] elems;
    allocatedSize *= 2;
    elems = new_elem;
}