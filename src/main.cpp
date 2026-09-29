#include <filesystem>
#include <fstream>
#include <print>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

using namespace std;
namespace fs = std::filesystem;

int main() {
  fs::path directories[2] = {"include", "src"};

  for (const auto& i : directories) {
    if (fs::create_directory(i)) println("{}[SUCCESS]:{} {}/ was created successfully", GREEN, RESET, static_cast<string>(i));
    else println("{}[WARNING]:{} {}/ already exist or failed to create!", RED, RESET, static_cast<string>(i));
  }

  ofstream clangd(".clangd");
  if (!clangd) {
    println(stderr, "{}[WARNING]:{} clangd failed to open for writing!", RED, RESET);
    return 1;
  }

  clangd << "CompileFlags:\n";
  clangd << "  Add: [-std=c++23, -I../include]\n";
  clangd.close();
  println("{}[SUCCESS]:{} .clangd was created successfully", GREEN, RESET);

  return 0;
}
