#include "grada.h"

Grada::Grada(int uneAdresse, int unNbCanaux, QObject *parent) :
  QObject(parent),
  adresse(uneAdresse),
  nbCanaux(unNbCanaux)
{

}


Grada::Grada(const Grada &source): QObject()
{
  adresse = source.adresse;
  nbCanaux = source.nbCanaux;
  etat = source.etat;
}

void Grada::setAdresse(int uneAdresse)
{
  adresse = uneAdresse;
}

void Grada::setNbCanaux(int unNbCanaux)
{
  nbCanaux = unNbCanaux;
}

void Grada::initialiser()
{

}

void Grada::initialiser(int adresse, int nbCanaux)
{
  Q_UNUSED(adresse)
  Q_UNUSED(nbCanaux)
}

void Grada::commander()
{

}

