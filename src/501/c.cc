#include <iostream>
#include <vector>

const unsigned long int MAX = (2 << 16);

typedef struct _vertex{
	unsigned long int degree;
	unsigned long int xorsum;
} vertex;

std::vector<vertex> vertices;
std::vector<unsigned long int> ready;

int main(int argc, char *argv[])
{
	unsigned long int n, edges;
	std::cin >> n;

	vertices.resize(n);
	edges = 0;
	for (unsigned long int i = 0; i < n; i++) {
		vertex v;
		std::cin >> v.degree >> v.xorsum;
		vertices[i] = v;
		edges += v.degree;

		if (v.degree == 1) {
			ready.push_back(i);
		}
	}

	std::cout << edges / 2 << std::endl;

	while (!ready.empty()) {
		unsigned long int v1 = ready.back();
		ready.pop_back();
		if (vertices[v1].degree == 1) {
			unsigned long int v2 = vertices[v1].xorsum;
			std::cout << v1 << " " << v2 << std::endl;
			vertices[v2].degree--;
			vertices[v2].xorsum ^= v1;

			if (vertices[v2].degree == 1) {
				ready.push_back(v2);
			}
		}
	}


	return 0;
}