#ifndef INTERFACEDMX_H
#define INTERFACEDMX_H

#include <QObject>
#include <string>
using namespace std;
#include "enttecdmxusb.h"


class InterfaceDMX : public QObject
{
  Q_OBJECT
public:
  explicit InterfaceDMX(QObject *parent = nullptr);


  private:
    static InterfaceDMX* interface;
    string nom;
    string numeroSerie;
    string port;
    bool connecte;
    EnttecDMXUSB* interfaceEnttec;

  protected:
    InterfaceDMX(const EnttecInterfaces & type=DMX_USB_PRO, string port="/dev/ttyUSB0");

  public:
    static InterfaceDMX* getInterface(const EnttecInterfaces & type=DMX_USB_PRO, string port="/dev/ttyUSB0");
    int seConnecter();
    int seDeconnecter();
    bool estDisponible();
    int reinitialiser();
    string getNom() const;
    string getNumeroSerie() const;
    string getPort() const;
    int setPort(string port);

    int setCanalDMX(int canal, int valeur);
    int envoyer();


signals:

};


#endif // INTERFACEDMX_H
