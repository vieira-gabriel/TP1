#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

#include "Entidades.cpp"

//--------------------------------------------------------------------------- 
/**
* Classe InterUI.
* Classe utilizada como interface para a camada de apresentacao.
*/
class InterUI {
private:
	virtual void showOption() = 0;

public:
	virtual void execute() = 0;
};

//--------------------------------------------------------------------------- 
/**
* Classe InterCMD.
* Classe utilizada como interface para a camada de servico em comandos.
*/
class InterCMD {
private:
public:
	virtual void execute() = 0;
};

#endif // INTERFACE_H_INCLUDED