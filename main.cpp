#include "fenetre.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Fenetre window;
    window.show();

    return app.exec();
}


