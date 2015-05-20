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
	std::vector< std::pair<ll, ll> > trees(n);

	for (ll i = 0; i < n; i++) {
		std::cin >> trees[i].first >> trees[i].second;
	}

	ll total = 0;
	for (ll i = 0; i < trees.size(); i++) {
		if (i == 0) {
			trees[i].second = 0;
			total++;
		} else if (i == trees.size() - 1) {
			total++;
		} else if (trees[i].first - trees[i].second > trees[i - 1].first + trees[i - 1].second) {
			trees[i].second = 0;
			total++;
		} else if (trees[i].first + trees[i].second < trees[i + 1].first) {
			total++;
		} else {
			trees[i].second = 0;
		}
	}


	std::cout << total << std::endl;
	return 0;
}