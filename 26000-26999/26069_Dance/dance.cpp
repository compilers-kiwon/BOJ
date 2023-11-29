#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

const static string init = "ChongChong";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    set<string> d;

    cin>>N;
    d.insert(init);

    for (int i=1;i<=N;i++) {
        string  s1,s2;

        cin>>s1>>s2;

        if (d.find(s1)!=d.end() || d.find(s2)!=d.end()) {
            d.insert(s1),d.insert(s2);
        }
    }

    cout<<d.size()<<'\n';
    return  0;
}