#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

static map<string,int>  preferred = {
    // Subject
    {"kor",1<<8},{"eng",1<<7},{"math",1<<6},
    // Fruit
    {"apple",1<<5},{"pear",1<<4},{"orange",1<<3},
    // Color
    {"red",1<<2},{"blue",1<<1},{"green",1<<0},
    // Don't care
    {"-",0}
};

static int  n,m;
static vector<int>  preference;

#define get_preference(s,f,c) \
    (preferred[(s)]+preferred[(f)]+preferred[(c)])

#define compare_preference(p1,p2)   ((p1)&(p2))

int init(void)
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        string  subject,fruit,color;

        cin>>subject>>fruit>>color;
        preference.push_back(get_preference(subject,fruit,color));
    }

    return  0;
}

int count(void)
{
    string  subject,fruit,color;
    int     p,ret;

    cin>>subject>>fruit>>color;
    p = get_preference(subject,fruit,color);

    ret = 0;

    for(int i=0;i<preference.size();i++)
    {
        if( compare_preference(preference[i],p) == p )
        {
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for(int i=1;i<=m;i++)
    {
        cout<<count()<<'\n';
    }

    return  0;
}