#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

static inline void get_numbers(int num_of_numbers,vector<int>& v)
{
    for (int i=1;i<=num_of_numbers;i++) {
        int d;
        cin>>d;
        v.push_back(d);
    }
}

int input(vector<int>& first,vector<int>& second)
{
    int n;

    cin>>n;

    get_numbers(n,first);
    get_numbers(n,second);

    sort(first.begin(),first.end());
    sort(second.begin(),second.end());

    return  0;
}

int get_num_of_wins(const vector<int>& me,const vector<int>& opp)
{
    int ret = 0;

    for (int i=0;i<me.size();i++) {
        ret += lower_bound(opp.begin(),opp.end(),me[i])-opp.begin();
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_first_wins,num_of_second_wins;
    vector<int> first,second;

    input(first,second);
    
    num_of_first_wins = get_num_of_wins(first,second);
    num_of_second_wins = get_num_of_wins(second,first);

    if (num_of_first_wins == num_of_second_wins) cout<<"tie\n";
    else cout<<(num_of_first_wins>num_of_second_wins?"first":"second")<<'\n';

    return  0;
}