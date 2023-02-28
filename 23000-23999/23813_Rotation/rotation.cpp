#include    <iostream>

using namespace std;

typedef long long int   int64;

int64   get_sum_of_digits(int64 number,int& length)
{
    int64   ret = 0;

    for(length=0;number>0;number/=10,length++)
    {
        ret += number%10;
    }

    return  ret;
}

int64   rotate(int64 sum,int length)
{
    int64   ret = 0;

    for(int i=1;i<=length;i++,sum*=10)
    {
        ret += sum;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   N,s;
    int     length_of_number;

    cin>>N;

    s = get_sum_of_digits(N,length_of_number);
    cout<<rotate(s,length_of_number)<<'\n';

    return  0;
}