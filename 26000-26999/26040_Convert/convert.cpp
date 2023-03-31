#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  A,B,C;

    getline(cin,A);
    getline(cin,B);

    for(int i=0;i<A.length();i++)
    {
        char&   c = A[i];

        if( isupper(c) && B.find(c)!=string::npos )
        {
            c = tolower(c);
        }

        C.push_back(c);
    }

    cout<<C<<'\n';

    return  0;
}