#include    <iostream>
#include    <string>

using namespace std;

typedef long long int   int64;

int check_palindrome(const string& str)
{
    for(int head=0,tail=str.length()-1;head<tail;head++,tail--)
    {
        if( str[head] != str[tail] )
        {
            return  0;
        }
    }

    return  stoi(str);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    int64   sum;

    cin>>n;
    sum = 0;

    for(int i=1;i<=n;i++)
    {
        string  num;

        cin>>num;
        sum += (int64)check_palindrome(num);
    }

    cout<<sum<<'\n';
    return  0;
}