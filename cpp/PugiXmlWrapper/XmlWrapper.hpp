#pragma once
#include "pugixml.hpp"
#include <string>
#include <vector>

class XmlNode;
class XmlAttribute;

class XmlDocument {
public:
    XmlDocument();
    bool LoadFromFile(const std::wstring& filePath);
    bool LoadFromString(const std::wstring& xmlContent);
    bool SaveToFile(const std::wstring& filePath, const wchar_t* indent = L"    ") const;
    std::wstring ToString(const wchar_t* indent = L"    ") const;
    XmlNode RootElement();
private:
    pugi::xml_document doc_;
    friend class XmlNode;
};

class XmlAttribute {
public:
    XmlAttribute(pugi::xml_attribute attr);
    std::wstring Name() const;
    std::wstring Value() const;
    void SetValue(const std::wstring& value);
    bool Empty() const;
private:
    pugi::xml_attribute attr_;
};

class XmlNode {
public:
    XmlNode();
    XmlNode(pugi::xml_node node);
    std::wstring Name() const;
    std::wstring Value() const;
    void SetValue(const std::wstring& val);

    XmlAttribute Attribute(const std::wstring& name) const;
    void SetAttribute(const std::wstring& name, const std::wstring& value);
    std::vector<XmlAttribute> Attributes() const;

    XmlNode Child(const std::wstring& name) const;
    XmlNode FirstChild() const;
    XmlNode NextSibling() const;
    std::vector<XmlNode> Children() const;
    std::vector<XmlNode> Children(const std::wstring& name) const;

    XmlNode AppendChild(const std::wstring& name);
    void RemoveChild(const std::wstring& name);

    XmlNode SelectSingleNode(const std::wstring& xpath) const;
    std::vector<XmlNode> SelectNodes(const std::wstring& xpath) const;

    bool Empty() const;

private:
    pugi::xml_node node_;
};
