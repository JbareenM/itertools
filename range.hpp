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
    class _range{
    private:
        T _begin;
        T _end;
    public:
        _range(const T begin,const T end):_begin(begin),_end(end){}
        //iterator_class________________________________________________________
        class iterator{
        private:
            T _ItrCurrent;
        public:
            iterator(T itr):_ItrCurrent(itr){}
            T &operator*() { return _ItrCurrent; }
            iterator &operator++(){
                ++_ItrCurrent;
                return *this;
            }
            const iterator operator++(int){
                iterator tmp = *this;
                _ItrCurrent++;
                return tmp;
            }
            bool operator==(const iterator &a) const { return _ItrCurrent == a._ItrCurrent; }
            bool operator!=(const iterator &a) const { return _ItrCurrent != a._ItrCurrent; }
        };//iterator_class________________________________________________________
        //_____________________________________________________
        iterator begin() const{return iterator(_begin);}
        iterator end() const{return iterator(_end);}
    };
    template <typename IT>
    _range<IT> range(IT begin, IT end){
        return _range<IT>(begin, end);
    }
}
#endif /* range_hpp */
