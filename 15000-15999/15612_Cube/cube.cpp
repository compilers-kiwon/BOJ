#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

typedef long long int   int64;

#define int64chr(i64)   ((char)((i64)+(int64)'0'))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int64   v;
        string  cube;

        for(cin>>v;v>0;v/=3) cube.push_back(int64chr(v%3));
        for(;!cube.empty()&&cube.back()=='0';cube.pop_back());
        
        reverse(cube.begin(),cube.end());
        cout<<(cube.empty()?"0":cube)<<'\n';
    }

    return  0;
}