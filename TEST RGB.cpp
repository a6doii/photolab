#include <iostream>
#include "bmplib.cpp"
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
using namespace std;


void loadImage () {

   char imageFileName[100];

   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
   
}
void loadImage2 () {

   char imageFileName[100];

   cout << "Enter the other source image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image2);
   
}
void saveImage () {
   char imageFileName[100];

   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
void verticalFlip(unsigned char image[][SIZE][RGB]){
    unsigned char copy[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                copy[i][j][k]=image[255-i][j][k];
                
            }
            
        }
            
    }
    memcpy(image,copy,sizeof(copy));


}
void horizontalFlip(unsigned char image[][SIZE][RGB]){
    unsigned char copy[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                copy[i][j][k]=image[i][255-j][k];
                
            }
        }
            
    }
    memcpy(image,copy,sizeof(copy));

}
void BW(unsigned char image[SIZE][SIZE][RGB]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int grayScale = (image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
            for (int k = 0; k < RGB; k++)
            {
                if(grayScale>128){
                    image[i][j][k]=255;

                }else{
                    image[i][j][k]=0;

                }
            }
            
            
            
        }
        
    }
    

}
void invert(unsigned char image[SIZE][SIZE][RGB]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0 ; j < SIZE; j++){
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k]=255 - image[i][j][k];
                
            }
            
        }
    }

}
void darklight(unsigned char image[][SIZE][RGB]){
    char choice;
    cout<<"Do you want to (d)arken or (l)ighten? " ;
    cin>>choice;
    if (choice=='d'){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB ;k++)
                {
                image[i][j][k]=floor(image[i][j][k]*0.5);

                    
                }
                
    
            }
            
        }

    }
     else{
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    ((image[i][j][k]*2)<=255)?image[i][j][k]=image[i][j][k]*2:image[i][j][k]=255;
                }
                
                

            }
            
        }

    }
    
    
}
void merge(unsigned char image1[][SIZE][RGB],unsigned char image2[][SIZE][RGB]){
    // unsigned char mergedImage[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image1[i][j][k]=(image1[i][j][k]+image2[i][j][k])/2;
                
            }
            
            
        }
        
    }
    
}
void flip(unsigned char image[][SIZE][RGB]){
    cout<<"Flip (h)orizontally or (v)ertically ?";
    char a;
    cin>>a;
    if (a=='v'){
        verticalFlip(image);
    }
    else{
        horizontalFlip(image);

    }
    
}
void rotate(unsigned char image [][SIZE][RGB]){
    int degree;
    cout<<"Rotate (90), (180) or (270) degrees?";
    cin>>degree;
    unsigned char copy[SIZE][SIZE][RGB];
    switch (degree)
    {
    case 90:
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[i][j][k]=image[255-j][i][k];
                    
                }
                
            }
            
        }
        memcpy(image ,copy ,sizeof(copy));  
        break;
    case 180:
        verticalFlip(image);
        break;
    case 270:
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[i][j][k]=image[j][255-i][k];
                    
                }
            }
            
        }
        memcpy(image ,copy ,sizeof(copy));

        break;
    
    default:
        cout<<"enter the degree of the angle again: ";
        cin>>degree;
    }

}
void detectImageEdges(unsigned char image[][SIZE][RGB]){
    unsigned char copy[SIZE][SIZE][RGB];
    BW(image);
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if(image[i][j][k]!=image[i+1][j+1][k]){
                    copy[i][j][k]=0;
                }
                else{
                    copy[i][j][k]=255;
                }
                }
            
            

            
        }
        
    }
    memcpy(image,copy,sizeof(copy));
    
}
void enlargeImage(unsigned char image[][SIZE][RGB]){
    unsigned char copy[SIZE][SIZE][RGB];
    int quarter;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4? ";
    cin>>quarter;
    int x=0,y=0;
    switch (quarter)
    {
    case 1:
        for (int i = 0; i < 128; i++)
        {
            // x++;
            for (int j = 0; j < 128; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=image[j][i][k];
                    copy[x+1][y][k]=image[j][i][k];
                    copy[x][y+1][k]=image[j][i][k];
                    copy[x+1][y+1][k]=image[j][i][k];
                }
                
                
                

                x+=2;
                
            }
            x=0;
            y+=2;
            
            
        }
    
        break;
    case 2:
    //runs quarter 3
        // x=0;
        // y=128;

        for (int i = 128; i <= 255; i++)
        {

            for (int j = 0; j < 128; j++)
            {
                // (copy[i][j]=copy[i+1][j]=copy[i][j+1]=copy[i+1][j+1])=image[i][j];
                // (copy[x][y]=copy[x+1][y]=copy[x][y+1]=copy[x+1][y+1])=image[j][i];
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=image[j][i][k];
                    copy[x+1][y][k]=image[j][i][k];
                    copy[x][y+1][k]=image[j][i][k];
                    copy[x+1][y+1][k]=image[j][i][k];
                }
                x+=2;
                // y++;
            }
            x=0;
            y+=2;

        
        
        }
        break;
    case 3:
    //runs quarter 3
    for (int i = 0; i < 128; i++)
    {
        for (int j = 128; j < 255; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                copy[x][y][k]=image[j][i][k];
                copy[x+1][y][k]=image[j][i][k];
                copy[x][y+1][k]=image[j][i][k];
                copy[x+1][y+1][k]=image[j][i][k];
            }
            x+=2;
        }
        x=0;
        y+=2;
        
        
    }
        break;
    case 4:
        // x=128;
        // y=128;
    //runs quarter 3
        for (int i = 128; i <= 255; i++)
        {
            for (int j = 128; j <= 255; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=image[j][i][k];
                    copy[x+1][y][k]=image[j][i][k];
                    copy[x][y+1][k]=image[j][i][k];
                    copy[x+1][y+1][k]=image[j][i][k];
                }
                x+=2;
            }
            x=0;
            y+=2;


            
            
        }
        break;
    
    default:
        break;
    }
    // for ( i ; i < n; i++)
    // {
    //     for ( j ; j < n; j++){
    //         (copy[i][j]=copy[i+1][j]=copy[i][j+1]=copy[i+1][j+1])=image[i][j];
    //     }
    // }
    memcpy(image,copy,sizeof(copy));
    
    

    

}
void blur(unsigned char image[][SIZE][RGB]){
    // unsigned char copy[SIZE][SIZE];
    // while (r--)
    // {

        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < 255; j++)
            {
               
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < RGB; l++)
                    {
                        image[i][j][l]=((image[i][j][l]+image[i+k][j][l]+image[i][j+k][l]+image[i+k][j+k][l]+image[i-k][j][l]+image[i][j-k][l])/6);
                        // image[i+1][j]=((image[i][j]+image[i+k][j]+image[i][j+k]+image[i+k][j+k]+image[i-k][j]+image[i][j-k])/6);
                        // image[i][j+1]=((image[i][j]+image[i+k][j]+image[i][j+k]+image[i+k][j+k]+image[i-k][j]+image[i][j-k])/6);
                        // image[i+1][j+1]=((image[i][j]+image[i+k][j]+image[i][j+k]+image[i+k][j+k]+image[i-k][j]+image[i][j-k])/6);
                        
                    }
                    
                    
                }
                
               

            }
            
        }
    // }
    // memcpy(image,copy,sizeof(copy));
}
void crop(unsigned char image[][SIZE][RGB]){
    int x ,y, l, w;
    cout<<"Please enter x y l w: ";
    cin>>x>>y>>l>>w;

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 265; j++)

        {
            for (int k = 0; k < RGB; k++)
            {
                if((j<x||j>x+l)||i<y||i>x+w){
                    image[i][j][k]=255;

            }
            }
            
            

            
        }
        
    }

}
void shrinkImage(unsigned char image[][SIZE][RGB]){
    unsigned char copy[SIZE][SIZE][RGB]={255};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                copy[i][j][k]=255;
                
            }
            
        }
    }
    float shrinkTo;
    cout<<"shrink to (0.5),(0.3) or (0.25)? ";
    int x=0,y=0;
    cin>>shrinkTo;
    if(shrinkTo==0.25){
    for (int i = 0; i < 256; i+=4)
        {
            for (int j = 0; j < 256; j+=4)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=(image[i][j][k]+image[i+1][j][k]+image[i][j+1][k]+image[i+1][j+1][k])*shrinkTo;
                }
                

                

                y++;
            }
            x++;
            y=0;
            
        }
    }
else if(shrinkTo==0.3){
        for (int i = 0; i < 256; i+=3)
        {
            for (int j = 0; j < 256; j+=3)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=(image[i][j][k]+image[i+1][j][k]+image[i+2][j][k]+image[i][j+1][k]+image[i][j+2][k]+image[i+1][j+1][k]+image[i+2][j+2][k]+image[i+1][j+2][k]+image[i+2][j+1][k])/9;


                }


                y++;
            }
            x++;
            y=0;
            
        }
}
else{
    for (int i = 0; i < 256; i+=2)
        {
            for (int j = 0; j < 256; j+=2)
            {
                for (int k = 0; k < RGB; k++)
                {
                    copy[x][y][k]=(image[i][j][k]+image[i+1][j][k]+image[i][j+1][k]+image[i+1][j+1][k])/4;
                }
                

                // copy[x][y]=(image[i][j]+image[i+1][j+1]+image[i][j+1]+image[i+1][j+1])/4;

                y++;
            }
            x++;
            y=0;
            
        }
    
}
    memcpy(image,copy,sizeof(copy));
    
}
void mirorImage(unsigned char image[][SIZE][RGB]){
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side?";
    char a;
    cin>>a;
    int x=0;
    switch (a){
        case 'u':

        for (int i = 128; i <SIZE ; i++,x++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++){
                    image[i][j][k]=image[128-x][j][k];
                }
            }
            
        }
        break;

        case 'l':

        for (int i = 0; i < SIZE ; i++)
        {
            for (int j = 128; j < SIZE; j++,x++)
            {
                for (int k = 0; k < RGB; k++){
                    image[i][j][k]=image[i][128-x][k];
                    
                }
                
            }
            x=0;
            
        }
        break;
        case 'r':
        for (int i = 0; i < SIZE ; i++)
        {
            for (int j = 128; j < SIZE; j++,x++)
            {
                for (int k = 0; k < RGB; k++){
                    image[i][128-x][k]=image[i][j][k];
                    
                }
                
                
            }
            x=0;
            
        }
        break;
        case 'd':

        for (int i = 128; i <SIZE ; i++,x++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++){
                    image[128-x][j][k]=image[i][j][k];
                    
                }
                
            }
            
        }
        break;

    }
        


}

void menu(){
    loadImage();

    int action ;
    while(true){
        cout<<("enter the number of the filter\n1-	Black & White Filter\n2-	Invert Filter\n3-	Merge Filter \n4-	Flip Image\n5-	Darken and Lighten Image \n6-	Rotate Image\n7-      Save the image to a file\n8-      detect image edges\n9-      enlarge image\n10-     blur image\n11-     crop image\n12-     shrink image\n0-	Exit\n");
        cin>>action;
        switch (action)
        {
        case 0:
            return;
            
            
            break;
        case 1:
            BW(image);
            break;
        case 2:
            invert(image);
            break;
        case 3:
            loadImage2();
            merge(image,image2);
            break;
        case 4:
            flip(image);
            break;
        case 5:
            darklight(image);
            break;
        case 6:
            rotate(image);
            break;
        case 7:
            saveImage();
            break;
        case 8:
            detectImageEdges(image);
            break;
        case 9:
            enlargeImage(image);
            break;
        case 10:
            blur(image);
            break; 
        case 11:
            crop(image);
            break;  
        case 12:
            shrinkImage(image);
            break;
        case 13:
            mirorImage(image);
            break;        

        default:
            cout<<" please enter another number: ";
            break;
        }
    }
}

int main()
{
    
    menu();


    
    
    
    
    return 0;
}
