#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  S;

    cin>>N>>S;
    (S.back()=='G')?S.pop_back():S.push_back('G');

    cout<<S<<'\n';
    return  0;
}