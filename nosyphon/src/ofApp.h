/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "GuiApp.h"


class ofApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
    
    void midibiz();
    
    float lfo(float amp, float rate,int shape);
	
    //-----------guibiz
    shared_ptr<GuiApp> gui;
    
    
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	ofxMidiIn midiIn;
	std::vector<ofxMidiMessage> midiMessages;
	std::size_t maxMessages = 10; //< max number of messages to keep track of
    
    ofShader shader_mixer;
    ofShader shader_blur;
    ofShader shader_sharpen;
    
   
    

 
    ofFbo fbo_draw;
    ofFbo fbo_feedback;
    ofFbo fbo_blur;
    
    
    ofFbo syphonTexture;
  
   // ofVec2f sineWave(int i,float rate,float amp);

   
    
    ofVideoGrabber cam1;
    
    ofVideoGrabber cam2;

    

    
    
   
    
};
