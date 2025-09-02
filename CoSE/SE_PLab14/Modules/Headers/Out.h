#pragma once;
#include <fstream>;
#include "Parm.h";

namespace Out {
    struct OUT {
        unsigned char* text;
        wchar_t outfile[PARM_MAXSIZE];
        std::ofstream* stream;
    };

    static const OUT INITOUT = {nullptr,L"",NULL};
    OUT getout(wchar_t outfile[PARM_MAXSIZE], unsigned char* text);
    void Write (OUT out);
    void Close (OUT out);
}