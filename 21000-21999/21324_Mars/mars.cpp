#include    <iostream>

using namespace std;

#define IN_RANGE(MIN,n,MAX)  ((MIN)<(n)&&(n)<(MAX))

int get_digit(float d)
{
    int ret;

    for(float i=0.0f;i<16.0f;i+=1.0f)
    {
        if( IN_RANGE(i*22.5f,d,i*22.5f+22.5f) )
        {
            ret = (int)i;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i+=2)
    {
        float   d1,d2;
        int     n;

        cin>>d1>>d2;
        n = get_digit(d1)*16+get_digit(d2);

        cout<<(char)n;
    }

    return  0;
}