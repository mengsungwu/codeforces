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

	ll C, Hr, Hb, Wr, Wb, maximum = 0;

	std::cin >> C >> Hr >> Hb >> Wr >> Wb;

	for (ll i = 0; i*i <= C; i++) {
		if (Wr*i <= C) {
			maximum = std::max(maximum, Hr*i + (C - Wr*i) / Wb * Hb);
		}
		if (Wb*i <= C) {
			maximum = std::max(maximum, Hb*i + (C - Wb*i) / Wr * Hr);
		}
	}

	std::cout << maximum << std::endl;

	return 0;
}