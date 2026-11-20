#pragma once
#include <exception>

using namespace std;
class ErrorHandler : public exception
{
public:
    const char* cantDisplayWInner() const throw()
    {
        return "Error: cant display winner";
    }
    //Define an error with a return type of char which is a constant. 
    // This way we return the intended error message.
     const char* cantAcknowledgeTurn() const throw()
    {
        return "Error: dont know whos turn";
    }
};

