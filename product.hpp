//
//  product.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/14/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef product_hpp
#define product_hpp
#include<iostream>
#include <sstream>

namespace itertools{
    
    template<typename T, typename E>
    class _product{
    private:
        T _First;
        E _Second;
    public:
        _product(T first,E second):_First(first),_Second(second){}
        //iterator_class________________________________________________________
        class iterator{
        private:
            typename T::iterator _FirstCur,_EndFirst;
            typename E::iterator _SecCur,_SecFirst,_EndSec;
        public:
            iterator(const typename T::iterator a,const typename T::iterator b,const typename E::iterator c,const typename E::iterator d):_FirstCur(a),_EndFirst(b),_SecFirst(c),_SecCur(c),_EndSec(d){}
            auto operator*(){
                std::ostringstream ostr;
                ostr<<*_FirstCur<<","<<*_SecCur;
                return ostr.str();
            }
            iterator& operator++() {
                ++_SecCur;
                if (_SecCur == _EndSec){
                    _SecCur = _SecFirst;
                    ++_FirstCur;
                }
                return *this;
            }
            const iterator operator++(int) {
                iterator tmp= *this;
                iterator::operator++();
                return tmp;
            }
            bool operator==(const iterator& rhs) const {
                if ((_SecCur == _EndSec || _FirstCur == _EndFirst) && (rhs._SecCur == _EndSec || rhs._FirstCur == _EndFirst))
                    return true;
                return _FirstCur == rhs._FirstCur && _SecCur == rhs._SecCur;
            }
            bool operator!=(const iterator& rhs) const {
                return !(*this==rhs);
            }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        iterator begin() {
            return iterator(_First.begin(), _First.end(), _Second.begin(), _Second.end());
        }
        iterator end() {
            return iterator(_First.end(), _First.end(), _Second.end(), _Second.end());
        }
    };
    template <typename IT, typename IE>
    _product<IT, IE> product(IT a, IE b){
        return _product<IT, IE>(a, b);
    }
}
#endif /* product_hpp */
