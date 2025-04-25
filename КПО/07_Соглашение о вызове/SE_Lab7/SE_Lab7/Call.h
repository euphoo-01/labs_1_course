#pragma once

#include <stdarg.h>

namespace Call {
	int _cdecl funcA(int, int, int);
	int _stdcall funcB(int*, int, int);
	int _fastcall funcC(int, int, int, int);
}
