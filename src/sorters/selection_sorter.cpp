//
// Created by milanyist on 2022.11.22..
//

#include "base_sorter.h"

template<typename T>
class SelectionSorter : public BaseSorter<T>{
public:
    void sort(T* array, int size, std::function<bool(T,T)> f){
        int i, j, index;
        for (i = 0; i < size - 1; ++i) {
            index = i;
            for (j = i + 1; j < size; ++j)
                if (f(array[j], array[index]))
                    index = j;
            if (index != i) {
                BaseSorter<T>::swap(array[index], array[i]);
            }
        }
    }
};


