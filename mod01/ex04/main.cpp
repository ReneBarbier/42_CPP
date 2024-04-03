#include <iostream>
#include <fstream>

int input_check(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "error: bad arguments." << std::endl; 
        std::cout << "usage: ./exec <filename> <replaced_str> <replacer_str>" << std::endl;
        return (1);
    }
    if (!argv[1][0] || !argv[2][0] || !argv[3][0])
    {
        std::cout << "error: bad arguments." << std::endl;
        std::cout << "arguments can't be empty." << std::endl;
        return (1);
    }
    return (0);
}

void replace(std::string *textLine, std::string replaced, std::string replacer)
{
    size_t pos = textLine->find(replaced);
    if (pos == std::string::npos)
        return ;
    textLine->erase(pos, replaced.length());
    textLine->insert(pos, replacer);
}

int main(int argc, char **argv)
{
    if (input_check(argc, argv))
       return (1);

    std::fstream readFile(argv[1]);
    if (!readFile)
        return (std::cout << "error: no file found\n", 1);
    std::string textLine;
    std::string outFileName(argv[1]);
    std::ofstream writeFile(outFileName.append(".replace"));
    std::string replaced(argv[2]);
    std::string replacer(argv[3]);
    while (getline(readFile, textLine))
    {
        replace(&textLine, replaced, replacer);
        writeFile << textLine << "\n";
    }
    writeFile.close();
}
