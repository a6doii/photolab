/* FCAI – OOP Programming – 2023 - Assignment 1
 Program Name:				photolab.cpp
 Last Modification Date:	05/10/2023
 ALhussain Abdo      and ID and Group: 20220878  unknown
 Abdulrahman Tarek   and ID and Group: 20221096  unknown
 Hana Ragab Ahmed    and ID and Group: 20221192  unknown
 Teaching Assistant:	unknown
 Purpose:Editing the image (bmp)
 */

#include <iostream>
#include "bmplib.cpp"
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
void loadImage () {   // load the image to convert it to a 256x256 pixel matrix
   char imageFileName[100];
   string s ;
   cout << "--------------------------------------\n--------------------------------------\nEnter the source image file name: ";
   cin >> imageFileName;
   while (s != "photographer" &&s!= "elephant" && s != "fruit" && s != "crowd" && s != "House" && s!= "mario" && s != "parots" ){
        cout << "Enter the source image correctly : ";   // Whale Loop checks if the image name is correct
        cin >> imageFileName;
        s = imageFileName;
   }
   strcat (imageFileName, ".bmp"); 
   readGSBMP(imageFileName, image); // convert it to a 256x256 pixel matrix
}
void loadImage2 () { //load another image if we need to merge two images
   char imageFileName[100];
    string s ;
   cout << "Enter the source image file name which you want to merge with: ";
   cin >> imageFileName;
   while (s != "photographer" &&s!= "elephant" && s != "fruit" && s != "crowd" && s != "House" && s!= "mario" && s != "parots" ){
        cout << "Enter the source image correctly : ";
        cin >> imageFileName;
        s = imageFileName;
   }
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);
}

void saveImage () { //  save the image after the user has finished editing
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image); //Convert a matrix of pixels into an image bmp
}
void verticalFlip(unsigned char image[][SIZE]){
    unsigned char copy[SIZE][SIZE];// Create an empty copy of the pixel 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            copy[i][j]=image[255-i][j];// Move the last pixel on the left side (image[255][j])
        }                              //to the first pixel right side  (copy[i][j])  gradually using Loop
                                       // we play in (i index) area to flip it vertical
    }
    memcpy(image,copy,sizeof(copy));


}
void horizontalFlip(unsigned char image[][SIZE]){
    unsigned char copy[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            copy[i][j]=image[i][255-j]; // the same above but we play in (j index) area to flip it horiz
        }
            
    }
    memcpy(image,copy,sizeof(copy));

}





void Black&White (unsigned char image[][SIZE]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j]>128){ // Select pixels with a white
                image[i][j]=255; // scale to convert them to pure white
            }else{
                image[i][j]=0;  // Convert everything else to pure black
            }
        }
        
    }
    
}
void invert(unsigned char image[][SIZE]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j]=255-image[i][j]; //Changing the pixel color to its opposite
        }                                //color in black and white gradations
        
    }
    
}

void darklight(unsigned char image[][SIZE]){
    char choice;
    cout << "Do you want to (d)arken or (l)ighten? ";
    cin >> choice;
    while ( choice != 'd' && choice != 'l') // close the ability of user in the input
    {                                       // to choice just darken or lighten
        cout << "Error : this is wrong input\nchoose from (h, v)";
        cin >> choice;
    }
    if (choice=='d'){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=floor(image[i][j]*0.5);// Decrease the value of each pixel
            }                                     //by  ( 0.5 )to make the colors darker
            
        }

    }
    else{
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                ((image[i][j]*2)<=255)?image[i][j]=image[i][j]*2:image[i][j]=255;
            } // If the pixel value is less than or equal to 255,
              // it lightens the color by multiplying the pixel value by (2)
        }     //Otherwise, the pixel value equals the pure white

    }
    
    
}
void merge(unsigned char image1[][SIZE],unsigned char image2[][SIZE]){

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image1[i][j]=(image1[i][j]+image2[i][j])/2;//The value of each pixel in the new image
            // is equal to the average sum of each pixel (same index) in the two images to be merged
        }
        
    }
    
}
void flip(unsigned char image[][SIZE]){
    cout<<"Flip (h)orizontally or (v)ertically ?";
    char a;
    cin>>a;
    while ( a != 'v' && a != 'h'){  // close the ability of user in the input
                                    // to choice just vertical or horizontal
        cout << "Error : this is a wrong direction\nchoose from ( v, h) : ";
        cin >> a ;
    }
    if (a=='v'){
        verticalFlip(image);  //Call to the previous function verticalFlip
    }
    else{
        horizontalFlip(image);// Call to the previous function horizontalFlip

    }
    
}
void rotate(unsigned char image [][SIZE]){
    int degree;
    cout<<"Rotate (90), (180) or (270) degrees?";
    cin>>degree;
    while ( degree != 90 && degree != 180 && degree != 270   )
        // close the ability of user in the input
        // to choice correct degree
    {
        cout << "Error: this is a wrong degree\nchoose from\n{90, 180, 270} : ";
        cin >> degree;
    }
    unsigned char copy[SIZE][SIZE];
    switch (degree)
    {
    case 90:
        horizontalFlip(image); // it's easy to know hahaha
        break;
    case 180:
        verticalFlip(image); // it's easy too
        break;
    case 270:
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                copy[i][j]=image[j][255-i];//play with (index i) to rotate by 270 degree
            }
            
        }
        memcpy(image ,copy ,sizeof(copy));

        break;
    
    default:
        cout<<"enter the degree of the angle again: ";
        cin>>degree;
    }

}
void menu(){
    //a function that contains all the actions of the previous functions
    // to allow the user to choose the type of filter
    loadImage();

    int action ;
    while(true){ // close the ability of user in the input between the able actions only
        cout<<("enter the number of the filter (NOTE: if you want to save the image press (7))\n1-	Black & White Filter\n2-	Invert Filter\n3-	Merge Filter \n4-	Flip Image\n5-	Darken and Lighten Image \n6-	Rotate Image\n7-      Save the image to a file\n--------------------------------------\n--------------------------------------\n");
        cin>>action;
        switch (action)
        {
        case 0:
            return;
            
            
            break;
        case 1:
            Black&White(image);
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

        default:
            cout<<" please enter another number: ";
            break;
        }
    }
}

int main()
{
    menu(); // here we go ,,now you can  enjoy with our program filter
            // don't forget it's just the first version of photolab .
    
    return 0;
}