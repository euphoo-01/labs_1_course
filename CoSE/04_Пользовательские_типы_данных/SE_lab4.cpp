#include <iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;
struct Date {
    day dd;
    month mm;
    year yyyy;
};

bool operator > (Date a, Date b) {
    if (a.yyyy != b.yyyy) {
        return a.yyyy > b.yyyy;
    }
    
    if (a.mm != b.mm) {
        return a.mm > b.mm;
    }
    
    return a.dd > b.dd;
}

bool operator < (Date a, Date b) {
    if (a.yyyy != b.yyyy) {
        return a.yyyy < b.yyyy;
    }
    
    if (a.mm != b.mm) {
        return a.mm < b.mm;
    }
    
    return a.dd < b.dd;
}

bool operator == (Date a, Date b) {
    return a.dd == b.dd && a.mm == b.mm && a.yyyy == b.yyyy;
}

int main() {
    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };

    if (date1 < date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 > date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 == date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 == date3) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}