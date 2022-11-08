#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>           Pos;
typedef struct{int d,c1,c2;}    Path;

#define make_path(s,p1,p2,p3)    {(s).d=(p1);(s).c1=(p2);(s).c2=(p3);}

int     get_distance(int r1,int c1,int r2,int c2)
{
    int d1 = r1-r2;
    int d2 = c1-c2;

    return  ((d1*d1)+(d2*d2));
}

int     find_parent(int me,int arr[])
{
    int&    ret = arr[me];

    if( ret != me )
    {
        ret = find_parent(ret,arr);
    }

    return  ret;
}

bool    is_shorter(const Path& p1,const Path& p2)
{
    return  (p1.d<=p2.d);
}

int     build_network(int num_of_cows,vector<Path>& wt)
{
    int ret = 0;
    int parent[MAX_SIZE];

    for(int i=1;i<=num_of_cows;i++)
    {
        parent[i] = i;
    }

    for(int i=0;i<wt.size();i++)
    {
        int&    dist = wt[i].d;
        int&    cow1 = wt[i].c1;
        int&    cow2 = wt[i].c2;

        int p1 = find_parent(cow1,parent);
        int p2 = find_parent(cow2,parent);

        if( p1 == p2 )
        {
            continue;
        }

        ret = max(ret,dist);
        parent[max(p1,p2)] = min(p1,p2);
    }

    return  ret;
}

void    input(int& num_of_cows,vector<Path>& wt)
{
    Pos p[MAX_SIZE];

    cin>>num_of_cows;

    for(int i=1;i<=num_of_cows;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    for(int i=1;i<num_of_cows;i++)
    {
        for(int j=i+1;j<=num_of_cows;j++)
        {
            Path    w;
            int     dist;

            dist = get_distance(p[i].first,p[i].second,
                                    p[j].first,p[j].second);
            make_path(w,dist,i,j);wt.push_back(w);
        }
    }

    sort(wt.begin(),wt.end(),is_shorter);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N;
    vector<Path>    wt;

    input(N,wt);
    cout<<build_network(N,wt)<<'\n';

    return  0;
}