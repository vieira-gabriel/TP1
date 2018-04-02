#include "Dominios.hpp"

void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se a primeira letra não for maiúscula (segunto tabela ASCII).

	if (nome[0] < 'A' || nome[0 > 'Z']) throw invalid_argument("Argumento invalido. Primeira letra deve ser maiúscula");

	// Lança exceção se o nome possuir menos que 20 caracteres.
	//nome.length() retorna o tamanho da string nome

	if (nome.length() > 20 || nome.length() < 1) throw invalid_argument("Argumento invalido. Nome precisa ter entre 1 e 20 caracteres");
}

void Nome::setNome(string nome) throw (invalid_argument){
	validar(nome);
	this->nome = nome;
}

void Nome::callNome(){
	//FAZER ESSE CÓDIGO
}

void Telefone::validar(int telefone[]) throw (invalid_argument){
	for (int i = 0; i < 11; ++i){ //11 é o número de caracteres na variável telefone
		if (telefone[i] < 0 || telefone[i] > 9) throw invalid_argument("Argumento invalido");
	}
}

void Telefone::setTelefone(int telefone[]) throw (invalid_argument){
	validar(telefone);
	int valor[13];
	valor[2] = " ";
	valor[8] = "-";

	for (int posicao1 = 0, int posicao2; posicao1 < 11; ++posicao1, ++posicao2){
		if (posicao1 == 2 || posicao1 == 8) ++posicao1;
		valor[posicao1] = telefone[posicao2];
	}
	//Essa função é para guardar o valor no formato AA NNNNN-NNNN

	this->telefone = valor;
}
void Telefone::callTelefone(){
	//FAZER ESSE CÓDIGO
}

void Endereco::validar(string endereco) throw (invalid_argument){
	int tamanho = endereco.length();
	if (tamanho > 20 || tamanho < 1) throw invalid_argument("Argumento invalido. Endereço precisa ter entre 1 e 20 caracteres");

	//Se o primeiro ou o ultimo caractere for " ", retornara um argumento inválido
	if (endereco[0] == ' ' || endereco[tamanho-1]) throw invalid_argument("Argumento invalido. Primeiro ou ultimo caractere não pode ser espaço em branco");
	//(tamanho-1) é a posição no ventor do ultimo caractere
}

void Endereco::setEndereco()