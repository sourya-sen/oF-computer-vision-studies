#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    originalImage.load("Lenna.png");
    outputImage.allocate(originalImage.getWidth(), originalImage.getHeight(), OF_IMAGE_COLOR);
    
    gui.setup();
    gui.add(alpha.setup("Alpha aka Brightness", 1.5, 0.0, 3.0));
    gui.add(beta.setup("Beta aka Contrast", 50, 0.0, 100.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    outputImage = adjustBrightnessContrast(originalImage, alpha, beta);
}

//--------------------------------------------------------------
void ofApp::draw(){
    originalImage.draw(0,0);
    outputImage.draw(512, 0);
    
    ofDrawBitmapStringHighlight("Original Image", 0, 512 - 15);
    ofDrawBitmapStringHighlight("Affected Image", 512, 512 - 15);
    
    gui.draw();
}

//--------------------------------------------------------------
ofImage ofApp::adjustBrightnessContrast(ofImage _input, float _alpha, float _beta){
    ofImage output;
    
    cv::Mat image = ofxCv::toCv(_input);
    cv::Mat outputMat = cv::Mat::zeros(image.size(), image.type());
    
    for( int y = 0; y < image.rows; y++ ) {
          for( int x = 0; x < image.cols; x++ ) {
              for( int c = 0; c < image.channels(); c++ ) {
                  outputMat.at<cv::Vec3b>(y,x)[c] =
                    cv::saturate_cast<uchar>( _alpha*image.at<cv::Vec3b>(y,x)[c] + _beta );
              }
          }
      }
    
    ofxCv::copy(outputMat, output);
    output.update();
    
    return output;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
