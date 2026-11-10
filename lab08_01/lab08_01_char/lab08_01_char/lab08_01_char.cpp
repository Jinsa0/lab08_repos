// lab08_01_char.cpp
// Кіц Роман Романович
// Лабораторна робота № 8.1 char
// Пошук та заміна символів у літерному рядку.
// Варіант 12

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція підрахунку символів, що входять у "BASIC", за допомогою strpbrk
int Count(char* s)
{
    int k = 0,
        pos = 0;
    char* t;
    while ((t = strpbrk(s + pos, "BASIC")) != nullptr)
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}

// Функція заміни "BASIC" на "Delphi" за допомогою strstr, strncat, strcat
// Пам'ять виділяється відповідно до розширення: len * 6 / 5 + 1
char* Change(char* s)
{
    size_t len = strlen(s);
    char* t = new char[len * 6 / 5 + 1];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;

    while ((p = strstr(s + pos1, "BASIC")) != nullptr)
    {
        pos2 = p - s + 5;
        strncat(t, s + pos1, p - (s + pos1));
        strcat(t, "Delphi");
        pos1 = pos2;
    }
    strcat(t, s + pos1);

    strcpy(s, t);
    return t;
}

int main()
{
    char str[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " characters from 'BASIC'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}