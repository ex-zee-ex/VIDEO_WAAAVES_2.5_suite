/*
 re the midi biz
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */






/*thanks to ed tannenbaum for help in fixing up the framebuffer code!*/










//so what is going to be added in here
//try out the new hsb controls for the framebuffers and also test with the other channels
//how many shader runs can we do?  curious if it will be feasible to do seperate shader runs for all of the vertex displacements but i think that it would be a good goal to have in terms of making a universial function for that to reuse as much as possible!  plus a goal is to test how many shader passes i can run before noticing slowdown!





#include "ofApp.h"


#include <iostream>

float aa=0.0;
float ss=0.0;
float dd=0.0;
float ff=0.0;
float xw=1.01;
float yw=1.01;
float jj=1;
float kk=1;
float ll=.05;

float qq=1.0;
float ee=100;

float oo=1.0;
int ii=1;

float gg=0;
float hh=0;

float theta=0;

float frequency=0;

float c1=1;
float c2=1;
float c3=1;
float c4=1;
float c5=1;
float c6=1;
float c7=1;
float c8=1;

float scale1=1;
float scale2=1;

//vidmixer variables
float scale=.5;

float tt=0;

//framebuffer buffer variables  fbob-->framebufferobjectbuffer

//int framecount=0;
//const int fbob=15;


//int compScale=2;


int framedelayoffset=0;  // this is used as an index to the circular framebuffers eeettt
unsigned int framecount=0; // framecounter used to calc offset eeettt


//i got this up to 240 frames with steady on my computer, is a bit skewed extreme for real time video
//executions tho
const int fbob=10; // number of "framedelay" buffers eeettt
//int dd=fbob;
//this buffers the framebuffers from the final screen draws

//this buffers the framebuffers from the final screen draws
ofFbo pastFrames[fbob];

ofFbo pastFrames_comp[fbob];
//ofFbo is the openframeworks framebuffer object
//this line is declaring an array of framebuffer objects
//many c++ afficionados prefer a c++ vector object instead of arrays every time
//because c++ vectors are like arrays but with some handier ways to access and add and delete contents
//but on the other hand vectors can have dynamic lengths and one can really end up in some
//trouble with dynamically working with framebuffers bc its generally best pratice to allocate
//memory on the gpu for all of yr framebuffers before yr code runs, trying to mess with that on
//the fly could have some interesting appeal to a glitch art style but is not going to please
//others

void incIndex()  // call this every frame to calc the offset eeettt
{
    
    framecount++;
    framedelayoffset=framecount % fbob;
}

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(60);
   // ofDisableAlphaBlending();
    //ofSetVerticalSync(FALSE);
    
    //syphon input
    
    //mClient.set("","Black Syphon");
    mClient.setup();
    mClient.set("","Syphoner");
    
    //syphonoutput
    mainOutputSyphonServer.setName("VIDEO_WAAAVES_screen");
    
    
    
    
    //audiovisualizer biz
    /*
    loop.load("sounds/5.wav");
    
    loop.setLoop(1);
    
    loop.setVolume(1);
    
    */
    
	ofSetVerticalSync(true);
	ofBackground(0);
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
    
    /**MIDIBIX***/
    
	// print input ports to console
	midiIn.listInPorts();
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add ofApp as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
    
    /*******/
    
    
    /**shaderobiz***/
    
#ifdef TARGET_OPENGLES

#else
    if(ofIsGLProgrammableRenderer()){
    
    }else{
   
        shader_mixer.load("shadersGL2/shader_mixer");
        
        //shader_displace.load("shadersGL2/shader_displace");
    }
#endif
    
   
    
 
    fbo_draw.allocate(ofGetWidth(), ofGetHeight());
    fbo_feedback.allocate(ofGetWidth(), ofGetHeight());
        syphonTexture.allocate(ofGetWidth(), ofGetHeight());
   
    
    fbo_feedback.begin();

    ofClear(0,0,0,255);
 
       fbo_feedback.end();
    
    fbo_draw.begin();
  ofClear(0,0,0,255);
    fbo_draw.end();
    
  
    
    
    //allocate and clear the variable delay final draw buffers
    //full resolution version
    
    for(int i=0;i<fbob;i++){
        
        pastFrames[i].allocate(ofGetWidth(), ofGetHeight());
        pastFrames[i].begin();
        ofClear(0,0,0,255);
        pastFrames[i].end();
        
    
    }//endifor
    
    
    
    
    
    
    
    
    
    
   
    
    //compressed by reducing the pixels by 1/4
    /*
    for(int i=0;i<fbob;i++){
        
        pastFrames_comp[i].allocate(ofGetWidth()/2, ofGetHeight()/2);
        pastFrames_comp[i].begin();
        ofClear(0,0,0,255);
        pastFrames_comp[i].end();
        
        
    }//endifor
    */
    
    
    //camerabiz
    //if u are having low framerates u can try lower resolution grabs
    //or if its all going smooth and u want to try higher resolutions here is where to fuck with that
    
    //add some optional UI interactivity with these
    //like a incrementer that cycles thru integers mod the lenght of the device list for selecting inputs cameras
    cam1.listDevices();
    cam1.setVerbose(true);
    cam1.setDeviceID(0);
     //cam1.initGrabber(1280, 960);
   cam1.initGrabber(640, 480);
   // cam1.initGrabber(320, 240);
    
    cam2.setDeviceID(1);
      // cam2.initGrabber(1920, 1080);
    cam2.initGrabber(640, 480);
    //cam2.initGrabber(320, 240);
    
    //here is a quick and hacky way to get a prerecorded video loop involved in this setup
    //put a movie file into the data folder of this project and change the load command to the name of yr movie
    //then command f "movie loop hack" for the next step
    /*
    loopMovie.setUseTexture(true);
    loopMovie.load("movies/QU.mov");
    loopMovie.setLoopState(OF_LOOP_NORMAL);
    loopMovie.play();
    */
    
    


    
}


//--------------------------------------------------------------
void ofApp::update() {
    
    //only update if active set a test for that too
    
    
    
    
    //cam1.update();
    //cam2.update();
    
    //movie loop hack
    //uncomment this part to update the movie looping thing
    //theres another step so command f movie loop hack for the next one
    //loopMovie.update();
    
    
    
    //audiovisualizer biz
    /*
    frequencyLine0.clear();
      frequencyLine1.clear();
      frequencyLine2.clear();
      frequencyLine3.clear();
    float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.99f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        int y=fftSmoothed[i] * ofGetHeight()/8*c2;
        int x=ofMap(i,0,nBandsToGet,0,ofGetWidth()/2);
        frequencyLine0.addVertex(x,y);
        frequencyLine1.addVertex(x,-y);
        frequencyLine2.addVertex(-x,-y);
        frequencyLine3.addVertex(-x,y);
        
    }
     
    
    */
    
    
   //  plane.set(ofGetWidth(), ofGetHeight(), ofGetWidth()/4, ofGetHeight()/4, OF_PRIMITIVE_TRIANGLE_STRIP);

}

//--------------------------------------------------------------
void ofApp::draw() {
    
    
/*midimessagesbiz**/
    
    
    //ofTranslate(0,0,-100);
	for(unsigned int i = 0; i < midiMessages.size(); ++i) {

		ofxMidiMessage &message = midiMessages[i];
		int x = 10;
		int y = i*40 + 40;
	
		// draw the last recieved message contents to the screen,
		// this doesn't print all the data from every status type
		// but you should get the general idea
		//stringstream text;
		//text << ofxMidiMessage::getStatusString(message.status);
		//while(text.str().length() < 16) { // pad status width
		//	text << " ";
		//}

		ofSetColor(127);
		if(message.status < MIDI_SYSEX) {
			//text << "chan: " << message.channel;
            if(message.status == MIDI_CONTROL_CHANGE) {
                
                //How to Midi Map
                //uncomment the line that says cout<<message control etc
                //run the code and look down in the console
                //when u move a knob on yr controller keep track of the number that shows up
                //that is the cc value of the knob
                //then go down to the part labled 'MIDIMAPZONE'
                //and change the numbers for each if message.control== statement to the values
                //on yr controller
                
                 // cout << "message.control"<< message.control<< endl;
                 // cout << "message.value"<< message.value<< endl;
                
                
                
                //MIDIMAPZONE
                //these are all set to output bipolor controls at this moment (ranging from -1.0 to 1.0)
                //if u uncomment the second line on each of these if statements that will switch thems to unipolor
                //controls (ranging from 0.0to 1.0) if  you prefer
                //then find the variable that youd like to control down in CAVARIABLEZONES or MIXERVARIBLEZONES
                //and substitute c1,c2, ..cn whichever control knob u wish the map
                if(message.control==20){
                    c1=(message.value-63.0)/63.0;
                    //  c1=(message.value)/127.00;
                    
                }
                
                if(message.control==21){
                    c2=(message.value-63.0)/63.0;
                    //  c2=(message.value)/127.00;
                    
                }
                
                if(message.control==22){
                    c3=(message.value-63.0)/63.00;
                    //  c3=(message.value)/127.00;
                }
                
                if(message.control==23){
                     c4=(message.value-63.0)/63.00;
                   // c4=(message.value)/127.00;
                   
                }
                
                if(message.control==24){
                     c5=(message.value-63.0)/63.00;
                  //  c5=(message.value)/127.00;
                  
                }
                if(message.control==25){
                    c6=(message.value-63.0)/63.0;
                    //  c4=(message.value)/127.00;
                }
                
                
                if(message.control==26){
                    c7=(message.value-63.0)/63.0;
                    //  c4=(message.value)/127.00;
                }
                if(message.control==27){
                     c8=(message.value-63.0)/63.00;
                  //  c8=(message.value)/127.0;
                   
                }
                
              
            }
            else if(message.status == MIDI_PITCH_BEND) {
                //text << "\tval: " << message.value;
			
			}
			else {
				//text << "\tpitch: " << message.pitch;
				
                
               // int N= message.pitch;
               // int FN=N-69;
                // frequency=pow(2.0,FN/12.0)*440;
               

				
			}
			
		}//

	
	}
   /******* endmidimessagesbiz*********/
   
 
    
    /***shaderbix**/
    
    
    //first draw the syphon input to a framebuffer to have it available as a texture to send to the mixer
    syphonTexture.begin();
    //fix some auto scaling stuffs in general
  //  int syphonscale=mClient.getWidth()/cam1.getWidth();
    
    mClient.draw(0,0,scale1*mClient.getWidth(),scale2*mClient.getHeight());
    
    syphonTexture.end();
    
 
   // float blurx =c7;
    //float blury = c6;
    
    
    
    
    
    
    
    ///draw to the buffers
    
    
   
    
    
    
    
    fbo_draw.begin();
    
    shader_mixer.begin();
   
    
     shader_mixer.setUniform1f("width", ofGetWidth());
    
    shader_mixer.setUniform1f("height", ofGetHeight());

     shader_mixer.setUniform1f("scale1", scale);
   
    
    //this is the variables that affect pixel displacement
    ofVec4f bright_wxyz;
    bright_wxyz.set(gui->x_displace,gui->y_displace,gui->z_displace,gui->w_displace);
    
    // bright_xyz.set(qq,ee,tt);
    shader_mixer.setUniform4f("bright_xyz",bright_wxyz);
    
    
    //fb0
    ofVec3f hsb_x;
    hsb_x.set(gui->fb0_hue/10,gui->fb0_saturation/10,gui->fb0_bright/10);
   // hsb_x.set(1,1,1);
    shader_mixer.setUniform3f("fb0_hsb_x",hsb_x);
    
    ofVec3f hue_x;
    hue_x.set(gui->fb0_huex_mod/10,gui->fb0_huex_offset/10,gui->fb0_huex_lfo/10);
    shader_mixer.setUniform3f("fb0_hue_x",hue_x);
    
    ofVec3f fb_rescale;
    fb_rescale.set(gui->fb0_x_displace,gui->fb0_y_displace,gui->fb0_z_displace/100);
    shader_mixer.setUniform3f("fb0_rescale",fb_rescale);
    
    ofVec3f fb_modswitch;
    fb_modswitch.set(gui->fb0_hue_invert,gui->fb0_saturation_invert,gui->fb0_bright_invert);
    
    //fb_modswitch.set(1.0,1.0,1.0);
    shader_mixer.setUniform3f("fb0_modswitch",fb_modswitch);
    
  //fb1
    hsb_x.set(gui->fb1_hue/10,gui->fb1_saturation/10,gui->fb1_bright/10);
    // hsb_x.set(1,1,1);
    shader_mixer.setUniform3f("fb1_hsb_x",hsb_x);
    
    
    hue_x.set(gui->fb1_huex_mod/10,gui->fb1_huex_offset/10,gui->fb1_huex_lfo/10);
    shader_mixer.setUniform3f("fb1_hue_x",hue_x);
    

    fb_rescale.set(gui->fb1_x_displace,gui->fb1_y_displace,gui->fb1_z_displace/100);
    shader_mixer.setUniform3f("fb1_rescale",fb_rescale);
    
    
   // ofVec3f fb_modswitch;
    fb_modswitch.set(gui->fb1_hue_invert,gui->fb1_saturation_invert,gui->fb1_bright_invert);
    
    //fb_modswitch.set(1.0,1.0,1.0);
    shader_mixer.setUniform3f("fb1_modswitch",fb_modswitch);
    
    //fb2
    hsb_x.set(gui->fb2_hue/10,gui->fb2_saturation/10,gui->fb2_bright/10);
    
    //hsb_x.set(1,1,2);
    shader_mixer.setUniform3f("fb2_hsb_x",hsb_x);
    
    
    hue_x.set(gui->fb2_huex_mod/10,gui->fb2_huex_offset/10,gui->fb2_huex_lfo/10);
    shader_mixer.setUniform3f("fb2_hue_x",hue_x);
    
    
    fb_rescale.set(gui->fb2_x_displace,gui->fb2_y_displace,gui->fb2_z_displace/100);
    shader_mixer.setUniform3f("fb2_rescale",fb_rescale);
    
    fb_modswitch.set(gui->fb2_hue_invert,gui->fb2_saturation_invert,gui->fb2_bright_invert);
    
    //fb_modswitch.set(1.0,1.0,1.0);
    shader_mixer.setUniform3f("fb2_modswitch",fb_modswitch);

    shader_mixer.setUniform1f("ps",ee);
    
    
    //here is where controls from the gui get shunted
    
    //for now channel 1 and 2 can only b cam1 or cam2 input
    shader_mixer.setUniform1i("channel1", gui->channel1);
    shader_mixer.setUniform1i("channel2", gui->channel2);
    shader_mixer.setUniform1i("mix1", gui->mix1);
    shader_mixer.setUniform1i("mix2", gui->mix2);
    
    
    //mix1 controls from the gui
    shader_mixer.setUniform1f("mix1blend1", gui->mix1blend1);
    
  

    shader_mixer.setUniform1f("mix1keythresh", gui->mix1lumakeythresh);
    shader_mixer.setUniform1f("mix1keybright",gui->mix1lumakeyvalue);
    
    
    
    
    
    
    
    
    //h and v flip controls
    //no shader_mixer.setUniform1i("ch1_h_mirror", gui->ch1_h_mirror);
  
    
    //channel1 controls from the gui
    //vector these up
    ///asuming these will all stay
    
    shader_mixer.setUniform1f("channel1bright_x", gui->channel1bright);
    shader_mixer.setUniform1f("channel1hue_x", gui->channel1hue);
    shader_mixer.setUniform1f("channel1saturation_x", gui->channel1saturation);
    
    
    
    shader_mixer.setUniform1i("channel1satwrap", gui->channel1satwrap);
    shader_mixer.setUniform1i("channel1brightwrap", gui->channel1brightwrap);
    
    
    shader_mixer.setUniform1i("ch1hue_powmaptoggle", gui->ch1hue_powmaptoggle);
    shader_mixer.setUniform1i("ch1sat_powmaptoggle", gui->ch1sat_powmaptoggle);
    shader_mixer.setUniform1i("ch1bright_powmaptoggle", gui->ch1bright_powmaptoggle);
    
    shader_mixer.setUniform1i("ch1hue_inverttoggle", gui->ch1hue_inverttoggle);
    shader_mixer.setUniform1i("ch1sat_inverttoggle", gui->ch1sat_inverttoggle);
    shader_mixer.setUniform1i("ch1bright_inverttoggle", gui->ch1bright_inverttoggle);

    
    
    shader_mixer.setUniform1f("channel1bright_powmap", gui->channel1brightpowmap);
    shader_mixer.setUniform1f("channel1hue_powmap", gui->channel1huepowmap);
    shader_mixer.setUniform1f("channel1sat_powmap", gui->channel1saturationpowmap);
    
  
    
    //channel2 controls from the gui
    shader_mixer.setUniform1f("channel2bright_x", gui->channel2bright);
    shader_mixer.setUniform1f("channel2hue_x", gui->channel2hue);
    shader_mixer.setUniform1f("channel2saturation_x", gui->channel2saturation);
    
    
    
    shader_mixer.setUniform1i("channel2satwrap", gui->channel2satwrap);
    shader_mixer.setUniform1i("channel2brightwrap", gui->channel2brightwrap);
    
    
    shader_mixer.setUniform1i("ch2hue_powmaptoggle", gui->ch2hue_powmaptoggle);
    shader_mixer.setUniform1i("ch2sat_powmaptoggle", gui->ch2sat_powmaptoggle);
    shader_mixer.setUniform1i("ch2bright_powmaptoggle", gui->ch2bright_powmaptoggle);
    
    shader_mixer.setUniform1i("ch2hue_inverttoggle", gui->ch2hue_inverttoggle);
    shader_mixer.setUniform1i("ch2sat_inverttoggle", gui->ch2sat_inverttoggle);
    shader_mixer.setUniform1i("ch2bright_inverttoggle", gui->ch2bright_inverttoggle);
    
    shader_mixer.setUniform1f("channel2bright_powmap", gui->channel2brightpowmap);
    shader_mixer.setUniform1f("channel2hue_powmap", gui->channel2huepowmap);
    shader_mixer.setUniform1f("channel2sat_powmap", gui->channel2saturationpowmap);
    
    
    
    
  
    
    
    
    
    
    
   
    
    shader_mixer.setUniform2f("cam1dimensions",ofVec2f(cam1.getWidth(),cam1.getHeight()));
    shader_mixer.setUniform2f("cam2dimensions",ofVec2f(cam2.getWidth(),cam2.getHeight()));
    
    
    
    
    
    shader_mixer.setUniform1f("fb0blend", gui->fb0blend);
    shader_mixer.setUniform1f("fb0lumakeyvalue", gui->fb0lumakeyvalue);
    shader_mixer.setUniform1f("fb0lumakeythresh", gui->fb0lumakeythresh);
    shader_mixer.setUniform1i("fb0mix", gui->FBmix);
    
    shader_mixer.setUniform1f("fb1blend", gui->fb1blend);
    shader_mixer.setUniform1f("fb1lumakeyvalue", gui->fb1lumakeyvalue);
    shader_mixer.setUniform1f("fb1lumakeythresh", gui->fb1lumakeythresh);
    shader_mixer.setUniform1i("fb1mix", gui->FB1mix);
    
    
    shader_mixer.setUniform1f("fb2blend", gui->fb2blend);
    shader_mixer.setUniform1f("fb2lumakeyvalue", gui->fb2lumakeyvalue);
    shader_mixer.setUniform1f("fb2lumakeythresh", gui->fb2lumakeythresh);
    shader_mixer.setUniform1i("fb2mix", gui->FB2mix);
    
    
   
    
    
    
    
    
    
    
    
    //--------------------------send the textures
    
    
    //this gets bound to tex0 when u do this way
    //for some reason i can't just erase this and move on
    //so replace this with a useful texture at some point
    fbo_feedback.draw(0,0);
    //for some reason i get weird glitches in acessing textures in gl2 when i don't bind a texture like this before sending the others in more formally by setUniformTexture so if you understand why that is happening please let me know
   
    
    //set a conditional statement of which fbo
    shader_mixer.setUniformTexture("syphon",syphonTexture.getTexture(),1);
    shader_mixer.setUniformTexture("cam1",cam1.getTexture(),2);
    shader_mixer.setUniformTexture("cam2",cam2.getTexture(),3);
    
    
    int delay0=gui->fb0delayamnt;
    int delay1=gui->fb1delayamnt;
    int delay2=gui->fb2delayamnt;
    
 
    
    //i think there is some need to dynamically scale both x and y based on ratios, fix this sooner than later
    shader_mixer.setUniform1f("compScalex",1);
    shader_mixer.setUniform1f("compScaley",1);
  //  shader_mixer.setUniformTexture("fb0",pastFrames[(abs(framedelayoffset-fbob-delay0))%fbob].getTexture(),4);
    
     shader_mixer.setUniformTexture("fb0",pastFrames[(abs(framedelayoffset-fbob-delay0)-1)%fbob].getTexture(),4);
    shader_mixer.setUniformTexture("fb1",pastFrames[(abs(framedelayoffset-fbob-delay1)-1)%fbob].getTexture(),5);
    shader_mixer.setUniformTexture("fb2",pastFrames[(abs(framedelayoffset-fbob-delay2)-1)%fbob].getTexture(),6);
    
  
    
    //testing syphon as a texture sent into a channel
    //currently replacing cam2
   
    
 
    
    
    
       
    
  
    
    
   
    
   
    shader_mixer.setUniform1f("qq",qq);
    
    shader_mixer.end();
    
	
    //this bit is for just testing stuff with a pretty little rotating square
    //you can just put whatever graphical code you want in this section and it will draw over everything
	/*
    ofSetColor(127+127*(sin(ofGetElapsedTimef())),127+127*(cos(ofGetElapsedTimef()/7)),127-127*(sin(ofGetElapsedTimef()/19)),255);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateZRad(ofGetElapsedTimef()/5);
    ofRotateYRad(ofGetElapsedTimef()/13);
    ofRotateXRad(ofGetElapsedTimef()/11);
    ofDrawRectangle(0,0, ofGetWidth()/4,ofGetHeight()/4);
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    */
    
    
    
    //secret visualizer fucntionality hidden in the code
    /*
    ofColor color;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    int limit=32;
    for(int i=0;i<limit;i++){
        int over=i*theta*c1;
        color.setHsb(fmod((c4*(255+over)),255),fmod((c5*(255+over)),255),fmod((c6*(255+over)),255));
        ofSetColor(color);
        ofPushMatrix();
        ofTranslate(over,over);
        frequencyLine0.draw();
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(over,-over);
        frequencyLine1.draw();
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(-over,-over);
        frequencyLine2.draw();
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(-over,over);
        frequencyLine3.draw();
        ofPopMatrix();
    }
    ofPopMatrix();
    */
    fbo_draw.end();
    
    //----------------------------------------------------------
    
    
    /*this part gets drawn to screen*/
    ofSetColor(ofColor::white);
   
    ofPushMatrix();
    //add seperate switchs for this and fbo
    ofTranslate(ofGetWidth()/2.0,ofGetHeight()/2.0);
    
    ofRotateZRad(oo*TWO_PI/ii);
    ofTranslate(0,0,0);
    fbo_draw.draw(-ofGetWidth()/2.0,-ofGetHeight()/2.0);
    ofPopMatrix();
    //audiovisualizer biz
    
    theta+=.001*(1+c3);
    
   
     
     
    
 
 
  
    
    
    
   

   
    
    
    
  
    
    //feed the previous frame into position 0
    
    //feed the previous frame into position 0 (index0)
    
    pastFrames[abs(fbob-framedelayoffset)-1].begin(); //eeettt
    
    
    ofPushMatrix();
    //recenter the coordinates so 0,0 is at the center of the screen
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
    //  ofRotateZRad(.01);
    ofTranslate(ff,gg,hh);
    ofRotateYRad(ss);
    ofRotateXRad(aa);
    ofRotateZRad(dd);
    //control translating the z component of the delay with a and z
   // ofTranslate(0,0,zz);
    
    fbo_draw.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    //cam1.draw(-ofGetWidth()/2,-ofGetHeight()/2,2*cam1.getWidth(),2*cam1.getHeight());
    ofPopMatrix();
    
    
    pastFrames[abs(fbob-framedelayoffset)-1].end(); //eeettt
    //-----____---____---__-__---____-----_--_-
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    //keep framecount from constantly incrementing and maintain the rhythm of the delays
    
   // if(framecount>=fbob){framecount=0;}
  
    
    int ofappchannel1= gui->channel1;
    
    
 
    
    ofSetHexColor(0xFFFFFF);
  //  ofDrawBitmapString(" delayhead: "+ofToString(delayhead),10, ofGetHeight()-5 );
   
    
    
    
    //this is just to test syphon input to make sure it is arriving
    //mClient.draw(0, 0);
    
    
    
    //add a switch for this
    if(gui->syphonOutput==1){
    mainOutputSyphonServer.publishScreen();
    }
    
    incIndex(); // increment framecount and framedelayoffset eeettt
}


 
 /****************************************************/



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='3'){
        aa=ss=dd=ff=gg=hh=0;
    }
    
    if(key=='2'){
          loop.play();
    }
    
 
    if(key=='1'){
        for(int i=0;i<fbob;i++){
            pastFrames[i].begin();
        
            ofClear(0,0,0,255);
        
            pastFrames[i].end();
        }
        
        fbo_draw.begin();
        ofClear(0,0,0,255);
        fbo_draw.end();
    }
    //if(key=='q'){sw1==0;}
    
    if(key=='a'){aa+=0.0001;}
    if(key=='z'){aa-=0.0001;}
    if(key=='s'){ss+=0.0001;}
    if(key=='x'){ss-=0.0001;}
    
    if(key=='d'){dd+=0.0001;}
    if(key=='c'){dd-=0.0001;}
    
    if(key=='f'){ff+=0.0001;}
    if(key=='v'){ff-=0.0001;}
    
    if(key=='g'){gg+=0.0001;}
    if(key=='b'){gg-=0.0001;}
    if(key=='h'){hh+=0.01;}
    if(key=='n'){hh-=0.01;}
    
    
    if(key=='j'){jj+=0.1;}
    if(key=='m'){jj-=0.1;}
    if(key=='k'){kk+=0.1;}
    if(key==','){kk-=0.1;}
    
    if(key=='l'){scale+=0.01;}
    if(key=='.'){scale-=0.01;}
    
    if(key==';'){scale1+=0.01;}
    if(key=='/'){scale1-=0.01;}
    
    if(key=='['){scale2+=0.01;}
    if(key==']'){scale2-=0.01;}
    
    if(key=='q'){qq+=0.001;cout << "qq"<<qq<< endl;}
    if(key=='w'){qq-=0.001;cout << "qq"<<qq<< endl;}
    if(key=='e'){ee+=1;cout << "ee"<<ee<< endl;}
    if(key=='r'){ee-=1;cout << "ee"<<ee<< endl;}
    
    
    if(key=='u'){ii+=1;}
    if(key=='i'){ii-=1;}
    if(key=='o'){oo+=.1;}
    if(key=='p'){oo-=.1;}
    
    if(key=='t'){tt+=.01;}
    if(key=='y'){tt-=.01;}


}

/************************/
//--------------------------------------------------------------
void ofApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {

	// add the latest message to the message queue
	midiMessages.push_back(msg);

	// remove any old messages if we have too many
	while(midiMessages.size() > maxMessages) {
		midiMessages.erase(midiMessages.begin());
	}
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
   
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased() {
}
