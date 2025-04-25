#include <stdarg.h>
#include "Call.h"

namespace Call {
	int _cdecl funcA(int a, int b, int c) {
		return a + b + c;
	}
	int _stdcall funcB(int* a, int b, int c) {
		return (*a) * b * c;
	}
	int _fastcall funcC(int a, int b, int c, int d) {
		return a + b + c + d;
	}
}
