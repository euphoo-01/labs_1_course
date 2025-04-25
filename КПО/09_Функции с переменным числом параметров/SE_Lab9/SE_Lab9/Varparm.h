#pragma once

#include <cstdarg>

namespace Varparm {
    int ivarparm(int count, ...);
    short svarparm(short count, ...);
    double fvarparm(...);
    double dvarparm(...);
}