#include "operationunaire.h"

/**
 * \fn OperationUnaire:: OperationUnaire(Litteral& l)
 * \brief Fonction de construction de l'objet OperateurUnaire.
 *
 * \param Un objet de type littérale.
 * \return Opération Unaire composée d'une littérale.
 */
OperationUnaire:: OperationUnaire(Litteral& l):unique(&l){}
