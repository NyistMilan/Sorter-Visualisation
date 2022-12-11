//
// Created by milanyist on 2022.10.31..
//

#ifndef CPP_HF2_COLUMN_LISTENER_H
#define CPP_HF2_COLUMN_LISTENER_H

class ColumnListener{
public:
    ColumnListener() = default;
    virtual void compare(int a, int b, bool swap) = 0;
    virtual ~ColumnListener() = default;
};

#endif //CPP_HF2_COLUMN_LISTENER_H
