#include <iostream>
using namespace std;

struct Pilha {
    int topo;
    int elementos[100];
};

Pilha* criarPilha() {
    Pilha* p = new Pilha;
    p->topo = 0;
    return p;
}

void liberarPilha(Pilha* p) {
    delete p;
}

bool estaVazia(Pilha* p) {
    return p->topo == 0;
}

bool empilhar(Pilha* p, int valor) {
    if (p->topo < 100) {
        p->elementos[p->topo++] = valor;
        return true;
    }
    return false;
}

int desempilhar(Pilha* p) {
    if (!estaVazia(p)) {
        return p->elementos[--p->topo];
    }
    return -1;
}

bool podeEmpilhar(Pilha* p, int valor) {
    if (estaVazia(p)) return true;
    return valor > p->elementos[p->topo - 1];
}

void imprimirTopo(Pilha* p, const string& nome) {
    if (!estaVazia(p)) {
        cout << "-- " << nome << " : " << p->elementos[p->topo - 1] << endl;
        desempilhar(p);
    }
}

int main() {
    Pilha* pilhaImpar = criarPilha();
    Pilha* pilhaPar = criarPilha();

    int numero;

    cout << "Pilha impar vazia: " << (estaVazia(pilhaImpar) ? "SIM" : "NAO") << endl;
    cout << "Pilha par vazia: " << (estaVazia(pilhaPar) ? "SIM" : "NAO") << endl;

    for (int i = 0; i < 3; ) {
        cout << "Digite um numero: ";
        cin >> numero;

        if (numero % 2 != 0) {
            if (podeEmpilhar(pilhaImpar, numero) && podeEmpilhar(pilhaPar, numero)) {
                cout << "E maior" << endl;
                empilhar(pilhaImpar, numero);
                i++;
            } else {
                cout << "E menor" << endl;
            }
        } else {
            if (podeEmpilhar(pilhaImpar, numero) && podeEmpilhar(pilhaPar, numero)) {
                cout << "E maior" << endl;
                empilhar(pilhaPar, numero);
                i++;
            } else {
                cout << "E menor" << endl;
            }
        }
    }

    cout << "------------------------------------" << endl;

    while (!estaVazia(pilhaImpar) || !estaVazia(pilhaPar)) {
        if (!estaVazia(pilhaImpar) && !estaVazia(pilhaPar)) {
            if (pilhaImpar->elementos[pilhaImpar->topo - 1] > pilhaPar->elementos[pilhaPar->topo - 1]) {
                imprimirTopo(pilhaImpar, "Impar");
            } else {
                imprimirTopo(pilhaPar, "Par");
            }
        } else if (!estaVazia(pilhaImpar)) {
            imprimirTopo(pilhaImpar, "Impar");
        } else if (!estaVazia(pilhaPar)) {
            imprimirTopo(pilhaPar, "Par");
        }
    }

    cout << "------------------------------------" << endl;

    cout << "Pilha impar vazia: " << (estaVazia(pilhaImpar) ? "SIM" : "NAO") << endl;
    cout << "Pilha par vazia: " << (estaVazia(pilhaPar) ? "SIM" : "NAO") << endl;

    liberarPilha(pilhaImpar);
    liberarPilha(pilhaPar);

    return 0;
}
