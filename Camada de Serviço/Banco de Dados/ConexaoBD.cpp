#include "ConexaoBD.h"

// Atributo est�tico.
list<ElementoResultado> ComandoSQL::listaResultado;

// Implementa��es de m�todos da classe ErroPersistencia.
EErroPersistencia::EErroPersistencia(string mensagem) : mensagem(mensagem) {}

string EErroPersistencia::what() const {
    return mensagem;
}

// Implementa��es de m�todos da classe ElementoResultado.
void ElementoResultado::setNomeColuna(const string& nomeColuna) {
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna) {
    this->valorColuna = valorColuna;
}

// Implementa��es de m�todos da classe ComandoSQL.
void ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na conex�o ao banco de dados: " + string(sqlite3_errmsg(bd)));
    }
}

void ComandoSQL::desconectar() {
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na desconex�o ao banco de dados");
    }
}

void ComandoSQL::executar() {
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK) {
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execu��o do comando SQL: " + string(mensagem));
    }
    desconectar();
}


int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna) {
    NotUsed = 0;
    ElementoResultado elemento;
    for (int i = 0; i < argc; i++) {
        elemento.setNomeColuna(nomeColuna[i] ? nomeColuna[i] : "NULL");
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_back(elemento);
    }
    return 0;
}

// Implementa��es de m�todos da classe ComandoLerSenha.
ComandoLerSenha::ComandoLerSenha(Cpf cpf) {
    comandoSQL = "SELECT senha FROM conta WHERE cpf = '";
    comandoSQL += cpf.getValor();
    comandoSQL += "'";
}

string ComandoLerSenha::getResultado() {
        //Remover senha;
        if (listaResultado.empty()) {
            throw EErroPersistencia("Lista de resultados vazia.");
        }
        ElementoResultado resultado = listaResultado.back();
        listaResultado.pop_back();

        return resultado.getValorColuna();
};

ComandoCriarConta::ComandoCriarConta(Conta conta) {
    comandoSQL = "INSERT INTO conta (cpf, nome, senha) VALUES ('" + conta.getCpf().getValor() + "', '" + conta.getNome().getValor() + "', '" + conta.getSenha().getValor() + "');";
}

// Implementa��o do m�todo ComandoAtualizarConta.
ComandoAtualizarConta::ComandoAtualizarConta(Conta conta) {
    comandoSQL = "UPDATE conta SET nome = '" + conta.getNome().getValor() + "', senha = '" + conta.getSenha().getValor() + "' WHERE cpf = '" + conta.getCpf().getValor() + "';";
}

ComandoExcluirConta::ComandoExcluirConta(Conta conta) {
    comandoSQL = "DELETE FROM conta WHERE cpf = '" + conta.getCpf().getValor() + "';";
}

ComandoListarConta::ComandoListarConta(Conta* conta) {
    comandoSQL = "SELECT * FROM conta WHERE cpf = '" + conta->getCpf().getValor() + "';";
}
