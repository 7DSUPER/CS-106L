template<class T>
RealVector<T>::RealVector() :
    logical_size(0), array_size(2)
{
    elems = new T[kInitialSize];
}

template<class T>
RealVector<T>::RealVector(size_t n, const T &val) :
    logical_size(n), array_size(2 * n)
{
    elems = new T[array_size];
    for (size_t i = 0; i < logical_size; ++i) {
        elems[i] = val;
    }
}

template<class T>
RealVector<T>::~RealVector()
{
    delete [] elems;
}

template<class T>
size_t RealVector<T>::size() const {
    return logical_size;
}

template<class T>
bool RealVector<T>::empty() const {
    return size() == 0;
}

template<class T>
T& RealVector<T>::at(size_t indx) {
    if (indx >= size()) {
        std::__throw_out_of_range("Out of bounds access of vector");
    } else {
        return *(begin() + indx);
    }
}

template<class T>
void RealVector<T>::insert(size_t pos, const T& elem) {
    if (size() == array_size) {
        grow();
    }
    for (size_t i = size(); i != pos; --i) {
        elems[i] = elems[i - 1];
    }
    elems[pos] = elem;
    ++logical_size;
}

template<class T>
void RealVector<T>::grow() {
    T *new_elems = new T[array_size * 2];
    for (size_t i = 0; i != size(); ++i) {
        new_elems[i] = elems[i];
    }
    delete [] elems;
    array_size *= 2;
    elems = new_elems;
}

template<class T>
void RealVector<T>::push_back(const T& elem) {
    insert(end(), elem);
}

template<class T>
typename RealVector<T>::iterator RealVector<T>::begin() {
    return elems;
}

template<class T>
typename RealVector<T>::iterator RealVector<T>::end() {
    return begin() + size();
}

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::c_begin() const {
    return elems;
}

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::c_end() const {
    return c_begin() + size();
}