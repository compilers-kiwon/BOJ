#include    <iostream>
#include    <string>

using namespace std;

const static string v = "aeiou";

#define is_vowel(c) (v.find((c))!=string::npos)

#define TRUE    1
#define FALSE   0

#define NONE    0

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     easy,prev_state;
    string  str;

    cin>>str;

    easy = TRUE;
    prev_state = NONE;
    
    for(int i=0;i<str.length();i++)
    {
        int current_state = 
                1<<(is_vowel(str[i])?1:0);
        
        if( (prev_state&current_state) != 0 )
        {
            easy = FALSE;
            break;
        }

        prev_state = current_state;
    }

    cout<<easy<<'\n';
    return  0;
}