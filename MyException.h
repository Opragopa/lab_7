#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

class MyException : public std::exception 
{
public:
	explicit MyException(const char* text);
	~MyException() noexcept override;
private:
	char* text_;
};
#endif