#pragma once
#include <exception>

using namespace std;
class ErrorHandler : public exception
{
public:
    virtual const char* cantDisplayWInner() const throw()
    {
        return "Error Error this an error";
    }
};

