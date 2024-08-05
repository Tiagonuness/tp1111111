#ifndef CONEXAOBD_H_INCLUDED
#define CONEXAOBD_H_INCLUDED
#include "../../Entidades.h"
#include <list>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "sqlite3.h"           // Incluir cabe�alho da biblioteca SQLite.

using namespace std;

// Declara��o da classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what() const;
};
//---------------------------------------------------------------------------
// Declara��o da classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};
//---------------------------------------------------------------------------
// Declara��o da classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "trabalho2db.db";                             // Nome do banco de dados.
        }
        void executar();
};
//---------------------------------------------------------------------------
// Declara��o da classe ComandoLerSenha.

class ComandoLerSenha : public ComandoSQL {
public:
        ComandoLerSenha(Cpf);
        string getResultado();
};

// Declara��o da classe ComandoCriarConta.
class ComandoCriarConta : public ComandoSQL {
public:
    ComandoCriarConta(Conta);
};

class ComandoAtualizarConta : public ComandoSQL {
public:
    ComandoAtualizarConta(Conta);
};

class ComandoExcluirConta : public ComandoSQL {
public:
    ComandoExcluirConta(Conta);
};

class ComandoListarConta : public ComandoSQL {
public:
    ComandoListarConta(Conta);
};
//---------------------------------------------------------------------------
// Implementa��es de m�todos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
};

#endif // CONEXAOBD_H_INCLUDED
