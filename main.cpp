// Author: Willy Iparraguirre
#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

bool validBmp;
void printRGB(Bitmap,int,int);


int main()
{
 do
 {
  cout<<"Please enter a proper bmp file,type done when finished. "<<endl;
  cin>>fileName;

  Bitmap image;
  vector< vector <Pixel> > bmp;
  Pixel rgb;

  image.open(fileName);
  validBmp = image.isImage();
 }

 while(fileName == "done" || fileName == "DONE" || fileName == "Done" || fileName <= 10);

   if(validBmp == true)
    {
     bmp = image.toPixelMatrix();

     printRGB(image,row,column);
    
    }

   else
    {
     cout<<"One or more of the files were NOT proper bmp format
  
}

void printRGB(Bitmap img, int r, int c)
{
 Pixel rgb;
 vector< vector <Pixel> > bmp;
 bmp = img.toPixelMatrix();

 for(int r = 0; r < bmp.size(); r++)
  {
   for(int c = 0; c < bmp[r].size(); c++)
    {
     
    }
  }
}
