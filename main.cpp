#include <bits/stdc++.h> // remove this after it is finished.
#define println(...) puts(std::format(__VA_ARGS__).c_str()) // for debugging

// todo: 这些声明到时候放到头文件里面
std::tuple<bool, std::vector<std::string>, std::map<int, int>, int> get_infos(std::fstream& file);

int main() {
	std::fstream f;
	f.open("temp.txt", std::ios::in);

	auto [is, unnamed_files, same_files, n] = get_infos(f);

	std::fstream __f;
	__f.open("__temp.txt", std::ios::out);

	int i = 0;
	for (; i < unnamed_files.size(); i++) {
		std::string file_name = unnamed_files[i];
		__f << std::format("{}.png {}.png\n", file_name, i + n + 1);
	}

	int begin = i + n + 1;
	for (auto [file_name, cnt] : same_files) {
		while (cnt--) {
			__f << std::format("{}.png {}.png\n", file_name, begin++);
		}
	}

	__f.close();
	f.close();
	return 0;
}

// todo: 拆分这个功能
std::tuple<bool, std::vector<std::string>, std::map<int, int>, int> get_infos(std::fstream& file) {
	std::vector<int> vec;
	std::vector<std::string> unnamed_files;

	std::string s;
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

	auto accumulate_same_files = [] (std::vector<int> nums) -> std::map<int, int> {
		int n = nums.size();
		int p = 0;
		int curr = -1;

		std::map<int, int> map;
		for (int i = 0; i < n; i++) {
			p += p == nums[i];
			map[p] += p == curr;
			curr = p;
		}

		return map;
	};

	std::ranges::sort(vec);
	bool is_sorted = std::ranges::is_sorted(vec);
	return { is_sorted, unnamed_files, accumulate_same_files(vec), vec.size() };
}