#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_TEAMS    2

void    simulate(const string& str,int score[])
{
    for(int i=0;i<str.length();i++)
    {
        int t = i%NUM_OF_TEAMS;

        switch(str[i])
        {
            case    'H':
                score[t]++;
                break;
            case    'D':
                score[t] = min(7,score[t]+2);
                break;
            case    'O':
                score[(t+1)%NUM_OF_TEAMS]++;
                break;
            case    'S':
            default:
                break;
        }

        if( score[t] == 7 )
        {
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  name[NUM_OF_TEAMS],str;
    int     S,score[NUM_OF_TEAMS]={0,};

    getline(cin,name[0]);getline(cin,name[1]);
    cin>>S>>str;

    simulate(str,score);
    cout<<name[0]<<' '<<score[0]<<' '<<name[1]<<' '<<score[1]<<". ";

    if( score[0] == 7 ) {
        cout<<name[0]<<" has won.\n";
    } else if( score[1] == 7 ) {
        cout<<name[1]<<" has won.\n";
    } else if( score[0] > score[1] ) {
        cout<<name[0]<<" is winning.\n";
    } else if( score[0] < score[1] ) {
        cout<<name[1]<<" is winning.\n";
    } else {
        cout<<"All square.\n";
    }

    return  0;
}