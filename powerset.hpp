//
//  powerset.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/14/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef powerset_hpp
#define powerset_hpp
#include<iostream>
#include<sstream>

namespace itertools{
    template <typename T>
    class _powerset{
    private:
        T _set;
    public:
        _powerset(const T s1):_set(s1){}
        //iterator_class________________________________________________________
        class iterator{
        private:
            typename T::iterator _cur;
        public:
            iterator(const typename T::iterator cur):_cur(cur){}
            iterator &operator++(){
                _cur++;
                return *this;
            }
            const auto &operator*(){
                std::ostringstream ostr;
                ostr<<"";
                return ostr.str();
            }
            bool operator!=(const iterator &rhs) const{
                return _cur != rhs._cur;
            }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        iterator begin(){
            return (_set.begin());
        }
        iterator end(){
            return (_set.end());
        }
    };
    template <typename IT>
    _powerset<IT> powerset(IT a){
        return _powerset<IT>(a);
    }
}

#endif /* powerset_hpp */
