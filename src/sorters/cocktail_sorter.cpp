//
// Created by milanyist on 2022.11.22..
//

#include "base_sorter.h"

template<typename T>
class CocktailSorter : public BaseSorter<T>{
public:
    void sort(T* array, int size, std::function<bool(T, T)> f){
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped){
            swapped = false;

            for (int i = start; i < end; ++i){
                if (f(array[i + 1], array[i])){
                    BaseSorter<T>::swap(array[i], array[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped)
                break;

            swapped = false;
            --end;
            for (int i = end - 1; i >= start; --i){
                if (f(array[i + 1], array[i])){
                    BaseSorter<T>::swap(array[i], array[i + 1]);
                    swapped = true;
                }
            }
            ++start;
        }
    }
};
