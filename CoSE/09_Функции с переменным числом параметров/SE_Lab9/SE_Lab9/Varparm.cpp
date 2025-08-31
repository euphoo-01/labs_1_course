#include "Varparm.h"
#include <cfloat>

namespace Varparm {

    int ivarparm(int count, ...) {
        int* p = (int*)(&count + 1); // указатель на первый переменный аргумент
        int product = 1;
        for (int i = 0; i < count; ++i) {
            product *= p[i];
        }
        return product;
    }

    short svarparm(short count, ...) {
        int* p = (int*)(&count + 2); // переменные аргументы передаются как int
        int max = p[0];
        for (int i = 1; i < count; ++i) {
            if (p[i] > max) {
                max = p[i];
            }
        }
        return static_cast<short>(max);
    }

    double fvarparm(float first, ...) {
        double* p = (double*)(&first + 1); // после float идёт double (выравнивание!)
        double sum = first;
        while (*p == DBL_MAX) {
            float value = static_cast<float>(*p);
            sum += *p;
            ++p;
        }
        return sum;
    }

    double dvarparm(double first, ...) {
        double* p = &first + 1;
        double sum = first;
        while (*p == DBL_MAX) {
            sum += *p;
            ++p;
        }
        return sum;
    }

}
