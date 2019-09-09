#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
  
    ofxDatGui* guisignal;
    ofxDatGui* guithings;
    
    ofxDatGui* guiFBops;
    
    
    //syphon output switch
    ofxDatGuiToggle* syphonOutputtoggle;
    bool syphonOutput=0;
    


    
    
    //channel1 hsb control strip
    ofxDatGuiSlider* channel1brightslider;
    ofxDatGuiSlider* channel1hueslider;
    ofxDatGuiSlider* channel1saturationslider;
    
    ofxDatGuiSlider* channel1brightpowmapslider;
    ofxDatGuiSlider* channel1huepowmapslider;
    ofxDatGuiSlider* channel1saturationpowmapslider;

    
 
    ofxDatGuiButton* channel1satwraptoggle;
    ofxDatGuiButton* channel1brightwraptoggle;
    
    ofxDatGuiButton* channel1huepowmaptoggle;
    ofxDatGuiButton* channel1satpowmaptoggle;
    ofxDatGuiButton* channel1brightpowmaptoggle;
    
    ofxDatGuiButton* channel1hueinverttoggle;
    ofxDatGuiButton* channel1satinverttoggle;
    ofxDatGuiButton* channel1brightinverttoggle;

    
    
    //channel2 hsb control strip
    ofxDatGuiSlider* channel2brightslider;
    ofxDatGuiSlider* channel2hueslider;
    ofxDatGuiSlider* channel2saturationslider;
    
    ofxDatGuiSlider* channel2brightpowmapslider;
    ofxDatGuiSlider* channel2huepowmapslider;
    ofxDatGuiSlider* channel2saturationpowmapslider;
    
    
    
    ofxDatGuiButton* channel2satwraptoggle;
    ofxDatGuiButton* channel2brightwraptoggle;
    
    ofxDatGuiButton* channel2huepowmaptoggle;
    ofxDatGuiButton* channel2satpowmaptoggle;
    ofxDatGuiButton* channel2brightpowmaptoggle;
    
   
    
    ofxDatGuiButton* channel2hueinverttoggle;
    ofxDatGuiButton* channel2satinverttoggle;
    ofxDatGuiButton* channel2brightinverttoggle;
    
    
   


    
    //mix1 control strip
    ofxDatGuiSlider* blendamountslider;
    ofxDatGuiSlider* mix1brightkeyamountslider;
    ofxDatGuiSlider* mix1brightkeythreshslider;
    
    //CAmix control strip
  
    ofxDatGuiSlider* CAmixbrightkeyamountslider;
    ofxDatGuiSlider* CAmixbrightkeythreshslider;
    ofxDatGuiSlider* CAmixslider;

    
    ofxDatGuiDropdown* ddchannel1;
    ofxDatGuiDropdown* ddchannel2;
    ofxDatGuiDropdown* ddmix1;
    ofxDatGuiDropdown* ddmix2;
    
    ofxDatGuiDropdown* CAddmix;
    
    //FBmixcontrolstipe
    ofxDatGuiSlider* fb0brightkeyamountslider;
    ofxDatGuiSlider* fb0brightkeythreshslider;
    ofxDatGuiSlider* fb0blendslider;
    ofxDatGuiSlider* fb0delayamountslider;
    
    ofxDatGuiSlider* fb1brightkeyamountslider;
    ofxDatGuiSlider* fb1brightkeythreshslider;
    ofxDatGuiSlider* fb1blendslider;
    ofxDatGuiSlider* fb1delayamountslider;
    
    ofxDatGuiSlider* fb2brightkeyamountslider;
    ofxDatGuiSlider* fb2brightkeythreshslider;
    ofxDatGuiSlider* fb2blendslider;
    ofxDatGuiSlider* fb2delayamountslider;
    
    ofxDatGuiSlider* fb3brightkeyamountslider;
    ofxDatGuiSlider* fb3brightkeythreshslider;
    ofxDatGuiSlider* fb3blendslider;
    ofxDatGuiSlider* fb3delayamountslider;

    
    
    //vertex displacement controls
    
    ofxDatGuiSlider* x_displace_slider;
    ofxDatGuiSlider* y_displace_slider;
    ofxDatGuiSlider* z_displace_slider;
    ofxDatGuiSlider* w_displace_slider;

    //fbop controls
    ofxDatGuiSlider* fb0_hue_slider;
    ofxDatGuiSlider* fb0_saturation_slider;
    ofxDatGuiSlider* fb0_bright_slider;
    
    ofxDatGuiSlider* fb0_huex_mod_slider;
    ofxDatGuiSlider* fb0_huex_offset_slider;
    ofxDatGuiSlider* fb0_huex_lfo_slider;
    
    ofxDatGuiSlider* fb0_x_displace_slider;
    ofxDatGuiSlider* fb0_y_displace_slider;
    ofxDatGuiSlider* fb0_z_displace_slider;
    
    ofxDatGuiButton* fb0_hue_invert_toggle;
    ofxDatGuiButton* fb0_saturation_invert_toggle;
    ofxDatGuiButton* fb0_bright_invert_toggle;
    
    
    //fb1
    ofxDatGuiSlider* fb1_hue_slider;
    ofxDatGuiSlider* fb1_saturation_slider;
    ofxDatGuiSlider* fb1_bright_slider;
    
    ofxDatGuiSlider* fb1_huex_mod_slider;
    ofxDatGuiSlider* fb1_huex_offset_slider;
    ofxDatGuiSlider* fb1_huex_lfo_slider;
    
    ofxDatGuiSlider* fb1_x_displace_slider;
    ofxDatGuiSlider* fb1_y_displace_slider;
    ofxDatGuiSlider* fb1_z_displace_slider;
    
    ofxDatGuiButton* fb1_hue_invert_toggle;
    ofxDatGuiButton* fb1_saturation_invert_toggle;
    ofxDatGuiButton* fb1_bright_invert_toggle;
    
    //fb2
    ofxDatGuiSlider* fb2_hue_slider;
    ofxDatGuiSlider* fb2_saturation_slider;
    ofxDatGuiSlider* fb2_bright_slider;
    
    ofxDatGuiSlider* fb2_huex_mod_slider;
    ofxDatGuiSlider* fb2_huex_offset_slider;
    ofxDatGuiSlider* fb2_huex_lfo_slider;
    
    ofxDatGuiSlider* fb2_x_displace_slider;
    ofxDatGuiSlider* fb2_y_displace_slider;
    ofxDatGuiSlider* fb2_z_displace_slider;
    
    ofxDatGuiButton* fb2_hue_invert_toggle;
    ofxDatGuiButton* fb2_saturation_invert_toggle;
    ofxDatGuiButton* fb2_bright_invert_toggle;
    
    //fb3
    ofxDatGuiSlider* fb3_hue_slider;
    ofxDatGuiSlider* fb3_saturation_slider;
    ofxDatGuiSlider* fb3_bright_slider;
    
    ofxDatGuiSlider* fb3_huex_mod_slider;
    ofxDatGuiSlider* fb3_huex_offset_slider;
    ofxDatGuiSlider* fb3_huex_lfo_slider;
    
    ofxDatGuiSlider* fb3_x_displace_slider;
    ofxDatGuiSlider* fb3_y_displace_slider;
    ofxDatGuiSlider* fb3_z_displace_slider;
    
    ofxDatGuiButton* fb3_hue_invert_toggle;
    ofxDatGuiButton* fb3_saturation_invert_toggle;
    ofxDatGuiButton* fb3_bright_invert_toggle;



    
 
    
    
  
    
    
    //masterframebuffermixcontrolstrip
    ofxDatGuiSlider* masterframebufferdelayamountslider;
   // ofxDatGuiSlider* masterframebuffermixslider;
    
    
    //h and v flip toggles
    ofxDatGuiToggle* ch1_h_mirrortoggle;
 
    
    
    //fbmixcontrolstrip
    float fb0lumakeyvalue=0.1;
    float fb0lumakeythresh=0.6;
    int fb0delayamnt=0;
    float fb0blend=.1;
    
    
    float fb1lumakeyvalue=0.1;
    float fb1lumakeythresh=0.6;
    int fb1delayamnt=0;
    float fb1blend=.1;
    
    float fb2lumakeyvalue=0.1;
    float fb2lumakeythresh=0.6;
    int fb2delayamnt=0;
    float fb2blend=.1;
    
    float fb3lumakeyvalue=0.1;
    float fb3lumakeythresh=0.6;
    int fb3delayamnt=0;
    float fb3blend=.1;

    
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
  
    
    int channel1=0;
    int channel2=0;
    
    int mix1=0;
    int mix2=0;
    int FBmix=0;
    int FB1mix=0;
    int FB2mix=0;
    int FB3mix=0;
    
    //h and v flip controls
    bool ch1_h_mirror=false;
   
    
    //mix1 varibals
    float mix1blend1=.5;
    float mix1lumakeyvalue=0.2;
    float mix1lumakeythresh=0.1;
    
    ofxDatGuiColorPicker* keyColorPicker;
    void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
    ofColor keyColorFromPicker;
    
    //mix2 variables
    int blend2=0;
    
    
    float x_displace=0.0;
    float y_displace=0.0;
    float z_displace=0.0;
    float w_displace=0.0;
    
    //fb0
    float fb0_x_displace=0.0;
    float fb0_y_displace=0.0;
    float fb0_z_displace=100.0;
  
    
    float fb0_hue=10.0;
    float fb0_saturation=10.0;
    float fb0_bright=10.0;
    
    float fb0_huex_mod=10.0;
    float fb0_huex_offset=0.0;
    float fb0_huex_lfo=0.0;
    
    bool fb0_hue_invert=0;
    bool fb0_saturation_invert=0;
    bool fb0_bright_invert=0;
    
    //fb1
    float fb1_x_displace=0.0;
    float fb1_y_displace=0.0;
    float fb1_z_displace=100.0;

    float fb1_hue=10.0;
    float fb1_saturation=10.0;
    float fb1_bright=10.0;
    
    float fb1_huex_mod=10.0;
    float fb1_huex_offset=0.0;
    float fb1_huex_lfo=0.0;
    
    bool fb1_hue_invert=0;
    bool fb1_saturation_invert=0;
    bool fb1_bright_invert=0;
    
    //fb2
    float fb2_x_displace=0.0;
    float fb2_y_displace=0.0;
    float fb2_z_displace=100.0;
    
    float fb2_hue=10.0;
    float fb2_saturation=10.0;
    float fb2_bright=10.0;
    
    float fb2_huex_mod=10.0;
    float fb2_huex_offset=0.0;
    float fb2_huex_lfo=0.0;
    
    bool fb2_hue_invert=0;
    bool fb2_saturation_invert=0;
    bool fb2_bright_invert=0;
    
    //fb3
    float fb3_x_displace=0.0;
    float fb3_y_displace=0.0;
    float fb3_z_displace=100.0;
    
    float fb3_hue=10.0;
    float fb3_saturation=10.0;
    float fb3_bright=10.0;
    
    float fb3_huex_mod=10.0;
    float fb3_huex_offset=0.0;
    float fb3_huex_lfo=0.0;
    
    bool fb3_hue_invert=0;
    bool fb3_saturation_invert=0;
    bool fb3_bright_invert=0;

    
    //channel1 variables
    float channel1bright=1.0;
    float channel1hue=1.0;
    float channel1saturation=1.0;
    
    float channel1brightpowmap=1.0;
    float channel1huepowmap=1.0;
    float channel1saturationpowmap=1.0;
    
    bool channel1satwrap=0;
    bool channel1brightwrap=0;
    
    bool ch1hue_powmaptoggle=0;
    bool ch1sat_powmaptoggle=0;
    bool ch1bright_powmaptoggle=0;
    
    bool ch1hue_inverttoggle=0;
    bool ch1sat_inverttoggle=0;
    bool ch1bright_inverttoggle=0;
    
    //channel2 variables
    float channel2bright=1.0;
    float channel2hue=1.0;
    float channel2saturation=1.0;
    
    float channel2brightpowmap=1.0;
    float channel2huepowmap=1.0;
    float channel2saturationpowmap=1.0;
    
    
    bool channel2satwrap=0;
    bool channel2brightwrap=0;
    
    
    bool ch2hue_powmaptoggle=0;
    bool ch2sat_powmaptoggle=0;
    bool ch2bright_powmaptoggle=0;
    
    bool ch2hue_inverttoggle=0;
    bool ch2sat_inverttoggle=0;
    bool ch2bright_inverttoggle=0;
    
    
  
   
   };
