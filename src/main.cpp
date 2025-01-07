#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include "Detector.h"
#include "Descriptor.h"
#include "Config.h"

namespace fs = std::filesystem;
using namespace std;
using namespace cv;

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
    ShiTomassi detector;
    ORBDescriptor descriptor;

    processDataset(detector, descriptor);
    return 0;
}
