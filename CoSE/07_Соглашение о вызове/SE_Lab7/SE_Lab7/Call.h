#pragma once

namespace Call {
	int _cdecl cdecll(int, int, int);
	int _stdcall cstd(int&, int, int);
	int _fastcall cfst(int, int, int, int);
}
