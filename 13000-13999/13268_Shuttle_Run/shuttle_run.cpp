#include    <iostream>
#include    <vector>

using namespace std;

#define START_POS       0
#define MAX_LEN         (10000+1)
#define NUM_OF_SECTIONS 5

const static pair<int,int>  section[NUM_OF_SECTIONS] = {
    {0,0},{1,5},{6,10},{11,15},{16,20}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int run(int from,int to,int offset,vector<int>& pos)
{
    for(int p=from;p!=to+offset;p+=offset)
    {
        if(p==pos.back()) continue;
        pos.push_back(p);
    }

    return  0;
}

int init(vector<int>& v)
{
    v.push_back(START_POS);

    for(int i=0;v.size()<MAX_LEN;i=(i+1)%NUM_OF_SECTIONS)
    {
        for(int j=0;j<=i;j++)
        {
            run(section[j].first,section[j].second,1,v);
        }

        for(int j=i;j>=0;j--)
        {
            run(section[j].second,section[j].first,-1,v);
        }
    }

    return  0;
}

int get_section(int p)
{
    int ret;

    for(int i=0;i<5;i++)
    {
        if( IN_RANGE(section[i].first,p,section[i].second) )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    int d;
    vector<int> pos;

    cin>>d;
    init(pos);
    
    cout<<get_section(pos[d])<<'\n';

    return  0;
}