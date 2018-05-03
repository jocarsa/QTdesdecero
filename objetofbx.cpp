#include "objetofbx.h"

// Array de nombres de color de color difuso
const char *diffuseColorsName[] = {
    "red",
    "blue",
    "green",
    "rust",
    "stainless_steel"
};
// Array de dos parametros de caracteres con el oxido y el acero inoxidable
const char *specularColorsName[] = {
    "_rust",
    "_stainless_steel",
    ""
};
// array de parametros de caracteres relacionados con el relieve
const char *bumpsName[] = {
    "no_bumps",
    "soft_bumps",
    "middle_bumps",
    "hard_bumps"
};

ObjetoFBX::ObjetoFBX(Qt3DCore::QNode *parent)
    : RenderableEntity(parent)
    , m_bumps(NoBumps)
    , m_diffuseColor(Red)
    , m_specularColor(None)
    , m_material(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial())
    , m_diffuseTexture(m_material->diffuse())
    , m_normalTexture(m_material->normal())
    , m_specularTexture(m_material->specular())
    , m_diffuseTextureImage(new Qt3DRender::QTextureImage())
    , m_normalTextureImage(new Qt3DRender::QTextureImage())
    , m_specularTextureImage(new Qt3DRender::QTextureImage())
{
    // Le pongo el URL de la malla que voy a usar
    mesh()->setSource(QUrl(QStringLiteral("qrc:/C:/Users/A1P9/Desktop/importar/tetera.obj")));
    // Le pongo por defecto una escala de 0.03
    transform()->setScale(0.03f);
    // Le añado una textura
    m_diffuseTexture->addTextureImage(m_diffuseTextureImage);
    // Textura normal
    m_normalTexture->addTextureImage(m_normalTextureImage);
    // Textura especular
    m_specularTexture->addTextureImage(m_specularTextureImage);

    setNormalTextureSource();
    setDiffuseTextureSource();
    setSpecularTextureSource();
    m_material->setShininess(10.0f);
    addComponent(m_material);
}

ObjetoFBX::~ObjetoFBX()
{
}

void ObjetoFBX::setObj(const QString& nombre)
{
    mesh()->setSource(QUrl(QStringLiteral("qrc:/C:/Users/A1P9/Desktop/importar/")+nombre));
}

void ObjetoFBX::setDiffuse(ObjetoFBX::DiffuseColor diffuse)
{
    if (diffuse != m_diffuseColor) {
        m_diffuseColor = diffuse;
        setDiffuseTextureSource();
    }
}

void ObjetoFBX::setSpecular(ObjetoFBX::SpecularColor specular)
{
    if (specular != m_specularColor) {
        m_specularColor = specular;
        setSpecularTextureSource();
    }
}

void ObjetoFBX::setBumps(ObjetoFBX::Bumps bumps)
{
    if (bumps != m_bumps) {
        m_bumps = bumps;
        setNormalTextureSource();
    }
}

void ObjetoFBX::setShininess(float shininess)
{
    if (shininess != m_material->shininess())
        m_material->setShininess(shininess);
}

ObjetoFBX::DiffuseColor ObjetoFBX::diffuse() const
{
    return m_diffuseColor;
}

ObjetoFBX::SpecularColor ObjetoFBX::specular() const
{
    return m_specularColor;
}

ObjetoFBX::Bumps ObjetoFBX::bumps() const
{
    return m_bumps;
}

float ObjetoFBX::shininess() const
{
    return m_material->shininess();
}

void ObjetoFBX::setNormalTextureSource()
{
    m_normalTextureImage->setSource(QUrl(QStringLiteral("qrc:/C:/Users/A1P9/Desktop/importar/normapguapo.png")));
}

void ObjetoFBX::setDiffuseTextureSource()
{
    m_diffuseTextureImage->setSource(QUrl(QStringLiteral("qrc:/C:/Users/A1P9/Desktop/importar/texdifusa.png")));
}

void ObjetoFBX::setSpecularTextureSource()
{
    m_specularTextureImage->setSource(QUrl(QStringLiteral("qrc:/C:/Users/A1P9/Desktop/importar/texespecular.png")));
}
