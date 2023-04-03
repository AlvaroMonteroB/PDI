#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
using namespace std;

class Image{//Defriniciones de nuestro objeto para el tratamiento de las imagenes
    private:
    unsigned char *file_h;
    unsigned char *img_h;
    cv::Mat img;
    public:
        Image(){
            file_h;
            img_h;
            img;
        }
    private:
        void read_header(string name,FILE *data);
    public:
        bool color_channel();
        void Read_data(string name);//terminado
        string get_filetype();
        Image color_multip(vector<int>multi);//Para modificar las intensidades de los colores primarios

};

