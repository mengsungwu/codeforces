#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::vector<std::pair<ll, ll> > intervals;

	for (ll i = 0; i < n; i++) {
		ll x, w;
		std::cin >> x >> w;
		intervals.push_back(std::make_pair(x + w,  x - w));
	}

	std::sort(intervals.begin(), intervals.end());

	ll pre = LLONG_MIN;
	ll total = 0;

	for (ll i = 0; i < n; i++) {
		if (intervals[i].second >= pre) {
			total++;
			pre = intervals[i].first;
		}
	}

	std::cout << total << std::endl;
	
	return 0;
}