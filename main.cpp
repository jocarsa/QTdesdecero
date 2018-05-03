#include <QGuiApplication>              // Esto es la base
#include <Qt3DExtras/qt3dwindow.h>      // Esto me permite crear una ventana 3D
#include <Qt3DCore/QEntity>             // Esto es el soporte básico para jerarquias de escenas y objetos
#include <Qt3DCore/QAspectEngine>       // Permite trabajar la proporción de aspecto de la camara
#include <Qt3DRender/QCamera>           // Permite crear cámaras 3D
#include <Qt3DExtras/qfirstpersoncameracontroller.h>    // Importo la capacidad de crear juegos FPS
#include "entidadplano.h"
#include "entidadcaja.h"
#include "objetofbx.h"
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QDiffuseMapMaterial>
int main(int argc, char *argv[])        // Esta clase principal que tiene que existir si o si y se tiene que llamar main
{
    QGuiApplication miaplicacion(argc, argv);
    Qt3DExtras::Qt3DWindow vista;       // Creo una vista que esta en Qt3DExtras
    Qt3DCore::QEntity *raizEscena = new Qt3DCore::QEntity();

    Qt3DRender::QCamera *camaraBasica = vista.camera();   // Creo una camara
    camaraBasica->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
        camaraBasica->setUpVector(QVector3D(0.0f, 1.0f, 0.0f));  // La camara esta vertical
        camaraBasica->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));    // El target de la vista que es el punto hacia el que apunta la camara
        camaraBasica->setPosition(QVector3D(0.0f, 3.5f, 25.0f));     // La posicion de la camara
        Qt3DExtras::QFirstPersonCameraController *controladorCamara = new Qt3DExtras::QFirstPersonCameraController(raizEscena);
        controladorCamara->setCamera(camaraBasica);
        vista.setRootEntity(raizEscena);

            EntidadPlano *entidadPlano = new EntidadPlano(raizEscena);
            entidadPlano->malla()->setHeight(100.0f);
            entidadPlano->malla()->setWidth(100.0f);
            entidadPlano->malla()->setMeshResolution(QSize(20, 20));
            Qt3DExtras::QPhongMaterial *mimaterial = new Qt3DExtras::QPhongMaterial();
            mimaterial->setDiffuse(QColor::fromRgb(255,0,0,255));
            entidadPlano->addComponent(mimaterial);

            entidadcaja *entidadCaja = new entidadcaja(raizEscena);
            //squareBamboo->setPosition(QVector3D(4.0f, 0.0f, 0.0f));

            entidadCaja->malla()->setXExtent(5.0f);
            entidadCaja->malla()->setYExtent(5.0f);
            entidadCaja->malla()->setZExtent(5.0f);
            Qt3DExtras::QPhongMaterial *mimaterial2 = new Qt3DExtras::QPhongMaterial();
            mimaterial2->setDiffuse(QColor::fromRgb(0,255,0,255));
            entidadCaja->addComponent(mimaterial2);
            // Transformamos la caja
            // Transformacion con setter
            entidadCaja->setPosition(QVector3D(0.0f, 5.0f, 0.0f));
            // Transformacion directa
            entidadCaja->m_transformacion->setTranslation(QVector3D(0.0f, 10.0f, 0.0f));

            // Ahora vamos a importar realmente el FBX instanciando la clase
            ObjetoFBX *primerobjeto = new ObjetoFBX(raizEscena);
            primerobjeto->transform()->setTranslation(QVector3D(8.0f, 0.0f, 0.0f));
            primerobjeto->setObj("donut.obj");


    vista.show();
    return miaplicacion.exec();
}
