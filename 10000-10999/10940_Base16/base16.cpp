#include    <iostream>

using namespace std;

#define MAX_SIZE    50

int main(void)
{
    char    buf[MAX_SIZE+1];

    scanf("%s",buf);

    for(int i=0;buf[i]!='\0';i++)
    {
        printf("%X",buf[i]);
    }

    puts("");
    return  0;
}