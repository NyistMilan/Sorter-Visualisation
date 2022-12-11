//
// Created by milanyist on 2022.10.30..
//

#ifndef CPP_HF2_BASE_SORTER_H
#define CPP_HF2_BASE_SORTER_H
#include <functional>

template<typename T>
class BaseSorter{
public:
    virtual void sort(T* array, int size, std::function<bool(T,T)> f) = 0;
    static inline void swap(T &a, T &b){
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }
    virtual ~BaseSorter() = default;
};


#endif //CPP_HF2_BASE_SORTER_H
