import image_handler as ih
import numpy as np


image1=ih.Image()
image2.ih.image()
path1=input("introduce la ruta de tu imagen 1")
path2=input("introduce la ruta de tu imagen 2")
op=int(input("Introduce la operacion a realizar|| \n1.- Suma\n2.-Multiplicacion\n3.-Resta\n4.-And\n5.-Or\n6.-Xor\n7.-Division\n"))
image1.read_img(path1, 0, 600 , 800)
image2.read_img(path2, 0, 600 , 800)
image=switch_operation[op]
image.show_image()










switch_operation={
    1:suma,
    3:Resta,
    2:multiplicacion
}


def Suma(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen    
    if img1.mode==1 and img2.mode==1:
        mat=np.empty(img1.height,img1.width)
        for i in range(img1.height):
            for j in range(img1.width):
                mat[i][j]=mat1[i][j]+mat2[i][j]
        output.assign_img(mat)
        return output
    elif img1.mode==3:
        mat=np.empty(img1.height,img1.width*3)
        for i in range(img1.height):
            for j in range(0,img1.width*3,3):
                mat[i][j]=mat1[i][j]+mat2[i][j]
                mat[i][j+1]=mat1[i][j+1]+mat2[i][j+1]
                mat[i][j+2]=mat1[i][j+2]+mat2[i][j+2]
        output.assign_img(mat)
        return output

def Resta(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen    
    if img1.mode==1 and img2.mode==1:
        mat=np.empty(img1.height,img1.width)
        for i in range(img1.height):
            for j in range(img1.width):
                mat[i][j]=mat1[i][j]-mat2[i][j]
        output.assign_img(mat)
        return output
    elif img1.mode==3:
        mat=np.empty(img1.height,img1.width*3)
        for i in range(img1.height):
            for j in range(0,img1.width*3,3):
                mat[i][j]=mat1[i][j]-mat2[i][j]
                mat[i][j+1]=mat1[i][j+1]-mat2[i][j+1]
                mat[i][j+2]=mat1[i][j+2]-mat2[i][j+2]
        output.assign_img(mat)
        return output

def multiplicacion(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen    
    if img1.mode==1 and img2.mode==1:
        mat=np.empty(img1.height,img1.width)
        for i in range(img1.height):
            for j in range(img1.width):
                mat[i][j]=(mat1[i][j]*mat2[i][j])/255
        output.assign_img(mat)
        return output
    elif img1.mode==3:
        mat=np.empty(img1.height,img1.width*3)
        for i in range(img1.height):
            for j in range(0,img1.width*3,3):
                mat[i][j]=(mat1[i][j]*mat2[i][j])/255
                mat[i][j+1]=(mat1[i][j+1]*mat2[i][j+1])/255
                mat[i][j+2]=(mat1[i][j+2]*mat2[i][j+2])/255
        output.assign_img(mat)
        return output
def And_(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen 
    if img1.mode==1 and img2.mode==1:
        mat=np.empty(img1.height,img1.width)
        mat=np.logical_and(mat1,mat2)
        output.assign_img(mat)
        return output

def Or_(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen 
    if img1.mode==1 and img2.mode==1:
        mat=np.logical_or(mat1,mat2)
        output.assign_img(mat)
        return output

def Xor_(img1:ih.Image,img2:ih.Image)->ih.Image:
    output=ih.Image()
    mat1=img1.imagen
    mat2=img2.imagen 
    if img1.mode==1 and img2.mode==1:
        mat=np.logical_xor(mat1,mat2)
        output.assign_img(mat)
        return output
    
