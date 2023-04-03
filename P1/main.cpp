
#include<stdio.h>
#include<vector>
#include "data_handler.cpp"
#include "menu_items.cpp"
using namespace std;

void options_color();
void options_grey();
bool color_grey(Image matriz);
int main(){
    string name;
    cout<<"Introduce el nombre de la imagen con su extension"<<endl;
    cin>>name;
    Image foto;
    foto.Read_data(name);
    
    if (color_grey(foto)){
        options_color();
    }else{
        options_grey();
    }
   
}

























bool color_grey(Image matriz){
    if (matriz.color_channel()){//Si es verdadero a color, si no, gris
        return true;
    }
    return false;
}




void options_color(){
 int opt;
 cout<<"1.-Modificar intensidad de colores"<<endl;
 cin>>opt;
 switch (opt)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
        
    
}

void options_grey(){

}
















