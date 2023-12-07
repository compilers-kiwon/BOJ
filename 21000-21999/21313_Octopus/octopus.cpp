#include    <iostream>
#include    <string>

using namespace std;

string simulate(int num_of_octopuses)
{
    string  ret;

    for (int i=1;i<=(num_of_octopuses/2)*2;i++) {
        ret.push_back((i%2)==1?'1':'2');
        ret.push_back(' ');
    }

    if (num_of_octopuses%2 == 1) ret.push_back('3');
    else ret.pop_back();

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    
    cin>>N;
    cout<<simulate(N)<<'\n';

    return  0;
}