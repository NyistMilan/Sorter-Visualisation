//
// Created by milanyist on 2022.11.22..
//

#ifndef CPP_HF2_COLUMN_H
#define CPP_HF2_COLUMN_H

#include "../view/column_listener.h"

class Column{
    static int compares;
    static int swaps;

    ColumnListener* listener = nullptr;
    int index = -1;
    int value = 0;
public:
    Column() = default;
    Column(int value, int index);
    void setListener(ColumnListener* colListener);
    Column& operator=(Column const& other);
    bool operator<(Column const& rhs);
    bool operator>(Column const& rhs);
    bool operator>=(Column const& rhs);
    bool operator<=(Column const& rhs);
    bool operator==(Column const& rhs);
    static void setCompares(int num);
    static void setSwaps(int num);
    static int getCompares();
    static int getSwaps();
    int getValue() const;
    ~Column() = default;
};

#endif //CPP_HF2_COLUMN_H
