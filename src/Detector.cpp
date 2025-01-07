#include "Detector.h"
#include "Config.h"

void HarrisDetector::detect(const Mat &image, vector<KeyPoint> &keypoints) {
    Mat gray, harrisCorners, harrisNorm;

    cvtColor(image, gray, COLOR_BGR2GRAY);
    cornerHarris(gray, harrisCorners, 3, 3, 0.04);
    normalize(harrisCorners, harrisNorm, 0, 255, NORM_MINMAX, CV_32FC1);

    keypoints.clear();
    for (int y = 0; y < harrisNorm.rows; y++) {
        for (int x = 0; x < harrisNorm.cols; x++) {
            if ((int)harrisNorm.at<float>(y, x) > Config::harrisThreshold) {
                keypoints.emplace_back(Point2f(x, y), 1);
            }
        }
    }
}

// ShiTomassi =  É um melhorador do detector de harris
void ShiTomassi::detect(const Mat &image, vector<KeyPoint> &keypoints) {
    Mat gray;
    
    // Converte a imagem para escala de cinza
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Detecta os cantos
    vector<Point2f> corners;
    goodFeaturesToTrack(
        gray,
        corners,
        100,     // Número máximo de cantos
        0.01,    // Qualidade mínima
        10,      // Distância mínima entre cantos
        Mat(),   // Nenhuma máscara
        3,       // Tamanho da janela
        false,   // Parâmetro de Harris
        0.04     
    );

    // Converte Point2f para KeyPoint
    keypoints.clear();
    for (const auto &corner : corners) {
        keypoints.emplace_back(corner, 1.0f);  // Raio padrão 1.0f
    }
}
