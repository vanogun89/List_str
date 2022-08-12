#include <iostream>
#include "string"

using namespace std;

struct Knot                                            //узел списка
{
    string val;
    Knot* next;
    Knot(string val1) : val(val1), next(nullptr) {}
};

struct List                                           //формирование списка
{
    Knot* first;
    Knot* last;
    List(): first(nullptr), last(nullptr) {}
    bool exists() 
    {
        return first == nullptr;
    }
    void push_back(string val1)
    {
        Knot* y = new Knot(val1);
        if (exists())
        {
            first = y;
            last = y;
            return;
        }
        last -> next = y;
        last = y;
    }
    void returny()
    {
        if (exists()) 
            return;
        Knot* y = first;
        while (y)
        {
            cout << y -> val << "  ";
            y = y -> next;
        }
        cout << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    List C, N, U;
    string tert, word;
    int schet = 0;
    cout << "Введите строку: ";
    getline(cin,tert);
    tert += (char)' ';
    cout << endl;
    int u = 0;
    for (int i = 0; i <= tert.length(); i++)
    { 
        if (tert[i] != (char)' ')
        {
            schet++;
        }
        if (tert[i] == (char)' ')
        {
            for (int j = i - schet; j < i; j++)
            {
                word += (char)tert[j];
            }
            if (schet % 2 == 0)
            {
                C.push_back(word);
            }
            else
            {
                N.push_back(word);
            }
            schet = 0;
            word.clear();
        }
    }
    cout << "Четные слова:" << endl;
    C.returny();
    cout << "Нечетные слова:" << endl;
    N.returny();
}
