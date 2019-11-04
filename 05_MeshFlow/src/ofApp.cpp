#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.initGrabber(640, 480);
    texture.load("meshTex.png");
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    gui.setup();
    gui.add(flowWindowSize.set("Flow Window Size", 8, 1, 20));
    gui.add(distortionStrength.set("Distortion Strength", 2.0f, 1.0f, 10.0f));
    
    stepSize = 4;
    xSteps = cam.getWidth()/stepSize;
    ySteps = cam.getHeight()/stepSize;
    
    for(int y = 0; y < ySteps; y++){
        for(int x = 0; x < xSteps; x++){
            mesh.addVertex(glm::vec3(x * stepSize, y * stepSize, 0));
            mesh.addTexCoord(glm::vec2(x * stepSize, y * stepSize));
        }
    }
    
    for(int y = 0; y < ySteps - 1; y++){
        for(int x = 0; x < xSteps - 1; x++){
            int nw = y * xSteps + x;
            int ne = nw + 1;
            int sw = nw + xSteps;
            int se = sw + 1;
            mesh.addIndex(nw);
            mesh.addIndex(ne);
            mesh.addIndex(se);
            mesh.addIndex(nw);
            mesh.addIndex(se);
            mesh.addIndex(sw);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    
    if(cam.isFrameNew()){
        flow.setWindowSize(flowWindowSize);
        flow.calcOpticalFlow(cam);
        int i = 0;
        for(int y = 1; y + 1 < ySteps; y++) {
            for(int x = 1; x + 1 < xSteps; x++) {
                int i = y * xSteps + x;
                glm::vec3 position(x * stepSize, y * stepSize, 0.0);
                ofRectangle area(position - glm::vec3(stepSize, stepSize, 0.0) / 2, stepSize, stepSize);
                auto offset = flow.getAverageFlowInRegion(area);
                mesh.setVertex(i, position + float(distortionStrength) * offset);
                i++;
            }
        }
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.draw(0, 0);
    flow.draw(0, 0);
    
    ofPushMatrix();
    ofTranslate(640, 0);
    texture.bind();
    mesh.draw();
    texture.unbind();
    ofPopMatrix();
    
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
