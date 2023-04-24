#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    string  in,out;

    cin>>in;

    for(int i=0;i<in.length();i++)
    {
        if( in[i] == 'e' )
        {
            out += "ee";
        }
        else
        {
            out.push_back(in[i]);
        }
    }

    cout<<out<<'\n';

    return  0;
}