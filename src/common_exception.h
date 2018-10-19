#ifndef __COMMON_EXCEPTION_H__
#define __COMMON_EXCEPTION_H__

#include <exception>
#include <string>

class Exception : public std::exception {
public:
	explicit Exception(std::string what);

	~Exception();

	const char* what() const noexcept override;

private:
	const std::string msg;
};

#endif
