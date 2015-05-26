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
	
	std::string s1, s2;

	std::cin >> s1 >> s2;

	ll distance = 0;
	for (ll i = 0; i < s1.size(); i++)
		if (s1[i] != s2[i])
			distance++;

	if (distance % 2) {
		std::cout << "impossible" << std::endl;
	} else {
		for (ll i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i])
				distance -= 2;
			if (distance < 0) 
				s1[i] = s2[i];
		}
		std::cout << s1 << std::endl;
	}

	return 0;
}