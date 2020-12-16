#include "myException.h"
#include "myString.h"

MyException::MyException(const char* text) {
    text_ = new char[strLength(text) + 1];
    for (int i = 0; i < strLength(text); ++i) {
        text_[i] = text[i];
    }
    text_[strLength(text)] = '\0';
}

MyException::~MyException() noexcept {
    delete[] text_;
}
