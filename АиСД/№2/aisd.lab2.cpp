#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    long int n;

    cout << "Введите начальное N: ";
    cin >> n;
    if (n <= 0)
    {
        cerr << "Ошибка!" << endl;
        return 1;
    }
    string buffer = to_string(n) + "\n";
    char answer;
    int left = 1, right = n, x;
    do
    {
        if (left == right)
        {
            x = (left + right) / 2;
            cout << x << endl;
            buffer += to_string(x) + '\n';
            break;
        }
        x = (left + right) / 2;
        cout << x << endl;
        buffer += to_string(x) + '\n';
        cout << "Много (+), мало (-), угадал (1): ";
        cin >> answer;

        if (answer == '-')
        {
            left = x + 1;
        }
        else if (answer == '+')
        {
            right = x - 1;
        }

    } while (answer != '1' && left <= right);

    cout << "Результаты: " << endl
         << buffer;

    cout << "Максимальное количество шагов: " << round(log2(n)) << endl;
    left = 1;
    right = n;
    cout << n << endl;
    do
    {
        if (left == right)
        {
            cout << x << endl;
            break;
        }
        x = (right + left) / 2;
        right = x - 1;
        cout << x << endl;
    } while (left <= right);

    return 0;
}