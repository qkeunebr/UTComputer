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
    QString string = QString::number(numerateur);
    if (denominateur != 1) {
        string += "/" + QString::number(denominateur);
    }
    return string;
}
