#ifndef OBJETOFBX_H
#define OBJETOFBX_H

#include <Qt3DExtras/QNormalDiffuseSpecularMapMaterial>
#include <Qt3DRender/qtexture.h>
#include "renderableentity.h"

class ObjetoFBX: public RenderableEntity
{
public:
    //ObjetoFBX();
    ObjetoFBX(Qt3DCore::QNode *parent = 0);
    ~ObjetoFBX();

    enum DiffuseColor {
        Red = 0,
        Blue,
        Green,
        RustDiffuse,
        StainlessSteelDiffuse
    };

    enum SpecularColor {
        RustSpecular = 0,
        StainlessSteelSpecular,
        None
    };

    enum Bumps {
        NoBumps = 0,
        SoftBumps,
        MiddleBumps,
        HardBumps
    };
    // Creamos una serie de setters
    void setObj(const QString& nombre);
    void setDiffuse(DiffuseColor diffuse);
    void setSpecular(SpecularColor specular);
    void setBumps(Bumps bumps);
    void setShininess(float shininess);
    // Creamos una serie de funciones getters
    DiffuseColor diffuse() const;
    SpecularColor specular() const;
    Bumps bumps() const;
    float shininess() const;

private:
    Bumps m_bumps;
    DiffuseColor m_diffuseColor;
    SpecularColor m_specularColor;
    Qt3DExtras::QNormalDiffuseSpecularMapMaterial *m_material;
    Qt3DRender::QAbstractTexture *m_diffuseTexture;
    Qt3DRender::QAbstractTexture *m_normalTexture;
    Qt3DRender::QAbstractTexture *m_specularTexture;
    Qt3DRender::QTextureImage *m_diffuseTextureImage;
    Qt3DRender::QTextureImage *m_normalTextureImage;
    Qt3DRender::QTextureImage *m_specularTextureImage;

    void setNormalTextureSource();
    void setDiffuseTextureSource();
    void setSpecularTextureSource();
};

#endif // OBJETOFBX_H
