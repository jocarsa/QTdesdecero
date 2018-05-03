#ifndef ENTIDADPLANO_H
#define ENTIDADPLANO_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPlaneMesh>        // Esto si que es una primitiva

class EntidadPlano : public Qt3DCore::QEntity
{
public:
    EntidadPlano(Qt3DCore::QNode *parent = 0);     // Constructor
    ~EntidadPlano();
    Qt3DExtras::QPlaneMesh *malla() const;

private:
    Qt3DExtras::QPlaneMesh *m_malla;                // Propiedad que almacena la malla
    Qt3DCore::QTransform *m_transformacion;         // Propiedad que almacena la transformacion
};

#endif // ENTIDADPLANO_H
