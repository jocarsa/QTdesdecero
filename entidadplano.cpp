#include "entidadplano.h"
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DCore/QTransform>

// Entidad plano
// Hereda de QEntity, luego automaticamente es una entidad
// Hereda de QplaneMesh, y lo mete en la propiedad m_malla, es decir
// de paso que se hereda, se coge la variable m_malla y se crea una nueva instancia de una malla plano
// Y ya muy de paso, se hace que transformacion sea una nueva instancia de QTransform
EntidadPlano::EntidadPlano(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity(new Qt3DCore::QEntity(parent))

{
    m_malla = new Qt3DExtras::QPlaneMesh();
    m_transformacion = new Qt3DCore::QTransform();
    addComponent(m_malla);
    addComponent(m_transformacion);
}

EntidadPlano::~EntidadPlano()
{

}
// Esto es de tipo QPlaneMesh, puntero a Entidadplano::malla, y es constante
Qt3DExtras::QPlaneMesh *EntidadPlano::malla() const
{
    return m_malla;     // Lo unico que hace es devolver la malla
}
