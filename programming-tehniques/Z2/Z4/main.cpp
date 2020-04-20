/* TP, 2018/2019
*/
#include <iostream>
#include <new>
#include <stdexcept>
long long int** StirlingoviBrojeviV2(int n)
{
    long long int**m = nullptr;
    if(n<=0) throw std::domain_error("Parametar ne smije biti negativan");
    int broj_elemenata = 0;
    for(int i = 1; i<=n+1; i++) broj_elemenata+=i;
    try {
        m = new long long int*[n+1] {};
        try {
            m[0] = new long long int[broj_elemenata];
            for(int i = 1; i<n+1; i++) m[i] = m[i-1] + i;

            m[0][0] = 1;
            for(int i = 1; i<n+1; i++) {
                for(int j = 0; j<i+1; j++) {
                    if(j==0) m[i][j] = 0;
                    else if(j==1 || j==i) m[i][j] = 1;
                    else m[i][j] = m[i-1][j-1] + j*m[i-1][j];
                }
            }
        } catch(...) {
            delete[] m[0];
            delete[] m;
            m = nullptr;
            throw std::range_error("Parametar prevelik za raspolozivu memoriju");

        }

    } catch(...) {
        delete[] m;
        m = nullptr;
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    return m;
}

long long int** StirlingoviBrojeviV1(int n)
{
    long long int** m = nullptr;
    if(n<=0) throw std::domain_error("Parametar ne smije biti negativan");
    try {
        m = new long long int*[n+1] {};
        try {
            for(int i = 0; i<n+1; i++) m[i] = new long long int[i+1] {};
        } catch(...) {
            for(int i = 0; i<n+1; i++) delete[] m[i];
            delete[] m;
            m = nullptr;
            throw std::range_error("Parametar prevelik za raspolozivu memoriju");

        }

        m[0][0] = 1;
        for(int i = 1; i<n+1; i++) {
            for(int j = 0; j<i+1; j++) {
                if(j==0) m[i][j] = 0;
                else if(j==1 || j==i) m[i][j] = 1;
                else m[i][j] = m[i-1][j-1] + j*m[i-1][j];
            }
        }
    } catch(...) {
        delete[] m;
        m = nullptr;
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    return m;
}

int main ()
{
    std::cout<<"Unesite n: ";
    int n;
    std::cin>>n;
    long long int** p = nullptr;
    try {
        p = StirlingoviBrojeviV1(n);
    } catch(std::range_error e) {
        std::cout<<e.what();
    }
    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<i+1; j++) std::cout<<p[i][j]<<" ";
        std::cout<<std::endl;
    }
    for(int i =0; i<n+1; i++) delete[] p[i];
    //delete[] p[0];
    delete[] p;
    return 0;
}
