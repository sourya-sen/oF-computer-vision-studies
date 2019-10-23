#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(640, 480);
    thresholdValue = 0;
    
//    threshold.allocate(cam.getWidth(), cam.getHeight(), OF_IMAGE_GRAYSCALE);
//    autoThreshold.allocate(cam.getWidth(), cam.getHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    cam.update();
    
    if(cam.isFrameNew()){
        ofxCv::convertColor(cam, greyscale, CV_RGB2GRAY);
        
        greyscale.update();
        
        ofxCv::copy(greyscale, threshold);
        ofxCv::copy(greyscale, autoThreshold);
        
//        ofxCv::convertColor(cam, threshold, CV_RGB2GRAY);
//        ofxCv::convertColor(cam, autoThreshold, CV_RGB2GRAY);
        
        ofxCv::autothreshold(autoThreshold);
        ofxCv::threshold(threshold, thresholdValue);
        
        threshold.update();
        autoThreshold.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.draw(0, 0, 640, 480);
    
    if(greyscale.isAllocated()) greyscale.draw(640, 0, 640, 480);
    if(threshold.isAllocated()) threshold.draw(0, 480, 640, 480);
    if(autoThreshold.isAllocated()) autoThreshold.draw(640, 480, 640, 480);
    
    ofDrawBitmapStringHighlight("Raw Camera Feed", 0, 15);
    ofDrawBitmapStringHighlight("Greyscale", 640, 15);
    ofDrawBitmapStringHighlight("Threshold with custom value of: " + ofToString(thresholdValue), 0, 480 + 15);
    ofDrawBitmapStringHighlight("Autothreshold", 640, 480 + 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case OF_KEY_UP:
            thresholdValue++;
            break;
            
        case OF_KEY_DOWN:
            thresholdValue--;
            break;
            
        default:
            break;
    }

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
