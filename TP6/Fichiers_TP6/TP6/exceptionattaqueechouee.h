#ifndef EXCEPTIONATTAQUEECHOUEE_H
#define EXCEPTIONATTAQUEECHOUEE_H
#include <string>

class ExceptionAttaqueEchouee: public std::runtime_error
{
public:
    ExceptionAttaqueEchouee(std::string exception = "");

};
#endif // EXCEPTIONATTAQUEECHOUEE_H
