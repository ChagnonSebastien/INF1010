#include <ExceptionCreatureMorte.h>


int ExceptionCreatureMorte::compteur_ = 0;

ExceptionCreatureMorte::ExceptionCreatureMorte(std::string messageErreur): std::runtime_error(messageErreur)
{
    compteur_++;
}

int ExceptionCreatureMorte::obtenirValeurCompteur()
{
    return compteur_;
}
