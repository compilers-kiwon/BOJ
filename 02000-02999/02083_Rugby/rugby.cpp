#include    <iostream>
#include    <string>

using namespace std;

#define AGE_OF_JUNIOR       17
#define WEIGHT_OF_SENIOR    80

bool    input(string& name,int& age,int& weight)
{
    cin>>name>>age>>weight;
    return  !(name=="#"&&age==0&&weight==0);
}

bool    is_senior(const int& age,const int& weight)
{
    return  (age>AGE_OF_JUNIOR||weight>=WEIGHT_OF_SENIOR);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  name;
    int     age,weight;

    for(;input(name,age,weight);)
    {
        cout<<name<<' '<<
            ((is_senior(age,weight))?"Senior":"Junior")<<'\n';
    }

    return  0;
}