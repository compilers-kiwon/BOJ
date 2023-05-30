#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define NONE    0x7FFFFFFF

typedef pair<int,int>   Deque;

int push(vector<Deque>& dq,
            int num,int front,int back)
{
    int f,b;

    f = b = NONE;

    for(int i=0;i<dq.size();i++)
    {
        if(dq[i].first==back) b=i;
        if(dq[i].second==front) f=i;
    }

    if( f!=NONE && b!=NONE )
    {
        dq[f].second = dq[b].second;
        dq.erase(dq.begin()+b);
    }
    else
    {
        if( f==NONE && b==NONE )
        {
            dq.push_back({num,num});
            return 1;
        }
        else
        {
            if( f != NONE )
            {
                dq[f].second = num;
            }
            else
            {
                dq[b].first = num;
            }
        }
    }

    return  0;
}

int get_adj_numbers(int& front,int& back,int num,
                        const vector<int>& numbers)
{
    for(int i=0;i<numbers.size();i++)
    {
        if( numbers[i] == num )
        {
            front = ((i==0)?NONE:numbers[i-1]);
            back = ((i==numbers.size()-1)?NONE:numbers[i+1]);
            break;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> numbers,sorted;
    vector<Deque> dq;

    cin>>N;

    for(int i=0;i<N;i++)
    {
        int n;

        cin>>n;

        numbers.push_back(n);
        sorted.push_back(n);
    }

    sort(sorted.begin(),sorted.end());

    int num_of_dqs = 0;

    for(int i=0;i<N;i++)
    {
        int front,back;

        get_adj_numbers(front,back,numbers[i],sorted);
        num_of_dqs += push(dq,numbers[i],front,back);
    }

    cout<<num_of_dqs<<'\n';
    return  0;
}