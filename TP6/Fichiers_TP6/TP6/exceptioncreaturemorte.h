#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H


class ExceptionCreatureMorte: public runtime_error
{

public:
    ExceptionCreatureMorte(string messageErreur);
    static int obtenirValeurCompteur();
private:
    static int compteur_;
}
#endif // EXCEPTIONCREATUREMORTE_H
