//TP 2017/2018: ZSR 2, Zadatak 1
#include <iostream>
bool DaLiJeProst(int n){
    bool prost = true;
    for(int i = 2; i<n; n++){
        std::cout<<n%i;
        if(n%i==0) {
            prost = false;
            break;
        }
    }
    
    return prost;
}

int main ()
{
    std::cout<<DaLiJeProst(11);;
	return 0;
}
