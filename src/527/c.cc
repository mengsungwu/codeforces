#include <iostream>
#include <set>
#include <vector>

int main(int argc, char *argv[])
{
	unsigned long int maxw, maxh, n;
	std::set<unsigned long int> cutw, cuth;
	std::vector<unsigned long int> intervalw, intervalh;

	std::cin >> maxw >> maxh >> n;

	cutw.insert(0);
	cutw.insert(maxw);
	intervalw.resize(maxw + 1);
	intervalw[maxw]++;


	cuth.insert(0);
	cuth.insert(maxh);
	intervalh.resize(maxh + 1);
	intervalh[maxh]++;


	for (unsigned long int i = 0; i < n; i++) {
		char cut;
		unsigned long int distance, pre, next;
		std::set<unsigned long int>::iterator it;

		std::cin >> cut >> distance;

		if (cut == 'H') {
			cuth.insert(distance);
			it = cuth.find(distance);
			pre = *std::prev(it);
			next = *std::next(it);
			intervalh[next - pre]--;
			intervalh[next - *it]++;
			intervalh[*it - pre]++;
			while (intervalh[maxh] == 0) {
				maxh--;
			}
		}
		else if (cut == 'V') {
			cutw.insert(distance);
			it = cutw.find(distance);
			pre = *std::prev(it);
			next = *std::next(it);
			intervalw[next - pre]--;
			intervalw[next - *it]++;
			intervalw[*it - pre]++;
			while (intervalw[maxw] == 0) {
				maxw--;
			}

		}
		else {
			std::cout << "error" << std::endl;
		}
		std::cout << static_cast<unsigned long long int>(maxw) * maxh << std::endl;
	}


	return 0;
}