#include<iostream>
#include<vector>
using namespace std;

typedef struct{
   unsigned char file_header[4];
    unsigned char file_size[4];
    unsigned char reserved[4];
    unsigned char file_des[4];
}Header_F;
typedef struct{
    unsigned char size_header[4];
    unsigned char img_width[4];
    unsigned char img_height[4];
    unsigned char img_plane[2];
    unsigned char img_depht[2];
    unsigned char img_compress[4];
    unsigned char img_size[4];
    unsigned char img_hor_res[4];
    unsigned char img_vert_res[4];
    unsigned char img_color[4];
    unsigned char img_color_imp[4];
}Header_img;

typedef struct{
    unsigned char b;
    unsigned char g;
    unsigned char r;

}RGB;

typedef struct{
    Header_F Head_f;
    Header_img Head_img;
    vector<RGB> pixel;
}Data;

bool valid_vals(vector<int>range);
Data color_multip_bmp(vector<int>multi);

Data data_read_BMP(char * name){
FILE *F;
    F=fopen("name","rw");
    if(!F){
        cout<<"Cannot read the file"<<endl;
    }
    fclose(F);
    Header_F header;
    Header_img img_header;
    vector<unsigned char> Matriz;
        //Leyendo la cabecera del archivo
        fread(header.file_header,sizeof(unsigned char),2,F);
        fread(header.file_size,sizeof(unsigned char),4,F);
        fread(header.reserved,sizeof(unsigned char),4,F);
        fread(header.file_des,sizeof(unsigned char),4,F);//offset
        //Leyendo cabecera de imagen
        fread(img_header.size_header, sizeof(unsigned char), 4, F);
        fread(img_header.img_width, sizeof(unsigned char), 4, F);
        fread(img_header.img_height, sizeof(unsigned char), 4, F);
        fread(img_header.img_plane, sizeof(unsigned char), 2, F);
        fread(img_header.img_depht, sizeof(unsigned char), 2, F);
        fread(img_header.img_compress, sizeof(unsigned char), 4, F);
        fread(img_header.img_size, sizeof(unsigned char), 4, F);
        fread(img_header.img_hor_res, sizeof(unsigned char), 4, F);
        fread(img_header.img_vert_res, sizeof(unsigned char), 4, F);
        fread(img_header.img_color, sizeof(unsigned char), 4, F);
        fread(img_header.img_color_imp, sizeof(unsigned char), 4, F);
        vector<RGB>pix;
        RGB aux,*iterator;
        for (int i = 0; i < int(img_header.img_size); i++)
        {
            fread(iterator,sizeof(RGB),1,F);
            aux=*iterator;
            pix.push_back(aux);
        }
        
        //fread(img_data,sizeof(RGB),((int)img_header.img_size)/sizeof(RGB),F);
        int num_pix=((int)img_header.img_size)/sizeof(RGB);
        if(pix.size()==num_pix){
          cout<<"Datos leidos correctamente "<<endl;  
        }else{
            perror("Error de lectura");
        }
        
        Data output;
        output.Head_f=header;
        output.Head_img=img_header;
        //output.C_data=img_data;
        output.pixel=pix;
        return output;



    

}



Data color_mod( Data matrix){//Modify the color intensity
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
    //Aqui es donde se modifica la imagen

}





Data color_multip_bmp(vector<int>multi, Data *& matrix){
    vector<RGB>image=matrix->pixel;
    //Primero el multiplicador para el rojo
    for(RGB &i:image){
        if(multi[0]==0)
          i.r;
        else if(multi[0]<0){
            i.r=i.r*-(multi[0]);
        }  
    }


}





bool valid_vals(vector<int>range){
    for (int i = 0; i < range.size(); i++)
    {
        if(range[i]<-100||range[i]>100){
            return false;
        }
    }return true;
    
}

