#include    <iostream>
#include    <string>
#include    <deque>

using namespace std;

int str2deque(deque<char>& d)
{
    string  str;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        d.push_back(str[i]);
    }

    return  0;
}

int input(deque<char>& original,
            deque<char>& insfected)
{
    str2deque(original);
    str2deque(insfected);
    return  0;
}

int simulate(deque<char>& original,
                deque<char>& insfected)
{
    for(;;)
    {
        bool    updated = false;

        if( !original.empty() && !insfected.empty()
                && original.front()==insfected.front() )
        {
            updated = true;
            original.pop_front();
            insfected.pop_front();
        }

        if( !original.empty() && !insfected.empty()
                && original.back()==insfected.back() )
        {
            updated = true;
            original.pop_back();
            insfected.pop_back();
        }

        if( updated == false )
        {
            break;
        }
    }

    return  insfected.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    deque<char> original,insfected;

    input(original,insfected);
    cout<<simulate(original,insfected)<<'\n';

    return  0;
}