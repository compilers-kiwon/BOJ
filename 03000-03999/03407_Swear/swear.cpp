#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_LEN             50000
#define NUM_OF_ELEMENTS     114

#define TRUE    1
#define FALSE   0
#define TBD     -1

#define OFFSET  ((char)0x20)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define get_idx(c)          ((int)((c)-'a'))
#define make_lower(c)       (IN_RANGE('A',(c),'Z')?(c)+OFFSET:(c))
#define tail_char(s)        ((s)[(s).length()-1])

string  element[NUM_OF_ELEMENTS] = {
    "H","He","Li","Be","B","C","N","O","F","Ne",
    "Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
    "Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn",
    "Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr",
    "Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
    "Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re",
    "Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
    "Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds",
    "Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm",
    "Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac",
    "Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es",
    "Fm","Md","No","Lr"
};

int             dp[MAX_LEN];
vector<string>  table[26],query;

void    input(void)
{
    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        string  q;

        cin>>q;
        query.push_back(q);
    }
}

void    init(void)
{
    for(int i=0;i<NUM_OF_ELEMENTS;i++)
    {
        string& sym = element[i];

        sym[0] = make_lower(sym[0]);
        table[get_idx(tail_char(sym))].push_back(sym);
    }
}

int     get_dp(string& str,int pos)
{
    if( pos == 0 )
    {
        return  true;
    }

    int&    ret = dp[pos-1];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = FALSE;

    vector<string>& candidates = table[get_idx(str[pos-1])];

    for(int i=0;i<candidates.size();i++)
    {
        string& sym = candidates[i];

        if( sym.length()>pos || str.substr(pos-sym.length(),sym.length())!=sym )
        {
            continue;
        }

        if( (ret=get_dp(str,pos-sym.length())) == TRUE )
        {
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init();

    for(int i=0;i<query.size();i++)
    {
        string& q = query[i];

        fill(&dp[0],&dp[q.length()],TBD);
        cout<<((get_dp(q,q.length())==TRUE)?"YES\n":"NO\n");
    }

    return  0;
}