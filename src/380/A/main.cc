#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long int ll;

typedef struct Command {
	ll offset;
	ll length;
	ll type;
	ll x, l, c;

	bool operator() (const Command &lhs, const Command &rhs) const {
		return (lhs.offset + lhs.length - 1 < rhs.offset + rhs.length - 1);
	}

	bool operator() (const Command &lhs, const ll rhs) const {
		return (lhs.offset + lhs.length - 1< rhs);
	}

	bool operator() (const ll lhs, const Command &rhs) const {
		return (lhs < rhs.offset + rhs.length - 1);
	}
} Command;

std::vector<ll> a;
std::vector<Command> commands;

void add(ll x)
{
	Command command;
	if (commands.size() == 0) {
		command.offset = a.size();
	} else {
		command.offset = commands.back().offset + commands.back().length;
	}
	command.length = 1;
	command.type = 1;
	command.x = x;
	commands.push_back(command);
}

void add(ll l, ll c)
{
	Command command;
	if (commands.size() == 0) {
		command.offset = a.size();
	}
	else {
		command.offset = commands.back().offset + commands.back().length;
	}
	command.length = l*c;
	command.type = 2;
	command.l = l;
	command.c = c;
	commands.push_back(command);
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll m, n;

	std::cin >> m;
	for (ll i = 0; i < m; i++) {
		ll t, x, l, c;
		std::cin >> t;

		if (t == 1) {
			std::cin >> x;
		}
		else {
			std::cin >> l >> c;
		}

		if (a.size() < 100000) {
			if (t == 1) {
				a.push_back(x);
			}
			else {
				while (c--) {
					for (ll j = 0; j < l; j++) {
						a.push_back(a[j]);
					}
					if (a.size() >= 100000) {
						break;
					}
				}
				if (c > 0) {
					add(l, c);
				}
			}
		} else {
			if (t == 1) {
				add(x);
			}
			else {
				add(l, c);
			}
		}
	}

	std::cin >> n;


	while (n--) {
		ll index;
		std::cin >> index;
		index--;
		if (index < a.size()) {
			std::cout << a[index] << " ";
		} else {
			std::vector<Command>::iterator it = std::lower_bound(commands.begin(), commands.end(), index, Command());
			index -= it->offset;
			if (it->type == 1) {
				std::cout << it->x << " ";
			}
			else {
				std::cout << a[index % it->l] << " ";
			}

		}
	}


	
	return 0;
}