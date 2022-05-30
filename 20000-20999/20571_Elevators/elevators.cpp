#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

typedef struct{int lower,upper,n;}  Regulation;
typedef vector<Regulation>  Requirement;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    init(map<string,Requirement>& table)
{
    Requirement r;

    r.push_back({1,1,0});
    r.push_back({2,5,1});
    r.push_back({6,10,2});
    r.push_back({11,15,3});
    r.push_back({16,20,4});
    table["residential"] = r;
    
    r.clear();
    r.push_back({1,1,0});
    r.push_back({2,7,1});
    r.push_back({8,14,2});
    r.push_back({15,20,3});
    table["commercial"] = r;

    r.clear();
    r.push_back({1,1,0});
    r.push_back({2,4,1});
    r.push_back({5,8,2});
    r.push_back({9,12,3});
    r.push_back({13,16,4});
    r.push_back({17,20,5});
    table["industrial"] = r;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  zone;
    int     N;

    map<string,Requirement> t;

    init(t);
    cin>>zone>>N;

    for(int i=0;i<t[zone].size();i++)
    {
        if( IN_RANGE(t[zone][i].lower,N,t[zone][i].upper) )
        {
            cout<<t[zone][i].n<<'\n';
            break;
        }
    }

    return  0;
}