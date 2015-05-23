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
	std::vector<ll> badges(n);
	for (ll i = 0; i < badges.size(); i++) {
		std::cin >> badges[i];
	}

	ll total = 0;
	ll duplicate = 0;
	std::sort(badges.begin(), badges.end());

	for (ll i = 1; i < badges.size(); i++) {
		ll diff = badges[i] - badges[i - 1];
		if (diff == 0) {
			duplicate++;
		} else if (diff > duplicate) {
			total += (1 + duplicate) * duplicate / 2;
			duplicate = 0;
		} else {
			for (ll j = 0; j < diff; j++) {
				total += duplicate;
				duplicate--;
			}
			duplicate++;
		}
	}
	total += (1 + duplicate) * duplicate / 2;
	std::cout << total << std::endl;
	
	return 0;
}