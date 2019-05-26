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
    class zip{
    private:
        T _First;
        E _Second;
    public:
        zip(const T first, const E second):_First(first),_Second(second){}
        //iterator_class________________________________________________________
        class const_iterator {
        private:
            typename T::const_iterator _FirstCur,_EndFirst;
            typename E::const_iterator _SecCur,_EndSec;
        public:
            const_iterator(typename T::const_iterator a, typename T::const_iterator b, typename E::const_iterator c,typename E::const_iterator d):_FirstCur(a),_EndFirst(b),_SecCur(c),_EndSec(d){}
            
            auto operator*() const{
                std::ostringstream ostr;
                ostr<<*_FirstCur<<","<<*_SecCur;
                return ostr.str();
            }
            const_iterator& operator++() {
                ++_FirstCur;
                ++_SecCur;
                return *this;
            }
            const const_iterator operator++(int) {
                const_iterator tmp= *this;
                const_iterator::operator++();
                return tmp;
            }
            bool operator==(const const_iterator& rhs) const {
                return _FirstCur == rhs._FirstCur && _SecCur == rhs._SecCur;
            }
            bool operator!=(const const_iterator& rhs) const {
                return !(*this==rhs);
            }//iterator_class________________________________________________________
            //_____________________________________________________
        };
        const_iterator begin() const{
            return const_iterator(_First.begin(), _First.end(), _Second.begin(), _Second.end());
        };
        const_iterator end() const{
            return const_iterator(_First.end(), _First.end(), _Second.end(), _Second.end());
        }
    };
}
#endif /* zip_hpp */
