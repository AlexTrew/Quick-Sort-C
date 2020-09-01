#include <vector>
#include <iostream>
#include <regex>
#include <sstream>

int Partition(std::vector<int>& A, int start, int end) {
	int pivot = A[end];
	int j = start;
	for (int i=start; i < end; i++) {
		if (A[i] < pivot) {
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			++j;
		}
	}
	int temp = A[end];
	A[end] = A[j];
	A[j] = temp;
	return j;
}

int QuickSort(std::vector<int>& A, int start, int end) {
	if (start < end) {
		int p = Partition(A, start, end);
		QuickSort(A, start, p - 1);
		QuickSort(A, p + 1, end);
	}
	return 0;
}

int main() {
	while (true) {
		std::cout << "Enter a sequence of numbers, separated by spaces. Type \"q\" to quit:" << std::endl;

		std::string input;
		std::getline(std::cin, input);
		if (std::regex_match(input, std::regex("(-?[0-9]+\\ )+-?[0-9]+")) || input.compare("q") == 0) {
			if (input.compare("q") == 0) {
				return 1;
			}

			std::istringstream iss(input);
			std::vector<std::string> numbers((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

			std::vector<int> sort_me;
			for (std::string& number : numbers) {
				sort_me.push_back(std::stoi(number));
			}

			QuickSort(sort_me, 0, sort_me.size()-1);
			std::string output;
			for (int num : sort_me) {
				output = output + std::to_string(num) + " ";
			}
			std::cout << output << std::endl;
		}
		else {
			std::cout << "input format error" << std::endl;
		}
	}
	return 0;
}