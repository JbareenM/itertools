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
    class chain{
    private:
        T _First;
        E _Second;
    public:
        chain(const T first,const E second) : _First(first), _Second(second){}
        
        class const_iterator{
        private:
            typename T::const_iterator _ItrFirst,_FirstEnd;
            typename E::const_iterator _ItrSecond;
        public:
            const_iterator(const typename T::const_iterator &first,const typename T::const_iterator end,const typename E::const_iterator &second):_ItrFirst(first),_FirstEnd(end),_ItrSecond(second){}
            const auto operator*() const{
                if (_ItrFirst != _FirstEnd)
                    return *_ItrFirst;
                return *_ItrSecond;
            }
            const_iterator &operator++(){
                if (_ItrFirst != _FirstEnd)
                    ++_ItrFirst;
                else
                    ++_ItrSecond;
                return *this;
            }
            const const_iterator operator++(int) {
                const_iterator tmp= *this;
                const_iterator::operator++();
                return tmp;
            }
            bool operator==(const const_iterator& a) const {
                return (_ItrFirst == a._ItrFirst && this->_ItrSecond == a._ItrSecond);
            }
            bool operator!=(const const_iterator &a) const{
                return !(*this==a);
            }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        const_iterator begin() const{
            return const_iterator(_First.begin(),_First.end(),_Second.begin());
        }
        const_iterator end() const{
            return const_iterator(_First.end(),_First.end(),_Second.end());
        }
    };
}
#endif /* chain_hpp */
