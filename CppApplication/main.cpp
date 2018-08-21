/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leo, Diego, Jesús
 *
 * Created on August 20, 2018, 5:07 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

/*
 * 
 */
string cambio(string sigla){

    if(sigla== "SP")  {sigla="SO";}
    else if(sigla== "SO") {sigla="SP";}
    else if(sigla== "LH") {sigla="HE";}
    else if(sigla== "HE") {sigla="LH";}
    else if(sigla== "BA")  {sigla="BQ";}
    else if(sigla== "BQ") {sigla="BA";}
    else if(sigla== "LE") {sigla="LEN";}
    else if(sigla== "LEN") {sigla="LE";}
    else if(sigla== "TB") {sigla="TOB";}
    else if(sigla== "TOB") {sigla="TB";}
    else if(sigla== "LC") {sigla="LCI";}
    else if(sigla== "LCI") {sigla="LC";}
    else if(sigla== "AN") {sigla="NA";}
    else if(sigla== "NA") {sigla="AN";}
    else if(sigla== "FR") {sigla="FRA";}
    else if(sigla== "VMA") {sigla="VIM";}
    else if(sigla== "VIM") {sigla="VMA";}
    else if(sigla== "VVA") {sigla="VV";}
    else if(sigla== "VV") {sigla="VVA";}
    else if(sigla== "NU") {sigla="NUO";}
    else if(sigla== "NUO") {sigla="NU";}
  return sigla;
}

string removeSpaces(string input)
{  
  for (int i = input.length()-1; i >= 0; --i) {
   if(input[i] == ' ')
      input.erase(i, 1);
}
  return input;
}

void doit(std::string O, std::string D, std::string F){
    int i=0;
    std::string reverse[30];
    ifstream myfile;
 myfile.open("metro.txt");
 myfile.clear();
 myfile.seekg(0, ios::beg);
 string line,linea, lineao, linead, ori, des;
 while(!myfile.eof())
{   
    getline(myfile,line,' ');
 if(line.find("Línea") != string::npos ) //HERE!
{ 
 getline(myfile,line,'\n');
 linea=line;
//cout << line << endl;
 getline(myfile,line,' ');
 } 
    if(line==O){
          getline(myfile,line,'\n');          
          if(F=="R"){
              reverse[i]=line;
              i++;
          }else{cout <<line << " ";}
          //cout <<linea << endl;
          lineao=linea;
          ori=line;
          getline(myfile,line,' ');
          getline(myfile,line,' ');
          do{ 
      // cout <<"Sigla: "<<line << endl;
       getline(myfile,line,'\n');
        if(F=="R"){
              reverse[i]=line;
              i++;
          }else{cout <<line << " ";}
        getline(myfile,line,' ');
          }while(line!=D);
    getline(myfile,line,'\n');
        if(F=="R"){
              reverse[i]=line;
              i++;
          }else{cout <<line << " ";}
    }/*
    if(line==D){
    getline(myfile,line,'\n');
          //cout <<line << endl;
          //cout <<linea << endl;
          linead=linea;
          des=line;
          getline(myfile,line,' ');
    }*/
    getline(myfile,line,'\n');
}
 do{
cout <<reverse[i]<<" ";i--;
 }while(i!=-1);
 cout <<endl;
 i=0;
 myfile.clear();
 myfile.seekg(0, myfile.beg);
 myfile.close();
}

void searchit(std::string O, std::string D, std::string LO, std::string LD , std::string F){
    ifstream myfile,combi,sesamo;
    string line,linea,est,sigla,change;
    string openthis = "linea"+removeSpaces(LO)+".txt";
    string abrete = "linea"+removeSpaces(LD)+".txt";
    //std::cout << openthis;
 myfile.open(openthis);
 sesamo.open(abrete);
 combi.open("combinaciones.txt");
 while (!combi.eof()){
     getline(combi,sigla,' ');//SP   
     getline(combi,est,' ');//San Pablo
     getline(combi,linea,' ');//1 
     if(linea==removeSpaces(LO)){
     getline(combi,line,'\n');//5
        if(line==removeSpaces(LD)){
            cout<<sigla<<" "<<est<<" "<<line<<" "<<linea;
            doit(O,sigla,F);
            change=cambio(sigla);
            doit(change,D,"R");
     }
     }else{getline(combi,line,'\n');}
     
 }
 while (!myfile.eof()){
     getline(myfile,line,' ');
 }
 while (!sesamo.eof()){
     getline(sesamo,line,' ');
 }

 myfile.close();
 sesamo.close();
 combi.close();
}

void r(std::string O, std::string D){
 //cout<<O<<endl<<D<<endl;
    ifstream myfile;
 myfile.open("metro.txt");
string line,linea, lineao, linead, ori, des, flag;
bool found = false;
while(!myfile.eof())
{getline(myfile,line,' ');
 if(line.find("Línea") != string::npos ) //HERE!
{ 
 getline(myfile,line,'\n');
 linea=line;
//cout << line << endl;
 getline(myfile,line,' ');
 } 
        if(line==D){
            flag="N";
    getline(myfile,line,'\n');
          //cout <<line << endl;
          //cout <<linea << endl;
          linead=linea;
          des=line;
          getline(myfile,line,' ');          
    }
    if(line==O){
        flag="R";
          getline(myfile,line,'\n');
          //cout <<line << endl;
          //cout <<linea << endl;
          lineao=linea;
          ori=line;
          getline(myfile,line,' ');
         /* getline(myfile,line,' ');
          do{ 
      // cout <<"Sigla: "<<line << endl;
       getline(myfile,line,'\n');
        cout <<line << endl;
        getline(myfile,line,' ');
          }while(line!=D);
    getline(myfile,line,'\n');
        cout <<line << endl;*/
    }
    getline(myfile,line,'\n');
}
//cout <<ori << endl;
//cout <<lineao << endl;
//cout <<des << endl;
//cout <<linead << endl;
myfile.close();
if(lineao==linead){
    if(flag=="N"){
    doit(O,D,flag);}else{doit(D,O,flag);}
}else{
searchit(O,D,lineao,linead,flag);
}

}
int main(int argc, char** argv) {
    
    string Argumento = argv[1];
    if(Argumento=="-v"){
    cout<<"Leonardo Aillapan Cuellar"<<endl;
    cout<<"Diego Pino Contreras"<<endl;
    cout<<"Jesús Zagal Velozo"<<endl;    
    }else if(Argumento=="-f"){
    string Origen = argv[2];
    string Destino = argv[3];
     //cout<<"Ruta"<<endl<<Origen<<endl<<Destino<<endl;
     r(Origen,Destino);
    }else if(Argumento=="-l"){
        std::ifstream is("metro.txt");
        char c;while (is.get(c)){std::cout << c;}
  is.close(); 
    }else{      
     cout<<"Error 404 Not Found"<<endl;
    }
    return 0;
}