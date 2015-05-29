#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long int ll;

typedef class BIT2D {
public:
	BIT2D(ll n, ll m) {
		tree.resize(4);
		for (ll i = 0; i < tree.size(); i++) {
			tree[i].resize(n);
			for (ll j = 0; j < tree[i].size(); j++) {
				tree[i][j].resize(n);
			}
		}
	}

	ll query(ll r, ll c) {
		ll index = (r % 2) * 2 + (c % 2);
		ll val = 0;
		for (ll x = r; x > 0; x -= (x & -x)) {
			for (ll y = c; y > 0; y -= (y & -y)) {
				val ^= tree[index][x][y];
			}
		}
		return val;
	}

	void update(ll r, ll c, ll val) {
		ll index = (r % 2) * 2 + (c % 2);
		for (ll x = r; x < tree[index].size(); x += (x & -x)) {
			for (ll y = c; y < tree[index][x].size(); y += (y & -y)) {
				tree[index][x][y] ^= val;
			}
		}
	}

private:
	std::vector< std::vector< std::vector<ll> > > tree;
} BIT2D;


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n, m;
	std::cin >> n >> m;

	BIT2D tree(n+1, n+1);

	for (ll i = 0; i < m; i++) {
		ll t, x0, y0, x1, y1, val;
		std::cin >> t >> x0 >> y0 >> x1 >> y1;
		if (t == 1) {
			val = tree.query(x1, y1) ^ tree.query(x0 - 1, y0 - 1) ^ tree.query(x1, y0 - 1) ^ tree.query(x0 - 1, y1);
			std::cout << val << "\n";
		} else if (t == 2) {
			std::cin >> val;
			tree.update(x0, y0, val);
			tree.update(x1 + 1, y0, val);
			tree.update(x0, y1 + 1, val);
			tree.update(x1 + 1, y1 + 1, val);
			
		} else {
			assert(false);
		}
	}
	
	return 0;
}