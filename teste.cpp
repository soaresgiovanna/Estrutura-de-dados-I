//ALGUNS COMANDO COMO O if(IsOrdered), FORAM PESQUISADOS POR CONTA DA DIFICULDADE EM RESOLVER  ALGUNS PROBLEMAS DO CODIGO.
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
bool ordenado_crescente(int v[])
{
    for(int i=0; i<(99999); i++)
    {
        if(v[i] > v[i+1])
            return false;
    }
    return true;
}
bool ordenado_decrescente(int v[])
{
    for(int i=0; i<(99999); i++)
    {
        if(v[i] < v[i+1])
            return false;
    }
    return true;
}
void quicksort(int v[], int left, int right) {
    int pivo = v[(left + right) / 2];
    int i = left, j = right;
    do {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quicksort(v, left, j);
    if (i < right) quicksort(v, i, right);
}

void insertionsort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i], j = i;
        while (j > 0 && v[j - 1] > aux) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

void selectionsort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int i_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i_menor]) i_menor = j;
        }
        int aux = v[i];
        v[i] = v[i_menor];
        v[i_menor] = aux;
    }
}

void bubble_sortmel(int v[], int n) {
    int troca = 1, aux;
    for (int i = 1; i < n && troca; i++) {
        troca = 0;
        for (int j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1]) {
                troca = 1;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void bubble_sort(int v[]) {
    int aux, n = 99999;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
void writeResults(ofstream &arq_said, const string &filename, int v[], int n) // Prepara a saída tanto para o arquivo quanto para o cmd
{
    string result;
    result = filename + "\n";
    if (ordenado_crescente(v))
    {
        result += "Esta ordenado!\n";
    } else {
        result += "Nao esta ordenado!\n";
    }

    int k[100000]; // Array para copiar os dados
    for (int i = 0; i < n; i++) {
        k[i] = v[i]; // Copiando o array original
    }

    // Quicksort
    clock_t inicial = clock();
    quicksort(k, 0, n - 1);
    result += "quicksort: " + to_string((float)(clock() - inicial) / CLOCKS_PER_SEC) + " segundos\n";
    result += "Ordenou!\n";

    // Insertion sort
    for (int i = 0; i < n; i++) {
        k[i] = v[i];
    }
    inicial = clock();
    insertionsort(k, n);
    result += "insertionsort: " + to_string((float)(clock() - inicial) / CLOCKS_PER_SEC) + " segundos\n";
    result += "Ordenou!\n";

    // Selection sort
    for (int i = 0; i < n; i++) {
        k[i] = v[i];
    }
    inicial = clock();
    selectionsort(k, n);
    result += "selection_sort: " + to_string((float)(clock() - inicial) / CLOCKS_PER_SEC) + " segundos\n";
    result += "Ordenou!\n";

    // Bubble sort melhorado
    for (int i = 0; i < n; i++) {
        k[i] = v[i];
    }
    inicial = clock();
    bubble_sortmel(k, n);
    result += "bubblesort_melhorado: " + to_string((float)(clock() - inicial) / CLOCKS_PER_SEC) + " segundos\n";
    result += "Ordenou!\n";

    // Bubble sort
    for (int i = 0; i < n; i++) {
        k[i] = v[i];
    }
    inicial = clock();
    bubble_sort(k);
    result += "bubblesort: " + to_string((float)(clock() - inicial) / CLOCKS_PER_SEC) + " segundos\n";
    result += "Ordenou!\n";

    result += "________________________________\n";

    // Escreve no arquivo e no cmd
    arq_said << result;
    cout << result;
}

int main() {
    ifstream arq_ent("aleat_100000.txt"), arq_ent1("cresc_100000.txt"), arq_ent2("decresc_100000.txt");
    ofstream arq_said("resultados.txt");

    if (!arq_ent.is_open() || !arq_said.is_open()) {
        cout << "Erro ao abrir arquivo!" << endl;
        return 1;
    }

    // Arrays para armazenar os dados dos arquivos
    int vetor_aleat[100000], vetor_cresc[100000], vetor_decresc[100000];
    string s;
    int j = 0, n = 100000;

    // Leitura do arquivo aleatorio
    while (getline(arq_ent, s)) {
        vetor_aleat[j++] = stoi(s);  // Uso do stoi para converter string para inteiro
    }

    // Leitura do arquivo crescente
    j = 0;
    while (getline(arq_ent1, s)) {
        vetor_cresc[j++] = stoi(s);
    }

    // Leitura do arquivo decrescente
    j = 0;
    while (getline(arq_ent2, s)) {
        vetor_decresc[j++] = stoi(s);
    }

    // Gerar resultados para o arquivo aleatorio
    writeResults(arq_said, "aleat_100000.txt", vetor_aleat, n);

    // Gerar resultados para o arquivo crescente
    arq_said << "cresc_100000.txt\n";
    cout << "cresc_100000.txt\n";
    writeResults(arq_said, "", vetor_cresc, n);

    // Gerar resultados para o arquivo decrescente
    writeResults(arq_said, "decresc_100000.txt", vetor_decresc, n);

    return 0;
}
