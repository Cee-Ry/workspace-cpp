#include <filesystem>
#include <print>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main() {
  fs::path directories[2] = {"include", "src"};

  for (const auto& i : directories) {
    if (fs::create_directory(i)) println("\033[32m[SUCCESS]:\033[0m {}/ was created successfully", static_cast<string>(i));
    else println("\033[31m[WARNING]:\033[0m {}/ already exist or failed to create!", static_cast<string>(i));
  }
  return 0;
}
