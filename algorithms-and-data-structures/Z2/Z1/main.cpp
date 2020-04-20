#include <iostream>
template <typename Tip>
struct Cvor {
    Tip el;
    Cvor* next;
    Cvor* prev;
};
template <typename Tip>
class DvostraniRed{
    Cvor<Tip>* front;
    Cvor<Tip>* top;
    int broj_el;
    public:
    DvostraniRed(){
        broj_el = 0;
        front = nullptr;
        top = nullptr;
    }
    DvostraniRed(const DvostraniRed<Tip> & l)
    {
        this->broj_el = l.broj_el;
        auto p = l.front;
        front = nullptr;
        Cvor<Tip>* q = nullptr;
        for(p; p != nullptr; p = p->next) {
            if(!front) {
                this->front = new Cvor<Tip> {p->el,nullptr,nullptr};
                top = front;
                q = front;
            } 
            else {
                q->next = new Cvor<Tip> {p->el,nullptr,q};
                q = q->next;
            }
        }
        top = q;
    }
    void staviNaVrh(Tip el){
        if(broj_el == 0){
            top = new Cvor<Tip>{el,nullptr,nullptr};
            front = top;
            broj_el++;
            return;
        }
        Cvor<Tip>* q = top;
        q->next = new Cvor<Tip>{el,nullptr,q};
        top = q->next;
        broj_el++;
    }
    
    Tip skiniSaVrha(){
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        if(broj_el == 1){
            Tip ret = top->el;
            delete top;
            front = nullptr;
            top = nullptr;
            broj_el--;
            return ret;
        }
        Tip ret = top->el;
        Cvor<Tip>* q = top;
        top = top->prev;
        top->next = nullptr;
        delete q;
        broj_el--;
        return ret;
    }
    void staviNaCelo(Tip el){
        if(broj_el == 0){
            front = new Cvor<Tip>{el,nullptr,nullptr};
            top = front;
            broj_el++;
            return;
        }
        Cvor<Tip>* q = front;
        front = new Cvor<Tip>{el,q,nullptr};
        q->prev = front;
        broj_el++;
        return;
    }
    Tip skiniSaCela(){
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        if(broj_el == 1){
            Tip ret = front->el;
            delete front;
            front = nullptr;
            top = nullptr;
            broj_el--;
            return ret;
        }
        Tip ret = front->el;
        Cvor<Tip>* q = front;
        front = front->next;
        delete q;
        front->prev = nullptr;
        broj_el--;
        return ret;
    }
    Tip& vrh(){
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        return top->el;
    }
    Tip vrh() const{
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        return top->el;
    }
    Tip& celo(){
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        return front->el;
    }
    Tip celo() const{
        if(broj_el == 0) throw std::domain_error("DvostraniRed je prazan!");
        return front->el;
    }
    int brojElemenata() const{
        return broj_el;
    }
    void brisi()
    {
        if(broj_el == 0) return;
        if(broj_el == 1) {
            delete front;
            front = nullptr;
            top=nullptr;
            broj_el--;
        } else {
            Cvor<Tip>* p = nullptr;
            for(; front != nullptr; front = front->next) {
                delete p;
                p = front;
            }
            delete p;
            broj_el = 0;
            front = nullptr;
            top = nullptr;
        }
    }
    DvostraniRed<Tip>& operator =(const DvostraniRed& red)
    {
        if(this == &red) return *this;
        Cvor<Tip>* p = nullptr;
        if(broj_el != 0) {
            for(; front != nullptr; front = front->next) {
                delete p;
                p = front;
            }
            delete p;
        }
        this->front = nullptr;
        this->broj_el = red.broj_el;
        Cvor<Tip>* q = nullptr;
        for(p = red.front; p != nullptr; p = p->next) {
            if(!this->front) {
                this->front = new Cvor<Tip> {p->el,p->next,nullptr};
                top = front;
                q = front;
            } else {
                q->next = new Cvor<Tip> {p->el,nullptr,q};
                q = q->next;
            }
        }
        q->next = nullptr;
        top = q;
        return *this;
    }
    ~DvostraniRed()
    {
        if(broj_el == 0) return;
        if(broj_el == 1) {
            delete front;
            front = nullptr;
            top=nullptr;
        } else {
            Cvor<Tip>* p = nullptr;
            for(; front != nullptr; front = front->next) {
                if(p != nullptr) delete p;
                p = front;
            }
            delete p;
            broj_el = 0;
            front = nullptr;
            top = nullptr;
        }
    }
};
//rucni testovi provjere by @derekwetrust
void test1(){
    DvostraniRed<int> r;
    for(int i = 1; i <= 10; i++){
        r.staviNaVrh(i);
    }
    for(int i = 1; i <= 10; i++){
        if(r.skiniSaCela() != i){
            std::cout<<"test1 failed!"<<std::endl;
            return;
        }
    }
    for(int i = 1; i <= 10; i++) r.staviNaVrh(i);
    for(int i = 10; i >= 1; i--){
        if(r.skiniSaVrha() != i){
            std::cout<<"test1 failed!"<<std::endl;
            return;
        }
    }
    for(int i = 1; i <= 10; i++) r.staviNaVrh(i);
    DvostraniRed<int> r2(r);
    if(r2.vrh() != r.vrh() || r2.celo() != r.celo()){
        std::cout<<"test1 faied!"<<std::endl;
        return;
    }
    for(int i = 1; i <= 10; i++){
        if(r2.skiniSaVrha() != r.skiniSaVrha()){
            std::cout<<"test1 failed!"<<std::endl;
            return;
        }
    }
    for(int i = 1; i <= 10; i++) r.staviNaCelo(i);
    r2 = r;
    for(int i = 1; i <= 10; i++){ 
        if(r2.skiniSaCela() != r.skiniSaCela()){
            std::cout<<"test1 failed!"<<std::endl;
            return;
        }
    }
    std::cout<<"test1 succeded!"<<std::endl;
}

void test2(){
    DvostraniRed<double> r;
    for(int i = 1; i <= 10; i++) r.staviNaVrh(i);
    if(r.brojElemenata() != 10){
        std::cout<<"test 2 failed"<<std::endl;
        return;
    }
    r.brisi();
    if(r.brojElemenata() != 0){
        std::cout<<"test 2 failed"<<std::endl;
        return;
    }
    for(int i = 1; i <= 10; i++) r.staviNaVrh(i);
     if(r.brojElemenata() != 10){
        std::cout<<"test 2 failed"<<std::endl;
        return;
    }
    r.vrh() = -8;
    r.celo() = 42;
    if(r.skiniSaCela() != 42 || r.skiniSaVrha() != -8){
        std::cout<<"test2 failed"<<std::endl;
        return;
   } 
    std::cout<<"test2 succeded!"<<std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}
