#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


string getStatus()
{
	string status;
	
	ifstream file;
	file.open("status.txt");
	file >> status;
	file.close();
	
	return status;
}

int main(int argc, char **argv)
{


	VideoCapture video;
  Mat frame;
	
  video.open("tik.mp4");

  if (video.isOpened() == false)
  {                                          
		cout << "Can't open video file." << endl;           
    return 0;
  }
	
	video.read(frame);
	
  while(true)
  {
		
		if(getStatus() == "resume")
			video.read(frame);
		
		if(getStatus() == "quit")
		{
			return 0;
		}
		if(frame.empty() == true)
		{
			cout << "Looks like we reached end of video." << endl;
			return 0; 
		}
		
		imshow("myVid", frame);
		waitKey(1);
				
  }
  
}

