#include    <iostream>
#include    <vector>
#include    <string>
#include    <queue>
#include    <map>

using namespace std;

typedef vector<string>      Children;
typedef pair<int,string>    Result;     // first:num,second:name

#define MAX_NUM_OF_ANSWER   3

int     input(map<string,Children>& t)
{
    int n,d;

    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
        string  name;
        int     m;

        cin>>name>>m;

        for(int j=1;j<=m;j++)
        {
            string  dname;

            cin>>dname;
            t[name].push_back(dname);
        }
    }

    return  d;
}

int     count_num_of_children(const string& name,map<string,Children>& t,int depth)
{
    if( depth == 0 )
    {
        return  t[name].size();
    }

    int ret = 0;

    for(int i=0;i<t[name].size();i++)
    {
        ret += count_num_of_children(t[name][i],t,depth-1);
    }

    return  ret;
}

void    count(int q,map<string,Children>& t,priority_queue<Result>& pq)
{
    map<string,Children>::iterator  it;

    for(it=t.begin();it!=t.end();it++)
    {
        int     ret;
        string  name = it->first;

        ret = count_num_of_children(name,t,q-1);
        
        if( ret != 0 )
        {
            pq.push(make_pair(ret,name));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int                     query;
        map<string,Children>    tree;
        priority_queue<Result>  answer;

        query = input(tree);
        count(query,tree,answer);

        cout<<"Tree "<<t<<":\n";

        for(int cnt=0;cnt<MAX_NUM_OF_ANSWER&&!answer.empty();cnt++)
        {
            int             num = answer.top().first;
            vector<string>  name;
            
            name.push_back(answer.top().second);
            answer.pop();

            for(;!answer.empty()&&num==answer.top().first;answer.pop(),cnt++)
            {
                name.push_back(answer.top().second);
            }

            for(int i=name.size()-1;i>=0;i--)
            {
                cout<<name[i]<<' '<<num<<'\n';
            }
        }

        if( t != T )
        {
            cout<<'\n';
        }
    }

    return  0;
}