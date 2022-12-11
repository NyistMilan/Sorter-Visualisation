//
// Created by milanyist on 2022.10.30..
//

#include "base_sorter.h"

template<typename T>
class BubbleSorter : public BaseSorter<T>{
public:
    void sort(T* array, int size, std::function<bool(T,T)> f){
        for(int i = size - 1; i > 0; i--)
            for(int j = 0; j < i; j++)
                if(!f(array[j], array[j + 1]))
                    BaseSorter<T>::swap(array[j], array[j + 1]);
    }
};

