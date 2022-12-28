#include    <iostream>
#include    <vector>

using namespace std;

#define LEN_OF_ANSWER   10
#define CUTLINE_SCORE   5

#define MIN_CHOICE  1
#define MAX_CHOICE  5

int compare_answer(const vector<int>& a,
                    const vector<int>& b,int c)
{
    int n = 0;

    for(int i=0;i<a.size();i++)
    {
        if( a[i] == b[i] )
        {
            n++;
        }
    }

    return  ((n>=c)?1:0);
}

int build_answer(vector<int>& my_answer,
                    const vector<int>& right_answer)
{
    if( my_answer.size() == right_answer.size() )
    {
        return  compare_answer(my_answer,
                        right_answer,CUTLINE_SCORE);
    }

    int ret = 0;

    for(int c=MIN_CHOICE;c<=MAX_CHOICE;c++)
    {
        if( my_answer.size() < 2 )
        {
            my_answer.push_back(c);
        }
        else
        {
            int pprev = my_answer[my_answer.size()-2];
            int prev = my_answer[my_answer.size()-1];

            if( pprev==prev && prev==c )
            {
                continue;
            }

            my_answer.push_back(c);
        }

        ret += build_answer(my_answer,right_answer);
        my_answer.pop_back();
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> my_answer,right_answer;

    for(int i=1;i<=LEN_OF_ANSWER;i++)
    {
        int n;

        cin>>n;
        right_answer.push_back(n);
    }

    cout<<build_answer(my_answer,right_answer)<<'\n';

    return  0;
}