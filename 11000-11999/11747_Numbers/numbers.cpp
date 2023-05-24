#include    <iostream>
#include    <string>

using namespace std;

#define is_included(big,small) \
        ((big).find((small))!=string::npos)

int input(string& num)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        char  d;

        cin>>d;
        num.push_back(d);
    }

    return  0;
}

int find_disappeared_number(const string& num)
{
    int ret;

    for(ret=0;is_included(num,to_string(ret));ret++);
    return  ret;
}

int main(void)
{
    cin.tie(NULL);

    string  numbers;

    input(numbers);
    cout<<find_disappeared_number(numbers)<<'\n';

    return  0;
}