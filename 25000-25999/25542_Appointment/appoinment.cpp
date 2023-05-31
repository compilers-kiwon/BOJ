#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>

using namespace std;

#define MAX_LEN 20
#define ALLOWED_DIFFERENCE_NUM  1

static int  N,L,num_of_differences[MAX_LEN];
static vector<string> stores;
static set<char> candidates[MAX_LEN];

int input(void)
{
    cin>>N>>L;

    for(int i=0;i<N;i++)
    {
        string  s;

        cin>>s;
        stores.push_back(s);

        for(int j=0;j<L;j++)
        {
            candidates[j].insert(s[j]);
        }
    }

    return  0;
}

bool    build_store_name(int pos,string& name)
{
    if( pos == L )
    {
        return  true;
    }

    set<char>::iterator s,e;

    s = candidates[pos].begin();
    e = candidates[pos].end();

    for(;s!=e;s++)
    {
        bool selectable = true;
        vector<int> marked;

        name.push_back(*s);

        for(int i=0;i<N;i++)
        {
            if( stores[i][pos] == *s )
            {
                continue;
            }

            marked.push_back(i);
            num_of_differences[i]++;

            if( num_of_differences[i] > 
                        ALLOWED_DIFFERENCE_NUM )
            {
                selectable = false;
                break;
            }
        }

        if( selectable &&
                build_store_name(pos+1,name) )
        {
            return  true;
        }

        name.pop_back();

        for(int i=0;i<marked.size();i++)
        {
            num_of_differences[marked[i]]--;
        }
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  place;

    input();
    build_store_name(0,place);

    cout<<(place.empty()?"CALL FRIEND":place)<<'\n';
    return  0;
}