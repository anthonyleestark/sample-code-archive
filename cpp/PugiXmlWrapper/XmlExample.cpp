#include "XmlWrapper.hpp"
#include <iostream>

int wmain() {
    XmlDocument doc;
    if (!doc.LoadFromFile(L"layout.xml")) {
        std::wcout << L"Không thể tải file layout.xml\n";
        return 1;
    }

    XmlNode root = doc.RootElement();
    for (const XmlNode& ctrl : root.Children()) {
        std::wcout << L"Control: " << ctrl.Name() << L"\n";
        for (const XmlAttribute& attr : ctrl.Attributes()) {
            std::wcout << L"  " << attr.Name() << L" = " << attr.Value() << L"\n";
        }
    }

    return 0;
}
