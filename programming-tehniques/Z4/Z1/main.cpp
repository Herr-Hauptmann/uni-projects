//TP 2018/2019: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::pair<double,double> Tacka;

bool Jednaki(double x, double y){
    return std::fabs(x-y) < 1e-3;
}

class Trougao{
    std::pair<double,double> Tacke[3];
    static int UbiloSeZaPomocne(const Tacka &t1, const Tacka& t2, const Tacka& t3){
        double rez = ((t1.first*(t2.second-t3.second)) - (t2.first*(t1.second-t3.second)) + (t3.first*(t1.second-t2.second)));
        return rez;
    }
    bool ProvjeraIndeksa(int indeks) const{
        if(indeks != 1 && indeks != 2 && indeks != 3) return true;
        return false;
    }
    double UdaljenostIzmedjuTacaka(const Tacka &t1, const Tacka &t2) const{
        return sqrt((t1.first-t2.first) * (t1.first-t2.first) + (t1.second-t2.second) * (t1.second-t2.second));
    }
    double UgaoTrougla(const Tacka&t1, const Tacka& t2, const Tacka& t3){
        
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t1);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka& t1, const Tacka& t2, const Tacka& t3){
    if(UbiloSeZaPomocne(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    Tacke[0] = t1; Tacke[1] = t2; Tacke[2] = t3;
}

void Trougao::Postavi(const Tacka& t1, const Tacka& t2, const Tacka& t3){
    if(UbiloSeZaPomocne(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    Tacke[0] = t1; Tacke[1] = t2; Tacke[2] = t3;
}

int Trougao::Orijentacija(const Tacka& t1, const Tacka& t2, const Tacka& t3){
    if(UbiloSeZaPomocne(t1,t2,t3) < 0) return -1;
    else if(UbiloSeZaPomocne(t1,t2,t3) > 0) return 1;
    else return 0;
}

void Trougao::Postavi(int indeks, const Tacka& t1){
    if(ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks");
    Tacke[indeks-1] = t1;
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks");
    return Tacke[indeks-1];
}

double Trougao::DajStranicu(int indeks) const{
    if(ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return UdaljenostIzmedjuTacaka(Tacke[1],Tacke[2]);
    if(indeks==2) return UdaljenostIzmedjuTacaka(Tacke[0],Tacke[2]);
    if(indeks==3) return UdaljenostIzmedjuTacaka(Tacke[0],Tacke[1]);
    
}

double Trougao::DajUgao(int indeks) const{
    if(ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks");
    double a,b,c;
    a = DajStranicu(1); b = DajStranicu(2); c = DajStranicu(3);
    if(indeks==1) 
    return acos((b*b + c*c - a*a )/ (2 * b * c));
    if(indeks==2)
    return acos((a*a + c*c - b*b) / (2 * a * c));
    if(indeks==3)
    return acos((a*a + b*b - c*c) / (2* a * b));
    
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
    centar.first = (Tacke[0].first + Tacke[1].first + Tacke[2].first) / 3;
    centar.second = (Tacke[0].second + Tacke[1].second + Tacke[2].second) / 3;
    return centar;
}

double Trougao::DajObim() const{
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    return (abs(UbiloSeZaPomocne(Tacke[0],Tacke[1],Tacke[2]))/2.);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(Tacke[0],Tacke[1],Tacke[2]) == 1) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka& t) const{
    int o1,o2,o3;
    o1 = Orijentacija(t,Tacke[0],Tacke[1]);
    o2 = Orijentacija(t,Tacke[1],Tacke[2]);
    o3 = Orijentacija(t,Tacke[2],Tacke[0]);
    bool neg,poz;
    
    neg = ((o1 < 0) || (o2 < 0) || (o3 > 0));
    poz = ((o1 > 0) || (o2 > 0) || (o3 > 0));
    
    return !(neg && poz);
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<Tacke[0].first<<","<<Tacke[0].second<<"),("<<Tacke[1].first<<","<<Tacke[1].second<<"),("<<Tacke[2].first<<","<<Tacke[2].second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    for(int i = 0; i<3; i++){
        Tacke[i].first+=delta_x;
        Tacke[i].second+=delta_y;
    }
}

void Trougao::Centriraj(const Tacka& t1){
    Tacka Centar_stari = DajCentar();
    Tacka Centar_novi = t1;
    double k1 = Centar_novi.first - Centar_stari.first;
    double k2 = Centar_novi.second - Centar_stari.second;
    this->Transliraj(k1,k2);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    for(int i = 0; i < 3; i++){
    auto t1 = Tacke[i].first; auto t2 = Tacke[i].second;
    Tacke[i].first = t.first + (t1 - t.first)*std::cos(ugao) - (t2 - t.second)*std::sin(ugao);
    Tacke[i].second = t.second + (t1 - t.first)*std::sin(ugao) + (t2 - t.second)*std::cos(ugao);

    }
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i = 0; i < 3; i++){
        Tacke[i].first = t.first + faktor*(Tacke[i].first - t.first);
        Tacke[i].second = t.second + faktor*(Tacke[i].second - t.second);
    }
    
}

void Trougao::Rotiraj(double ugao){
    this->Rotiraj(this->DajCentar(),ugao);
}

void Trougao::Skaliraj(double faktor){
    this->Skaliraj(this->DajCentar(),faktor);
}

bool DaLiSuIdenticni(const Trougao& t1, const Trougao& t2){
    for(int i = 0; i < 3; i++){
        bool pronadjen = false;
        for(int j = 0; j < 3; j++) if(t1.Tacke[i] == t2.Tacke[j]) pronadjen = true;
        if(!pronadjen) return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao& t2){
    std::vector<std::pair<Tacka,double>> v1, v2;
    for(int i = 1; i <= 3; i++){
        v1.push_back({t1.DajTjeme(i),t1.DajStranicu(i)});
        v2.push_back({t2.DajTjeme(i),t2.DajStranicu(i)});
    }
    std::sort(v1.begin(),v1.end(),[](std::pair<Tacka,double> p1, std::pair<Tacka,double> p2){
        return p1.second > p2.second;
    });
    std::sort(v2.begin(),v2.end(),[](std::pair<Tacka,double> p1, std::pair<Tacka,double> p2){
        return p1.second > p2.second;
    });
    
    std::vector<double> v3, v4;
    for(int i = 1; i <= 3; i++){
        v3.push_back(t1.DajStranicu(i));
        v4.push_back(t2.DajStranicu(i));
    }
    std::sort(v3.begin(),v3.end());
    std::sort(v4.begin(),v4.end());
    bool sss = false;
    if(std::equal(v3.begin(),v3.end(),v4.begin())) sss = true;
    bool ori = false;
    if(t1.Orijentacija(v1.at(0).first,v1.at(1).first,v1.at(2).first) == t2.Orijentacija(v2.at(0).first,v2.at(1).first,v2.at(2).first)) ori = true;
    if(ori && sss) return true;
    else return false;
    
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> v1,v2;
    for(int i = 1; i <= 3; i++){
        v1.push_back(t1.DajStranicu(i));
        v2.push_back(t2.DajStranicu(i));
    }
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());
    double k,k1,k2,k3;
    k1 = v1.at(0) / v2.at(0); k2 = v1.at(1) / v2.at(1); k3 = v1.at(2) / v2.at(2);
    if(Jednaki(k1,k2) && Jednaki(k1,k3) && Jednaki(k2,k3)) k = k1;
    else return false;
    if(k>0){
        auto tp = t2;
        tp.Skaliraj(k);
        if(DaLiSuPodudarni(t1,tp)==true) return true;
    }
    else{
        auto tp = t1;
        tp.Skaliraj(1./k);
        if(DaLiSuPodudarni(tp,t2) == true) return true;
    }
    
}









int main ()
{
  std::vector<std::shared_ptr<Trougao> > v;
  std::cout<<"Koliko zelite kreirati trouglova: ";
  int n;
  std::cin>>n;
  v.resize(n);
  for(int i = 0; i < n; i++){
      std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
      double x1, y1, x2, y2, x3, y3;
      std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
      Tacka t1, t2, t3;
      t1 = {x1,y1}; t2 = {x2,y2}; t3 = {x3,y3};
      try{
      Trougao pomocni(t1,t2,t3);
      }
      catch(std::domain_error e){
         std::cout<<e.what()<<", ponovite unos!"<<std::endl;
          i--;
          continue; 
      }
      v.at(i) = std::make_shared<Trougao>(t1,t2,t3);
  }
  
  std::cout<<"Unesite vektor translacije (dx dy): ";
  double dx, dy;
  std::cin>>dx>>dy;
  std::cout<<"Unesite ugao rotacije: ";
  double ugao;
  std::cin>>ugao;
  std::cout<<"Unesite faktor skaliranja: ";
  double k;
  std::cin>>k;
  auto p2 = std::transform(v.begin(),v.end(),v.begin(),[k,ugao,dx,dy,&v](std::shared_ptr<Trougao> it){
      it->Transliraj(dx,dy);
      it->Rotiraj(ugao);
      it->Skaliraj(it->DajTjeme(1),k);
      return it;
  });
  std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)->bool{
      return t1->DajPovrsinu() < t2->DajPovrsinu();
  });
  std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
  std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> it){
      it->Ispisi();
      std::cout<<std::endl;
  });
  auto p3 = std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)->bool{
      return t1->DajObim() < t2->DajObim();
  });
  if(p3!=v.end()){ std::cout<<"Trougao sa najmanjim obimom: ";
  (*p3)->Ispisi();
  std::cout<<std::endl;
  }
  std::vector<std::pair<Trougao,Trougao>> identicni;
  std::vector<std::pair<Trougao,Trougao>> podudarni;
  std::vector<std::pair<Trougao,Trougao>> slicni;
  for(int i = 0; i < v.size(); i++){
      for(int j = i+1; j < v.size(); j++){
          if(DaLiSuIdenticni(*v.at(i),*v.at(j)) == true) identicni.emplace_back(*v.at(i),*v.at(j));
          if(DaLiSuPodudarni(*v.at(i),*v.at(j))) podudarni.emplace_back(*v.at(i),*v.at(j));
          if(DaLiSuSlicni(*v.at(i),*v.at(j)) && !DaLiSuIdenticni(*v.at(i),*v.at(j))){ 
              slicni.emplace_back(*v.at(i),*v.at(j));}
          
      }
  }
  if(identicni.size() == 0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
  else {std::cout<<"Parovi identicnih trouglova: "<<std::endl;
  for(int i = 0; i < identicni.size(); i++){ 
      identicni.at(i).first.Ispisi();
      std::cout<<" i ";
      identicni.at(i).second.Ispisi();
      std::cout<<std::endl;
      
  }
  }
  
  if(podudarni.size() == 0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
  else{ std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
  for(int i = 0; i < podudarni.size(); i++){ 
      podudarni.at(i).first.Ispisi();
      std::cout<<" i ";
      podudarni.at(i).second.Ispisi();
      std::cout<<std::endl;}
  }
  if(slicni.size() == 0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
  else{ std::cout<<"Parovi slicnih trouglova: "<<std::endl;
  for(int i = 0; i < slicni.size(); i++){ 
      slicni.at(i).first.Ispisi();
      std::cout<<" i ";
      slicni.at(i).second.Ispisi();
      std::cout<<std::endl;}
  }
  
	return 0;
}