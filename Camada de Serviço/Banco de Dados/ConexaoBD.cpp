#include "ConexaoBD.h"

// Atributo estático.
list<ElementoResultado> ComandoSQL::listaResultado; //200060422

// Implementações de métodos da classe ErroPersistencia.
EErroPersistencia::EErroPersistencia(string mensagem) : mensagem(mensagem) {} //200060422

string EErroPersistencia::what() const { //200060422
    return mensagem;
}

// Implementações de métodos da classe ElementoResultado.
void ElementoResultado::setNomeColuna(const string& nomeColuna) { //200060422
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna) { //200060422
    this->valorColuna = valorColuna;
}

// Implementações de métodos da classe ComandoSQL.
void ComandoSQL::conectar() { //200060422
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na conexão ao banco de dados: " + string(sqlite3_errmsg(bd)));
    }
}

void ComandoSQL::desconectar() { //200060422
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na desconexão ao banco de dados");
    }
}

void ComandoSQL::executar() { //200060422
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK) {
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execução do comando SQL: " + string(mensagem));
    }
    desconectar();
}


int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna) { //200060422
    NotUsed = 0;
    ElementoResultado elemento;
    for (int i = 0; i < argc; i++) {
        elemento.setNomeColuna(nomeColuna[i] ? nomeColuna[i] : "NULL");
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_back(elemento);
    }
    return 0;
}

// Implementações de métodos da classe ComandoLerSenha.
ComandoLerSenha::ComandoLerSenha(Cpf cpf) { //200060422
    comandoSQL = "SELECT senha FROM conta WHERE cpf = '";
    comandoSQL += cpf.getValor();
    comandoSQL += "'";
}

string ComandoLerSenha::getResultado() { //200060422
        //Remover senha;
        if (listaResultado.empty()) {
            throw EErroPersistencia("Lista de resultados vazia.");
        }
        ElementoResultado resultado = listaResultado.back();
        listaResultado.pop_back();

        return resultado.getValorColuna();
};

ComandoCriarConta::ComandoCriarConta(Conta conta) { //200060422
    comandoSQL = "INSERT INTO conta (cpf, nome, senha) VALUES ('" + conta.getCpf().getValor() + "', '" + conta.getNome().getValor() + "', '" + conta.getSenha().getValor() + "');";
}

// Implementação do método ComandoAtualizarConta.
ComandoAtualizarConta::ComandoAtualizarConta(Conta conta) { //200060422
    comandoSQL = "UPDATE conta SET nome = '" + conta.getNome().getValor() + "', senha = '" + conta.getSenha().getValor() + "' WHERE cpf = '" + conta.getCpf().getValor() + "';";
}

ComandoExcluirConta::ComandoExcluirConta(Conta conta) { //200060422
    comandoSQL = "DELETE FROM conta WHERE cpf = '" + conta.getCpf().getValor() + "';";
}

ComandoListarConta::ComandoListarConta(Conta conta) { //200060422
    comandoSQL = "SELECT * FROM conta WHERE cpf = '" + conta.getCpf().getValor() + "';";
}

string ComandoListarConta::getResultado() { //200060422
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    cout << "--- Detalhes da conta ---" << endl;
    for (const auto& resultado : listaResultado) {
        cout << resultado.getValorColuna() << endl;
    }

    // Armazenar o primeiro elemento da lista para retornar
    ElementoResultado resultado = listaResultado.front();
    listaResultado.pop_front();  // Remover o primeiro elemento da lista

    return resultado.getValorColuna();
}
