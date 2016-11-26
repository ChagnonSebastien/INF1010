#include <ExceptionCreatureMorte.h>


int ExceptionCreatureMorte::compteur_ = 0;

ExceptionCreatureMorte::ExceptionCreatureMorte(string messageErreur): runtime_error(messageErreur)
{
    compteur_++;
}

ExceptionCreatureMorte::obtenirValeurCompteur()
{
    return compteur_;
}
