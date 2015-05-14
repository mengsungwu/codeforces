#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>

std::vector<long long int> flips;
std::vector< std::tuple<unsigned char, unsigned char, bool> > nodes;
std::vector< std::pair<long long int, long long int> > edges;

struct PairLess {
	bool operator() (const std::pair<long long int, long long int> &left, const std::pair<long long int, long long int> &right) {
		if (left.first < right.first) {
			return true;
		}
		if (left.first == right.first && left.second < right.second) {
			return true;
		}
		return false;
	}
};

void flip_tree(long long int node, unsigned char parent, unsigned char grandparent)
{
	std::get<2>(nodes[node]) = true;

	unsigned char value = std::get<0>(nodes[node]) ^ grandparent;
	if (value != std::get<1>(nodes[node])) {
		flips.push_back(node);
		grandparent ^= 1;
	}

	std::vector< std::pair<long long int, long long int> >::iterator it = std::lower_bound(edges.begin(), edges.end(), std::make_pair(node, 0), PairLess());
	while (it != edges.end() && it->first == node) {
		long long int child = it->second;
		if (std::get<2>(nodes[child]) == false) {
			flip_tree(child, grandparent, parent);
		}
		it++;
	}
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	long long int n;
	std::cin >> n;
	

	for (long long int i = 0; i < n - 1; i++) {
		long long int v1, v2;
		std::cin >> v1 >> v2;
		edges.push_back(std::make_pair(v1, v2));
		edges.push_back(std::make_pair(v2, v1));
	}

	std::sort(edges.begin(), edges.end());
	nodes.resize(n + 1);

	for (long long int i = 1; i <= n; i++) {
		std::cin >> std::get<0>(nodes[i]);
	}

	for (long long int i = 1; i <= n; i++) {
		std::cin >> std::get<1>(nodes[i]);
	}

	flip_tree(1, 0, 0);

	std::cout << flips.size() << std::endl;
	for (long long int i = 0; i < flips.size(); i++) {
		std::cout << flips[i] << std::endl;
	}

	return 0;
}