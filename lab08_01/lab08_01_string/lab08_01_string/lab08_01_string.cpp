// lab08_01_string.cpp
// Кіц Роман Романович
// Лабораторна робота № 8.1 string
// Пошук та заміна символів у літерному рядку.
// Варіант 12

#include <iostream>
#include <string>

using namespace std;

// Функція підрахунку символів, що входять у "BASIC", засобами std::string
int Count(const string& s)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find_first_of("BASIC", pos)) != string::npos)
    {
        k++;
        pos++;
    }
    return k;
}

// Функція заміни "BASIC" на "Delphi" засобами std::string
// Клас std::string автоматично виділяє та перевиділяє необхідну пам'ять
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("BASIC", pos)) != string::npos)
    {
        s.replace(pos, 5, "Delphi");
        pos += 6;
    }
    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "String contained " << Count(str) << " characters from 'BASIC'" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}