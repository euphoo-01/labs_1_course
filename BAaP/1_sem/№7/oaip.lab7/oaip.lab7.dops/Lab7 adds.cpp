#include <iostream>

void func_2()
{
    int count = 0;

    for(int fifty = 0; fifty <= 2; fifty++) {
        for(int twenty = 0; twenty <= 5; twenty++) {
            for(int five = 0; five <= 20; five++) {
                for(int two = 0; two <= 50; two++) {
                    if(fifty * 50 + twenty * 20 + five * 5 + two * 2 == 100) {
                        count++;
                    }
                }
            }
        }
    }

    std::cout << "Count = " << count;
}

void func_3()
{
    double C1, C2;
    std::cout << "Введите количество воды в первом сосуде (C1): ";
    std::cin >> C1;
    std::cout << "Введите количество воды во втором сосуде (C2): ";
    std::cin >> C2;

    for(int i = 0; i < 6; i++) {
        C2 += C1 / 2;
        C1 /= 2;

        C1 += C2 / 2;
        C2 /= 2;
    }

    std::cout << "Количество воды в первом сосуде после 12 переливаний: " << C1 << std::endl;
    std::cout << "Количество воды во втором сосуде после 12 переливаний: " << C2 << std::endl;

    return;
}

void func_4()
{
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                for(int l = 0; l <= 9; l++) {
                    int number = 1000 * i + 100 * j + 10 * k + l;

                    if(number % 2 == 0 && number % 7 == 0 && number % 11 == 0 &&
                        i + j + k + l == 30 &&
                        (i == j || i == k || i == l || j == k || j == l || k == l)) {
                        std::cout << "Номер автомобиля: " << number << std::endl;
                        return;
                    }
                }
            }
        }
    }

    return;
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	//func_2();
    //func_3();
    func_4();
}