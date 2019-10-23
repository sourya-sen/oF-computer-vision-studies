#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    video.load("handsTrees.mov");
    video.setLoopState(OF_LOOP_NONE);
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    video.update();
    
    if(video.isFrameNew()){
        image.setFromPixels(video.getPixels());
        image.update();
        
        if(gray.isAllocated()){
            ofxCv::copy(gray, grayPrev);
            grayPrev.update();
        }
        
        ofxCv::convertColor(image, gray, CV_RGB2GRAY);
        gray.update();
        
        if(gray.isAllocated()){
            ofxCv::absdiff(gray, grayPrev, diff);
            diff.update();
        }
        
        if(diff.isAllocated()){
            ofxCv::copy(diff, diffAmplified);
            cv::Mat temp = ofxCv::toCv(diffAmplified);
            temp *= 5.0;
            diffAmplified.update();
        }
        
        if(diffAmplified.isAllocated() && !diffBuffer.isAllocated()){
            ofxCv::copy(diffAmplified, diffBuffer);
            diffBuffer.update();
        } else {
            cv::Mat temp = ofxCv::toCv(diffBuffer);
            temp *= 0.75; //dampen
            
            cv::Mat otherTemp;
            ofxCv::copy(temp, otherTemp);
            
            otherTemp += ofxCv::toCv(diffAmplified); //add in current amplified difference
            ofxCv::toOf(otherTemp, diffBuffer);
            diffBuffer.update();
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(gray.isAllocated()) gray.draw(0, 0, 640, 480);
    if(diff.isAllocated()) diff.draw(640, 0, 640, 480);
    if(diffAmplified.isAllocated()) diffAmplified.draw(0, 480, 640, 480);
//    if(diffBuffer.isAllocated()) diffBuffer.draw(640, 480, 640, 480);
    
    
    if(diffBuffer.isAllocated()){
        ofPixels pix = diffBuffer.getPixels();
        
        for(int x = 0; x < pix.getWidth(); x++){
            for(int y = 0; y < pix.getHeight(); y++){
                auto c = pix.getColor(x, y);
                float b = c.getBrightness(); //Returns the brightness, between 0-255
                
                int xOffset = 640;
                int yOffset = 480;
                
                float brightnessValue;
                
                if(b > 250){
                    brightnessValue = 0;
                } else {
                    brightnessValue = 255;
                }
                
                ofSetColor(brightnessValue);
                ofDrawCircle(xOffset + x, yOffset + y, 2);
            }
        }
    }
    
    ofDrawBitmapStringHighlight("Converted Gray Image", 0, 15);
    ofDrawBitmapStringHighlight("Absolute Difference with Previous Frame", 640, 15);
    ofDrawBitmapStringHighlight("Amplified Difference", 0, 480 + 15);
    ofDrawBitmapStringHighlight("Visualising Difference Buffer", 640, 480 + 15);
    
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
