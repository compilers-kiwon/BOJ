#include    <iostream>
#include    <vector>

using namespace std;

static inline int get_required_water(int target,int current)
{
    return  max(0,target-current);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int n,b,required;
        vector<int> h = {0};

        cin>>n;
        if (n == 0) break;

        for (int i=1;i<=n;i++) {
            int height;

            cin>>height;
            h.push_back(height);
        }

        cin>>b;
        required = 0;

        for (int i=1;i<=n;i++) {
            required += get_required_water(h[b]+1,h[i]);
        }

        cout<<required<<'\n';
    }

    return  0;
}