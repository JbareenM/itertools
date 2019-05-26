//
//  powerset.hpp
//  iterable
//
//  Created by Jeme Jbareen on 5/14/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//
//https://stackoverflow.com/questions/24365954/how-to-generate-a-power-set-of-a-given-set

#ifndef powerset_hpp
#define powerset_hpp
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

namespace itertools{
    template<typename T>
    class powerset{
    private:
        T _set;
    public:
        powerset(const T set):_set(set){}
         //iterator_class________________________________________________________
        class const_iterator {
        private:
            const T& _cur;
            uint _Total;
        public:
            const_iterator(const T& cur, int index):_cur(cur), _Total(index){}
            const_iterator& operator++() {
                ++_Total;
                return *this;
            }
            auto operator*() const {
                vector<typename remove_const<typename remove_reference<decltype(*(_set.begin()))>::type>::type> ans;
                int i=1;
                for (auto j : _cur){
                    if (i & _Total)
                        ans.push_back(j);
                    i=i<<1;
                }
                return ans;
            }
            const const_iterator operator++(int) {
                const_iterator tmp= *this;
                ++_Total;
                return tmp;
            }
            bool operator==(const const_iterator& rhs) const {_Total == rhs._Total;}
            bool operator!=(const const_iterator& rhs) const {return !(_Total == rhs._Total);}
        };//iterator_class________________________________________________________
        //_____________________________________________________
        auto begin() const {return const_iterator(_set, 0);}
        auto end() const {
            int size = 0;
            for (auto i : _set)
                size += 1;
            return const_iterator(_set, int(pow(2,size)));
        }
    };
    template <typename IT>
    std::ostream &operator<<(std::ostream &out, const std::vector<IT> &vec){
        out << "{";
        auto i = vec.begin();
        while (i != vec.end()){
            out<<*i;
            i++;
            if (i != vec.end())
                out<<",";
        }
        out << "}";
        return out;
    }
}
#endif /* powerset_hpp */
