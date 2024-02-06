/*!
 * \file modificateur.h
 * \brief Represente la personne qui a modifié quelque chose.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include "personne.h"
#include "date.h"
/*! \class Modificateur.
 *  \brief Classe d'une personne ayant modifié quelque chose.
 */
class Modificateur : public Personne
{
private:
    /* data */
    Date modification; /*!< Date de modification de quelque chose.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur du modificateur.
         *
         *  \param personne : personne qui a modifié.
         *  \param date : date de la modification.
         */
    Modificateur(const Personne &, const Date&);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~Modificateur();
};

