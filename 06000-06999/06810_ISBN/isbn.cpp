#include    <iostream>
#include    <string>

using namespace std;

const string    head = "9780921418";

#define chr2int(c)  ((int)((c)-'0'))
#define is_even(n)  ((n)%2==0)

void    input(string& tail)
{
    for(int i=0;i<3;i++)
    {
        char    c;

        cin>>c;
        tail.push_back(c);
    }
}

int     get_1_3_sum(string num)
{
    int ret = 0;

    for(int i=0;i<num.length();i++)
    {
        ret += chr2int(num[i])*(is_even(i)?1:3);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  tail;

    input(tail);
    cout<<"The 1-3-sum is "<<get_1_3_sum(head+tail)<<'\n';

    return  0;
}