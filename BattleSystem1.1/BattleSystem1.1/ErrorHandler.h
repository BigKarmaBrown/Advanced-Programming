#pragma once
#include <exception>

using namespace std;
class ErrorHandler : public exception
{
    virtual const char* what() const throw()
    {
        return "Error Error this an error";
    }
};

