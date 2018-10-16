#include "common_exception.h"

#include <string>

Exception::Exception(std::string what) : 
	msg(std::move(what.c_str())) {}

Exception::~Exception() {}

const char* Exception::what() const noexcept {
	return this->msg;
}
