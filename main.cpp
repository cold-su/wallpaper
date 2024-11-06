#include <bits/stdc++.h> // remove this after it is finished.

bool is_sorted(std::fstream& file);

int main() {
	std::fstream f;
	f.open("temp.txt", std::ios::in);

	if (is_sorted(f)) {
		return 0;
	}

	return 0;
}

bool is_sorted(std::fstream& file) {
	std::string s;
	std::vector<int> nums;
	while (getline(file, s)) {
		std::string new_string;

		for (char i : s) {
			if (i == '.') {
				break;
			}
			new_string += i;
		}

		nums.push_back(std::stoi(new_string));
	}

	return std::ranges::is_sorted(nums);
}