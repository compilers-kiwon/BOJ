#include    <iostream>

using namespace std;

int main(void)
{
    const char* str = "FITO2\n192.168.1.100\nfito2021\n\n";

    for(int i=0;str[i]!='\0';i++)
    {
        printf("%02X ",str[i]);
    }

    return  0;
}