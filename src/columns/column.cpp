//
// Created by milanyist on 2022.11.22..
//

#include "column.h"

int Column::compares = 0;
int Column::swaps = 0;

Column::Column(int value, int index): value{value}, index{index}{}

bool Column::operator==(Column const& rhs){
    if(listener) listener->compare(index, rhs.index, false);
    compares++;
    return (value == rhs.value);
}

bool Column::operator<(Column const& rhs){
    if(listener) listener->compare(index, rhs.index, false);
    compares++;
    return (value < rhs.value);
}

bool Column::operator<=(Column const& rhs){
    if(listener) listener->compare(index, rhs.index, false);
    compares++;
    return (value <= rhs.value);
}

bool Column::operator>(Column const& rhs){
    if(listener) listener->compare(index, rhs.index, false);
    compares++;
    return (value > rhs.value);
}

bool Column::operator>=(Column const& rhs){
    if(listener) listener->compare(index, rhs.index, false);
    compares++;
    return (value >= rhs.value);
}

Column& Column::operator=(Column const& other){
    if(this != &other) {
        value = other.value;
        (index == -1) ? index = other.index : swaps++;
        if (listener) listener->compare(other.index, index, true);
    }
    return *this;
}

int Column::getValue() const{
    return value;
}

void Column::setListener(ColumnListener* colListener){
    listener = colListener;
}

void Column::setCompares(int num){
    compares = num;
}

int Column::getCompares(){
    return compares;
}

void Column::setSwaps(int num){
    swaps = num;
}

int Column::getSwaps(){
    return (swaps / 2);
}

