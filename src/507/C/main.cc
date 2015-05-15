#include <iostream>

#include <algorithm>
#include <vector>
#include <map>
#include <set>

unsigned long long int node_visited(char command, long long int depth, unsigned long long int target)
{

	if (depth == 0) {
		return 0;
	}

	unsigned long long int half = 1ULL << (depth - 1);

	if (command == 'L' && target > half) {
		return (1ULL << depth) + node_visited('L', depth - 1, target - half);
	}

	if (command == 'L' && target <= half) {
		return 1ULL + node_visited('R', depth - 1, target);
	}

	if (command == 'R' && target > half) {
		return 1ULL + node_visited('L', depth - 1, target - half);
	}

	if (command == 'R' && target <= half) {
		return (1ULL << depth) + node_visited('R', depth - 1, target);
	}

}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	unsigned long long int h, n;
	std::cin >> h >> n;

	std::cout << node_visited('L', h, n);

	return 0;
}