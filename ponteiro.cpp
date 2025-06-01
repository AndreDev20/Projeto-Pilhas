#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};

struct Pilha {
    Node* topo;
};

// -----------------------------------------

Pilha* criarPilha() {
    Pilha* novaPilha = new Pilha;
    novaPilha->topo = nullptr;
    return novaPilha;
}

void liberarPilha(Pilha* pilha) {
    Node* atual = pilha->topo;
    while (atual != nullptr) {
        Node* aux = atual->proximo;
        delete atual;
        atual = aux;
    }
    delete pilha;
}

bool estaVazia(Pilha* pilha) {
    return pilha->topo == nullptr;
}

void empilhar(Pilha* pilha, int valor) {
    Node* novoNo = new Node;
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        return -1;
    }
    Node* aux = pilha->topo;
    int valor = aux->valor;
    pilha->topo = aux->proximo;
    delete aux;
    return valor;
}

bool jaExiste(Pilha* pilha, int valor) {
    Node* atual = pilha->topo;
    while (atual != nullptr) {
        if (atual->valor >= valor) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void exibirTopo(Pilha* pilha, const string& nome) {
    if (!estaVazia(pilha)) {
        cout << nome << ": " << pilha->topo->valor << endl;
        desempilhar(pilha);
    }
    cout << "------------------------------------" << endl;
}

int main() {
    Pilha* pilhaImpares = criarPilha();
    Pilha* pilhaPares = criarPilha();

    int numero;
    int contador = 0;

    while (contador < 3) {
        cout << "Digite um numero: ";
        cin >> numero;

        if (numero % 2 == 0) {
            if (!jaExiste(pilhaImpares, numero) && !jaExiste(pilhaPares, numero)) {
                cout << "E maior" << endl;
                empilhar(pilhaPares, numero);
                contador++;
            } else {
                cout << "E menor" << endl;
            }
        } else {
            if (!jaExiste(pilhaImpares, numero) && !jaExiste(pilhaPares, numero)) {
                cout << "E maior" << endl;
                empilhar(pilhaImpares, numero);
                contador++;
            } else {
                cout << "E menor" << endl;
            }
        }
    }

    cout << "Pilha impar vazia: " << (estaVazia(pilhaImpares) ? "SIM" : "NAO") << endl;
    cout << "Pilha par vazia: " << (estaVazia(pilhaPares) ? "SIM" : "NAO") << endl;

    cout << "------------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        if (!estaVazia(pilhaImpares) && !estaVazia(pilhaPares)) {
            if (pilhaImpares->topo->valor > pilhaPares->topo->valor) {
                exibirTopo(pilhaImpares, "Impar");
            } else {
                exibirTopo(pilhaPares, "Par");
            }
        } else if (!estaVazia(pilhaImpares)) {
            exibirTopo(pilhaImpares, "Impar");
        } else if (!estaVazia(pilhaPares)) {
            exibirTopo(pilhaPares, "Par");
        }
    }

    liberarPilha(pilhaImpares);
    liberarPilha(pilhaPares);

    return 0;
}
