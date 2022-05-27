#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define IN_RANGE(MIN,n,MAX)         ((MIN)<=(n)&&(n)<=(MAX))
#define get_distance(x1,y1,x2,y2)   (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

typedef struct{int x1,y1,x2,y2;} Rectangle;
typedef struct{int x,y,r;}  Circle;
typedef pair<int,int>   Shot;

int m,n;

bool    hit(int x,int y,Rectangle& r)
{
    return  (IN_RANGE(r.x1,x,r.x2)&&IN_RANGE(r.y1,y,r.y2));
}

bool    hit(int x,int y,Circle& c)
{
    return  (get_distance(c.x,c.y,x,y)<=(c.r*c.r));
}

void    input(vector<Rectangle>& r,vector<Circle>& c,vector<Shot>& s)
{
    cin>>m;

    for(int i=1;i<=m;i++)
    {
        string      header;
        Rectangle   rt;
        Circle      ct;

        cin>>header;

        if( header == "rectangle" )
        {
            cin>>rt.x1>>rt.y1>>rt.x2>>rt.y2;
            r.push_back(rt);
        }
        else
        {
            cin>>ct.x>>ct.y>>ct.r;
            c.push_back(ct);
        }
    }

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x,y;

        cin>>x>>y;
        s.push_back(make_pair(x,y));
    }
}

int     get_num_of_hits(vector<Rectangle>& r,vector<Circle>& c,Shot& s)
{
    int ret = 0;

    for(int i=0;i<r.size();i++)
    {
        ret += (hit(s.first,s.second,r[i])?1:0);
    }

    for(int i=0;i<c.size();i++)
    {
        ret += (hit(s.first,s.second,c[i])?1:0);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Rectangle>   rectangle_tragets;
    vector<Circle>      circle_targets;
    vector<Shot>        shots;

    input(rectangle_tragets,circle_targets,shots);

    for(int i=0;i<shots.size();i++)
    {
        cout<<get_num_of_hits(rectangle_tragets,circle_targets,shots[i])<<'\n';
    }

    return  0;
}