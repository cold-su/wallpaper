#include <bits/stdc++.h> // remove this after it is finished.

std::pair<bool, std::vector<int>> is_sorted(std::fstream& file);

int main() {
	std::fstream f;
	f.open("temp.txt", std::ios::in);

	auto [is, nums] = is_sorted(f);

	if (is) {
		return 0;
	}

	return 0;
}

std::pair<bool, std::vector<int>> is_sorted(std::fstream& file) {
	std::string s;
	std::vector<int> vec;
	while (getline(file, s)) {
		if (s == "") {
			continue;
		}
		std::string new_string;

		for (char i : s) {
			if (i == '.') {
				break;
			}
			new_string += i;
		}

		vec.push_back(std::stoi(new_string));
	}

	bool __is_sorted = std::ranges::is_sorted(vec);

	return { __is_sorted, vec };
}