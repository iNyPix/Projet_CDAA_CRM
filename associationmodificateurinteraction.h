#ifndef CRM_ASSOCIATIONMODIFICATEURINTERACTION_H
#define CRM_ASSOCIATIONMODIFICATEURINTERACTION_H
/*!
 * \file associationmodificateurinteraction.h
 * \brief Classe permettant de retrouver un modificateur d'une interaction
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include "modificateur.h"
#include "interaction.h"
/*! \class AssociationModificateurInteraction.
 *  \brief Classe associant un modificateur à une interaction.
 */
class AssociationModificateurInteraction {

private:
    Modificateur * modificateur; /*!< Modificateur de l'interaction.*/
    Interaction * interaction;/*!< Interaction modifié.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         *
         */
    AssociationModificateurInteraction();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur par défaut.
         *
         */
    ~AssociationModificateurInteraction();

    void setMod(Modificateur *);
    void setInteraction(Interaction *);
    /*!
         *  \brief Retrouve le modificateur.
         *
         *  \return La personne qui a modifié l'interaction.
         */
    Modificateur* getModif();
    /*!
         *  \brief Retrouve l'interaction.
         *
         *  \return L'interaction modifié.
         */
    Interaction* getInteraction();
};


#endif //CRM_ASSOCIATIONMODIFICATEURINTERACTION_H
