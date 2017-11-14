// Author: Willy Iparraguirre
#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

const int MAX_FILENAME = 10;
bool validBmp;
int row, column, depth;
string fileName;

void printRGB(Bitmap,int,int,int);

int main()
{
        //Create a loop that will ask the user to enter a file until they reach the max of ten or if they enter "done". 
        do
        {      
                cout<<"Please enter a proper bmp file(max of 10), type done when finished."<<endl;
                cin>>fileName;
          
                Bitmap image;
                vector< vector <Pixel> > bmp;
                Pixel rgb;
              
                //Check to see whether or not each file is a bmp format, and if they are all the same size.
                image.open(fileName);
                validBmp = image.isImage();

                if(validBmp == true)
                { 
                        bmp = image.toPixelMatrix();
                        //Print the matrix of the bmp if it is in proper format, this can be a function.
                        printRGB(image,row,column,depth);
                }
                //Print error if all the images aren't the same size and if they aren't propper bmp format, or the user has submitted more than 10 files.
                else
                {
                        cout<<"One or more of the files were NOT proper bmp formati, OR they weren't all the same size."<<endl;
                }
        }
        while(fileName == "done" || fileName == "Done" || fileName == "DONE" && validBmp == false);

        return 0;
} 
//Combine the valid images together to create a single composite image, this can be done in a function.
//As the images are being loaded notify the user an occasional progression report.
//Function for printing the matrix of the bmp and finding the average of each pixel.
vector< vector< vector<Pixel> > > validImg(Bitmap img, int x, int y)
{
  
}
void printRGB(Bitmap img, int r, int c, int d)
{
        double average, sumRed, sumGreen, sumBlue;
        Bitmap image;
        Pixel rgb;
        vector< vector < vector<Pixel> > >bmp;
        bmp = img.toPixelMatrix();

        for(int r = 0; r < bmp.size(); r++)
        {

                for(int c = 0; c < bmp[r].size(); c++)
                {
                        sumRed = 0;
                        sumGreen = 0;
                        sumBlue = 0;

                        for(int d = 0; d < bmp[r][c].size(); d++)
                        {
                                rgb = bmp[r][c];
                                sumRed = rgb.red + sumRed;
                                sumGreen = rgb.green + sumGreen;;
                                sumBlue = rgb.blue + sumBlue;
                                bmp[r][c] = rgb;
                        }
                        rgb = bmp[r][c];
                        average = (sumRed + sumGreen + sumBlue) / bmp.size();
                        bmp[r][c] = rgb;
                }
              image.fromPixelMatrix(bmp);
              image.save("composite-wiparraguirre.bmp");
        }
}        
