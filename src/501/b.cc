#include <iostream>
#include <string>

const unsigned long int MAX = 1000;

std::string old_names[MAX];
std::string new_names[MAX];

int main(int argc, char *argv[])
{
	unsigned long int n, name_count;
	std::cin >> n;
	name_count = 0;

	for (unsigned long int i = 0; i < n; i++) {
		unsigned long int j;
		std::string old_name, new_name;
		std::cin >> old_name >> new_name;

		for (j = 0; j < name_count; j++) {
			if (new_names[j].compare(old_name) == 0) {
				new_names[j] = new_name;
				break;
			}
		}
		if (j == name_count) {
			old_names[name_count] = old_name;
			new_names[name_count] = new_name;
			name_count++;
		}
	}

	std::cout << name_count << std::endl;
	for (unsigned long int i = 0; i < name_count; i++) {
		std::cout << old_names[i] << " " << new_names[i] << std::endl;
	}

	return 0;
}