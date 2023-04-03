typedef struct{//Definicion del header del archivo si es bmp
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
