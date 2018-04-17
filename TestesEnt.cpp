#include "TestesEnt.hpp"

void TestesEnt::iniciar(){
	resultado_teste = SUCESSO;
}

//--------------------------------------------------------------------------- 
//Teste Entidade Leitor.

void Teste_Leitor::leitorValido(){
	try{
		leitor.getNome().setNome("Joao");
		if (leitor.getNome().getNome() != "Joao"){
			resultado_teste = FALHA;
		}

		leitor.getSobrenome().setNome("Marques");
		if (leitor.getSobrenome().getNome() != "Marques"){
			resultado_teste = FALHA;
		}

		leitor.getEmail().setEmail("JoaoMarques@email");
		if (leitor.getEmail().getEmail() != "JoaoMarques@email"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}