#include "main.hpp"

std::string processFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::string line, total_line;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Error: file not found");
    }

    while (std::getline(file, line))
    {
        std::size_t found = line.find(s1);
        std::size_t start = 0;

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
    return total_line;
}

bool writeFile(const std::string& filename, const std::string& content)
{
    std::ofstream outFile(filename);
    if (!outFile.is_open())
        return false;
    outFile << content;
    outFile.close();
    return true;
}

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

    try
    {
        std::string processedContent = processFile(filename, s1, s2);
        if (!writeFile(newFilename, processedContent))
        {
            std::cerr << "Error: Unable to write to file " << newFilename << std::endl;
            return 1;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
