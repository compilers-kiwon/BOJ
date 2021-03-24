#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_TABLE_SIZE  (30+1)

void    input(int table[][MAX_TABLE_SIZE],vector<string>& students)
{
    int L,n;

    cin>>L>>n;

    for(int row=0;row<=L;row++)
    {
        for(int col=0;col<=L;col++)
        {
            cin>>table[row][col];
        }
    }

    getchar();

    for(int i=1;i<=n;i++)
    {
        string  name;

        getline(cin,name);
        students.push_back(name);
    }
}

void    parse_name(const string& name,int& num_of_vowel,int& num_of_cons)
{
    num_of_vowel = num_of_cons = 0;

    for(int i=0;i<name.length();i++)
    {
        switch(name[i])
        {
            case    'a':
            case    'e':
            case    'i':
            case    'o':
            case    'u':
            case    'y':
                num_of_vowel++;
                break;
            default:
                num_of_cons++;
                break;
        }
    }
}

int     main(void)
{
    int K;

    cin>>K;

    for(int k=1;k<=K;k++)
    {
        vector<string>  students;
        int sum = 0;
        int p[MAX_TABLE_SIZE][MAX_TABLE_SIZE];
        
        input(p,students);

        for(int i=0;i<students.size();i++)
        {
            int v,c;

            parse_name(students[i],v,c);
            sum += p[v][c];
        }

        cout<<"Data Set "<<k<<":\n"<<sum<<"\n\n";
    }

    return  0;
}