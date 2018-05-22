// Trabalho 2 de TP
// Autores: Bruno Takashi (12/0167263) e Gabriel Arimatéa (15/0126956)

#include "Dominios.hpp"
#include "Entidades.hpp"
#include "Testes_dominios.hpp"
#include "Testes_entidades.hpp"
#include "Stubs.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cstdio>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main(){

	StubAutenticacao *Autentica;
	// Declara e instancia as controladoras.

    //ISAutenticacao 		*cntrISAutenticacao;
    //ISLeitor  			*cntrISLeitor;
    //ISDesenvolvedor 	*cntrISDesenvolvedor;
    //ISAdm       		*cntrISAdm;


    //cntrISAutenticacao = new CntrISAutenticacao();
    //cntrISLeitor = new CntrISLeitor();
    //cntrISDesenvolvedor = new CntrISDesenvolvedor();
    //cntrISAdm = new CntrISAdm();

    // Declara e instancia os stubs.

    //ILNAutenticacao		*stubLNAutenticacao;
    //ILNLeitor   		*stubLNLeitor;
    //ILNDesenvolvedor    *stubLNDesenvolvedor;
    //ILNAdm    		  	*stubLNAdm;

    //stubLNAutenticacao = new StubLNAutenticacao();
    //stubLNLeitor = new StubLNLeitor();
    //stubLNDesenvolvedor = new StubLNDesenvolvedor();
    //stubLNAdm = new StubLNAdm();

    // Estabelece relacionamentos entre controladoras e stubs.

    //cntrISAutenticacao->setCntrLNAutenticacao(stubLNAutenticacao);
    //cntrISLeitor->setCntrLNUsuario(stubLNLeitor);
    //cntrISDesenvolvedor->setCntrLNDesenvolvedor(stubLNDesenvolvedor);
    //cntrISAdm->setCntrLNAdm(stubLNAdm);

	string email, senha;
	int usuario = 0;

	while(usuario == 0){
	
		cout << "\tVocábulos Controlados" << endl << endl;
	
		cout << "\tEntre com o email e a senha cadastrado ou  que deseja cadastrar" << endl;
	
		cout << "Email = ";
		cin >> email;
		cout << endl;
	    cout << "Senha = ";
	    cin >> senha;
	    cout << endl ;
	
	    usuario = Autentica->autenticar("teste@teste", "Senha123");
	    
	    switch(usuario){
	    	case -1:
	    		char resposta;
	    		while(resposta != 'y' || resposta != 'n'){
					cout << "\tDeseja se cadastrar?" << endl;
					cout << "(y/n) " << resposta << endl;
					if(resposta == 'y' ||resposta == 'Y' || resposta == 's' || resposta == 'S'){
						resposta = 'y';
						//colocar parte de registro aqui
					}
					else if (resposta == 'n' ||resposta == 'N'){
						usuario = 0;
					}
	
				}
			break;
			case -2:
				cout << "\tSenha incorreta" << endl;
				usuario = 0;
			break;
	    	case 1:
	    		cout << "\tBem vindo, leitor" << endl;
	    	break;
	    	case 2:
	    		cout << "\tBem vindo, desenvolvedor" << endl;
	    	break;
	    	case 3:
	    		cout << "\tBem vindo, administrador" << endl;
	    	break;
	    	}
	    }

	return 0;
}