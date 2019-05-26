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
    class powerset{
    private:
        T _set;
    public:
        powerset(const T s1):_set(s1){}
        //iterator_class________________________________________________________
        class _iterator{
        private:
            typename T::_iterator _cur;
        public:
            _iterator(const typename T::_iterator cur):_cur(cur){}
            _iterator &operator++(){
                _cur++;
                return *this;
            }
            auto &operator*() const{
                std::ostringstream ostr;
                ostr<<"";
                return ostr.str();
            }
            bool operator!=(const _iterator &rhs) const{
                return _cur != rhs._cur;
            }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        auto begin() const{return (_set.begin());}
        auto end() const{return (_set.end());}
    };
}

#endif /* powerset_hpp */
