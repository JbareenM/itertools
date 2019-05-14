//
//  zip.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/13/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef zip_hpp
#define zip_hpp
#include <iostream>
#include <sstream>

namespace itertools{
    
    template<typename T, typename E>
    class _zip{
    private:
        T _First;
        E _Second;
    public:
        _zip(const T first, const E second):_First(first),_Second(second){}
        //iterator_class________________________________________________________
        class iterator {
        private:
            typename T::iterator _FirstCur;
            typename T::iterator _EndFirst;
            typename E::iterator _SecCur;
            typename E::iterator _EndSec;
        public:
            iterator(typename T::iterator a, typename T::iterator b, typename E::iterator c,typename E::iterator d):_FirstCur(a),_EndFirst(b),_SecCur(c),_EndSec(d){}
            
            auto operator*() {
                std::ostringstream ostr;
                ostr<<*_FirstCur<<","<<*_SecCur;
                return ostr.str();
            }
            iterator& operator++() {
                ++_FirstCur;
                ++_SecCur;
                return *this;
            }
            const iterator operator++(int) {
                iterator tmp= *this;
                iterator::operator++();
                return tmp;
            }
            bool operator==(const iterator& rhs) const {
                return _FirstCur == rhs._FirstCur && _SecCur == rhs._SecCur;
            }
            bool operator!=(const iterator& rhs) const {
                return !(*this==rhs);
            }//iterator_class________________________________________________________
            //_____________________________________________________
        };
        iterator begin(){
            return iterator(_First.begin(), _First.end(), _Second.begin(), _Second.end());
        };
        iterator end(){
            return iterator(_First.end(), _First.end(), _Second.end(), _Second.end());
        }
    };
    template <typename IT, typename IE>
    _zip<IT, IE> zip(IT a, IE b){
        return _zip<IT, IE>(a, b);
    }
}
#endif /* zip_hpp */
