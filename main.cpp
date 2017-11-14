// Author: Willy Iparraguirre
#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

const int MAX_FILENAME = 10;
bool validBmp;
int row, column, depth;
string fileName, Images;

vector< vector<Pixel> > validImg(string);
void printRGB(int,int,int);

int main()
{
        //Create a loop that will ask the user to enter a file until they reach the max of ten or if they enter "done". 
        do
        {      
                cout<<"Please enter a proper bmp file(max of 10), type done when finished."<<endl;
                cin>>fileName;         
                
                validImg(Images);  
              
                printRGB(row,column,depth);
        }
        while(fileName == "done" || fileName == "Done" || fileName == "DONE" && validBmp == false);

        return 0;
} 
vector< vector<Pixel> > validImg(string Images)
{
        Bitmap image;
        vector< vector <Pixel> >bmp;
        Pixel rgb;

        image.open(fileName);
        validBmp = image.isImage();

        if(validBmp == true)
        {
                bmp = image.toPixelMatrix();
        }
        else
        {
                cout<<"One or more of the files were NOT proper bmp format, OR they weren't all the same size."<<endl;
        } 
}
void printRGB(Bitmap img, int r, int c, int d)
{
        double average, sumRed, sumGreen, sumBlue;
        Bitmap image;
        Pixel rgb;
        vector< vector< vector<Pixel> > >bmp;
        image.toPixelMatrix(bmp);

        for(int r = 0; r < bmp.size(); r++)
        {

                for(int c = 0; c < bmp[r].size(); c++)
                {
                        sumRed = 0;
                        sumGreen = 0;
                        sumBlue = 0;

                        for(int d = 0; d < bmp[r][c].size(); d++)
                        {
                                rgb = bmp[r][c][d];
                                sumRed = rgb.red + sumRed;
                                sumGreen = rgb.green + sumGreen;;
                                sumBlue = rgb.blue + sumBlue;
                                bmp[r][c][d] = rgb;
                        }
                        average = (sumRed + sumGreen + sumBlue) / bmp.size();
                }
                image.fromPixelMatrix(bmp);
                image.save("composite-wiparraguirre.bmp");
        }
        return = vector< vector< vector<Pixel> > >bmp ;      
}        
