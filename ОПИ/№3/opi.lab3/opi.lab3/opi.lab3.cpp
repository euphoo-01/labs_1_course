#include <iostream>
// LavshukStanislav2007
// 4C 61 76 73 68 75 6B 53 74 61 6E 69 73 6C 61 76 32 30 30 37
// 4c 61 76 73 68 75 6b 53 74 61 6e 69 73 6c 61 76 32 30 30 37
// 4c00 6100 7600 7300 6800 7500 6b00 5300 7400 6100 6e00 6900 7300 6c00 6100 7600 3200 3000 3000 3700

// ЛавшукСтаниславАлександрович2007
// CB E0 E2 F8 F3 EA D1 F2 E0 ED E8 F1 EB E0 E2 C0 EB E5 EA F1 E0 ED E4 F0 EE E2 E9 F7 32 30 30 37
// d0 9b d0 b0 d0 b2 d1 88 d1 83 d0 ba d0 a1 d1 82 d0 b0 d0 bd d0 b8 d1 81 d0 bb d0 b0 d0 b2 d0 90 d0 bb d0 b5 d0 ba d1 81 d0 b0 d0 bd d0 b4 d1 80 d0 be d0 b2 d0 b8 d1 87 32 30 30 37
// 1b04 3004 3204 4804 4304 3a04 2104 4204 3004 3d04 3804 4104 3b04 3004 3204 1004 3b04 3504 3a04 4104 3004 3d04 3404 4004 3e04 3204 3804 4704 3200 3000 3000 3700

// Лавшук2007Stanislav
// CB E0 E2 F8 F3 EA 32 30 30 37 53 74 61 6E 69 73 6C 61 76
// d0 9b d0 b0 d0 b2 d1 88 d1 83 d0 ba 32 30 30 37 53 74 61 6e 69 73 6c 61 76
// 1b04 3004 3204 4804 4304 3a04 3200 3000 3000 3700 5300 7400 6100 6e00 6900 7300 6c00 6100 7600
int main() {
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "LavshukStanislav2007";
	char rfie[] = "ЛавшукСтаниславАлександрович2007";
	char lr[] = "Лавшук2007Stanislav";

	wchar_t Lfie[] = L"LavshukStanislav2007";
	wchar_t Rfie[] = L"ЛавшукСтаниславАлександрович2007";
	wchar_t LR[] = L"Лавшук2007Stanislav";

	std::cout << hello << lfie << std::endl;
	return 0;
}