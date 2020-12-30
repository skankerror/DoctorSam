#include "interfacedmx.h"

InterfaceDMX::InterfaceDMX(QObject *parent) : QObject(parent)
{

}

InterfaceDMX* InterfaceDMX::interface = NULL;

int InterfaceDMX::seConnecter() {
   if(this->connecte == false)
   {
      this->interfaceEnttec = new EnttecDMXUSB();
      connecte = true;
      return 0;
   }
   return -1;
}

int InterfaceDMX::seDeconnecter() {
   if(this->connecte == true)
   {
      delete this->interfaceEnttec;
      connecte = false;
      return 0;
   }
   return -1;
}

string InterfaceDMX::getNom() const {
   return this->interfaceEnttec->GetNomInterface();
}

string InterfaceDMX::getNumeroSerie() const {
   return this->interfaceEnttec->GetSerialNumber();
}

string InterfaceDMX::getPort() const {
   return this->interfaceEnttec->GetPortInterface();
}

int InterfaceDMX::setPort(string port) {
   this->port = port;
   return 0;
}

int InterfaceDMX::envoyer() {
   this->interfaceEnttec->SendDMX();
   return 0;
}

bool InterfaceDMX::estDisponible() {
   bool etat;
   if(this->connecte == true)
      etat = this->interfaceEnttec->IsAvailable();
   else
   {
      this->interfaceEnttec = new EnttecDMXUSB();
      etat = this->interfaceEnttec->IsAvailable();
      delete this->interfaceEnttec;
   }
   return etat;
}

int InterfaceDMX::setCanalDMX(int canal, int valeur) {
   if(this->interfaceEnttec->SetCanalDMX(canal, (int)valeur) == true)
      return 0;
   return -1;
}

int InterfaceDMX::reinitialiser() {
   if(this->interfaceEnttec->ResetCanauxDMX() == false)
      return -1;
   this->interfaceEnttec->SendDMX();
   return 0;
}

InterfaceDMX* InterfaceDMX::getInterface(const EnttecInterfaces & type, string port)
{
   if(interface == NULL)
   {
      interface = new InterfaceDMX(type, port);
   }

   return interface;
}

InterfaceDMX::InterfaceDMX(const EnttecInterfaces & type, string port) {
   interfaceEnttec =  new EnttecDMXUSB(type, port);
   if(this->interfaceEnttec->IsAvailable() == true)
        connecte = true;
   else connecte = false;
}
