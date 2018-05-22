#include "Stubs.hpp"

//-----------------------------------------------------------------------------------------------
//Stub de Autenticação

int StubAutenticacao::autenticar(string email, string senha) throw(runtime_error){

	/*ofstream BD;							// Objeto do arquivo para escrita
	ifstream BDs;							// Objeto do arquivo para leitura

	string emailBD, senhaBD;
	int usuario;

	BDs.open("usuarios.txt");

	BDs >> emailBD;
	cout << emailBD << " ";
	BDs >> senhaBD;
	cout << senhaBD << " ";
	BDs >> usuario;
	cout << usuario << endl;

	while(BDs.good()){
	 	if(strcmp(emailBD, email)){
	 		if(strcmp(senhaBD, senha)){
				BDs.close();
	 			return usuario;
			}
	 		else{
	 			cout << "Senha incorreta" << endl;
				BDs.close();
	 			return -2;
	 		}
	 	}
	 	else{
	 		cout << "Email não cadastrado" << endl;
			BDs.close();
	 		return -1;
	 	}
		BDs >> emailBD;
		BDs >> senhaBD;
		BDs >> usuario;
	}
	BDs.close();*/
	if(email == "teste@teste" && senha == "Senha123") return 3;
	return 0;
};

//-----------------------------------------------------------------------------------------------
//Stub de Administrador



//-----------------------------------------------------------------------------------------------
//Stub de Desenvolvedor



//-----------------------------------------------------------------------------------------------
//Stub de Leitor




//-----------------------------------------------------------------------------------------------
//Stub de Vocabulário