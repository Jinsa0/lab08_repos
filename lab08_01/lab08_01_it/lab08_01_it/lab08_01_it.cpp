// lab08_01_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 8.1 іт
// Пошук та заміна символів у літерному рядку.
// Варіант 12

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція для підрахунку кількості символів, що входять у слово "BASIC"
int Count(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C')
            k++;
    }
    return k;
}

// Функція заміни слова "BASIC" на "Delphi"
// Оскільки "BASIC" (5 симв.) замінюється на "Delphi" (6 симв.),
// пам'ять виділяється з коефіцієнтом розширення: len * 6 / 5 + 1
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 5)
        return str;

    char* tmp = new char[len * 6 / 5 + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i + 4 < len)
    {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' &&
            str[i + 3] == 'I' && str[i + 4] == 'C')
        {
            strcat(t, "Delphi");
            t += 6;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    while (str[i] != '\0')
    {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
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