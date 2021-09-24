#include	<vector>
#include	<algorithm>

int		kth(std::vector<int> &a, int k)
{
	int ans = 0;
 
    std::nth_element(a.begin(),a.begin()+(k-1),a.end());
	ans = a[k-1];
    
	return ans;
}