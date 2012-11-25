#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool Reverse_words(char str[]);
void Reverse_string(char str[], int start, int end);
bool Reverse_words(string& str);
int main();

bool Reverse_words(char str[])
{
    int start =0, end = 0, length;
    length = strlen(str);

    Reverse_string(str, start, length-1);

    while(end<length)
    {
        if(str[end] != ' ')
        {
            start = end;
            while(end<length && str[end] !=' ')
                end++;
            end--;
            Reverse_string(str, start, end);
        }

    end++;
    }
};


void Reverse_string(char str[], int start, int end)
{
    char tmp;
    while(end>start)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++; end--;
    }
};


int main()
{
    char str[] = "Do or do not, there is no try.";
    cout << "input: "<<str<<"\n";
    Reverse_words(str);
    cout << "output: "<< str<<"\n";
    return 0;
}
