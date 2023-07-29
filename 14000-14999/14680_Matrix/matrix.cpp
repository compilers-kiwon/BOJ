#include    <iostream>
#include    <vector>

using namespace std;

#define MOD(n)  ((n)%1000000007)

typedef long long int           int64;
typedef vector<vector<int64>>   Matrix;

#define FALSE   0
#define TRUE    1

int get_matrix(Matrix& matrix)
{
    int X,Y;

    cin>>X>>Y;

    for(int row=0;row<X;row++)
    {
        vector<int64>   a;

        for(int col=0;col<Y;col++)
        {
            int n;

            cin>>n;
            a.push_back(n);
        }

        matrix.push_back(a);
    }

    return  0;
}

int multipy_matrix(vector<Matrix>& v)
{
    Matrix& m1 = v[v.size()-2];
    Matrix& m2 = v[v.size()-1];
    Matrix  m3;

    if( m1.front().size() != m2.size() )
    {
        return  FALSE;
    }

    for(int m1_row=0;m1_row<m1.size();m1_row++)
    {
        vector<int64>   row;

        for(int m2_col=0;m2_col<m2.front().size();m2_col++)
        {
            int64   sum = 0;
            
            for(int i=0;i<m2.size();i++)
            {
                sum = MOD(sum+MOD(m1[m1_row][i]*m2[i][m2_col]));
            }

            row.push_back(sum);
        }

        m3.push_back(row);
    }

    v.push_back(m3);
    return  TRUE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<Matrix>  m;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        Matrix  cur;

        get_matrix(cur);
        m.push_back(cur);

        if( m.size() >= 2 )
        {
            if( multipy_matrix(m) != TRUE )
            {
                cout<<"-1\n";
                return  0;
            }
        }
    }

    Matrix& result = m.back();
    int64   sum = 0;

    for(int row=0;row<result.size();row++)
    {
        for(int col=0;col<result[row].size();col++)
        {
            sum = MOD(sum+result[row][col]);
        }
    }

    cout<<sum<<'\n';
    return  0;
}