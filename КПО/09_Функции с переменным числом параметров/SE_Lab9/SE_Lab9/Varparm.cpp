#include "Varparm.h"
#include <cstdarg>
#include <climits>
#include <cfloat>

namespace Varparm {
    int ivarparm(int count, ...) {
        va_list args;
        va_start(args, count);
        int product = 1;
        for (int i = 0; i < count; ++i) {
            product *= va_arg(args, int);
        }
        va_end(args);
        return product;
    }

    short svarparm(short count, ...) {
        va_list args;
        va_start(args, count);
        short max = static_cast<short>(va_arg(args, int)); // short передается как int
        for (int i = 1; i < count; ++i) {
            short value = static_cast<short>(va_arg(args, int));
            if (value > max) max = value;
        }
        va_end(args);
        return max;
    }

    double fvarparm(...) {
        int a;
        va_list args;
        va_start(args,a);
        double sum = 0.0;
        double value;
        while ((value = va_arg(args, double)) != static_cast<double>(FLT_MAX)) {
            sum += value;
        }
        va_end(args);
        return sum;
    }

    double dvarparm(...) {
        int a;
        va_list args;
        va_start(args, a);
        double sum = 0.0;
        double value;
        while ((value = va_arg(args, double)) != DBL_MAX) {
            sum += value;
        }
        va_end(args);
        return sum;
    }
}