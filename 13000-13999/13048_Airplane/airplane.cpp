#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define INF         0x7FFFFFFFFFFFFFFF

typedef long long int   int64;
typedef pair<int,int64> Part;
typedef struct{int row,col;int64 num_of_parts;}  State;

int     n,m;
int64   total_sum,sum_of_row[MAX_SIZE],sum_of_col[MAX_SIZE];

vector<State>   part_info;

void    input(void)
{
    cin>>n>>m;

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=m;col++)
        {
            int64   a;

            cin>>a;

            if( a == 0 )
            {
                continue;
            }

            total_sum += a;

            sum_of_row[row] += a;
            sum_of_col[col] += a;

            State   s;

            s.row=row;s.col=col;s.num_of_parts=a;
            part_info.push_back(s);
        }
    }
}

int     get_middle_pos(int64* arr,int size)
{
    int             ret;
    vector<Part>    p;

    for(int i=1;i<=size;i++)
    {
        if( arr[i] != 0 )
        {
            p.push_back(make_pair(i,arr[i]));
        }
    }

    int64   half = total_sum/2;
    int64   current_sum = 0;

    for(int i=0;i<p.size();i++)
    {
        current_sum += p[i].second;

        if( current_sum > half )
        {
            ret = p[i].first;
            break;
        }

        if( current_sum == half )
        {
            if( total_sum%2 == 0 )
            {
                ret = (p[i].first+p[i+1].first)/2;
            }
            else
            {
                ret = p[i+1].first;
            }
        }
    }

    return  ret;
}

int64   get_num_of_actions_for_each_part(int row,int col)
{
    int64   ret = 0;

    for(int i=0;i<part_info.size();i++)
    {
        int&    part_row = part_info[i].row;
        int&    part_col = part_info[i].col;
        int64&  part_num = part_info[i].num_of_parts;

        ret += (((int64)(abs(part_row-row))+(int64)(abs(part_col-col)))*2+2)*part_num;

    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int mid_row,mid_col;

    mid_row = get_middle_pos(sum_of_row,n);
    mid_col = get_middle_pos(sum_of_col,m);

    cout<<mid_row<<' '<<mid_col<<' '<<get_num_of_actions_for_each_part(mid_row,mid_col)<<'\n';

    return  0;
}