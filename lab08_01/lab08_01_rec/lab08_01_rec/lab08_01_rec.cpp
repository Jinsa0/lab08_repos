// lab08_01_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 8.1 рек
// Пошук та заміна символів у літерному рядку.
// Варіант 12

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція підрахунку символів, що входять у слово "BASIC"
int Count(const char* str, int i)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    return 0;
}

// Рекурсивна функція заміни "BASIC" на "Delphi"
// Пам'ять для dest виділяється заздалегідь з урахуванням розширення
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0' && str[i + 1] != '\0' && str[i + 2] != '\0' &&
        str[i + 3] != '\0' && str[i + 4] != '\0')
    {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' &&
            str[i + 3] == 'I' && str[i + 4] == 'C')
        {
            strcat(t, "Delphi");
            return Change(dest, str, t + 6, i + 5);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        while (str[i] != '\0')
        {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " characters from 'BASIC'" << endl;

    // Пам'ять виділяється під максимальну потенційну довжину після заміни (100 * 6 / 5 + 1 = 121, взято 151)
    char* dest1 = new char[151];
    dest1[0] = '\0';

    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}