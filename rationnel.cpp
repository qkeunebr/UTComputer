#include "rationnel.h"

#include <QString>

/**
 * \fn const QString Rationnel::toString() const
 * \brief Méthode toString() pour la classe Rationnel.
 *
 * \param
 * \return Objet de type QString représentant un objet de type Rationnel.
 */
const QString Rationnel::toString() const {
    QString string;
    if(numerateur!=0){
        string += QString::number(numerateur);
    }
    if (denominateur != 1 && denominateur!=0) {
        string += "/" + QString::number(denominateur);
    }
    if(numerateur==0 || denominateur==0){
        string += QString::number(denominateur);

    }
    return string;
}
