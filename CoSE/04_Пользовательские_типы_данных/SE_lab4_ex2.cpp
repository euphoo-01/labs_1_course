#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

typedef int day;
typedef int month;
typedef int year;
typedef int hour;
typedef int minute;

typedef string ID;
typedef string Owner;
typedef float Balance;
typedef float Amount;

struct Date {
    day dd;
    month mm;
    year yyyy;
    hour hh;
    minute minmin;
};

struct BankAccount {
    ID id;
    Owner owner;
    Balance balance;
};

struct TransferInfo {
    ID to;
    Date date;
    Amount amount;
};

struct WithdrawInfo {
    ID from;
    Date date;
    Amount amount;
};

TransferInfo operator >>(Amount amount, BankAccount& to) {
    Date date;
    time_t currentTime = time(nullptr);
    tm localTime = *localtime(&currentTime);
    date.dd = localTime.tm_mday;
    date.mm = localTime.tm_mon + 1; // Месяцы начинаются с 0
    date.yyyy = localTime.tm_year + 1900; // Года отсчитываются от 1900
    date.hh = localTime.tm_hour;
    date.minmin = localTime.tm_min;

    to.balance += amount;
    cout << "Перевод выполнен успешно. Сумма на счете: " << to.balance << "$" << endl;
    return { to.id, date, amount };
}

WithdrawInfo operator <<(Amount amount, BankAccount& from) {
    Date date;
    time_t currentTime = time(nullptr);
    tm localTime = *localtime(&currentTime);
    date.dd = localTime.tm_mday;
    date.mm = localTime.tm_mon + 1;
    date.yyyy = localTime.tm_year + 1900;
    date.hh = localTime.tm_hour;
    date.minmin = localTime.tm_min;

    if (from.balance < amount) {
        return { from.id, date, -1.0f };
    }
    from.balance -= amount;
    cout << "Снятие выполнено успешно. Сумма на счете: " << from.balance << "$" << endl;
    return { from.id, date, amount };
}

string dateToStr(const Date& date) {
    ostringstream oss;
    oss << date.dd << '/' << date.mm << '/' << date.yyyy
        << ' ' << date.hh << ':' << date.minmin;
    return oss.str();
}

void printWithdrawInfo(WithdrawInfo withdraw) {
    if (withdraw.amount != -1.0f) {
        cout << "======== ЧЕК =========" << endl
            << "Снятие со счета: " << withdraw.from << endl
            << "Сумма снятия: " << withdraw.amount << endl
            << "Дата снятия: " << dateToStr(withdraw.date) << endl;
    }
    else {
        cout << "Недостаточно денег для снятия!" << endl;
    }
}
void printTransferInfo(TransferInfo transfer) {
    cout << "======== ЧЕК =========" << endl
        << "Пополнение счета: " << transfer.to << endl
        << "Сумма пополнения: " << transfer.amount << endl
        << "Дата пополнения: " << dateToStr(transfer.date) << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankAccount account1 = { "897293479250000ESKUFH9186", "Петров Василий Васильевич", 1000 };
    BankAccount account2 = { "897270179250000DIJDAQ0010", "Иванов Иван Иванович", 300 };

    TransferInfo transaction1 = 1000 >> account1;
    printTransferInfo(transaction1);

    WithdrawInfo transaction2 = 1000 << account1;
    printWithdrawInfo(transaction2);

    WithdrawInfo transaction3 = 1000 << account2;
    printWithdrawInfo(transaction3);

    return 0;
}