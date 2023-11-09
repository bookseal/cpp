#include "main.hpp"

int main(void) {
	std::string filename = "infile.txt";
	std::string line;
	std::string total_line;
	std::string s1 = "test";
	std::string s2 = "TEST222";
	
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	while (getline(file, line)) {
		std::size_t found = line.find(s1);

		if (found != std::string::npos)
		{
			total_line.append(line, 0, found);
			total_line.append(s2);
			total_line.append(line, found + s1.length(), line.length() - found - s1.length());
		}
		else
			total_line += line;
		total_line += "\n";
	}
	file.close();mplace");
	outfile << total_line;
	return 0;
}