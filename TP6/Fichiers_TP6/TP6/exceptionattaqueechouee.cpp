#include "ExceptionAttaqueEchouee.h"

ExceptionAttaqueEchouee::ExceptionAttaqueEchouee(std::string exception) : std::runtime_error(exception)
{

}
