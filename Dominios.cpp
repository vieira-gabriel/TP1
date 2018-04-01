#include "Dominios.hpp"

void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se a primeira letra não for maiúscula (segunto tabela ASCII).

	if (nome[0] < 'A' || nome[0 > 'Z']) throw invalid_argument("Argumento invalido. Primeira letra deve ser maiúscula");

	// Lança exceção se o nome possuir menos que 20 caracteres.

	if (strlen > 20 || strlen < 1) throw invalid_argument("Argumento invalido. Nome precisa ter entre 1 e 20 caracteres");
}	