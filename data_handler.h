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
    RGB *C_data;
}Data;

bool valid_vals(vector<int>range);


Data data_read(char * name){
FILE *F;
    F=fopen("name","r");
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
        fread(header.file_des,sizeof(unsigned char),4,F);
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
        RGB *img_data=new RGB[(int)img_header.img_size];
        fread(img_data,sizeof(RGB),((int)img_header.img_size)/sizeof(RGB),F);
        int num_pix=((int)img_header.img_size)/sizeof(RGB);

        Data output;
        output.Head_f=header;
        output.Head_img=img_header;
        output.C_data=img_data;
        return output;



    

}


Data color_mod(){//Modify the color intensity
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

        }

    }   
}

bool valid_vals(vector<int>range)