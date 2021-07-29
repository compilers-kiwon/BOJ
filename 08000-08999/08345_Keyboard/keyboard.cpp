#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    0x100

char    row[MAX_SIZE];

void    init(void)
{
    row['`']=row['1']=row['2']=row['3']=row['4']=row['5']=row['6']
        =row['7']=row['8']=row['9']=row['0']=row['-']=row['=']='1';
    
    row['Q']=row['W']=row['E']=row['R']=row['T']=row['Y']=row['U']
        =row['I']=row['O']=row['P']=row['[']=row[']']=row['\\']='2';

    row['A']=row['S']=row['D']=row['F']=row['G']=row['H']
        =row['J']=row['K']=row['L']=row[';']=row['\'']='3';

    row['Z']=row['X']=row['C']=row['V']=row['B']
        =row['N']=row['M']=row[',']=row['.']=row['/']='4';
    
    row[' ']='5';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str,result;

    init();
    getline(cin,str);

    for(int i=0;i<str.length();i++)
    {
        result.push_back(row[str[i]]);
    }

    cout<<result<<'\n';
    return  0;
}