#include    <iostream>

using namespace std;

#define MAX_LEN (200+1)

int inverse(char* str,int head,int tail)
{
    for(;head<tail;head++,tail--)
    {
        swap(str[head],str[tail]);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,A,B;
    char    str[MAX_LEN+1] = {0,};

    cin>>N>>A>>B>>&str[1];
    inverse(str,A,B);
    cout<<&str[1]<<'\n';

    return  0;
}