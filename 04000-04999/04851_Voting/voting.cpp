#include    <iostream>
#include    <string>

using namespace std;

enum {
    QUORUM = 0,
    YES = 1,
    NO = 2,
    TIE = 3,
    MAX_RESULT = 4
};

#define get_half(n) (((n)+1)/2)

int count(const string& s,char c)
{
    int ret = 0;

    for(int i=0;i<s.length();i++)
    {
        ret += (s[i]==c)?1:0;
    }

    return  ret;
}

int simulate(const string& result)
{
    int num_of_half,num_of_absent;
    int num_of_yes,num_of_no;

    num_of_half = get_half(result.length());
    num_of_absent = count(result,'A');

    if( num_of_absent >= num_of_half )
    {
        return  QUORUM;
    }

    num_of_yes = count(result,'Y');
    num_of_no = count(result,'N');

    return  (num_of_yes==num_of_no)?TIE:
                (num_of_yes>num_of_no)?YES:NO;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const string result[MAX_RESULT] = {
        "need quorum","yes","no","tie"
    };

    for(;;)
    {
        string  v;

        cin>>v;

        if( v == "#" )
        {
            break;
        }

        cout<<result[simulate(v)]<<'\n';
    }

    return  0;
}