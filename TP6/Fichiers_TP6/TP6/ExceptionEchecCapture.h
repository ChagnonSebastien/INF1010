#ifndef EXCEPTIONECHECCAPTURE_H
#define EXCEPTIONECHECCAPTURE_H
#include <string>

class ExceptionEchecCapture: public std::runtime_error
{
public:
    ExceptionEchecCapture(std::string exception = "");

};
#endif // EXCEPTIONECHECCAPTURE_H
