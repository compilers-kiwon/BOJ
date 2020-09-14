#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

typedef	struct	_POST_INFO	Post;
struct	_POST_INFO
{
	string		message;
	vector<int>	replies;
};

vector<Post>	post_vec;

void	input(int& num_of_posts)
{
	cin>>num_of_posts;
	
	for(int i=1;i<=num_of_posts;i++)
	{
		int		k;
		Post	p;
		
		cin>>k>>p.message;
		
		post_vec.push_back(p);
		post_vec[k].replies.push_back(i);
	}
}

void	print(int indent,int post_index)
{
	vector<int>&	sub = post_vec[post_index].replies;
	string			head(indent,'.');
	
	for(int i=0;i<sub.size();i++)
	{
		cout<<head<<post_vec[sub[i]].message<<'\n';
		print(indent+1,sub[i]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	Post	root;
	int		n;
	
	post_vec.push_back(root);
	
	input(n);
	print(0,0);
	
	return	0;
}
