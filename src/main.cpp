#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#ifdef HAVE_OPENCV_XFEATURES2D
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/xfeatures2d.hpp"

#include "Detector.h"
#include "Descriptor.h"
#include "Config.h"

using std::cout;
using std::endl;

namespace fs = std::filesystem;
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

void processDataset(Detector &detector, Descriptor &descriptor) {
    vector<KeyPoint> keypoints;
    Mat descriptors, gray, outputImage;
    Scalar keyPointsColor;

    int count = 0;
    fs::create_directories(Config::outputFolder);

    for (const auto &entry : fs::directory_iterator(Config::imagesFolderPath)) {
        if (count >= Config::limit) break;

        string path = entry.path().string();
        Mat image = imread(path, IMREAD_COLOR);

        if (image.empty()) {
            cout << "Erro ao carregar a imagem: " << path << endl;
            continue;
        }

        // Detect keypoints
        detector.detect(image, keypoints);

        // Generate Descriptors
        descriptor.compute(image, keypoints, descriptors);

        // In case of generating images in grayscale
        if(Config::useGrayScale){
            cvtColor(image, gray, COLOR_BGR2GRAY);
            image = gray;
        }

        // Draw keypoints
        if (Config::keyPointsColor == "red") {
            keyPointsColor = Scalar(0, 0, 255);
        }
        if (Config::keyPointsColor == "green") {
            keyPointsColor = Scalar(0, 255, 0);
        }

        drawKeypoints(image, keypoints, outputImage, keyPointsColor, DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

        // Save images with keypoints
        string outputPath = Config::outputFolder + "/" + entry.path().filename().string();
        imwrite(outputPath, outputImage);

        count++;
    }

    cout << "Processamento concluído. " << count << " imagens processadas." << endl;
}

int main() {
    // SIFTDetector detector;
    // ShiTomassi detector;
    SURFDetect detector;
    cout << "Cheguei aqui";
    // ORBDescriptor descriptor;
    SURFDescriptor descriptor;

    processDataset(detector, descriptor);

    return 0;
}

#else
int main()
{
    std::cout << "This tutorial code needs the xfeatures2d contrib module to be run." << std::endl;
    return 0;
}
#endif