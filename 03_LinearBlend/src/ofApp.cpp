#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    checkerboard.load("checks.png");
    gradient.load("gradient.png");
    
    output.allocate(600, 600, OF_IMAGE_COLOR);
    
    gui.setup();
    
    gui.add(blend.setup("blend", 0.5, 0.0, 1.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float beta = 1.0 - blend;
    
    cv::Mat buffer;
    
    cv::addWeighted(ofxCv::toCv(checkerboard), blend, ofxCv::toCv(gradient), beta, 0.0, buffer);
    ofxCv::copy(buffer, output);
    output.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    output.draw(0, 0);
    
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
