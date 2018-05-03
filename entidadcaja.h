#ifndef ENTIDADCAJA_H
#define ENTIDADCAJA_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QCuboidMesh>        // Esto si que es una primitiva

class entidadcaja: public Qt3DCore::QEntity
{
//public:
   // entidadcaja();
    public:
        entidadcaja(Qt3DCore::QNode *parent = 0);     // Constructor
        ~entidadcaja();
        Qt3DExtras::QCuboidMesh *malla() const;
        Qt3DCore::QTransform *m_transformacion;         // Propiedad que almacena la transformacion
        void setPosition(const QVector3D &pos);

    private:
        Qt3DExtras::QCuboidMesh *m_malla;                // Propiedad que almacena la malla

    };

#endif // ENTIDADCAJA_H
