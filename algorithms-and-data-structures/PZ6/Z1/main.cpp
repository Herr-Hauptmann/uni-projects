#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <fstream>
template<typename Tip>
// bubble sort
void bubble_sort(Tip* niz, int vel)
{
    if(vel == 0 || vel == 1) return;
    for(int i = vel - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            if(niz[j-1] > niz[j]) {
                Tip temp = niz[j-1];
                niz[j-1] = niz[j];
                niz[j] = temp;
            }
        }
    }
}
// selection sort
template<typename Tip>
void selection_sort(Tip* niz, int vel)
{
    if(vel == 0 || vel == 1) return;
    for(int i = 0; i < vel; i++) {
        int min_i = i;
        for(int j = i + 1; j < vel; j++) {
            if(niz[min_i] > niz[j]) min_i = j;
        }
        Tip temp = niz[i];
        niz[i] = niz[min_i];
        niz[min_i] = temp;
    }
}

//merge
template<typename Tip>
void merge(Tip* niz, int l, int p, int q, int u){
    Tip* b = new Tip[u - l + 1];
    int i = 0;
    int j = q - l;
    int k = l;
    for(int m = 0; m <= u - l; m++) b[m] = niz[l + m];
    while(i <= p - l && j <= u - l){
        if(b[i] <= b[j]){
            niz[k] = b[i];
            i++;
        }
        else{
            niz[k] = b[j];
            j++;
        }
        k++;
    }
    while(i <= p - l){
        niz[k] = b[i];
        k++; i++;
    }
    while(j <= u - l){
        niz[k] = b[j];
        k++; j++;
    }
    delete[] b;
}
//merge-sort pomocni
template <typename Tip>
void merge_sort_pravi(Tip* niz, int l, int u){
    if(u > l){
        int p = (l + u - 1) / 2;
        int q = p + 1;
        merge_sort_pravi(niz, l, p);
        merge_sort_pravi(niz, q, u);
        merge(niz,l,p,q,u);
    }
}
//merge sort
template <typename Tip>
void merge_sort(Tip* niz, int vel){
    merge_sort_pravi(niz, 0, vel - 1);
}

// particija
template <typename Tip>
int particija(Tip* niz, int prvi, int zadnji){
    Tip pivot = niz[prvi];
    int p = prvi + 1;
    while(p <= zadnji && niz[p] < pivot) p++;
    for(int i = p + 1; i <= zadnji; i++){
        if(niz[i] < pivot){
            Tip temp = niz[i];
            niz[i] = niz[p];
            niz[p] = temp;
            p++;
        }
    }
    Tip temp = niz[prvi];
    niz[prvi] = niz[p - 1];
    niz[p - 1] = temp;
    return p - 1;
}


//quci sort pomocni
template <typename Tip>
void quick_sort_pravi(Tip* niz, int prvi, int zadnji){
    if(prvi < zadnji){
        int j = particija(niz, prvi, zadnji);
        quick_sort_pravi(niz, prvi, j - 1);
        quick_sort_pravi(niz, j + 1, zadnji);
    }
}

// quick sort
template<typename Tip>
void quick_sort(Tip* niz, int vel)
{
    quick_sort_pravi(niz, 0, vel - 1);

}

// ucitaj
void ucitaj(std::string filename, int* &niz, int &vel){
    std::ifstream ulaz(filename);
    if(!ulaz) throw std::domain_error("Greška");
    int broj;
    vel = 0;
    int i = 0;
    while(ulaz >> broj) vel++;
    ulaz.close();
    ulaz.open(filename);
    niz = new int[vel];
    while(ulaz >> broj) niz[i++] = broj;
}

// generisi
void generisi(std::string filename, int vel){
    std::ofstream izlaz(filename);
    srand(time(NULL));
    for(int i = 0; i < vel; i++) izlaz << rand() << " ";
}

// zapisi
void zapisi(std::string filename, int* niz, int vel){
    std::ofstream izlaz(filename);
    for(int i = 0; i < vel; i++) izlaz << niz[i] << " ";
}

void test1(){
    int* niz;
    int vel;
    generisi("test.txt", 100);
    ucitaj("test.txt", niz, vel);
    std::cout << "Izaberi: " << std::endl << "1 - Bubble sort\n" << "2 - Selection sort\n" << "3 - Merge sort\n" << "4 - Quick sort\n";
    int meni;
    std::cin >> meni;
        bool flag = true;
        clock_t vrijeme = clock();
        switch(meni){
        case 1:
        bubble_sort(niz, vel);
        break;
        case 2:
        selection_sort(niz, vel);
        break;
        case 3:
        merge_sort(niz, vel);
        break;
        case 4:
        quick_sort(niz, vel);
        break;
        default:
        std::cout << "Pogrešan unos!";
        }
        clock_t  vrijeme2 = clock();
        int ukvrijeme = (vrijeme2 - vrijeme) / (CLOCKS_PER_SEC / 1000);
        for(int i = 0; i < vel - 1; i++){
            if(niz[i] > niz[i + 1]){
                flag = false;
                break;
            }
        }
        if(!flag) std::cout << "Pogrešno!";
        else std::cout << "Vrijeme izvršavanja: " << ukvrijeme << " ms.\n";
        zapisi("sort1.txt", niz, vel);
}


int main()
{
    test1();
    return 0;
}
