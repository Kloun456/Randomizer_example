#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void foo(ifstream& fin);
string Random_example();
string Random_example_with_bracket();
int Random_number();
char Random_signs();
int discharge(int numb);


int main()
{
    ifstream fin;
    string s;
    fin.open("File.txt");
    s = Random_example();
    cout << s;

}

void foo(ifstream& fin)
{

}

string Random_example()
{
    srand(time(0));
    string example;
    int quantity_number = rand() % 3 + 2, rand_numb, result = 0;
    char sign = '+';
    while (quantity_number)
    {
        rand_numb = Random_number();
        example += to_string(rand_numb);
        example += " ";

        switch (sign)
        {
        case '+':
            result += rand_numb;
            break;
        case '-':
            result -= rand_numb;
            break;
        }

        if (result < 0)
        {
            quantity_number++;
            example.erase(example.size() - 3 - discharge(rand_numb));
            result += rand_numb;
        }
        sign = Random_signs();
        if (quantity_number - 1)
            example += sign;
        else
            example += " =";
        example += " ";
        quantity_number--;
    }
    return example;
}

string Random_example_with_bracket()
{
    string example;


    return example;
}

int Random_number()
{
    int x = 0, random = rand() % 2 + 1;; // later replace x on float
    for (int i = 0; i < random; i++) // two-digit number
        x = x * 10 + rand() % 10;
    return x;
}

char Random_signs()
{
    int n = rand() % 2;
    switch (n)
    {
    case 0:
        return '+';
    case 1:
        return '-';
    }
}

int discharge(int numb)
{
    int rank = 0;
    while (numb)
    {
        rank++;
        numb /= 10;
    }
    return rank;
}