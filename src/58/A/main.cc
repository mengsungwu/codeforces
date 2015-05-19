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
	std::string word, hello("hello");
	std::cin >> word;

	ll i = 0;

	for (std::string::iterator it = word.begin(); it != word.end(); it++) {
		if (*it == hello[i]) {
			i++;
		}
	}

	if (i == hello.size()) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}