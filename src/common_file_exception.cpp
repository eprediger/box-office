#include "common_file_exception.h"

#include <string>

FileException::FileException(std::string what) : 
	msg(std::move(what)) {}

FileException::~FileException() {}

const char* FileException::what() const noexcept {
	return this->msg.c_str();
}
