#include "Descriptor.h"

// using namespace cv;
#include "opencv2/xfeatures2d.hpp"
using namespace cv::xfeatures2d;

void ORBDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Ptr<ORB> orb = ORB::create();
    orb->compute(image, keypoints, descriptors);
};

// void SIFTDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
//     cv::Ptr<cv::SIFT> siftPtr = cv::SIFT::create();
//     siftPtr->compute(image, keypoints, descriptors);
// };

void SURFDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Ptr<SURF> surfPtr = SURF::create();
    surfPtr->compute(image, keypoints, descriptors);
};

void BRISKDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Ptr<BRISK> briskPtr = BRISK::create();
    briskPtr->compute(image, keypoints, descriptors);
};

void BRIEFDescriptor::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Ptr<BriefDescriptorExtractor> briefPtr = BriefDescriptorExtractor::create(64, false);
    briefPtr->compute(image, keypoints, descriptors);
};
