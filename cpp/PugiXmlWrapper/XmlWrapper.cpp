#include "XmlWrapper.hpp"
#include <sstream>

XmlDocument::XmlDocument() {}

bool XmlDocument::LoadFromFile(const std::wstring& filePath) {
    return doc_.load_file(filePath.c_str());
}

bool XmlDocument::LoadFromString(const std::wstring& xmlContent) {
    return doc_.load_string(pugi::as_utf8(xmlContent).c_str());
}

bool XmlDocument::SaveToFile(const std::wstring& filePath, const wchar_t* indent) const {
    return doc_.save_file(filePath.c_str(), pugi::as_utf8(indent).c_str());
}

std::wstring XmlDocument::ToString(const wchar_t* indent) const {
    std::ostringstream oss;
    doc_.save(oss, pugi::as_utf8(indent).c_str());
    return pugi::as_wide(oss.str());
}

XmlNode XmlDocument::RootElement() {
    return XmlNode(doc_.document_element());
}

XmlAttribute::XmlAttribute(pugi::xml_attribute attr) : attr_(attr) {}

std::wstring XmlAttribute::Name() const {
    return pugi::as_wide(attr_.name());
}

std::wstring XmlAttribute::Value() const {
    return pugi::as_wide(attr_.value());
}

void XmlAttribute::SetValue(const std::wstring& value) {
    attr_.set_value(pugi::as_utf8(value).c_str());
}

bool XmlAttribute::Empty() const {
    return attr_.empty();
}

XmlNode::XmlNode() : node_() {}
XmlNode::XmlNode(pugi::xml_node node) : node_(node) {}

std::wstring XmlNode::Name() const {
    return pugi::as_wide(node_.name());
}

std::wstring XmlNode::Value() const {
    return pugi::as_wide(node_.child_value());
}

void XmlNode::SetValue(const std::wstring& val) {
    node_.text().set(pugi::as_utf8(val).c_str());
}

XmlAttribute XmlNode::Attribute(const std::wstring& name) const {
    return XmlAttribute(node_.attribute(pugi::as_utf8(name).c_str()));
}

void XmlNode::SetAttribute(const std::wstring& name, const std::wstring& value) {
    node_.append_attribute(pugi::as_utf8(name).c_str()) = pugi::as_utf8(value).c_str();
}

std::vector<XmlAttribute> XmlNode::Attributes() const {
    std::vector<XmlAttribute> result;
    for (auto attr : node_.attributes()) {
        result.push_back(XmlAttribute(attr));
    }
    return result;
}

XmlNode XmlNode::Child(const std::wstring& name) const {
    return XmlNode(node_.child(pugi::as_utf8(name).c_str()));
}

XmlNode XmlNode::FirstChild() const {
    return XmlNode(node_.first_child());
}

XmlNode XmlNode::NextSibling() const {
    return XmlNode(node_.next_sibling());
}

std::vector<XmlNode> XmlNode::Children() const {
    std::vector<XmlNode> result;
    for (auto child : node_.children()) {
        result.push_back(XmlNode(child));
    }
    return result;
}

std::vector<XmlNode> XmlNode::Children(const std::wstring& name) const {
    std::vector<XmlNode> result;
    for (auto child : node_.children(pugi::as_utf8(name).c_str())) {
        result.push_back(XmlNode(child));
    }
    return result;
}

XmlNode XmlNode::AppendChild(const std::wstring& name) {
    return XmlNode(node_.append_child(pugi::as_utf8(name).c_str()));
}

void XmlNode::RemoveChild(const std::wstring& name) {
    node_.remove_child(pugi::as_utf8(name).c_str());
}

XmlNode XmlNode::SelectSingleNode(const std::wstring& xpath) const {
    return XmlNode(node_.select_node(pugi::as_utf8(xpath).c_str()).node());
}

std::vector<XmlNode> XmlNode::SelectNodes(const std::wstring& xpath) const {
    std::vector<XmlNode> result;
    auto set = node_.select_nodes(pugi::as_utf8(xpath).c_str());
    for (auto&& entry : set) {
        result.push_back(XmlNode(entry.node()));
    }
    return result;
}

bool XmlNode::Empty() const {
    return node_.empty();
}
