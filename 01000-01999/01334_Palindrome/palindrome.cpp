#include    <iostream>
#include    <string>

using namespace std;

#define do_nothing_if_same(n1,n2)   {if((n1)==(n2))continue;}

int increase_one(string& num,int idx)
{
    if( idx < 0 )
    {
        num.insert(0,"1");
        return  0;
    }

    char&   current = num[idx];

    if( current != '9' )
    {
        current++;
    }
    else
    {
        current = '0';
        increase_one(num,idx-1);
    }

    return  0;
}

int build_palindrome(string& num)
{
    increase_one(num,num.length()-1);

    for(int h=0,t=num.length()-1;h<num.length();h++,t--)
    {
        do_nothing_if_same(num[h],num[t]);
        
        char&   front = num[min(h,t)];
        char&   back = num[max(h,t)];

        if( front > back )
        {
            back = front;
        }
        else
        {
            back = front;
            increase_one(num,max(h,t)-1);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  num;

    cin>>num;
    build_palindrome(num);
    cout<<num<<'\n';

    return  0;
}