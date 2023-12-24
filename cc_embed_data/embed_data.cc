#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
  std::string output_path = argv[1];
  std::string ns = argv[2];
  std::ofstream output_file(output_path);
  output_file << "#include <cstdint>\n";
  output_file << "namespace " << ns << " {\n";
  for (int i = 3; i < argc; i += 2) {
    std::string input_path = argv[i];
    std::string var_name = argv[i + 1];
    std::replace(var_name.begin(), var_name.end(), '-', '_');
    std::ifstream input_file(input_path, std::ios::binary);
    output_file << "const char data_" << var_name << "[] = {";
    char ch;
    int64_t byte_count = 0;
    while (input_file.get(ch)) {
      output_file << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned int>(static_cast<unsigned char>(ch))
                  << ',';
      byte_count++;
    }
    output_file << "0x00};\n";  // null terminator
    output_file << "const char* " << var_name << "() { return data_" << var_name
                << "; }\n";
    output_file << "uint64_t " << var_name << "_size() { return "
                << std::to_string(byte_count) << "; }\n";
  }
  output_file << "}\n";
  return 0;
}