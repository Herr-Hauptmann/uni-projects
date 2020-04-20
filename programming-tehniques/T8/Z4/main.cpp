//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
std::string ZamijeniPremaRjecniku(std::string s, std::map<std::string,std::string> mapa){
  bool razmak = true;
  for(int i = 0; i<s.size(); i++){
   if(razmak==true && s[i]!=' '){
    razmak = false;
    std::string buffer;
    std::string::iterator it = s.begin()+i;
    auto it3 = it;
    while(it3!=s.end()){
     if(*it3!=' ') buffer.push_back(*it3);
     if(*it3==' ') break;
     it3++;
    }
    auto it2 = mapa.find(buffer);
    if(it2!=mapa.end()){
      s.erase(it-s.begin(),buffer.size());     
      s.insert(it-s.begin(),it2->second);
   }
   
  }
  if(s[i]==' ') razmak=true;
  }
return s;
}

int main ()
{
 std::map<std::string, std::string> rjecnik 
    { 
        {"jabuka", "apple"}, 
        {"da", "yes"}, 
        {"kako", "how"}, 
        {"ne", "no"}, 
        {"majmun", "monkey"}, 
        {"mart", "ozujak"},
        {"maj", "svibanj"}, 
        {"jul", "srpanj"}
    };
    
  std::cout << ZamijeniPremaRjecniku("  kako   da   ne   ", rjecnik) << std::endl;
	return 0;
}