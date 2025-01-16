#include "Descriptor.h"

// using namespace cv;
#include "opencv2/xfeatures2d.hpp"
#include <opencv2/objdetect.hpp>
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

void HOG::compute(const Mat &image, vector<KeyPoint> &keypoints, Mat &descriptors) {
    Mat gray;

    // Converte a imagem para escala de cinza
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Para armazenar todos os descritores como um único Mat
    vector<vector<float>> allDescriptors;

    // Criação do HOGDescriptor
    HOGDescriptor hog(
        Size(64, 128), // Tamanho da janela de detecção
        Size(16, 16),  // Tamanho do bloco
        Size(8, 8),    // Passo entre blocos
        Size(8, 8),    // Tamanho da célula
        9              // Número de bins do histograma
    );

    // Converte KeyPoints para uma lista de retângulos (necessário para o HOG)
    for (const auto& kp : keypoints) {
        Point pt = kp.pt; // Coordenadas do ponto
        int roiWidth = 64;
        int roiHeight = 128;

        // Ajustar ROI para que ele esteja dentro da imagem
        int startX = max(0, pt.x - roiWidth / 2);
        int startY = max(0, pt.y - roiHeight / 2);
        int endX = min(startX + roiWidth, gray.cols);
        int endY = min(startY + roiHeight, gray.rows);

        Rect roi(startX, startY, endX - startX, endY - startY);

        // Ignora ROIs que não têm o tamanho esperado
        if (roi.width != roiWidth || roi.height != roiHeight) {
            continue;
        }

        Mat subImage = gray(roi);
        vector<float> descriptor; // Vetor para armazenar descritores
        hog.compute(subImage, descriptor); // Calcula os descritores para o ROI
        allDescriptors.push_back(descriptor); // Adiciona os descritores à lista geral
    }

    // Converter os descritores para Mat
    if (!allDescriptors.empty()) {
        int descriptorSize = allDescriptors[0].size(); // Tamanho de cada descritor
        descriptors.create((int)allDescriptors.size(), descriptorSize, CV_32F);

        for (size_t i = 0; i < allDescriptors.size(); i++) {
            memcpy(descriptors.ptr<float>((int)i), allDescriptors[i].data(), descriptorSize * sizeof(float));
        }
    } else {
        descriptors.release(); // Libera o Mat se nenhum descritor foi calculado
    }
}


