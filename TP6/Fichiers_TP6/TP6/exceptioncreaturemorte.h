#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H
#include <string>

class ExceptionCreatureMorte : public std::runtime_error
{
public:
    ExceptionCreatureMorte(std::string messageErreur);
    static int obtenirValeurCompteur();
private:
    static int compteur_;
};
#endif // EXCEPTIONCREATUREMORTE_H
