#include    <iostream>

using namespace std;

#define is_TroyMartian(a,e)     ((a)>=3&&(e)<=4)
#define is_VladSaturnian(a,e)   ((a)<=6&&(e)>=2)
#define is_GraemeMercurian(a,e) ((a)<=2&&(e)<=3)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_antenna,num_of_eyes;

    cin>>num_of_antenna>>num_of_eyes;

    cout<<(is_TroyMartian(num_of_antenna,num_of_eyes)?"TroyMartian\n":"");
    cout<<(is_VladSaturnian(num_of_antenna,num_of_eyes)?"VladSaturnian\n":"");
    cout<<(is_GraemeMercurian(num_of_antenna,num_of_eyes)?"GraemeMercurian\n":"");

    return  0;
}