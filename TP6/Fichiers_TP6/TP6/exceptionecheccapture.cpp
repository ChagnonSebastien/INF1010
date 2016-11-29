#include <ExceptionEchecCapture.h>

ExceptionEchecCapture::ExceptionEchecCapture(std::string exception): std::runtime_error(exception)
{

}
