//
// Created by Karolina on 01.04.2018.
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool possible( char* u, char* v, char* w ){


    int su=sizeof(u);
    int sv=sizeof(v);
    int sw=sizeof(w);
    int  n=254;
    int C[n];

    for(int i=0;i<n;i++) C[i]=0;
    for(int i=0;i<su;i++) {
        C[(int)u[i]]++;
        cout<<C[(int)u[i]]<<" "<<u[i]<<endl;
    }
    for(int i=0;i<sv;i++) C[(int)v[i]]++;
    for(int i=0;i<sw;i++){
        cout<<C[(int)w[i]]<<" "<<w[i]<<endl;
        C[(int)w[i]]--;
        cout<<C[(int)w[i]]<<" "<<w[i]<<endl;
        if(C[(int)w[i]]<0) return false;
    }
    return true;
}
int main(){
    //har * ponk="ponk";
    char *ponk = new char[4];
    strcpy(ponk, "ponk");
    //char * kwat="kwat";
    char *kwat = new char[4];
    strcpy(kwat, "kwat");
    char *at = new char[2];
    strcpy(at, "poff");
    if(possible(ponk,kwat,at)) cout<<"YEEEAh"<<endl;
    else
        cout<<"KICHA"<<endl;
}