#include <iostream>
#include <fstream>
#include <string>

// Function to replace all occurrences of s1 with s2 in a string
std::string replaceInString(std::string line, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return line;

    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length();
    }
    return line;
}

int main(int argc, char *argv[]) {
    // Check if we have the correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Open input file
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Cannot open input file " << filename << std::endl;
        return 1;
    }

    // Create and open output file
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output file " << outFilename << std::endl;
        inFile.close();
        return 1;
    }

    // Process the file line by line
    std::string line;
    while (std::getline(inFile, line)) {
        // Replace s1 with s2 in the current line
        std::string modifiedLine = replaceInString(line, s1, s2);

        // Write the modified line to the output file
        outFile << modifiedLine;

        // Add newline if not at end of file
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}
