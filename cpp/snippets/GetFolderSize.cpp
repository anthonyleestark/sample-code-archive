#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

// a function that shows the size of a specific folder
long long get_folder_size(const fs::path& folder) {
    // initialize the total size
    long long total_size = 0;
    // loop through all the files and subfolders in the folder
    for (const auto& entry : fs::recursive_directory_iterator(folder)) {
        // ignore symbolic links
        if (!fs::is_symlink(entry.path())) {
            // get the size of the file in bytes
            long long file_size = fs::file_size(entry.path());
            // add the file size to the total size
            total_size += file_size;
        }
    }
    // return the total size in bytes
    return total_size;
}

// example usage
int main() {
    fs::path folder = "C:\\Users\\Admin\\Documents";
    long long size = get_folder_size(folder);
    std::cout << "The size of " << folder << " is " << size << " bytes\n";
    return 0;
}