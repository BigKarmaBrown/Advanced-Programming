#pragma once
#include <exception>

using namespace std;
class ErrorHandler : public exception
{
public:
    const string* cantDisplayWInner() const throw()
    {
        return "Error: cant display winner";
    }
     const char* cantAcknowledgeTurn() const throw()
    {
        return "Error: dont know whos turn";
    }
};

