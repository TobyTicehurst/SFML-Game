#pragma once

// deriving from this class makes the class noncopyable and nonmoveable
class NonCopyable {

public:

	// deleted copy and move constructors and assignment operators to avoid pointer invalidation (amoung other things)
	// all are declared deleted even though only copy is needed (more explicit)
	NonCopyable(const NonCopyable& n) = delete;
	NonCopyable& operator = (const NonCopyable &n) = delete;
	NonCopyable(const NonCopyable&& n) = delete;
	NonCopyable& operator = (const NonCopyable&& n) = delete;

protected:

	NonCopyable() = default;
	~NonCopyable() = default;

};