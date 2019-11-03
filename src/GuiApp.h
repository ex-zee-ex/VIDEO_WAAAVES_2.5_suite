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
    ofxDatGui* guiPixelate;
    
    
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
    
    
    
    ofxDatGuiDropdown* ddchannel1;
    ofxDatGuiDropdown* ddchannel2;
    ofxDatGuiDropdown* ddmix1;
    ofxDatGuiDropdown* ddmix2;
    
    
    
    //FBmixcontrolstipe
    ofxDatGuiSlider* fb0brightkeyamountslider;
    ofxDatGuiSlider* fb0brightkeythreshslider;
    ofxDatGuiSlider* fb0blendslider;
    ofxDatGuiSlider* fb0delayamountslider;
    
    ofxDatGuiButton* fb0_hflip_toggle;
    ofxDatGuiButton* fb0_vflip_toggle;
    
    ofxDatGuiSlider* fb1brightkeyamountslider;
    ofxDatGuiSlider* fb1brightkeythreshslider;
    ofxDatGuiSlider* fb1blendslider;
    ofxDatGuiSlider* fb1delayamountslider;
    
    ofxDatGuiButton* fb1_hflip_toggle;
    ofxDatGuiButton* fb1_vflip_toggle;
    
    ofxDatGuiSlider* fb2brightkeyamountslider;
    ofxDatGuiSlider* fb2brightkeythreshslider;
    ofxDatGuiSlider* fb2blendslider;
    ofxDatGuiSlider* fb2delayamountslider;
    
    ofxDatGuiButton* fb2_hflip_toggle;
    ofxDatGuiButton* fb2_vflip_toggle;
    
    ofxDatGuiSlider* fb3brightkeyamountslider;
    ofxDatGuiSlider* fb3brightkeythreshslider;
    ofxDatGuiSlider* fb3blendslider;
    ofxDatGuiSlider* fb3delayamountslider;
    
    ofxDatGuiButton* fb3_hflip_toggle;
    ofxDatGuiButton* fb3_vflip_toggle;

    
    
    //vertex displacement controls
    
    
    //blur and sharpen controls
    ofxDatGuiSlider* blur_amount_slider;
    ofxDatGuiSlider* sharpen_amount_slider;
    
    
    

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



    //pixelations
    
    //cam1
    ofxDatGuiButton* cam1_pixel_toggle;
    ofxDatGuiSlider* cam1_pixel_scale_slider;
    ofxDatGuiSlider* cam1_pixel_mix_slider;
    ofxDatGuiSlider* cam1_pixel_brightscale_slider;
    
    bool cam1_pixel_switch=0;
    int cam1_pixel_scale=64;
    float cam1_pixel_mix=1;
    float cam1_pixel_brightscale=0;
    
    //cam2
    ofxDatGuiButton* cam2_pixel_toggle;
    ofxDatGuiSlider* cam2_pixel_scale_slider;
    ofxDatGuiSlider* cam2_pixel_mix_slider;
    ofxDatGuiSlider* cam2_pixel_brightscale_slider;
    
    bool cam2_pixel_switch=0;
    int cam2_pixel_scale=64;
    float cam2_pixel_mix=1;
    float cam2_pixel_brightscale=0;
    
    
    //fb0
    ofxDatGuiButton* fb0_pixel_toggle;
    ofxDatGuiSlider* fb0_pixel_scale_slider;
    ofxDatGuiSlider* fb0_pixel_mix_slider;
    ofxDatGuiSlider* fb0_pixel_brightscale_slider;
 
    bool fb0_pixel_switch=0;
    int fb0_pixel_scale=64;
    float fb0_pixel_mix=1;
    float fb0_pixel_brightscale=0;
    
    //fb1
    ofxDatGuiButton* fb1_pixel_toggle;
    ofxDatGuiSlider* fb1_pixel_scale_slider;
    ofxDatGuiSlider* fb1_pixel_mix_slider;
    ofxDatGuiSlider* fb1_pixel_brightscale_slider;
    
    bool fb1_pixel_switch=0;
    int fb1_pixel_scale=64;
    float fb1_pixel_mix=1;
    float fb1_pixel_brightscale=0;
    
    //fb2
    ofxDatGuiButton* fb2_pixel_toggle;
    ofxDatGuiSlider* fb2_pixel_scale_slider;
    ofxDatGuiSlider* fb2_pixel_mix_slider;
    ofxDatGuiSlider* fb2_pixel_brightscale_slider;
    
    bool fb2_pixel_switch=0;
    int fb2_pixel_scale=64;
    float fb2_pixel_mix=1;
    float fb2_pixel_brightscale=0;
    
    
    //fb3
    ofxDatGuiButton* fb3_pixel_toggle;
    ofxDatGuiSlider* fb3_pixel_scale_slider;
    ofxDatGuiSlider* fb3_pixel_mix_slider;
    ofxDatGuiSlider* fb3_pixel_brightscale_slider;
    
    bool fb3_pixel_switch=0;
    int fb3_pixel_scale=64;
    float fb3_pixel_mix=1;
    float fb3_pixel_brightscale=0;

    
    
    //camera and syphon rescalings
    ofxDatGuiSlider* cam1_scale_slider;
    float cam1_scale=.5;
    
    ofxDatGuiSlider* cam2_scale_slider;
    float cam2_scale=.5;

    
   //master draw xyz rotations and displacements
   // ofxDatGuiSlider* master_z_displace_slider;
    //ofxDatGuiSlider* master_z_displace_slider;
    //ofxDatGuiSlider* master_z_displace_slider;
    
    
    //masterframebuffermixcontrolstrip
    ofxDatGuiSlider* masterframebufferdelayamountslider;
   // ofxDatGuiSlider* masterframebuffermixslider;
    
    
    
 
    
    
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
    ofxDatGuiButton* cam1_hflip_toggle;
    ofxDatGuiButton* cam1_vflip_toggle;

    bool cam1_hflip_switch=0;
    bool cam1_vflip_switch=0;
    
    ofxDatGuiButton* cam2_hflip_toggle;
    ofxDatGuiButton* cam2_vflip_toggle;
    
    bool cam2_hflip_switch=0;
    bool cam2_vflip_switch=0;

    

    bool fb0_hflip_switch=0;
    bool fb0_vflip_switch=0;
    
    bool fb1_hflip_switch=0;
    bool fb1_vflip_switch=0;

    bool fb2_hflip_switch=0;
    bool fb2_vflip_switch=0;

    bool fb3_hflip_switch=0;
    bool fb3_vflip_switch=0;
    
    
    //rotations
    ofxDatGuiSlider* fb0_rotate_slider;
    float fb0_rotate=0;
    
    ofxDatGuiSlider* fb1_rotate_slider;
    float fb1_rotate=0;
    
    ofxDatGuiSlider* fb2_rotate_slider;
    float fb2_rotate=0;
    
    ofxDatGuiSlider* fb3_rotate_slider;
    float fb3_rotate=0;
   
    
    //mix1 varibals
    float mix1blend1=.5;
    float mix1lumakeyvalue=0.2;
    float mix1lumakeythresh=0.1;
    
    
    //mix2 variables
    int blend2=0;
    
    
    //tetrahedron switch
    ofxDatGuiButton* tetrahedron_switch_toggle;
    bool tetrahedron_switch=0;
    
       
    //blur and sharpen variables
    float blur_amount=1;
    float sharpen_amount=.01;
    
    
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
