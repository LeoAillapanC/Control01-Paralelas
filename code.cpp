#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

using namespace std;

struct station {
  std::string code;
  std::string name;
  station *next;
  station *prev;
  bool combinacion;
};

int main(int argc, char const *argv[]) {
  string Argumento = argv[1];
  string Destino = argv[3];
  string Origen = argv[2];
  station aux;
  std::map<std::string, int> mapa;
  std::map<int, std::string> mymap;
  std::map<std::string, std::string> lineas, metro;
  int c = 0 , i = 0;
  bool flag=false, bandera = false;
  std::string sg, name, line, prev, linae;
  ifstream myfile("metro.txt");
  while(!myfile.eof()){
    getline(myfile,sg,' ');
    getline(myfile,name,'\n');
    if(sg.find("Línea") != string::npos ){
      linae = name;
      //std::cout << linae << '\n';
      i = 0;
    }else if (myfile.eof()) {
      break;
    }else{
//      std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      mapa.insert(std::pair<std::string, int>(sg, c));
      mymap.insert(std::pair<int, std::string>(c, name));
      lineas.insert(std::pair<std::string, std::string>(sg, linae));
      if (linae=="1") {
        cout<<RED;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }else if (linae=="2") {
        cout<<RESET;
        cout<<YEL;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }else if (linae=="4") {
        cout<<RESET;
        cout<<BLU;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }else if (linae=="4a") {
        cout<<RESET;
        cout<<CYN;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }else if (linae=="5") {
        cout<<RESET;
        cout<<GRN;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }else{
        cout<<RESET;
        cout<<MAG;
        std::cout<<c<<" "<<i<<" "<<sg<<" "<<name <<" "<<linae<<'\n';
      }
      c++;
      i++;
      }
  }
  /*std::cout <<mymap.find(mapa.find(Origen)->second)->second<< '\n';
  std::cout <<mymap.find(mapa.find(Destino)->second)->second<< '\n';
  std::cout <<lineas.find(Origen)->second<< '\n';
  std::cout <<lineas.find(Destino)->second<< '\n';
  for (auto& x: mymap){
    std::cout << x.first<< "->" <<x.second<<' ';
  }
*/
  return 0;
}
