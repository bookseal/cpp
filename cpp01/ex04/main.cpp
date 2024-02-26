#include "main.hpp"

std::string processFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::string line, total_line;
    // 변수를 선언한다.
    // Data type: std::ifstream
    // Variable name: file
	std::ifstream file(filename);

    // 점은 언제 쓰는가?
         // 점은 변수에 쓴다.
    // 점은 변수에 안 쓰는가?
        // 점은 변수에 쓴다.
    // ㅎ: 점은 구조체에 쓴다.
    // 구조체는 변수인가?
	if (!file.is_open())
		throw std::runtime_error("Error: file not found");

	while (std::getline(file, line))
    {
		std::size_t found = line.find(s1);
		std::size_t start = 0;
        // line = "Hello, this is a test line"
        // s1 = "is"
        // s2 = "was"
		while (found != std::string::npos)
		{
			total_line.append(line, start, found - start);
			total_line.append(s2);
			start = found + s1.length();
			found = line.find(s1, start);
		}
		total_line.append(line, start, line.length() - start);
		total_line += "\n";
	}
	file.close();
    // total_line = "Hello, thwas was a test line\n"
	return total_line;
}

bool writeFile(const std::string& filename, const std::string& content)
{
    // Data type: std::ofstream
    // Variable name: outFile
	std::ofstream outFile(filename);
	
	if (!outFile.is_open())
		return false;
    // << 는 무엇인가?
        // << 는 출력 연산자이다.
	outFile << content;
	outFile.close();
	return true;
}

/*
 Create a program that takes three parameters in the following order:
 a filename and two strings, s1 and s2.

It will open the file <filename> and
 copies its content into a new file <filename>.replace,
 replacing every occurrence of s1 with s2.

Using C file manipulation functions is forbidden and will be considered cheating.
 All the member functions of the class std::string are allowed, except replace.
 Use them wisely!

 */
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: <program> <filename> <search string> <replace string>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string newFilename = filename + ".replace";

    std::string processedContent = processFile(filename, s1, s2);
    // std::string processedContent = "Hello, thwas was a test line\n"
    if (!writeFile(newFilename, processedContent))
    {
        std::cerr << "Error: Unable to write to file " << newFilename << std::endl;
        return 1;
    }

	return 0;
}
