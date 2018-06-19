
#include "Comandos.hpp"

//--------------------------------------------------------------------------- 
// Classe CmdSULeitor.

CmdSULeitor::CmdSULeitor(Nome a, Nome b, Email e, Senha d){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
}

void CmdSULeitor::execute() throw (invalid_argument){
	Leitor leitor;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	
	leitor.setNome(nome);
	leitor.setSobrenome(sobrenome);
	leitor.setEmail(email);
	leitor.setSenha(senha);

	userLer.insert(userLer.end(), leitor);
}

//--------------------------------------------------------------------------- 
// Classe CmdSUDev.

CmdSUDev::CmdSUDev(Nome a, Nome b, Email e, Senha d, Data f){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
	nascimento = f;
}

void CmdSUDev::execute() throw (invalid_argument){
	Desenvolvedor dev;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}

	dev.setNome(nome);
	dev.setSobrenome(sobrenome);
	dev.setEmail(email);
	dev.setSenha(senha);
	dev.setData(nascimento);

	userDev.insert(userDev.end(), dev);
}

//--------------------------------------------------------------------------- 
// Classe CmdSUAdmin.

CmdSUAdmin::CmdSUAdmin(Nome a, Nome b, Email e, Senha d, Data f, Telefone g, Endereco h){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
	nascimento = f;
	telefone = g;
	endereco = h;
}

void CmdSUAdmin::execute() throw (invalid_argument){
	Administrador admin;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}

	admin.setNome(nome);
	admin.setSobrenome(sobrenome);
	admin.setEmail(email);
	admin.setSenha(senha);
	admin.setData(nascimento);
	admin.setTelefone(telefone);
	admin.setEndereco(endereco);

	userAdm.insert(userAdm.end(), admin);
}

//--------------------------------------------------------------------------- 
// Classe CmdLogin.

CmdLogin::CmdLogin(Email a, Senha b){
	email = a;
	senha = b;
}

void CmdLogin::execute() throw (invalid_argument){
	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			if (itLer->getSenha().getSenha() == senha.getSenha()){
				result = LG_LEITOR;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			if (itDev->getSenha().getSenha() == senha.getSenha()){
				result = LG_DEV;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			if (itAdm->getSenha().getSenha() == senha.getSenha()){
				result = LG_ADMIN;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	result = LG_ERROR;
	throw invalid_argument("***Usuario inexistente.");
}



//##############################################################################################
//############################### Acoes de usuario #############################################
//##############################################################################################

//--------------------------------------------------------------------------- 
// Classe CmdNewVocab.

CmdNewVocab::CmdNewVocab(Vocabulario_controlado a, Definicao b, Email c){
	vocab = a;
	defin = b;
	user = c;
}

void CmdNewVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome().getNome()) {
			throw invalid_argument("***Vocabulario ja existente!");
		}
	}

	Vocabulario input;
	input.vocabulario = vocab;
	input.definicao = defin;
	input.administrador = user;

	listVocab.insert(listVocab.end(), input);
}

//--------------------------------------------------------------------------- 
// Classe CmdEditVocab.

CmdEditVocab::CmdEditVocab(Vocabulario_controlado a, Definicao b, Email c){
	vocab = a;
	defin = b;
	user = c;
}

void CmdEditVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome().getNome()) {
			if (itVocab->administrador.getEmail() == user.getEmail()){
				itVocab->vocabulario = vocab;
				itVocab->definicao = defin;
				return;
			}
			else {
				throw invalid_argument("***Usuario nao eh administrador desse vocabulario!");
			}
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdDeleteVocab.

CmdDeleteVocab::CmdDeleteVocab(Nome a, Email b){
	vocab = a;
	user = b;
}

void CmdDeleteVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) { 
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()) {
			if (itVocab->administrador.getEmail() == user.getEmail()){
				listVocab.erase(itVocab);
				return;
			}
			else {
				throw invalid_argument("***Usuario nao eh administrador desse vocabulario!");
			}
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe CmdNewTermo.

CmdNewTermo::CmdNewTermo(Termo a, Nome b, Email c){
	termo = a;
	user = c;
	vocab = b;
}

void CmdNewTermo::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome().getNome()){
					throw invalid_argument("***Termo ja existe!");
				}
			}

			Stermo stermo;
			stermo.termo = termo;

			if (user.getEmail() == itVocab->administrador.getEmail()){
				itVocab->termo.insert(itVocab->termo.end(), stermo);
				return;
			}
			for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
				if (itMail->getEmail() == user.getEmail()){
					itVocab->termo.insert(itVocab->termo.end(), stermo);
					return;
				}
			}

			throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdEditTermo.

CmdEditTermo::CmdEditTermo(Termo a, Nome b, Email c){
	termo = a;
	user = c;
	vocab = b;
}

void CmdEditTermo::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome().getNome()){
					Stermo stermo;
					stermo.termo = termo;

					if (user.getEmail() == itVocab->administrador.getEmail()){
						itVocab->termo.insert(itVocab->termo.end(), stermo);
						return;
					}
					for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
						if (itMail->getEmail() == user.getEmail()){
							itVocab->termo.insert(itVocab->termo.end(), stermo);
							return;
						}
					}

					throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");
				}
			}
			throw invalid_argument("***Termo inexistente!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdDeleteTermo.

CmdDeleteTermo::CmdDeleteTermo(Nome a, Nome c, Email b){
	termo = a;
	user = b;
	vocab = c;
}

void CmdDeleteTermo::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome()){
					
					if (user.getEmail() == itVocab->administrador.getEmail()){
						itVocab->termo.erase(itTermo);
						return;
					}
					for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
						if (itMail->getEmail() == user.getEmail()){
							itVocab->termo.erase(itTermo);
							return;
						}
					}

					throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");
				}
			}
			throw invalid_argument("***Termo inexistente!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe CmdNewDefin.

CmdNewDefin::CmdNewDefin(Definicao a, Nome b, Nome c, Email d){
	defin = a;
	termo = c;
	user = d;
	vocab = b;
}

void CmdNewDefin::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome()){
					if (itTermo->definicao.size() >= 5){
						throw invalid_argument("***Termo com definicoes lotada(5)!");
					}

					for (itDef = itTermo->definicao.begin(); itDef != itTermo->definicao.end(); itDef++) {
						if (itDef->getTexto().getTexto() == defin.getTexto().getTexto()){
							throw invalid_argument("***Definicao ja existe!");
						}
					}

					if (user.getEmail() == itVocab->administrador.getEmail()){
						itTermo->definicao.insert(itTermo->definicao.end(), defin);
						return;
					}
					for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
						if (itMail->getEmail() == user.getEmail()){
							itTermo->definicao.insert(itTermo->definicao.end(), defin);
							return;
						}
					}

					throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");

					
				}
			}

			throw invalid_argument("***Termo inexistente!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdEditDefin.

CmdEditDefin::CmdEditDefin(Definicao a, Texto e, Nome b, Nome c, Email d){
	defin = a;
	termo = c;
	user = d;
	vocab = b;
	old = e;
}

void CmdEditDefin::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome()){
					for (itDef = itTermo->definicao.begin(); itDef != itTermo->definicao.end(); itDef++) {
						if (itDef->getTexto().getTexto() == defin.getTexto().getTexto()){
							throw invalid_argument("***Nova definicao ja existe!");
						}
					}					

					for (itDef = itTermo->definicao.begin(); itDef != itTermo->definicao.end(); itDef++) {
						if (itDef->getTexto().getTexto() == old.getTexto()){
							
							if (user.getEmail() == itVocab->administrador.getEmail()){
								itDef->setTexto(defin.getTexto());
								itDef->setDataCriacao(defin.getDataCriacao());
								return;
							}
							for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
								if (itMail->getEmail() == user.getEmail()){
									itDef->setTexto(defin.getTexto());
									itDef->setDataCriacao(defin.getDataCriacao());
									return;
								}
							}

							throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");

						}
					}

					throw invalid_argument("***Definicao inexistente!");
				}
			}
			throw invalid_argument("***Termo inexistente!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdDeleteDefin.

CmdDeleteDefin::CmdDeleteDefin(Texto a, Nome b, Nome c, Email d){
	defin = a;
	termo = c;
	user = d;
	vocab = b;
}

void CmdDeleteDefin::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				if (itTermo->termo.getNome().getNome() == termo.getNome()){
					for (itDef = itTermo->definicao.begin(); itDef != itTermo->definicao.end(); itDef++) {
						if (itDef->getTexto().getTexto() == defin.getTexto()){

							if (user.getEmail() == itVocab->administrador.getEmail()){
								itTermo->definicao.erase(itDef);
								return;
							}
							for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
								if (itMail->getEmail() == user.getEmail()){
									itTermo->definicao.erase(itDef);
									return;
								}
							}

							throw invalid_argument("***Usuario nao eh desenvolvedor/admin desse vocabulario!");

						}
					}
					throw invalid_argument("***Definicao inexistente!");
				}
			}
			throw invalid_argument("***Termo inexistente!");
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}



//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe CmdSUVocab.

CmdSUVocab::CmdSUVocab(Nome a, Email b){
	vocab = a;
	user = b;
}

void CmdSUVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			if (itVocab->administrador.getEmail() == user.getEmail()) {
				throw invalid_argument("***Usuario ja eh administrador do vocabulario!");
			}

			if (itVocab->desenvolvedor.size() >= 10) {
				throw invalid_argument("***Vocabulario com capacidade maxima de desenvolvedores(10)!");
			}

			for (itMail = itVocab->desenvolvedor.begin(); itMail != itVocab->desenvolvedor.end(); itMail++) {
				if (itMail->getEmail() == user.getEmail()) {
					throw invalid_argument("***Usuario ja eh desenvolvedor do vocabulario!");
				}
			}

			itVocab->desenvolvedor.insert(itVocab->desenvolvedor.end(), user);
			return;
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

//--------------------------------------------------------------------------- 
// Classe CmdListVocab.

CmdListVocab::CmdListVocab(list<Nome> &l){
	lista = &l;
}

void CmdListVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		lista->insert(lista->end(), itVocab->vocabulario.getNome());
	}
}

//--------------------------------------------------------------------------- 
// Classe CmdShowVocab.

CmdShowVocab::CmdShowVocab(Nome a, list<Nome> &l){
	lista = &l;
	vocab = a;
}

void CmdShowVocab::execute() throw (invalid_argument){
	for (itVocab = listVocab.begin(); itVocab != listVocab.end(); itVocab++) {
		if (itVocab->vocabulario.getNome().getNome() == vocab.getNome()){
			resultadoVoc = itVocab->vocabulario;
			resultadoDef = itVocab->definicao;

			for (itTermo = itVocab->termo.begin(); itTermo != itVocab->termo.end(); itTermo++) {
				lista->insert(lista->end(), itTermo->termo.getNome());
			}
			return;
		}
	}

	throw invalid_argument("***Vocabulario inexistente!");
}

