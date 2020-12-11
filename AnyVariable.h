//
// Created by Дарья on 05.12.2020.
//

#ifndef LAB1_SEM5_ANYVARIABLE_H
#define LAB1_SEM5_ANYVARIABLE_H

#include "AnyVarBase.h"

template <typename T>
class AnyVariable: public AnyVarBase {
public:
    AnyVariable(const T& val): data(val) { }
    T GetValue() {
        return data;
    }

    virtual AnyVariable<T> * clone() const override {
        return new AnyVariable<T>(this->data);
    }
private:
    T data;
};


#endif //LAB1_SEM5_ANYVARIABLE_H
