#include "../Headers/Out.h";
#include "../Headers/Error.h"

#include <complex>
#include <cstring>

namespace Out {
    OUT getout(wchar_t outfile[PARM_MAXSIZE], unsigned char* text) {
        OUT out = Out::INITOUT;
        wcscpy(out.outfile,outfile);

        char coutfile[PARM_MAXSIZE];
        wcstombs(coutfile,outfile,PARM_MAXSIZE + 1);
        out.stream = new std::ofstream();
        out.stream->open(coutfile, std::ios::out);
        if (!out.stream->is_open() || !out.stream->good()) {
            delete out.stream;
            out.stream = nullptr;
            throw ERROR_THROW(114);
        }
        out.text = text;
        return out;
    }

    void Write(OUT out) {
        if (out.stream->good() || !out.stream->is_open()) {
            int idx = 0;
            while (out.text[idx] != '\0') {
                (*out.stream) << out.text[idx];
                idx++;
            }
            (*out.stream) << std::endl;
        } else {
            throw ERROR_THROW(1);
        }

    }

    void Close(OUT out) {
        if (out.stream->is_open() && out.stream->good()) {
            out.stream->close();
        }
        delete out.stream;
        out.stream = nullptr;
    }

}