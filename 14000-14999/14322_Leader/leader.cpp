#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

typedef pair<int,string>    Candidate;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_letter(c)        IN_RANGE('A',(c),'Z')

int     get_num_of_used_letters(const string& str)
{
    set<char>   tmp;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( is_letter(c) == true )
        {
            tmp.insert(c);
        }
    }

    return  tmp.size();
}

void    get_candidate_information(Candidate& c)
{
    getline(cin,c.second);
    c.first = get_num_of_used_letters(c.second);
}

int     main(void)
{
    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int         N;
        Candidate   selected;

        cin>>N;getchar();
        selected = make_pair(0," ");

        for(int i=1;i<=N;i++)
        {
            Candidate   c;

            get_candidate_information(c);

            if( (c.first>selected.first) ||
                (c.first==selected.first && c.second<selected.second) )
            {
                selected = c;
            }
        }

        cout<<"Case #"<<t<<": "<<selected.second<<'\n';
    }

    return  0;
}