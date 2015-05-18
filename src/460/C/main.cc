#include <iostream>
#include <limits>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>



typedef long long int ll;

ll n, m, w, minimum;
std::vector<ll> heights;
bool possible(ll height)
{
	ll current = 0, total = 0;
	std::vector<ll> segments(heights.size());
	for (ll i = 0; i < heights.size(); i++) {
		if (i >= w) {
			current -= segments[i - w];
		}

		if (heights[i] + current < height) {
			segments[i] = height - current - heights[i];
			current += segments[i];
		}

		total += segments[i];
	}


	return (total <= m);
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> m >> w;
	heights.resize(n);

	minimum = LLONG_MAX;
	for (ll i = 0; i < n; i++) {
		std::cin >> heights[i];
		minimum = std::min(minimum, heights[i]);
	}

	ll begin = minimum;
	ll end = minimum + m;
	while (begin < end) {
		ll middle = begin + (end - begin + 1) / 2;
		if (possible(middle)) {
			begin = middle;
		} else {
			end = middle - 1;
		}
	}

	std::cout << begin << std::endl;

	return 0;
}