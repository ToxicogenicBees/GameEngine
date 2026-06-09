/*
    File.cpp

    Implementation of a raw text file storage class
*/

#include "Assets/Types/File.hpp"

File::File(const std::vector<std::byte>& content)
    : Asset("File"),
      CONTENT_(content) {}

const std::vector<std::byte>& File::content() const {
    return CONTENT_;
}
