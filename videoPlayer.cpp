#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


// this function will get a status from status.txt file
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

	//here we defined our opencv variables that handle video and frame
	VideoCapture video;
  Mat frame;
	
	//here we open video file which its name given by argument
  video.open(argv[1]);

	// checking wether that video can open and ply
  if (video.isOpened() == false)
  {                                          
		cout << "Can't open video file." << endl;           
    return 0;
  }
	
	// read one frame of video to cause video windows open even if video paused
	video.read(frame);
	
  while(true)
  {
		
		// we fetch status from status.txt to see whether-
		// - must play video (read another frame) or not
		if(getStatus() == "resume")
			video.read(frame);
		
		// again fetching status from status.txt to quit if wanted
		if(getStatus() == "quit")
			return 0;
			
		// checking if frames finished
		if(frame.empty() == true)
		{
			cout << "Looks like we reached end of video." << endl;
			return 0; 
		}
		
		// showing a window which the wanted frame will play in that windo
		imshow("myVid", frame);
		waitKey(1);
		
		// this loop is for making video slower
		for(int i = 0; i < 10000000; i++);
  }
  
}

