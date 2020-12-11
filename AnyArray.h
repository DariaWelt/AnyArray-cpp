//
// Created by Дарья on 05.12.2020.
//

#ifndef LAB1_SEM5_ANYARRAY_H
#define LAB1_SEM5_ANYARRAY_H
#include "AnyVariable.h"
#include <vector>
#include <memory>

class AnyArray {
public:
    // friend method for access to privates fields in std::swap
    friend void swap(AnyArray& a1, AnyArray& a2) {
        swap(a1.vectorAny, a2.vectorAny);
    }

    AnyArray& operator=(AnyArray a) {
        // calling friend function
        swap(*this, a);
        return *this;
    }

    AnyArray() {}
    ~AnyArray() {
        for (const auto &item : vectorAny) {
            delete(item);
        }
    }

    AnyArray(const AnyArray& arr) {
        for (const auto &item : arr.vectorAny) {
            // deep copy of vector content
            vectorAny.push_back(item->clone());
        }
    }

    template<typename T>
    void Push(T val) {
        AnyVarBase* var= new AnyVariable<T>(val);
        vectorAny.push_back(var);
    }
    template<typename T>
    void Get(int i, T& val) {
        auto anyVarT = dynamic_cast<AnyVariable<T>*>(vectorAny[i]);
        if (anyVarT == nullptr) {
            std::cout << "Can't cast. Wrong type. Try again" << std::endl;
            return;
        }
        val = anyVarT->GetValue();
    }

private:
    std::vector<AnyVarBase*> vectorAny;
};

#endif //LAB1_SEM5_ANYARRAY_H
