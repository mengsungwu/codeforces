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

	std::vector<ll> likes(26);
	std::string s;

	for (ll i = 0; i < likes.size(); i++) {
		std::cin >> likes[i];
	}

	std::cin >> s;

	ll total = 0, sum = 0;
	std::map< std::pair<ll, ll>, ll > d;

	for (ll i = 0; i < s.size(); i++) {
		total += d[std::make_pair(s[i], sum)];
		sum += likes[s[i] - 'a'];
		d[std::make_pair(s[i], sum)]++;
	}

	std::cout << total << std::endl;
	
	return 0;
}