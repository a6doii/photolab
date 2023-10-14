/* FCAI – OOP Programming – 2023 - Assignment 1
 Program Name:				photolab.cpp
 Last Modification Date:	05/10/2023
 ALhussain Abdo      and ID and Group: 20220878  unknown
 Abdulrahman Tarek   and ID and Group: 20221096  unknown
 Hana Ragab Ahmed    and ID and Group: 20221192  unknown
 Teaching Assistant:	unknown
 Purpose:..........
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE] , image2[SIZE][SIZE];
int n ;
void menu (){
    cout << "\nWhich filter do you want to implement , Choose from the menu from ( 1 to 14)-or exit\n\n";
    cout << "1.Black and White      2.Invert Image          3.Merge Images\n\n4.Flip Image           5.Rotate Image          6.Darken and Lighten Image\n\n7.Detect Image Edges   8.Enlarge Image         9.Shrink Image\n\n10.Mirror Image        11.Shuffle Image        12.Blur Image \n\n13.Crop Image          14.Skew Horizon/Vertic  0.exit\n ";
    cin >> n ;

}

void Take_Name_Of_The_Image( ){ //  load the image
    cout << "Enter name for an image : ";
    char Name[100];
    cin >> Name; // photographer.bmp
    strcat ( Name, ".bmp" );
    readGSBMP(Name, image);
}
void saveimage(unsigned char imag[][SIZE]){
    char Name[100];
    cout << "The name which you want to extract the image with : ";
    cin >> Name;
    strcat (Name, ".bmp");
    writeGSBMP(Name, imag);
}


unsigned first[128][128],second[128][128],third[128][128],fourth[128][128];

void one_1 (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = first[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
    saveimage(image2);
}
void two_1 (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = second[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
    saveimage(image2);
}
void three_1 (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = third[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
    saveimage(image2);
}
void four_1 (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = fourth[i][j];
            cont_j+=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
    saveimage(image2);
}

void one ( int a , int b  ){
    // a = 128 || 0 , b = 0 || 128
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = first[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void two ( int a , int b ){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = second[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void three (int a, int b){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = third[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void four (int a ,int b ){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = fourth[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}

void operation (int n ){
    if ( n == 1 ){ // BW
        for (int i = 0 ; i < SIZE ; i++ ){
            for (int j = 0  ; j < SIZE; j++ ){
                if ( image[i][j] > 127)
                    image[i][j] = 255;
                else image[i][j]= 0;
            }
        }
        saveimage(image);
    }
    else  if ( n == 2 ){
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                image[i][j] = 255-image[i][j];
            }
        }
        saveimage(image);
    }
    else if ( n == 3 ){
        char Nametomerge[100];
        cout << "Enter name for the image which you want to merge it : ";
        cin >> Nametomerge;
        strcat( Nametomerge , ".bmp");
        readGSBMP (Nametomerge, image2);
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j<SIZE  ; j++ ){
                image [i][j] = (image2[i][j] + image[i][j])/2;
            }
        }
        saveimage(image);
    }
    else if ( n == 4 ){
        cout << "Do you want to flib the image\n1.horizontally\n2.vertically\nchoos from (1, 2 ) : ";
        int a ;
        cin >> a ;
        unsigned char temp [SIZE][SIZE];
        if ( a == 1 )
        {
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < 128 ; j++ ){
                    temp[i][j] = image[i][j];
                    image[i][j] = image[i][255-j];
                    image[i][255-j] = temp[i][j];
                }
            }
        }
        else {
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < 128 ; j++ ){
                    temp[j][i] = image[j][i];
                    image[j][i] = image[255 - j ][i];
                    image[255-j][i] = temp[j][i];
                }
            }
        }
        saveimage(image);
    }
    else if ( n == 5 ){
        cout << "Which degree do you want to rotate the image\nchoose (1.90 , 2.180, 3.270) : ";
        int a ;
        cin >> a ;
        if ( a == 1){
            unsigned char temp [SIZE][SIZE];
            int cont_i =  0 , cont_j = 0 ;
            for (int i = SIZE-1; i >= 0 ; i-- ){
                for (int j = 0 ; j < SIZE ; j ++ )
                {
                    image[j][i] = temp[cont_i][cont_j++];
                }
                cont_i++;
                cont_j = 0 ;
            }
            for (int i = 0 ; i < SIZE ;i++){
                for (int j = 0 ; j < SIZE ; j ++ )
                {
                    image[i][j] = temp[i][j];
                }
            }
        }
        saveimage(image);
    }
    else if ( n == 6 ){
        cout << "Do you want it\n1.Darken\n2.lighten\nchoose from (1,2) : ";
        int a ;
        cin >> a ;
        if ( a == 1 )
        {
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ ){
                    image[i][j ] /= 2;
                }
            }
        }
        else {
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ ){
                    image[i][j ] += (  255 - image[i][j] ) / 2 ;
                }
            }
        }
        saveimage(image);
    }
    else if ( n == 7) {
        unsigned char temp[SIZE][SIZE];
        for (int i = 0 ; i < SIZE -1  ; i ++ ){
            for (int j = 0 ; j < SIZE -1  ; j++ ){
                if  (  image[i][j]  < image[i+1][j+1] - 10  || image[i][j] < image[i+1][j]  )
                {
                    temp[i][j] = 0;
                }
                else temp[i][j] = 255;
            }
        }
        for (int i  =0 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                image[i][j] = temp[i][j];
            }
        }
        saveimage(image);
    }
    else if ( n == 8){
        int num ;
        cout << "How many quarters do you want to print\nchoose from(1:4) : ";
        cin >> num ;
        cout << "\nselect four number (the order) between (1:4)\n(NOTE :tap space between each one: ";
        int a = 0  , b = 0  , c = 0 , d = 0 ;
        for (int i = 0 ; i <  num; i++){
            if ( !a )
            {
                cin >> a ;
                continue;
            }
            else if (!b)
            { cin >> b ;
                continue;}
            else if ( !c )
            {
                cin >> c ;
                continue;
            }
            else if (!d)
            {
                cin >> d ;
                continue;
            }
        }
        for (int i = 0 ; i < 128 ; i ++ ){
            for (int j = 0 ; j < 128 ; j++){
                first[i][j] = image[i][j];
            }
        }
        int cont_i = 0 , cont_j = 0 ;
        for (int i = 0 ; i < 128 ; i ++){
            for (int j = 128 ; j < SIZE ; j++ ){
                second[cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < 128; j ++  ){
                third[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 128 ;  j< SIZE; j ++  ){
                fourth[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        if (a == 1 || b == 1 || c == 1 || d == 1  )
            one_1 ();
        if ( a== 2  || b == 2 || c == 2 || d == 2 )
            two_1();
        if ( a == 3 || b== 3 || c == 3 || d == 3 )
            three_1 ();
        if (a == 4 || c == 4 || b == 4 || c == 4 )
            four_1 ();

    }
    else if ( n == 9 ){
        unsigned char copy[SIZE][SIZE];
        int cont_i =  0, cont_j = 0 ;
        for (int i = 0 ; i < SIZE ;i ++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                copy[i][j] = 255;
            }
        }
        cout << "Shrink to 1.(1/2), 2.(1/3), 3.(1/4)?\nchoose from (1:3) : ";
        int a ;
        cin >> a ;
        if ( a == 1 ){
            for (int i = 0 ; i+ 2  < SIZE ; i+=2   ){
                for (int j = 0 ; j + 2  < SIZE ; j +=2  ) {
                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1]   );
                    avg /= 4;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }

        }
        else if ( a == 2 ){
            for (int i = 0 ; i+ 3  < SIZE ; i+=3   ){
                for (int j = 0 ; j + 3  < SIZE ; j +=3  ) {
                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i][j+2 ] + image[i+1][j] + image[i+1][j+1] + image[i+1][j+2] +
                            image[i+2][j] + image[i+2][j+1] + image[i+2][j+2 ] );
                    avg /= 9;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }

        }
        else {
            for (int i = 0 ; i+ 4  < SIZE ; i+=4   ){
                for (int j = 0 ; j + 4  < SIZE ; j +=4  ) {
                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i][j+2 ] + image[i][j+3] +  image[i+1][j] + image[i+1][j+1] + image[i+1][j+2] + image[i+1][j+3] +
                            image[i+2][j] + image[i+2][j+1] + image[i+2][j+2 ] + image[i+2][j+3] +image[i+3][j] + image[i+3][j+1] + image[i+3][j+2 ] + image[i+3][j+3] );
                    avg /= 16;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }
        }
        saveimage(copy);
    }
    else if ( n == 10 ){
        cout << "Do you want to mirror the image\n{1.Left, 2.Right, 3.Upper, 4.Lower}\nchoose from (1:4) : ";
        int a ;
        cin >> a ;
        if ( a == 1 ){
            for (int i = 0 ; i < SIZE ;  i ++ ){
                for (int j = 0 ; j < 128 ; j ++ ){
                    image[i][255-j] = image[i][j];
                }
            }
            saveimage(image);
        }
        if ( a == 2 ){
            for (int i = 0 ; i<SIZE ;  i ++ ){
                for (int j = 128 ; j<SIZE ; j ++ ){
                    image[i][255-j] = image[i][j];
                }
            }
            saveimage(image);
        }
        if (a == 3 ){
            for (int i = 0 ; i < 128 ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++){
                    image[255- i][j] = image[i][j];
                }
            }
            saveimage(image);
        }
        if ( a == 4 ){
            for (int i = 128 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++){
                    image[ 255- i ][j] = image[i][j];
                }
            }
            saveimage(image);
        }

    }
    else if ( n == 11 ){
        unsigned copy[SIZE][SIZE];
        for (int i = 0 ; i < 128 ; i ++ ){
            for (int j = 0 ; j < 128 ; j++){
                first[i][j] = image[i][j];
            }
        }
        int cont_i = 0 , cont_j = 0 ;
        for (int i = 0 ; i < 128 ; i ++){
            for (int j = 128 ; j < SIZE ; j++ ){
                second[cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < 128; j ++  ){
                third[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 128 ;  j< SIZE; j ++  ){
                fourth[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        cont_i= 0 ,cont_j = 0 ;
        cout << "which order do you want to print the quarters\nselect four number (the order) between (1:4)\n(NOTE :tap space between each one: ";
        int a , b , c , d ;
        cin >> a >> b >> c  >> d ;
        cont_i = 0 , cont_j = 0 ;
        if ( a == 1 )
        {
            cont_i = 0 , cont_j = 0 ;
            one ( cont_i, cont_j);
        }
        else  if ( a == 2 )
        {
            cont_i = 0 , cont_j = 0 ;
            two ( cont_i, cont_j);
        }
        else  if ( a == 3 )
        {
            cont_i = 0 , cont_j = 0 ;
            three( cont_i, cont_j);
        }
        else  if ( a == 4 )
        {
            cont_i = 0 , cont_j = 0 ;
            four ( cont_i, cont_j);
        }
        if ( b == 1 )
        {
            cont_i = 0 , cont_j = 128;
            one (cont_i,cont_j);
        }
        else  if ( b == 2 )
        {
            cont_i = 0 , cont_j = 128;
            two (cont_i,cont_j);
        }
        else  if ( b == 3 )
        {
            cont_i = 0 , cont_j = 128;
            three (cont_i,cont_j);
        }
        else  if ( b == 4 )
        {
            cont_i = 0 , cont_j = 128;
            four (cont_i,cont_j);
        }
        if ( c == 1 )
        {
            cont_i = 128 , cont_j = 0;
            one (cont_i,cont_j);
        }
        else if ( c == 2 )
        {
            cont_i = 128 , cont_j = 0;
            two (cont_i,cont_j);
        }
        else  if ( c == 3 )
        {
            cont_i = 128 , cont_j = 0;
            three (cont_i,cont_j);
        }
        else  if ( c == 4 )
        {
            cont_i = 128 , cont_j = 0;
            four (cont_i,cont_j);
        }
        if ( d == 1 )
        {
            cont_i = 128 , cont_j = 128;
            one (cont_i,cont_j);
        }
        else  if ( d == 2 )
        {
            cont_i = 128, cont_j = 128;
            two (cont_i,cont_j);
        }
        else  if ( d == 3  )
        {
            cont_i = 128 , cont_j = 128;
            three(cont_i,cont_j);
        }
        else  if ( d == 4 )
        {
            cont_i = 128 , cont_j = 128;
            four (cont_i,cont_j);
        }
        saveimage(image);
    }
    else if (n == 12 ){
        unsigned char copy1[SIZE][SIZE];
        for(int i=0;i<SIZE ;i++){
            for (int j=0;j<SIZE;j++){
                copy1[i][j]=image[i+1][j];

            }
        }
        saveimage(image);
    }
    else if ( n == 14 ){
        cout << "Do you want it (H).horizontally or (V).verticlly)\n";
        char ch ;
        cin >> ch;
        cout << "Enter the degree: ";
        float deg;
        cin >> deg;
        unsigned char copy[SIZE][SIZE];
        for(int i = 0 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                copy[i][j] = 255;
            }
        }
        int a = 1 , b = 256;
        double pi = 22/7.0;
        if ( ch == 'V'){
            for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
                int leftangle = ( tan (deg * ( pi / 180.0))*b);
                int rightangle = (tan(deg * (pi/180.0))*a);
                double pixels = ( 256- (leftangle + rightangle ) );
                pixels =  256.0/pixels; // 1.2 //==> 1 ===> 0.2 REMINDER = 0.2 ,,,  1.2 + 0.2 ==> 1.4 ==> 2.4 ==>  2 ===>  2.4 ==> r = 0.4
                double a = pixels , remainder = 0 ;
                int j = leftangle;
                for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                    int avg = 0 ;
                    for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                        avg += image[i][w+k];
                    }
                    avg /= floor( pixels + remainder );
                    if ( j > 256-rightangle){
                        break;
                    }
                    copy[i][j++] = avg; // 2.4   ..   2 <  3.2   ,, 0.6
                    if (  floor ( pixels) <floor ( pixels + remainder) ) // 3 ==>  3.2 ==> 2.4
                    {
                        remainder -= ( floor(pixels + remainder)  - pixels );
                    }
                    else {
                        remainder += pixels - floor(pixels);
                    }
                }
            }
        }
        else if ( ch == 'H'){
            int a = 1 , b = 256;
            double pi = 22/7.0;
            for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
                int leftangle = ( tan (deg * ( pi / 180.0))*b);
                int rightangle = (tan(deg * (pi/180.0))*a);
                double pixels = ( 256- (leftangle + rightangle ) );
                pixels =  256.0/pixels;
                double a = pixels , remainder = 0 ;
                int j = leftangle;
                for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                    int avg = 0 ;
                    for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                        avg += image[w+k][i];
                    }
                    avg /= floor( pixels + remainder );
                    if ( j > 256-rightangle){
                        break;
                    }
                    copy[j++][i] = avg; // 2.4   ..   2 <  3.2   ,, 0.6
                    if (  floor ( pixels) <floor ( pixels + remainder) ) // 3 ==>  3.2 ==> 2.4
                    {
                        remainder -= ( floor(pixels + remainder)  - pixels );
                    }
                    else {
                        remainder += pixels - floor(pixels);
                    }
                }
            }
        }
        saveimage(copy);
    }
}
int main()
{
         menu();
        Take_Name_Of_The_Image();
        operation(n);


    return 0;
}