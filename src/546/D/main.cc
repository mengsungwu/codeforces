#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>


typedef long long int ll;

std::vector<ll> count(5000001);

void build_table(void)
{
	for (ll i = 1; i < count.size(); i++) {
		count[i] = 0;
	}

	for (ll i = 2; i < count.size(); i++) {
		if (count[i] == 0) {
			for (ll j = i + i; j < count.size(); j += i) {
				count[j] = i;
			}
		}
	}

	for (ll i = 2; i < count.size(); i++) {
		if (count[i] == 0) {
			count[i] = 1;
		} else {
			count[i] = count[i / count[i]] + 1;
		}
	}

	for (ll i = 1; i < count.size(); i++) 
		count[i] += count[i - 1];
}
int main(int argc, char *argv[])
{

	ll t;
	scanf("%I64d", &t);

	build_table();

	while (t--) {
		ll a, b;
		scanf("%I64d %I64d", &a, &b);
		printf("%I64d\n", count[a] - count[b]);
	}
	
	return 0;
}