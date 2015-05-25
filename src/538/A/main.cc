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

	std::string str, codeforces("CODEFORCES");

	std::cin >> str;

	for (ll i = 0; i < str.size(); i++) {
		for (ll j = 0; j < str.size() - i + 1; j++) {
			std::string tmp = str;
			
			if (tmp.erase(i, j).compare(codeforces) == 0) {
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "NO" << std::endl;


	return 0;
}