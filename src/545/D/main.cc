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

	std::vector<ll> queue(n);
	for (ll i = 0; i < n; i++) {
		std::cin >> queue[i];
	}

	std::sort(queue.begin(), queue.end());

	ll total = 0, time = 0;
	for (ll i = 0; i < queue.size(); i++) {
		if (time <= queue[i]) {
			total++;
			time += queue[i];
		}
	}

	std::cout << total << std::endl;


	return 0;
}