#include "rationnel.h"

#include <QString>

const QString Rationnel::toString() const {
    QString string = QString::number(numerateur);
    if (denominateur != 1) {
        string += "/" + QString::number(denominateur);
    }
    return string;
}
