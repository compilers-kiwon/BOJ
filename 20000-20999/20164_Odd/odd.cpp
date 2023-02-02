#include    <iostream>
#include    <string>

using namespace std;

#define INF 0x7FFFFFFF

#define char2int(c) ((int)((c)-'0'))
#define is_odd(n)   (((n)%2)==1)

static int  max_cnt,min_cnt;

#define get_number_from_two_numbers(n1,n2) \
                to_string(stoi((n1))+stoi((n2)))

#define get_number_from_three_numbers(n1,n2,n3) \
                to_string(stoi((n1))+stoi((n2))+stoi((n3)))

int     get_num_of_odds(const string& num)
{
    int ret = 0;

    for(int i=0;i<num.length();i++)
    {
        ret += is_odd(char2int(num[i]))?1:0;
    }

    return  ret;
}

void    dfs(const string& num,int num_of_odds)
{
    if( num.length() == 1 )
    {
        max_cnt = max(max_cnt,num_of_odds);
        min_cnt = min(min_cnt,num_of_odds);

        return;
    }

    if( num.length() == 2 )
    {
        string  s1,s2,sum;

        s1.push_back(num.front());
        s2.push_back(num.back());

        sum = get_number_from_two_numbers(s1,s2);
        dfs(sum,num_of_odds+get_num_of_odds(sum));
    }

    for(int p1=1;p1<=num.length()-2;p1++)
    {
        for(int p2=p1+1;p2<=num.length()-1;p2++)
        {
            int s1_len = p1;
            int s2_len = p2-p1;
            int s3_len = num.length()-p2;

            string  s1 = num.substr(0,s1_len);
            string  s2 = num.substr(p1,s2_len);
            string  s3 = num.substr(p2,s3_len);
            string  sum = get_number_from_three_numbers(s1,s2,s3);

            dfs(sum,num_of_odds+get_num_of_odds(sum));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  N;

    cin>>N;
    
    max_cnt = 0;
    min_cnt = INF;

    dfs(N,get_num_of_odds(N));
    cout<<min_cnt<<' '<<max_cnt<<'\n';

    return  0;
}