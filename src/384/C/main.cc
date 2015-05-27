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

typedef class SegmentTree {
public:

	SegmentTree(std::vector<ll> data) {

		for (M = 1; M < data.size() + 2; M <<= 1)
			;

		tree.resize(M << 1);

		for (ll i = 0; i < data.size(); i++)
			tree[M + i] = data[i];

		for (ll i = M - 1; i > 0; i--) 
			tree[i] = tree[i << 1] + tree[(i << 1) + 1];

	}

	ll query(ll x, ll y) {
		ll total = 0;
		for (x += M - 1, y += M + 1; x^y ^ 1; x >>= 1, y >>= 1) {
			if (~x & 1) total += tree[x ^ 1];
			if (y & 1) total += tree[y ^ 1];
		}
		return total;
	}


private:
	ll M;
	std::vector<ll> tree;

} SegmentTree;


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n, total = 0;
	std::cin >> n;
	a.resize(n + 1);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	SegmentTree tree(a);

	for (ll i = 1; i <= n; i++) {
		if (a[i] == 0) {
			total += tree.query(1, i);
		}
	}

	std::cout << total << std::endl;

	return 0;
}