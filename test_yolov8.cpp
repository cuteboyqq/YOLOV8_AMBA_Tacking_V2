/*******************************************************************************
 * test_yolov8.c
 *
 * History:
 *  2023/10/02  - [Alister Hsu] created
 *
 ******************************************************************************/
// #include "yolov8_utils/yolov8_class.h"
// #include "yolov8_utils/object.hpp"
// #include "yolov8_utils/point.hpp"
// #include "yolov8_utils/bounding_box.hpp"
#include "yolov8_utils/vision_tracker.hpp"
using namespace std;


void showTrackedHumanResults(std::vector<TrackedObj>& objList)
{
	for (int i=0; i<objList.size(); i++)
  {
    TrackedObj& obj = objList[i];

	cout << "Obj[" << obj.id << "] ";
    cout << "Type: " << obj.type << " ";
    cout << "Conf: " << obj.confidence << " ";
    cout << "Loc: (" << obj.pLoc.x << " m, " << obj.pLoc.y << " m, " << obj.pLoc.z << " m)" << endl;
  }
}


int main(int argc, char **argv)
{
	int rval = 0;
	int sig_flag = 0;
	int idxFrame = 0;
	// std::vector<BoundingBox> bboxList;
	// YoloV8_Class yolov8(argc,argv);
	cout<<"create vTracker"<<endl;
	VisionTracker vTracker("./config/config.txt",argc,argv);
	cout<<"create VisionTrackingResults"<<endl;
	VisionTrackingResults result;
	//ea_tensor_t *tensor;
	//img_set_t *img_set;
	//img_set = new img_set_t;
	// cv::Mat img = cv::Mat::zeros(1920,1080,CV_8UC3);
	cout<<"create cv::Mat img"<<endl;
	cv::Mat img;
	while(1)
	{	
		idxFrame+=1;
		cout<<"---------------------------[main]Frame num = "<<idxFrame<<"-------------------------------"<<endl;
		
		// img = yolov8.Get_img();
		// if (img.empty())
		// {
		// 	break;
		// }
		// sig_flag = yolov8.test_yolov8_run();
		// bboxList.clear();
		// yolov8.Get_Yolov8_Bounding_Boxes(bboxList,img);
		cout<<"Start vTracker.run(img)"<<endl;
		vTracker.run(img);
		cout<<"Done vTracker.run(img)"<<endl;
		vTracker.getResults(result);
		if (vTracker.isFinishDetection())
		{
			std::cout << "\nFrame: [" << idxFrame << "]" << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			showTrackedHumanResults(result.humanObjList);
		}
		
	};

	return rval;
}
