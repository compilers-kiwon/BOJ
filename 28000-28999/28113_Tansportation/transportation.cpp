#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A,B;

    cin>>N>>A>>B;
    cout<<((A==B)?"Anything":
            (A<B)?"Bus":"Subway")<<'\n';
    
    return  0;
}