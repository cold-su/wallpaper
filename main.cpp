#include <bits/stdc++.h> // remove this after it is finished.
#define println(...) puts(std::format(__VA_ARGS__).c_str()) // for debugging

// todo: 这些声明到时候放到头文件里面
std::tuple<bool, std::vector<std::string>, int, int> is_sorted(std::fstream& file);

int main() {
	std::fstream f;
	f.open("temp.txt", std::ios::in);

	auto [is, files, pos, n] = is_sorted(f);
	bool have_unnamed_files = files.size() > 0;

	std::vector<std::pair<std::string, int>> queue;
	if (have_unnamed_files) {
		if (is) {
			std::fstream __f;
			__f.open("__temp.txt", std::ios::out);
			for (int i = 0; i < files.size(); i++) {
				std::string file_name = files[i];
				__f << std::format("{}.png {}.png\n", file_name, i + n + 1);
			}
			__f.close();
		}
		// todo
	}

	f.close();
	return 0;
}

// todo: 拆分这个功能
std::tuple<bool, std::vector<std::string>, int, int> is_sorted(std::fstream& file) {
	std::string s;
	std::vector<int> vec;
	std::vector<std::string> unnamed_files;
	while (getline(file, s)) {
		if (s == "") {
			continue;
		}
		std::string new_string;

		bool named = true;
		for (char i : s) {
			if (i == '.') {
				break;
			}
			if (!('0' <= i && i <= '9')) {
				named = false;
			}
			new_string += i;
		}

		if (!named) {
			unnamed_files.push_back(new_string);
		} else {
			vec.push_back(std::stoi(new_string) - 1);
		}

	}

	auto check = [] (std::vector<int> nums) -> std::pair<bool, int> {
		int n = nums.size();
		int p = 0;
		for (int i = 0; i < n; i++) {
			p += p == nums[i];
		}
		p--;

		return {p == nums[n - 1], p};
	};

	std::ranges::sort(vec);
	auto [__is_sorted, pos] = check(vec); //todo: pos 是第一个出现的空位

	return { __is_sorted, unnamed_files, pos, vec.size() };
}