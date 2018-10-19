#ifndef __COMMON_FILE_EXCEPTION_H__
#define __COMMON_FILE_EXCEPTION_H__

#include <exception>
#include <string>

class FileException : public std::exception {
public:
	explicit FileException(std::string what);

	~FileException();

	const char* what() const noexcept override;

private:
	const std::string msg;
};

#endif
