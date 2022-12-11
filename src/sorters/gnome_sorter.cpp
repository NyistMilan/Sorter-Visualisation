//
// Created by milanyist on 2022.11.22..
//

#include "base_sorter.h"

template<typename T>
class GnomeSorter : public BaseSorter<T>{
public:
    void sort(T* array, int size, std::function<bool(T, T)> f){
        int i = 0;
        while (i < size) {
            if (i == 0 || f(array[i - 1], array[i])) {
                i++;
            } else {
                BaseSorter<T>::swap(array[i], array[i - 1]);
                i--;
            }
        }
    }
};
