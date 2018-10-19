#include "common_exception.h"

#include <string>

Exception::Exception(std::string what) : 
	msg(std::move(what)) {}

Exception::~Exception() {}

const char* Exception::what() const noexcept {
	return this->msg.c_str();
}
