#include    <iostream>
#include    <vector>

using namespace std;

int get_sum(const vector<int>& v)
{
    int ret = 0;

    for(int i=0;i<v.size();i++)
    {
        ret += v[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;;i++)
    {
        int n,sum;

        cin>>n,sum=0;

        if(n==0) break;

        for(int row=1;row<=n;row++)
        {
            vector<int> numbers;

            for(int col=1;col<=row;col++)
            {
                int num;

                cin>>num;
                numbers.push_back(num);
            }

            if( row==1 || row==n )
            {
                sum += get_sum(numbers);
            }
            else
            {
                sum += numbers.front()+numbers.back();
            }
        }

        cout<<"Case #"<<i<<":"<<sum<<'\n';
    }

    return  0;
}