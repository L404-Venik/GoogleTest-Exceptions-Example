#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>


// ������� ����� ����������
class TMyException : public std::runtime_error
{
    std::string message;

public:

    explicit TMyException(const std::string& msg = "")
        : std::runtime_error(msg), message(msg) {}

    // �������� ��� ���������� ������ � ����������
    TMyException& operator<<(const std::string& text)
    {
        message += text;
        return *this;
    }

    // ��������������� ������ what()
    const char* what() const noexcept override
    {
        return message.c_str();
    }

};

// ������-����������
class DerivedException1 : public TMyException
{
public:
    explicit DerivedException1(const std::string& msg = "")
        : TMyException(msg) {
    }
};

class DerivedException2 : public TMyException
{
public:
    explicit DerivedException2(const std::string& msg = "")
        : TMyException(msg) {
    }
};

class DerivedException3 : public TMyException {

public:
    explicit DerivedException3(const std::string& msg = "")
        : TMyException(msg) {
    }
};