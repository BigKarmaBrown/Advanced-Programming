#pragma once
#include <exception>

using namespace std;
class ErrorHandler : public exception
{
public:
    virtual const char* cantDisplayWInner() const throw()
    {
        return "Error: cant display winner";
    }
    virtual const char* cantAcknowledgeTurn() const throw()
    {
        return "Error: dont know whos turn";
    }
};

