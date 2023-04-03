#include"menu_items.h"
#include<vector>
using namespace std;

vector <int> color_mod(){//Modify the color intensity
    bool wl=true;
    int opt;
    vector <int>multiplicador;

    while (wl){
        cout<<"Que color quieres modificar\n1.-Rojo\n2.-Verde\n3.-Azul"<<endl;
        
        cin>>opt;
        cout<<"-100 eliminar color---100 maximizarlo, rango de -100 a 100"<<endl;
        switch (opt)
        {
        case 1:
            cin>>multiplicador[0];
            break;
        case 2:
            cin>>multiplicador[1];
            break;
        case 3:
            cin>>multiplicador[2];
            break; 
        default:
            break;
        }
        if (!(valid_vals(multiplicador))){//Si no se encuentra en el rango
            cout<<"Introduce un multiplicador valido"<<endl;
            wl=true;
        }else{
            wl=false;
        }
    }   
    return multiplicador;
    //Aqui es donde se modifica la imagen
}

bool valid_vals(vector<int>range){
    for (int i = 0; i < range.size(); i++)
    {
        if(range[i]<-100||range[i]>100){
            return false;
        }
    }return true;
    
}