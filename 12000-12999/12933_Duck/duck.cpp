#include    <iostream>
#include    <string>

using namespace std;

#define EXPECTED_SOUND  "quack"
#define EXPECTED_LEN    5

#define INF     0x7FFFFFFF
#define NONE    -1

#define is_head(p)  ((p)==0)
#define is_tail(p)  ((p)==EXPECTED_LEN-1)

#define get_pos(str,s)  (string((str)).find((s)))

int get_sum_of_range(const int* arr,int from,int to)
{
    int ret = 0;

    for(int i=from;i<=to;i++)
    {
        ret += arr[i];
    }

    return  ret;
}

int parse_sound(const string& sound)
{
    int ret = 0;
    int current = 0;
    int expected[EXPECTED_LEN+1] = {INF,0,};
    
    for(int i=0;i<sound.length();i++)
    {
        char    s = sound[i];
        int     pos = get_pos(EXPECTED_SOUND,s);

        if( expected[pos] == 0 )
        {
            return  NONE;
        }


        expected[pos]--;
        expected[pos+1]++;

        current += (is_head(pos)?1:is_tail(pos)?-1:0);
        ret = max(ret,current);
    }

    return  (current!=0)?NONE:ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  recorded;

    cin>>recorded;
    cout<<parse_sound(recorded)<<'\n';

    return  0;
}