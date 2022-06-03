#include    <iostream>
#include    <vector>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define build_number(a,b,c) ((a)*1000+(b)*100+(c)%100)

bool    is_divisible(int n,int a,int b,int c)
{
    return  ((n%(a+b)==0)||(n%(b+c)==0)||(n%(c+a)==0));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,s,M;
    vector<int> books_to_be_read;

    cin>>N>>s>>M;

    for(int month=1;month<=12;month++)
    {
        int N1 = month+10;
        int N2 = s;
        int cnt = 0;

        for(int N3=10;N3<=N;N3++)
        {
            if( IN_RANGE(11,N3,22) == true )
            {
                continue;
            }

            if( is_divisible(build_number(N1,N2,N3),N1,N2,N3) == true )
            {
                cnt++;

                if( month==M && books_to_be_read.empty() )
                {
                    books_to_be_read.push_back(N1);
                    books_to_be_read.push_back(N2);
                    books_to_be_read.push_back(N3);
                }
            }
        }

        cout<<cnt<<'\n';
    }

    if( books_to_be_read.empty() )
    {
        books_to_be_read.push_back(0);
        books_to_be_read.push_back(0);
        books_to_be_read.push_back(0);
    }

    for(int i=0;i<books_to_be_read.size();i++)
    {
        cout<<books_to_be_read[i]<<' ';
    }
    cout<<'\n';

    return  0;
}