//
//  range.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/12/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef range_hpp
#define range_hpp

namespace itertools{
    template <typename T>
    class range{
    private:
        T _begin;
        T _end;
    public:
        range(const T begin,const T end):_begin(begin),_end(end){}
        //iterator_class________________________________________________________
        class const_iterator{
        private:
            T _ItrCurrent;
        public:
            const_iterator(T itr):_ItrCurrent(itr){}
            T operator*() const{ return _ItrCurrent; }
            const_iterator &operator++(){
                ++_ItrCurrent;
                return *this;
            }
            const const_iterator operator++(int){
                const_iterator tmp = *this;
                _ItrCurrent++;
                return tmp;
            }
            bool operator==(const const_iterator &a) const { return _ItrCurrent == a._ItrCurrent; }
            bool operator!=(const const_iterator &a) const { return _ItrCurrent != a._ItrCurrent; }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        const_iterator begin() const{return const_iterator(_begin);}
        const_iterator end() const{return const_iterator(_end);}
    };
}
#endif /* range_hpp */
