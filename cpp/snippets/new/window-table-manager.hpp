#include <unordered_map>
#include <string>
#include <array>
#include <iostream>
#include <variant>

class Window {
public:
    void render() { std::cout << "Rendering window!" << std::endl; }
    // Other window-related methods
};

// Using variant to represent any of the three types of IDs
using WindowID = std::variant<uint64_t, std::string, std::array<uint8_t, 16>>;

// Define a custom hash and equality function for the variant
struct WindowIDHash {
    size_t operator()(const WindowID& windowID) const {
        return std::visit([](auto&& arg) {
            return std::hash<std::decay_t<decltype(arg)>>()(arg);
        }, windowID);
    }
};

struct WindowIDEqual {
    bool operator()(const WindowID& lhs, const WindowID& rhs) const {
        return lhs == rhs;
    }
};

// Define the map that stores windows by any type of ID
using WindowTable = std::unordered_map<WindowID, Window, WindowIDHash, WindowIDEqual>;

WindowTable windowRegistry;

void addWindow(const WindowID& id, const Window& window) {
    windowRegistry[id] = window;
}

Window* getWindowByID(const WindowID& id) {
    auto it = windowRegistry.find(id);
    return it != windowRegistry.end() ? &it->second : nullptr;
}

int main() {
    Window window1;
    window1.render();
    
    // Add windows using different IDs
    addWindow(12345, window1); // By ID
    addWindow("window_name", window1); // By name
    std::array<uint8_t, 16> uuid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    addWindow(uuid, window1); // By UUID
    
    // Retrieve windows by any ID
    Window* w1 = getWindowByID(12345);
    Window* w2 = getWindowByID("window_name");
    Window* w3 = getWindowByID(uuid);
    
    std::cout << "Window 1 retrieved by ID: " << (w1 ? "Found" : "Not Found") << std::endl;
    std::cout << "Window 2 retrieved by Name: " << (w2 ? "Found" : "Not Found") << std::endl;
    std::cout << "Window 3 retrieved by UUID: " << (w3 ? "Found" : "Not Found") << std::endl;
    
    return 0;
}
