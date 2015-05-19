#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;

ll a, b, n;

bool possible(ll l, ll r, ll t, ll m)
{
	ll al = a + (l - 1) * b;
	ll ar = a + (r - 1) * b;
	ll sum = (al + ar) * (r - l + 1) / 2;

	return (ar <= t && sum <= t * m);
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	
	std::cin >> a >> b >> n;
	for (ll i = 0; i < n; i++) {
		ll l, t, m;
		std::cin >> l >> t >> m;

		ll begin = l;
		ll end = l + t;
		while (begin < end) {
			ll middle = begin + (end - begin + 1) / 2;
			if (possible(l, middle, t, m)) {
				begin = middle;
			} else {
				end = middle - 1;
			}
		}
		if (possible(l, begin, t, m)) {
			std::cout << begin << std::endl;
		} else {
			std::cout << -1 << std::endl;
		}
	}

	return 0;
}