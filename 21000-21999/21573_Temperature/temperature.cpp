#include    <iostream>
#include    <string>

using namespace std;

int get_final_temperature(int cur,int required,
                            const string& command)
{
    return  (command=="heat"?max(cur,required):
                command=="freeze"?min(cur,required):
                command=="auto"?required:cur);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cur,required;
    string  command;

    cin>>cur>>required>>command;
    cout<<get_final_temperature(cur,required,command)<<'\n';

    return  0;
}