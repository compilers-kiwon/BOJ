#include    <iostream>

using namespace std;

#define MAX_SIZE        (500+1)
#define ROTATION_SIZE   8

static int  X[MAX_SIZE][MAX_SIZE];

typedef pair<int,int>   Pos;    // first:row,second:col

#define ROTATION_LIST(top,bottom,left,right,mid) \
    {\
        {(top),(left)},{(top),(mid)},{(top),(right)},\
        {(mid),(right)},{(bottom),(right)},{(bottom),(mid)},\
        {(bottom),(left)},{(mid),(left)}\
    }

#define get_rotated_idx(idx,r)  (((i)+(r))%ROTATION_SIZE)
#define get_num_of_rotations(d) (((360+(d))%360)/45)

int rotate_arr(int top,int bottom,
            int left,int right,int r)
{
    int mid = (left+right)/2;
    int rotated[ROTATION_SIZE];
    
    Pos arr[ROTATION_SIZE] =
        ROTATION_LIST(top,bottom,left,right,mid);

    for(int i=0;i<ROTATION_SIZE;i++)
    {
        rotated[get_rotated_idx(i,r)] =
                X[arr[i].first][arr[i].second];
    }

    for(int i=0;i<ROTATION_SIZE;i++)
    {
        X[arr[i].first][arr[i].second] = rotated[i];
    }

    return  0;
}

int input(int& arr_size,int& degree)
{
    cin>>arr_size>>degree;

    for(int row=1;row<=arr_size;row++)
    {
        for(int  col=1;col<=arr_size;col++)
        {
            cin>>X[row][col];
        }
    }

    return  0;
}

int simulate(int size,int degree)
{
    int r = get_num_of_rotations(degree);

    if( r == 0 )
    {
        return  0;
    }

    for(int h=1,t=size;h!=t;h++,t--)
    {
        rotate_arr(h,t,h,t,r);
    }

    return  0;
}

int print(int size)
{
    for(int row=1;row<=size;row++)
    {
        for(int col=1;col<=size;col++)
        {
            cout<<X[row][col]<<' ';
        }
        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int n,d;

        input(n,d);
        simulate(n,d);
        print(n);
    }

    return  0;
}