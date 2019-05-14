//
//  chain.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/12/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef chain_hpp
#define chain_hpp

namespace itertools{
    
    template <typename T, typename E>
    class _chain{
    private:
        T _First;
        E _Second;
    public:
        _chain(const T first,const E second) : _First(first), _Second(second){}

        class iterator{
        private:
            typename T::iterator _ItrFirst,_FirstEnd;
            typename E::iterator _ItrSecond;
        public:
            iterator(const typename T::iterator &first,const typename T::iterator end,const typename E::iterator &second):_ItrFirst(first),_FirstEnd(end),_ItrSecond(second){}
            const auto operator*(){
                if (_ItrFirst != _FirstEnd)
                    return *_ItrFirst;
                return *_ItrSecond;
            }
            iterator &operator++(){
                if (_ItrFirst != _FirstEnd)
                    ++_ItrFirst;
                else
                    ++_ItrSecond;
                return *this;
            }
            const iterator operator++(int) {
                iterator tmp= *this;
                iterator::operator++();
                return tmp;
            }
            bool operator==(const iterator& a) const {
                return (_ItrFirst == a._ItrFirst && this->_ItrSecond == a._ItrSecond);
            }
            bool operator!=(const iterator &a) const{
                return !(*this==a);
            }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        const iterator begin() {
            return iterator(_First.begin(),_First.end(),_Second.begin());
        }
        const iterator end(){
            return iterator(_First.end(),_First.end(),_Second.end());
        }
    };
    template <typename IT, typename IE>
    _chain<IT, IE> chain(IT start1, IE start2){
        return _chain<IT, IE>(start1, start2);
    }
}
#endif /* chain_hpp */
