#ifndef GRADA_H
#define GRADA_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>

#include "interfacedmx.h"

class Grada : public QObject
{
  Q_OBJECT
public:
  explicit Grada(int uneAdresse = 0, int unNbCanaux = 0, QObject *parent = nullptr);
  ~Grada(){};
  Grada(const Grada &source);

  int getAdresse() const{ return adresse; };
  void setAdresse(int uneAdresse);
  int getNbCanaux() const { return nbCanaux; };
  void setNbCanaux(int unNbCanaux);
  void initialiser();
  void initialiser(int adresse, int nbCanaux);
  void commander();

private:
  int adresse;
  int nbCanaux;
  QVector<int> etat;


signals:

};

#endif // GRADA_H
