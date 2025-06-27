#include <windows.h>
#include <string>

class AppRegistry
{
public:
    static unsigned int GetRegistryValueInt(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName);
    static bool WriteRegistryValueInt(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName, int nValue);
    static std::wstring GetRegistryValueString(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName);
    static bool WriteRegistryValueString(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName, const wchar_t* value);
    static bool DeleteRegistrySection(const wchar_t* sectionName, const wchar_t* subSectionName = nullptr);
};

unsigned int AppRegistry::GetRegistryValueInt(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName)
{
    HKEY hKey;
    LONG result;
    DWORD dwType;
    unsigned int value = UINT_MAX;  // Default if not found

    std::wstring fullSectionName = sectionName;
    if (subSectionName != nullptr) {
        fullSectionName += L"\\" + std::wstring(subSectionName);
    }

    result = RegOpenKeyEx(HKEY_CURRENT_USER, fullSectionName.c_str(), 0, KEY_READ, &hKey);
    if (result == ERROR_SUCCESS) {
        DWORD dwSize = sizeof(unsigned int);
        result = RegQueryValueEx(hKey, keyName, NULL, &dwType, (LPBYTE)&value, &dwSize);
        if (result != ERROR_SUCCESS || dwType != REG_DWORD) {
            value = UINT_MAX; // If it's not found or not the correct type
        }
        RegCloseKey(hKey);
    }

    return value;
}

bool AppRegistry::WriteRegistryValueInt(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName, int nValue)
{
    HKEY hKey;
    LONG result;
    DWORD dwDisposition;
    std::wstring fullSectionName = sectionName;
    if (subSectionName != nullptr) {
        fullSectionName += L"\\" + std::wstring(subSectionName);
    }

    result = RegCreateKeyEx(HKEY_CURRENT_USER, fullSectionName.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition);
    if (result == ERROR_SUCCESS) {
        result = RegSetValueEx(hKey, keyName, 0, REG_DWORD, (const BYTE*)&nValue, sizeof(nValue));
        RegCloseKey(hKey);
        return (result == ERROR_SUCCESS);
    }
    return false;
}

std::wstring AppRegistry::GetRegistryValueString(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName)
{
    HKEY hKey;
    LONG result;
    DWORD dwType;
    wchar_t value[512];
    DWORD dwSize = sizeof(value);

    std::wstring fullSectionName = sectionName;
    if (subSectionName != nullptr) {
        fullSectionName += L"\\" + std::wstring(subSectionName);
    }

    result = RegOpenKeyEx(HKEY_CURRENT_USER, fullSectionName.c_str(), 0, KEY_READ, &hKey);
    if (result == ERROR_SUCCESS) {
        result = RegQueryValueEx(hKey, keyName, NULL, &dwType, (LPBYTE)value, &dwSize);
        if (result == ERROR_SUCCESS && dwType == REG_SZ) {
            RegCloseKey(hKey);
            return std::wstring(value, dwSize / sizeof(wchar_t));
        }
        RegCloseKey(hKey);
    }

    return L"";  // Return an empty string if not found
}

bool AppRegistry::WriteRegistryValueString(const wchar_t* sectionName, const wchar_t* subSectionName, const wchar_t* keyName, const wchar_t* value)
{
    HKEY hKey;
    LONG result;
    DWORD dwDisposition;
    std::wstring fullSectionName = sectionName;
    if (subSectionName != nullptr) {
        fullSectionName += L"\\" + std::wstring(subSectionName);
    }

    result = RegCreateKeyEx(HKEY_CURRENT_USER, fullSectionName.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition);
    if (result == ERROR_SUCCESS) {
        result = RegSetValueEx(hKey, keyName, 0, REG_SZ, (const BYTE*)value, (DWORD)(wcslen(value) + 1) * sizeof(wchar_t));
        RegCloseKey(hKey);
        return (result == ERROR_SUCCESS);
    }

    return false;
}

bool AppRegistry::DeleteRegistrySection(const wchar_t* sectionName, const wchar_t* subSectionName)
{
    HKEY hKey;
    LONG result;
    std::wstring fullSectionName = sectionName;
    if (subSectionName != nullptr) {
        fullSectionName += L"\\" + std::wstring(subSectionName);
    }

    result = RegOpenKeyEx(HKEY_CURRENT_USER, fullSectionName.c_str(), 0, KEY_SET_VALUE, &hKey);
    if (result == ERROR_SUCCESS) {
        result = RegDeleteKey(hKey, fullSectionName.c_str());
        RegCloseKey(hKey);
        return (result == ERROR_SUCCESS);
    }

    return false;
}
