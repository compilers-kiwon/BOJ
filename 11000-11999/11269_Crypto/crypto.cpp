#include    <iostream>
#include    <string>

using namespace std;

#define NAME_STR    "PER"
#define NAME_LEN    3

int get_num_of_different_letters(const string& origin,const string& target)
{
    int ret = 0;

    for(int i=0;i<origin.length();i++)
    {
        ret += (origin[i]!=target[i])?1:0;
    }

    return  ret;
}

int build_target(int length,string& ret)
{
    for(int i=0;i<length;i+=NAME_LEN)
    {
        ret += NAME_STR;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  cipher,changed;

    cin>>cipher;
    build_target(cipher.length(),changed);
    cout<<get_num_of_different_letters(cipher,changed)<<'\n';

    return  0;
}