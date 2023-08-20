#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    std::string output_path = argv[1];
    std::string ns = argv[2];
    std::ofstream output_file(output_path);
    output_file << "namespace " << ns << " {\n";
    for (int i = 3; i < argc; i += 2)
    {
        std::string input_path = argv[i];
        std::string var_name = argv[i + 1];
        std::ifstream input_file(input_path);
        std::stringstream buffer;
        buffer << input_file.rdbuf();
        std::string contents = buffer.str();
        output_file << "const char data_" << var_name << "[] = R\"(" << contents << ")\";\n";
        output_file << "const char* " << var_name << "() { return data_" << var_name << "; }\n";
    }
    output_file << "}\n";
    return 0;
}
