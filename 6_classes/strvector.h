//in case mutliple files in a project include strvector, 
//this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>

class StrVector {
    public:
        //type alias (this is how iterator types work!)
        using iterator = std::string*;

        //define an initial size for your underlying array
        const size_t kInitialSize = 2;
        
        //constructors and destructor
        StrVector();
        StrVector(size_t n, const std::string &str);
        ~StrVector();

        bool empty() const;
        size_t size() const;

        std::string &operator[] (size_t index);
        const std::string &operator[] (size_t index) const;
        std::string at(size_t index);

        void push_back(const std::string &elem);
        iterator insert(iterator pos, const std::string &elem);

        iterator begin();
        iterator end();
        
    private:
        void grow();
        std::string* elems;
        size_t logicalSize;
        size_t allocatedSize;
};

#endif // STRVECTOR_H


