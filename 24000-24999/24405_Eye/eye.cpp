#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;
    int     left_length,right_legnth;

    cin>>str;

    left_length = str.find(')');
    right_legnth = str.length()-left_length;

    if( left_length == right_legnth )
    {
        cout<<"correct\n";
    }
    else
    {
        cout<<"fix\n";
    }

    return  0;
}