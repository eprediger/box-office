#ifndef __COMMON_LOCK_H__
#define __COMMON_LOCK_H__

#include <mutex>

class Lock {
public:
	explicit Lock(std::mutex &m);
	~Lock();

private:
	Lock(const Lock&) = delete;
	Lock& operator=(const Lock&) = delete;
	Lock(Lock&&) = delete;
	Lock& operator=(Lock&&) = delete;

private:
	std::mutex &m;
};

#endif
