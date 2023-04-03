#include"data_handler.h"
#include<map>
void Image::Read_data(string name){//Funcion para leer imagenes tipo mapa de bits 
FILE *F;
    F=fopen(name.data(),"r+");
    if(!F){
        cout<<"Cannot read the file"<<endl;
    }
    //name=get_filetype();//Obtenemos el tipo de archivo para poder almacenarlo de manera adecuada
    read_header("BMP",F);//En este caso leemos los bmp
    cv::Mat imagen;
        img=cv::imread(name);
        if (!img.data){
            cout<<"No se pudo leer la imagen";
        }
        //fread(img_data,sizeof(RGB),((int)img_header.img_size)/sizeof(RGB),F);
}



bool Image::color_channel(){//Si es a color, devolvemos verdadero, si no, es falso
    if (img.channels()>1){
        return true;
    }
    return false;
}



Image Image::color_multip(vector<int>multi){
    Image output;
    //Primero el multiplicador para el rojo
    cv::Size sz=img.size();
    int pix=sz.height*sz.width;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <img.rows; j++)
        {
            for (int k = 0; k <img.cols ; k++)
            {
                if (multi[i]<0)
                {
                    /* code */
                }else if (multi[i]>0)
                {
                    /* code */
                }else if(multi[i]==0){

                }
                
                
            }
            
        }
        
    }
    


    return output;
}


void Image::read_header(string name,FILE *data){
    if(name=="BMP"){
        fread(file_h,sizeof(unsigned char),14,data);
        fread(img_h,sizeof(unsigned char),40,data);
        if(file_h&&img_h){
            return;
        }else{
            perror("Cannot store the headers");
        }
    }
}




