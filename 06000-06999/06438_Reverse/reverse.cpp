#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

int main(void)
{
    int N;

    cin>>N;getchar();

    for(int i=1;i<=N;i++)
    {
        string  str;

        getline(cin,str);
        reverse(str.begin(),str.end());

        cout<<str<<'\n';
    }

    return  0;
}