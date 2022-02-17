#include    <iostream>

using namespace std;

#define MAX_SIZE                6
#define MAX_NUM                 9
#define NUM_OF_DEFAULT_STICKS   4

int N,ex[MAX_SIZE];

const int num_of_sticks[MAX_NUM+1] = {6,2,5,5,4,5,6,3,7,6};

#define get_value(d1,d2)    ((d1)*10+(d2))

bool    evaluate_exp(void)
{
    int n1,n2,n3;

    n1 = get_value(ex[0],ex[1]);
    n2 = get_value(ex[2],ex[3]);
    n3 = get_value(ex[4],ex[5]);

    return  (n1+n2==n3);
}

int     get_num_of_used_sticks(void)
{
    int ret = NUM_OF_DEFAULT_STICKS;

    for(int i=0;i<MAX_SIZE;i++)
    {
        ret += num_of_sticks[ex[i]];
    }

    return  ret;
}

bool    build_expression(int pos)
{
    if( pos == MAX_SIZE )
    {
        return  (evaluate_exp()&&(N==get_num_of_used_sticks()));
    }

    for(int i=0;i<=MAX_NUM;i++)
    {
        ex[pos] = i;

        if( build_expression(pos+1) == true )
        {
            return  true;
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    if( build_expression(0) == true )
    {
        cout<<ex[0]<<ex[1]<<'+'<<ex[2]<<ex[3]<<'='<<ex[4]<<ex[5]<<'\n';
    }
    else
    {
        cout<<"impossible\n";
    }

    return  0;
}