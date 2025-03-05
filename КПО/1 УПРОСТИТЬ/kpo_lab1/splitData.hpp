#include <vector>
#include <string>
using namespace std;
std::vector<int> splitData(string date)
{
    std::vector<int> temp;

    temp.push_back(stoi(date.substr(0, 2))); // day
    temp.push_back(stoi(date.substr(2, 2))); // month
    temp.push_back(stoi(date.substr(4, 4))); // year

    return temp;
}