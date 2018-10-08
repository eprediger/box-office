#include "common_exception.h"

Exception::Exception(std::string what) : 
	msg(std::move(what.c_str())) {}

Exception::~Exception() {}

const char* Exception::what() const noexcept {
	return this->msg;
}
