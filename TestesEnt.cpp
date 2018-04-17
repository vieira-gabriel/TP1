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

void Teste_Leitor::run(){
	iniciar();

	leitorValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Leitor: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Leitor: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Desenvolvedor.

void Teste_Desenvolvedor::desenvolvedorValido(){
	try{
		desenvolvedor.getNome().setNome("Maria");
		if (desenvolvedor.getNome().getNome() != "Maria"){
			resultado_teste = FALHA;
		}

		desenvolvedor.getSobrenome().setNome("Julia");
		if (desenvolvedor.getSobrenome().getNome() != "Julia"){
			resultado_teste = FALHA;
		}

		desenvolvedor.getEmail().setEmail("MaJu45@email");
		if (desenvolvedor.getEmail().getEmail() != "MaJu45@email"){
			resultado_teste = FALHA;
		}

		desenvolvedor.getData().setData(10, 9, 2018);
		if (desenvolvedor.getData().getDay() != 10 || desenvolvedor.getData().getMonth() != 9 || desenvolvedor.getData().getYear() != 2018){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Desenvolvedor::run(){
	iniciar();

	desenvolvedorValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Desenvolvedor: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Desenvolvedor: Falha.\n");
    }
}

