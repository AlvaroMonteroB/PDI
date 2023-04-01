#include<iostream>
#include<stdio.h>
#include<vector>
#include"data_handler.h"
using namespace std;

int main(){
    string name;
    cout<<"Introduce el nombre de la imagen con su extension"<<endl;
    cin>>name;
    Data img=data_read_BMP(name.data());
    int opt;
    cout<<"1.-Modificar color"<<endl;
    cin>>opt;
    switch (opt)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
        
    return 0;
}


















