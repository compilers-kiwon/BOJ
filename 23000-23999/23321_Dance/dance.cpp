#include    <iostream>
#include    <string>

using namespace std;

#define READY_TO_LEAP   ".omln"
#define LEAPING         "owln."
#define SEATING         "..oLn"

#define MAX_SIZE        10000
#define LEN_OF_STATE    5

static string   state[MAX_SIZE];

int input(void)
{
    int ret;

    for(int i=0;i<LEN_OF_STATE;i++)
    {
        string  str;

        cin>>str;
        ret = str.length();

        for(int j=0;j<str.length();j++)
        {
            state[j].push_back(str[j]);
        }
    }

    return  ret;
}

int simulate(int num_of_people)
{
    for(int i=0;i<num_of_people;i++)
    {
        if( state[i] == READY_TO_LEAP )
        {
            state[i] = LEAPING;
        }
        else if( state[i] == LEAPING )
        {
            state[i] = READY_TO_LEAP;
        }
    }

    return  0;
}

int print(int num_of_people)
{
    for(int i=0;i<LEN_OF_STATE;i++)
    {
        for(int j=0;j<num_of_people;j++)
        {
            cout<<state[j][i];
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_people = input();

    simulate(num_of_people);
    print(num_of_people);

    return  0;
}