#include <iostream>
#include <string.h>


using namespace std;

bool Permutation(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2) return false;

    for(int i=0; i<len1; i++)
    {
        if(str1[i] != str2[len2-i-1])
            return false;
    }

    cout<<"permutation!\n";
    return true;
};

int main()
{
    char* str1 = "ttttt";
    char* str2 = "ttttt";
    char* str3 = "32132";

    cout<< Permutation(str1,str2) <<"\n";
    cout<< Permutation(str1,str3) <<"\n";
    return 0;
}
