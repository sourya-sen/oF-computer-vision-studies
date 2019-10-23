#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(640, 480);
    
    gui.setup();
    gui.add(blurSize.setup("Size of Blur", 10, 0, 255));
    gui.add(medianBlurSize.setup("Size of Median Blur", 10, 0, 255));
    gui.add(gaussianBlurSize.setup("Size of Gaussian Blur", 10, 0, 255));
    gui.add(useGreyscale.setup("Use Gresycale", false));

}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    if(cam.isFrameNew()){
        cv::Mat buffer;
        
        if(useGreyscale){
            ofxCv::convertColor(cam, buffer, CV_RGB2GRAY);
        } else {
            ofxCv::copy(cam, buffer);
        }
        
        ofxCv::blur(buffer, blur, blurSize);
        ofxCv::medianBlur(buffer, medianBlur, medianBlurSize);
        ofxCv::GaussianBlur(buffer, gaussianBlur, gaussianBlurSize);
        
        blur.update();
        medianBlur.update();
        gaussianBlur.update();
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0, 640, 480);
    
    if(blur.isAllocated()) blur.draw(640, 0, 640, 480);
    if(medianBlur.isAllocated()) medianBlur.draw(0, 480, 640, 480);
    if(gaussianBlur.isAllocated()) gaussianBlur.draw(640, 480, 640, 480);
    
    ofDrawBitmapStringHighlight("Blur", 640, 15);
    ofDrawBitmapStringHighlight("Median Blur", 0, 480 + 15);
    ofDrawBitmapStringHighlight("Gaussian Blur", 640, 480 + 15);
    
    gui.draw();
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
