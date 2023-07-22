#include "iostream"
#include "string"

using std::string;
using std::cin;

int t;

bool isChar(char c)
{
    return (c >= 'a' && c <= 'z');
}

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        string word = "";

        for (int i = 0; i < 8; ++i)
        {
            string temp;
            cin >> temp;

            for (int j = 0; j < 8; ++j)
            {
                if (isChar(temp[j]))
                {
                    word += temp[j];
                }
            }
        }

        printf("%s\n", word.c_str());
    }
}