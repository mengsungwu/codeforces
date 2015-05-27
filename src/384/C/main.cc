#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long int ll;

std::vector<ll> a;

ll s;
std::vector<ll> d;

class IntervalSumTree {
public:
	

	IntervalSumTree(std::vector<ll> data) {
		for (M = 1; M < data.size() + 2; M <<= 1)
			;

		tree.resize(M << 1);

		for (ll i = M; i < data.size(); i++)
			tree[M + i] = data[i];
		for (ll i = M - 1; i > 0; i--)
			tree[i] = tree[i << 1] + tree[(i << 1) + 1];
	}

	ll query(ll x, ll y) {

	}


private:
	ll M;
	std::vector<ll> tree;

};


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n;
	std::cin >> n;
	a.resize(n + 1);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}


	ll x, y;
	std::cin >> x >> y;
	std::cout << query(x, y) << std::endl;

	return 0;
}