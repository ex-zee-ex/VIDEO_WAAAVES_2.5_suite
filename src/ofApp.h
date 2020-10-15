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
#include "ofxNDISender.h"
#include "ofxNDISendStream.h"

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
    
    void NDI_reciever_setup(string reciever_name);
    void NDI_reciever_update();
    
    ofxNDIReceiver ndi_receiver_;
    ofxNDIRecvVideoFrameSync ndi_video_;
    ofPixels ndi_pixels;
    
    ofFbo ndi_fbo;
    
    void NDI_sender_setup(string app_name);
    void NDI_sender_update();
    
    ofxNDISender sender_;
    ofxNDISendVideo ndi_send_video_;
    
    void tetrahedron_setup();
    
    float lfo(float amp, float rate,int shape);
    
    void lfo_update();
	
   
    
    
    void hypercube_draw();
    
    float hypercube_theta=0;
    float hypercube_phi=0;
    float hypercube_r=0.0;
    
    float hypercube_x[8];
    float hypercube_y[8];
    float hypercube_z[8];
    
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
