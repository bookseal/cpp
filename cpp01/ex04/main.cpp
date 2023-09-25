#include "main.hpp"

int main(void) {
	std::string filename = "infile.txt";
	std::string line;
	std::string total_line;
	std::string s1 = "test";
	std::string s2 = "TEST";
	
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	while (getline(file, line)) {
		std::size_t found = line.find(s1);
		if (found != std::string::npos)
		{
			std::cout << "Word found at index: " << found << std::endl;
			for (int i = 0; i < found; i++) {
				total_line[i] = line[i];
			}
			for (int i = 0; i < s2.length(); i++) {
				total_line[found + i] = s2[i];
			}
			for (int i = found + s1.length(); i < line.length(); i++) {
				total_line[i] = line[i];
			}
		}
		else
			total_line += line;
		total_line += "\n";
	}
	file.close();

	// std::cout << total_line << std::endl;
	return 0;
}