#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long int ll;

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n;
	std::cin >> n;
	std::vector<ll> boxes(n);
	std::map<ll, ll> piles;

	for (ll i = 0; i < n; i++) {
		std::cin >> boxes[i];
	}

	std::sort(boxes.begin(), boxes.end());

	for (ll i = 0; i < n; i++) {
		std::map<ll, ll>::iterator it;
		for (it = piles.begin(); it != piles.end(); it++) {
			if (it->second <= boxes[i]) {
				it->second++;
				break;
			}
		}
		if (it == piles.end()) {
			piles[piles.size()] = 1;
		}
	}

	std::cout << piles.size() << std::endl;


	return 0;
}