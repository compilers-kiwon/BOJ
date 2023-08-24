#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (5)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,max_num_of_people;
    int cnt[MAX_SIZE+1] = {0,};
    vector<int> day;

    cin>>N;
    max_num_of_people = 0;

    for (int i=1;i<=N;i++) {
        char    p[MAX_SIZE+2];

        cin>>&p[1];

        for (int d=1;d<=MAX_SIZE;d++) {
            if (p[d] == 'Y') {
                if(++cnt[d] >= max_num_of_people) {
                    if (cnt[d] > max_num_of_people) day.clear();
                    max_num_of_people = cnt[d];
                    day.push_back(d);
                }
            }
        }
    }

    sort(day.begin(),day.end());

    for (int i=0;i<day.size();i++) {
        cout<<day[i]<<(i==day.size()-1?'\n':',');
    }

    return  0;
}