#include "entidadcaja.h"
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DCore/QTransform>

entidadcaja::entidadcaja(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity(new Qt3DCore::QEntity(parent))

{
    m_malla = new Qt3DExtras::QCuboidMesh();
    m_transformacion = new Qt3DCore::QTransform();
    addComponent(m_malla);
    addComponent(m_transformacion);
}

entidadcaja::~entidadcaja()
{

}
// Esto es de tipo QPlaneMesh, puntero a Entidadplano::malla, y es constante
Qt3DExtras::QCuboidMesh *entidadcaja::malla() const
{
    return m_malla;     // Lo unico que hace es devolver la malla
    //return m_transformacion;     // Lo unico que hace es devolver la malla
}

void entidadcaja::setPosition(const QVector3D &pos)
{
    //m_transformacion->transform()->setTranslation(pos);
    m_transformacion->setTranslation(pos);
}
