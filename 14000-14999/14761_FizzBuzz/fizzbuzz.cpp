#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X,Y,N;

    cin>>X>>Y>>N;

    for(int i=1;i<=N;i++)
    {
        string  out;

        out += (i%X)?"":"Fizz";
        out += (i%Y)?"":"Buzz";

        if(out.empty()) cout<<i<<'\n';
        else cout<<out<<'\n';
    }

    return  0;
}