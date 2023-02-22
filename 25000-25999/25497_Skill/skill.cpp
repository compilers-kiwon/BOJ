#include    <iostream>
#include    <string>

using namespace std;

int simulate(const string& skills)
{
    int ret,L,S;
    
    ret = L = S = 0;

    for(int i=0;i<skills.length();i++)
    {
        switch(skills[i])
        {
            case '1':case '2':case '3':
            case '4':case '5':case '6':
            case '7':case '8':case '9':
                ret++;break;
            case 'L':
                L++;break;
            case 'S':
                S++;break;
            case 'R':
                if(!L) return ret;
                L--,ret++;break;
            case 'K':
                if(!S) return ret;
                S--,ret++;break;
            default:
                // do nothing
                break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  s;

    cin>>N>>s;
    cout<<simulate(s)<<'\n';

    return  0;
}