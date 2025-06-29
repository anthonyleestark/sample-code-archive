#include <iostream>
#include <windows.h>
using namespace std;

// a function that shows the free space of a specific disk volume
bool get_disk_free_space(const string& volume, ULARGE_INTEGER& free_space) {
    // convert the volume name to a wide string
    wstring wvolume(volume.begin(), volume.end());
    // get the free space for the current user
    BOOL result = GetDiskFreeSpaceExW(wvolume.c_str(), &free_space, NULL, NULL);
    // return true if successful, false otherwise
    return result != 0;
}

// example usage
int main() {
    string volume = "C:\\";
    ULARGE_INTEGER free_space;
    bool success = get_disk_free_space(volume, free_space);
    if (success) {
        cout << "The free space of " << volume << " is " << free_space.QuadPart << " bytes\n";
    } else {
        cout << "Failed to get the free space of " << volume << "\n";
    }
    return 0;
}