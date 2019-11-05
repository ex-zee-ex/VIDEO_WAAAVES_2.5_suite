/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"


int fbob=30;

int guiscale=275;

void GuiApp::setup(){
    
    ofBackground(0);
    
    guisignal = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
    guisignal->addFRM();
    guisignal->addBreak();
    
    guisignal->addTextInput("Signal Flow", "# open frameworks #");
    vector<string> channel1options ={"channel1 none","channel1 cam1","channel1 cam2","channel1 syphon"};
    vector<string> mix1options ={"mix1 none","mix1 blend","mix1 key"};
    vector<string> channel2options ={"channel2 none","channel2 cam1","channel2 cam2","channel2 syphon"};
    vector<string> CAmixoptions ={"CA none","CA blend","CA key"};
    guisignal->addDropdown("SELECT A camera", channel1options);
    guisignal->addDropdown("SELECT A mixxx", mix1options);
  
    vector<string> FBmixoptions ={"FB none","FB blend","FB key"};
    vector<string> FB1mixoptions ={"FB1 none","FB1 blend","FB1 key"};
    
    vector<string> FB2mixoptions ={"FB2 none","FB2 blend","FB2 key"};
    vector<string> FB3mixoptions ={"FB3 none","FB3 blend","FB3 key"};
    
    //put these all into a folder? yes please do
    
    ofxDatGuiFolder* mix1_thingsfolder = guisignal->addFolder("mix1things", ofColor::white);
    
    blendamountslider=mix1_thingsfolder->addSlider("mix1blendamnt",-5.0,5.0);
    //bind this slider
    blendamountslider->bind(mix1blend1);
    
    mix1brightkeyamountslider=mix1_thingsfolder->addSlider("mix1brightkeyamnt",0.00,1.00);
    mix1brightkeythreshslider=mix1_thingsfolder->addSlider("mix1brightkeythreshamnt",0.00,1.00);
    
    mix1brightkeyamountslider->bind(mix1lumakeyvalue);
    mix1brightkeythreshslider->bind(mix1lumakeythresh);
    
    
    
    
    guisignal->addDropdown("SELECT A camera", channel2options);

   
    
   
    
    
    
    ///FBmixcontrols
    guisignal->addDropdown("FB0_mixoptions", FBmixoptions);
    ofxDatGuiFolder* fb0mix_thingsfolder = guisignal->addFolder("FB0mixthings", ofColor::white);
    
    fb0blendslider=fb0mix_thingsfolder->addSlider("fb0 mixamnt",-5.0,5.0);
    fb0brightkeyamountslider=fb0mix_thingsfolder->addSlider("fb0brightkeyamnt",0.00,1.00);
    fb0brightkeythreshslider=fb0mix_thingsfolder->addSlider("fb0brightkeythreshamnt",0.00,1.00);
    
    
    
    fb0brightkeyamountslider->bind(fb0lumakeyvalue);
    fb0brightkeythreshslider->bind(fb0lumakeythresh);
    fb0delayamountslider=fb0mix_thingsfolder->addSlider("fb0 delay amnt",0,fbob-1);
    
    fb0blendslider->bind(fb0blend);
  
    fb0delayamountslider->bind(fb0delayamnt);
    
    fb0_hflip_toggle=fb0mix_thingsfolder->addToggle("fb0 h mirror",false);
    fb0_vflip_toggle=fb0mix_thingsfolder->addToggle("fb0 v mirror",false);
    
    

    
    
    
   
    ///FB1mixcontrol
    guisignal->addDropdown("FB1_mixoptions", FB1mixoptions);
    ofxDatGuiFolder* fb1mix_thingsfolder = guisignal->addFolder("FB1mixthings", ofColor::white);
    
    fb1blendslider=fb1mix_thingsfolder->addSlider("fb1 mixamnt",-5.0,5.0);
    fb1brightkeyamountslider=fb1mix_thingsfolder->addSlider("fb1mixbrightkeyamnt",0.00,1.00);
    fb1brightkeythreshslider=fb1mix_thingsfolder->addSlider("fb1mixbrightkeythreshamnt",0.00,1.00);
    
    fb1brightkeyamountslider->bind(fb1lumakeyvalue);
    fb1brightkeythreshslider->bind(fb1lumakeythresh);
    
    fb1blendslider->bind(fb1blend);
    
    fb1delayamountslider=fb1mix_thingsfolder->addSlider("fb1 delay amnt",0,fbob-1);
    
    fb1delayamountslider->bind(fb1delayamnt);
    
    fb1_hflip_toggle=fb1mix_thingsfolder->addToggle("fb1 h mirror",false);
    fb1_vflip_toggle=fb1mix_thingsfolder->addToggle("fb1 v mirror",false);


    
    ///FB2mixcontrol
    guisignal->addDropdown("FB2_mixoptions", FB2mixoptions);
    ofxDatGuiFolder* fb2mix_thingsfolder = guisignal->addFolder("FB2mixthings", ofColor::white);
    
    fb2blendslider=fb2mix_thingsfolder->addSlider("fb2 mixamnt",-5.0,5.0);
    fb2brightkeyamountslider=fb2mix_thingsfolder->addSlider("fb2mixbrightkeyamnt",0.00,1.00);
    fb2brightkeythreshslider=fb2mix_thingsfolder->addSlider("fb2mixbrightkeythreshamnt",0.00,1.00);
    
    fb2brightkeyamountslider->bind(fb2lumakeyvalue);
    fb2brightkeythreshslider->bind(fb2lumakeythresh);
    
    fb2blendslider->bind(fb2blend);
    
    fb2delayamountslider=fb2mix_thingsfolder->addSlider("fb2 delay amnt",0,fbob-1);
    
    fb2delayamountslider->bind(fb2delayamnt);
    
    fb2_hflip_toggle=fb2mix_thingsfolder->addToggle("fb2 h mirror",false);
    fb2_vflip_toggle=fb2mix_thingsfolder->addToggle("fb2 v mirror",false);

    
    
    ///FB3mixcontrol
    guisignal->addDropdown("FB3_mixoptions", FB3mixoptions);
    ofxDatGuiFolder* fb3mix_thingsfolder = guisignal->addFolder("Fb3mixthings", ofColor::white);

    fb3blendslider=fb3mix_thingsfolder->addSlider("fb3 mixamnt",-5.0,5.0);
    fb3brightkeyamountslider=fb3mix_thingsfolder->addSlider("fb3mixbrightkeyamnt",0.00,1.00);
    fb3brightkeythreshslider=fb3mix_thingsfolder->addSlider("fb3mixbrightkeythreshamnt",0.00,1.00);
    
    fb3brightkeyamountslider->bind(fb3lumakeyvalue);
    fb3brightkeythreshslider->bind(fb3lumakeythresh);
    
    fb3blendslider->bind(fb3blend);
    
    fb3delayamountslider=fb3mix_thingsfolder->addSlider("fb3 delay amnt",0,fbob-1);
    
    fb3delayamountslider->bind(fb3delayamnt);

    fb3_hflip_toggle=fb3mix_thingsfolder->addToggle("fb3 h mirror",false);
    fb3_vflip_toggle=fb3mix_thingsfolder->addToggle("fb3 v mirror",false);

    
    
  
    
    blur_amount_slider=guisignal->addSlider("blur amount",0.0,5.0);
    blur_amount_slider->bind(blur_amount);
    
    sharpen_amount_slider=guisignal->addSlider("sharpen amount",0.0,.3);
    sharpen_amount_slider->bind(sharpen_amount);

    
    cam1_scale_slider=guisignal->addSlider("cam1 scale",0,2);
    cam1_scale_slider->bind(cam1_scale);
    
    cam2_scale_slider=guisignal->addSlider("cam2 scale",0,2);
    cam2_scale_slider->bind(cam2_scale);
    
    
    cam1_hflip_toggle=guisignal->addToggle("cam1 h mirror",false);
    cam1_vflip_toggle=guisignal->addToggle("cam1 v mirror",false);
    
    cam2_hflip_toggle=guisignal->addToggle("cam2 h mirror",false);
    cam2_vflip_toggle=guisignal->addToggle("cam2 v mirror",false);

    syphonOutputtoggle=guisignal->addToggle("syphon out",false);
    tetrahedron_switch_toggle=guisignal->addToggle("tetrahedron",false);
    guisignal->onDropdownEvent(this, &GuiApp::onDropdownEvent);
    //guisignal->onColorPickerEvent(this, &GuiApp::onColorPickerEvent);
    
    //registertolistentoevents
    guisignal->onButtonEvent(this, &GuiApp::onButtonEvent);
    
    
    
    
    ///-----------------------------------
    guithings = new ofxDatGui(guiscale,0 );//ofxDatGuiAnchor::TOP_RIGHT );
    guithings->addBreak();
    
    guithings->addTextInput("like doing things", "# open frameworks #");
    
    
    
    
    
    //channel1 hsb manipulation strip
    ofxDatGuiFolder* channel1_thingsfolder = guithings->addFolder("channel1things", ofColor::white);
    
    channel1hueslider= channel1_thingsfolder->addSlider("ch1hue ", -5.0, 5.0);
    channel1saturationslider= channel1_thingsfolder->addSlider("ch1saturation ", -5.0, 5.0);
    channel1brightslider= channel1_thingsfolder->addSlider("ch1brightness ", -5.0, 5.0);
    
    
    channel1hueinverttoggle=channel1_thingsfolder->addToggle("ch1hueinvert",false);
    channel1satinverttoggle=channel1_thingsfolder->addToggle("ch1satinvert",false);
    channel1brightinverttoggle=channel1_thingsfolder->addToggle("ch1brightinvert",false);
    
    channel1satwraptoggle=channel1_thingsfolder->addToggle("ch1satwrap",false);
    channel1brightwraptoggle=channel1_thingsfolder->addToggle("ch1brightwrap",false);
    
    channel1huepowmaptoggle=channel1_thingsfolder->addToggle("ch1huepowmap",false);
    channel1satpowmaptoggle=channel1_thingsfolder->addToggle("ch1satpowmap",false);
    channel1brightpowmaptoggle=channel1_thingsfolder->addToggle("ch1brightpowmap",false);
    
    channel1huepowmapslider= channel1_thingsfolder->addSlider("ch1huepowmap", -4.0, 4.0);
    channel1saturationpowmapslider= channel1_thingsfolder->addSlider("ch1satpowmap", -4.0, 4.0);
    channel1brightpowmapslider= channel1_thingsfolder->addSlider("ch1brightpowmap", -4.0, 4.0);
    
  
    channel1_thingsfolder->expand();
    
    
    //channel2 hsb manipulation strip
    
    ofxDatGuiFolder* channel2_thingsfolder = guithings->addFolder("channel2things", ofColor::white);
    
    channel2hueslider= channel2_thingsfolder->addSlider("ch2hue ", -5.0, 5.0);
    channel2saturationslider= channel2_thingsfolder->addSlider("ch2saturation ", -5.0, 5.0);
    channel2brightslider= channel2_thingsfolder->addSlider("ch2brightness ", -5.0, 5.0);
    
    channel2hueinverttoggle=channel2_thingsfolder->addToggle("ch2hueinvert",false);
    channel2satinverttoggle=channel2_thingsfolder->addToggle("ch2satinvert",false);
    channel2brightinverttoggle=channel2_thingsfolder->addToggle("ch2brightinvert",false);

    channel2satwraptoggle=channel2_thingsfolder->addToggle("ch2satwrap",false);
    channel2brightwraptoggle=channel2_thingsfolder->addToggle("ch2brightwrap",false);
    
    channel2huepowmaptoggle=channel2_thingsfolder->addToggle("ch2huepowmap",false);
    channel2satpowmaptoggle=channel2_thingsfolder->addToggle("ch2satpowmap",false);
    channel2brightpowmaptoggle=channel2_thingsfolder->addToggle("ch2brightpowmap",false);
    
    
    channel2huepowmapslider= channel2_thingsfolder->addSlider("ch2huepowmap", -5.0, 5.0);
    channel2saturationpowmapslider= channel2_thingsfolder->addSlider("ch2satpowmap", -5.0, 5.0);
    channel2brightpowmapslider= channel2_thingsfolder->addSlider("ch2brightpowmap", -5.0, 5.0);
    
    
   // channel2_thingsfolder->expand();

    
    
    
 
    

    
    
    //bind the gui channel1
    channel1hueslider->bind(channel1hue);
    channel1saturationslider->bind(channel1saturation);
    channel1brightslider->bind(channel1bright);
    
    channel1huepowmapslider->bind(channel1huepowmap);
    channel1saturationpowmapslider->bind(channel1saturationpowmap);
    channel1brightpowmapslider->bind(channel1brightpowmap);
    
    //bind the gui channel2
    channel2hueslider->bind(channel2hue);
    channel2saturationslider->bind(channel2saturation);
    channel2brightslider->bind(channel2bright);
    
    channel2huepowmapslider->bind(channel2huepowmap);
    channel2saturationpowmapslider->bind(channel2saturationpowmap);
    channel2brightpowmapslider->bind(channel2brightpowmap);
  
    
    
    
   
    
    //registertolistentoevents
    guithings->onButtonEvent(this, &GuiApp::onButtonEvent);
    
    
    //----------------------
    //use this for how to manipulate each framebuffer in space seperatly
    //so for each one we want to have seperate vert shader controls as well
    //i think we start from there, then figure out how to replicate all those rotations and stuff
    //in more concise shader terms
    //s
   
    
  
   
    
    guiFBops= new ofxDatGui(2*guiscale,0 );
    guiFBops->addBreak();
    
    
    //fb0
    ofxDatGuiFolder* fb0_opsfolder = guiFBops->addFolder("fb0ops", ofColor::white);
    fb0_hue_slider= fb0_opsfolder->addSlider("hue_x ", 0.0, 20.0);
    fb0_saturation_slider= fb0_opsfolder->addSlider("sat_x ", 0.0, 20.0);
    fb0_bright_slider= fb0_opsfolder->addSlider("bright_x", 0.0, 20.0);
    
    fb0_hue_invert_toggle=fb0_opsfolder->addToggle("hue0 invert",0);
    fb0_saturation_invert_toggle=fb0_opsfolder->addToggle("saturationg0 invert",0);
    fb0_bright_invert_toggle=fb0_opsfolder->addToggle("bright0 invert",0);
    
    fb0_huex_mod_slider= fb0_opsfolder->addSlider("huex_mod", 0.0, 20.0);
    fb0_huex_offset_slider= fb0_opsfolder->addSlider("huex_offset", -20.0, 20.0);
    fb0_huex_lfo_slider= fb0_opsfolder->addSlider("huex_lfo", -20.0, 20.0);
    
    fb0_x_displace_slider= fb0_opsfolder->addSlider("x_displace", -20.0, 20.0);
    fb0_y_displace_slider= fb0_opsfolder->addSlider("y_displace", -20.0, 20.0);
    fb0_z_displace_slider= fb0_opsfolder->addSlider("z_displace", 90, 110.0);
    fb0_rotate_slider=fb0_opsfolder->addSlider("rotate", -157.07, 157.07);

    
    
    fb0_hue_slider->bind(fb0_hue);
    fb0_saturation_slider->bind(fb0_saturation);
    fb0_bright_slider->bind(fb0_bright);
    fb0_huex_mod_slider->bind(fb0_huex_mod);
    fb0_huex_offset_slider->bind(fb0_huex_offset);
    fb0_huex_lfo_slider->bind(fb0_huex_lfo);
    fb0_x_displace_slider->bind(fb0_x_displace);
    fb0_y_displace_slider->bind(fb0_y_displace);
    fb0_z_displace_slider->bind(fb0_z_displace);
    fb0_rotate_slider->bind(fb0_rotate);
    
    //fb1
    ofxDatGuiFolder* fb1_opsfolder = guiFBops->addFolder("fb1ops", ofColor::white);
    fb1_hue_slider= fb1_opsfolder->addSlider("hue_x ", 0.0, 20.0);
    fb1_saturation_slider= fb1_opsfolder->addSlider("sat_x ", 0.0, 20.0);
    fb1_bright_slider= fb1_opsfolder->addSlider("bright_x", 0.0, 20.0);
    
    fb1_hue_invert_toggle=fb1_opsfolder->addToggle("hue1 invert",0);
    fb1_saturation_invert_toggle=fb1_opsfolder->addToggle("saturationg1 invert",0);
    fb1_bright_invert_toggle=fb1_opsfolder->addToggle("bright1 invert",0);
    
    fb1_huex_mod_slider= fb1_opsfolder->addSlider("huex_mod", 0.0, 20.0);
    fb1_huex_offset_slider= fb1_opsfolder->addSlider("huex_offset", -20.0, 20.0);
    fb1_huex_lfo_slider= fb1_opsfolder->addSlider("huex_lfo", -20.0, 20.0);
    
    fb1_x_displace_slider= fb1_opsfolder->addSlider("x_displace", -20.0, 20.0);
    fb1_y_displace_slider= fb1_opsfolder->addSlider("y_displace", -20.0, 20.0);
    fb1_z_displace_slider= fb1_opsfolder->addSlider("z_displace", 90, 110);
    fb1_rotate_slider=fb1_opsfolder->addSlider("rotate", -157.07, 157.07);
    
    
    
    fb1_hue_slider->bind(fb1_hue);
    fb1_saturation_slider->bind(fb1_saturation);
    fb1_bright_slider->bind(fb1_bright);
    fb1_huex_mod_slider->bind(fb1_huex_mod);
    fb1_huex_offset_slider->bind(fb1_huex_offset);
    fb1_huex_lfo_slider->bind(fb1_huex_lfo);
    fb1_x_displace_slider->bind(fb1_x_displace);
    fb1_y_displace_slider->bind(fb1_y_displace);
    fb1_z_displace_slider->bind(fb1_z_displace);
    fb1_rotate_slider->bind(fb1_rotate);
    
    //fb2
    ofxDatGuiFolder* fb2_opsfolder = guiFBops->addFolder("fb2ops", ofColor::white);
    fb2_hue_slider= fb2_opsfolder->addSlider("hue_x ", 0.0, 20.0);
    fb2_saturation_slider= fb2_opsfolder->addSlider("sat_x ", 0.0, 20.0);
    fb2_bright_slider= fb2_opsfolder->addSlider("bright_x", 0.0, 20.0);
    
    fb2_hue_invert_toggle=fb2_opsfolder->addToggle("hue2 invert",0);
    fb2_saturation_invert_toggle=fb2_opsfolder->addToggle("saturationg2 invert",0);
    fb2_bright_invert_toggle=fb2_opsfolder->addToggle("bright2 invert",0);
    
    fb2_huex_mod_slider= fb2_opsfolder->addSlider("huex_mod", 0.0, 20.0);
    fb2_huex_offset_slider= fb2_opsfolder->addSlider("huex_offset", -20.0, 20.0);
    fb2_huex_lfo_slider= fb2_opsfolder->addSlider("huex_lfo", -20.0, 20.0);
    
    fb2_x_displace_slider= fb2_opsfolder->addSlider("x_displace", -20.0, 20.0);
    fb2_y_displace_slider= fb2_opsfolder->addSlider("y_displace", -20.0, 20.0);
     fb2_z_displace_slider= fb2_opsfolder->addSlider("z_displace", 90, 110.0);
     fb2_rotate_slider=fb2_opsfolder->addSlider("rotate",  -157.07, 157.07);
    
    
    
    fb2_hue_slider->bind(fb2_hue);
    fb2_saturation_slider->bind(fb2_saturation);
    fb2_bright_slider->bind(fb2_bright);
    fb2_huex_mod_slider->bind(fb2_huex_mod);
    fb2_huex_offset_slider->bind(fb2_huex_offset);
    fb2_huex_lfo_slider->bind(fb2_huex_lfo);
    fb2_x_displace_slider->bind(fb2_x_displace);
    fb2_y_displace_slider->bind(fb2_y_displace);
    fb2_z_displace_slider->bind(fb2_z_displace);
    fb2_rotate_slider->bind(fb2_rotate);
    
    
    //fb3
    ofxDatGuiFolder* fb3_opsfolder = guiFBops->addFolder("fb3ops", ofColor::white);
    fb3_hue_slider= fb3_opsfolder->addSlider("hue_x ", 0.0, 20.0);
    fb3_saturation_slider= fb3_opsfolder->addSlider("sat_x ", 0.0, 20.0);
    fb3_bright_slider= fb3_opsfolder->addSlider("bright_x", 0.0, 20.0);
    
    fb3_hue_invert_toggle=fb3_opsfolder->addToggle("hue2 invert",0);
    fb3_saturation_invert_toggle=fb3_opsfolder->addToggle("saturationg2 invert",0);
    fb3_bright_invert_toggle=fb3_opsfolder->addToggle("bright2 invert",0);
    
    fb3_huex_mod_slider= fb3_opsfolder->addSlider("huex_mod", 0.0, 20.0);
    fb3_huex_offset_slider= fb3_opsfolder->addSlider("huex_offset", -20.0, 20.0);
    fb3_huex_lfo_slider= fb3_opsfolder->addSlider("huex_lfo", -20.0, 20.0);
    
    fb3_x_displace_slider= fb3_opsfolder->addSlider("x_displace", -20.0, 20.0);
    fb3_y_displace_slider= fb3_opsfolder->addSlider("y_displace", -20.0, 20.0);
    fb3_z_displace_slider= fb3_opsfolder->addSlider("z_displace", 90, 110.0);
     fb3_rotate_slider=fb3_opsfolder->addSlider("rotate", -157.07, 157.07);
    
    
    
    fb3_hue_slider->bind(fb3_hue);
    fb3_saturation_slider->bind(fb3_saturation);
    fb3_bright_slider->bind(fb3_bright);
    fb3_huex_mod_slider->bind(fb3_huex_mod);
    fb3_huex_offset_slider->bind(fb3_huex_offset);
    fb3_huex_lfo_slider->bind(fb3_huex_lfo);
    fb3_x_displace_slider->bind(fb3_x_displace);
    fb3_y_displace_slider->bind(fb3_y_displace);
    fb3_z_displace_slider->bind(fb3_z_displace);
    fb3_rotate_slider->bind(fb3_rotate);

 
    guiFBops->onButtonEvent(this, &GuiApp::onButtonEvent);
    
    //pixelations functions
    
    
    guiPixelate= new ofxDatGui(3*guiscale,0 );
    guiPixelate->addBreak();
    
    //cam1
    ofxDatGuiFolder* cam1_pixelfolder = guiPixelate->addFolder("cam1 pixelate", ofColor::white);
    cam1_pixel_toggle=cam1_pixelfolder->addToggle("cam1 pixel switch",0);
    cam1_pixel_scale_slider=cam1_pixelfolder->addSlider("quantisation",0,256);
    cam1_pixel_mix_slider=cam1_pixelfolder->addSlider("mix",-2,2);
    cam1_pixel_brightscale_slider=cam1_pixelfolder->addSlider("bright scale",-10,10);
    
    
    cam1_pixel_scale_slider->bind(cam1_pixel_scale);
    cam1_pixel_mix_slider->bind(cam1_pixel_mix);
    cam1_pixel_brightscale_slider->bind(cam1_pixel_brightscale);
    
    //cam2
    ofxDatGuiFolder* cam2_pixelfolder = guiPixelate->addFolder("cam2 pixelate", ofColor::white);
    cam2_pixel_toggle=cam2_pixelfolder->addToggle("cam2 pixel switch",0);
    cam2_pixel_scale_slider=cam2_pixelfolder->addSlider("quantisation",0,256);
    cam2_pixel_mix_slider=cam2_pixelfolder->addSlider("mix",-2,2);
    cam2_pixel_brightscale_slider=cam2_pixelfolder->addSlider("bright scale",-10,10);
    
    
    cam2_pixel_scale_slider->bind(cam2_pixel_scale);
    cam2_pixel_mix_slider->bind(cam2_pixel_mix);
    cam2_pixel_brightscale_slider->bind(cam2_pixel_brightscale);
    

    //fb0
    ofxDatGuiFolder* fb0_pixelfolder = guiPixelate->addFolder("fb0 pixelate", ofColor::white);
    fb0_pixel_toggle=fb0_pixelfolder->addToggle("fb0 pixel switch",0);
    fb0_pixel_scale_slider=fb0_pixelfolder->addSlider("quantisation",0,256);
    fb0_pixel_mix_slider=fb0_pixelfolder->addSlider("mix",-2,2);
    fb0_pixel_brightscale_slider=fb0_pixelfolder->addSlider("bright scale",-10,10);


    fb0_pixel_scale_slider->bind(fb0_pixel_scale);
    fb0_pixel_mix_slider->bind(fb0_pixel_mix);
    fb0_pixel_brightscale_slider->bind(fb0_pixel_brightscale);
    
    //fb1
    ofxDatGuiFolder* fb1_pixelfolder = guiPixelate->addFolder("fb1 pixelate", ofColor::white);
    fb1_pixel_toggle=fb1_pixelfolder->addToggle("fb1 pixel switch",0);
    fb1_pixel_scale_slider=fb1_pixelfolder->addSlider("quantisation",0,256);
    fb1_pixel_mix_slider=fb1_pixelfolder->addSlider("mix",-2,2);
    fb1_pixel_brightscale_slider=fb1_pixelfolder->addSlider("bright scale",-10,10);
    
    
    fb1_pixel_scale_slider->bind(fb1_pixel_scale);
    fb1_pixel_mix_slider->bind(fb1_pixel_mix);
    fb1_pixel_brightscale_slider->bind(fb1_pixel_brightscale);
    
    //fb2
    ofxDatGuiFolder* fb2_pixelfolder = guiPixelate->addFolder("fb2 pixelate", ofColor::white);
    fb2_pixel_toggle=fb2_pixelfolder->addToggle("fb2 pixel switch",0);
    fb2_pixel_scale_slider=fb2_pixelfolder->addSlider("quantisation",0,256);
    fb2_pixel_mix_slider=fb2_pixelfolder->addSlider("mix",-2,2);
    fb2_pixel_brightscale_slider=fb2_pixelfolder->addSlider("bright scale",-10,10);
    
    
    fb2_pixel_scale_slider->bind(fb2_pixel_scale);
    fb2_pixel_mix_slider->bind(fb2_pixel_mix);
    fb2_pixel_brightscale_slider->bind(fb2_pixel_brightscale);
    
    //fb3
    ofxDatGuiFolder* fb3_pixelfolder = guiPixelate->addFolder("fb3 pixelate", ofColor::white);
    fb3_pixel_toggle=fb3_pixelfolder->addToggle("fb3 pixel switch",0);
    fb3_pixel_scale_slider=fb3_pixelfolder->addSlider("quantisation",0,256);
    fb3_pixel_mix_slider=fb3_pixelfolder->addSlider("mix",-2,2);
    fb3_pixel_brightscale_slider=fb3_pixelfolder->addSlider("bright scale",-10,10);
    
    
    fb3_pixel_scale_slider->bind(fb3_pixel_scale);
    fb3_pixel_mix_slider->bind(fb3_pixel_mix);
    fb3_pixel_brightscale_slider->bind(fb3_pixel_brightscale);

    
    
    
    
 
    guiPixelate->onButtonEvent(this, &GuiApp::onButtonEvent);
    ofxDatGuiLog::quiet();
    
  }
    //-----------------------------

/*
void GuiApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
    cout << "onColorPickerEvent: " << e.target->getLabel() << " " << e.target->getColor() << endl;
    ofSetBackgroundColor(e.color);
    
    
    //need to set up label based if statements here
    keyColorFromPicker=e.target->getColor();
}
 
 
 */
//another thing to thinkabout with dropdown events is
//that i could just have one dropdown event
//and seperate the same inputs from diferent dropdowns
//by like ch2_cam2 etc and then the 1 function can shunt everything
    void GuiApp::onDropdownEvent(ofxDatGuiDropdownEvent e)
    {
        cout << "onDropdownEvent: " << e.target->getLabel() << " Selected" << endl;
        
        
        if(e.target->getLabel()=="channel1 none"){
            channel1=0;
            
        }//endife1

        
        if(e.target->getLabel()=="channel1 cam1"){
            channel1=1;
        
        }//endife1
        
        if(e.target->getLabel()=="channel1 cam2"){
            channel1=2;
            
        }//endife2
        if(e.target->getLabel()=="channel1 syphon"){
            channel1=3;
            
        }//endife2
        
        
        
        if(e.target->getLabel()=="channel2 none"){
            channel2=0;
            
        }//endife1
        if(e.target->getLabel()=="channel2 cam1"){
            channel2=1;
            
        }//endife1
        
        if(e.target->getLabel()=="channel2 cam2"){
            channel2=2;

        }//endife2
        if(e.target->getLabel()=="channel2 syphon"){
            channel2=3;
            
        }//endife2

        
        
        if(e.target->getLabel()=="mix1 none"){
            mix1=0;
            
        }//endife1
        
        if(e.target->getLabel()=="mix1 blend"){
            mix1=1;
            
        }//endife1
        
        if(e.target->getLabel()=="mix1 key"){
            mix1=2;
            
            
        }//endife1
        
     
        
        if(e.target->getLabel()=="FB none"){
            FBmix=0;
        }
        
        
        
        if(e.target->getLabel()=="FB blend"){
            FBmix=1;
            
        }//endife1
        
        if(e.target->getLabel()=="FB key"){
            FBmix=2;
        }
        
        if(e.target->getLabel()=="FB1 none"){
            FB1mix=0;
        }
        
        
        if(e.target->getLabel()=="FB1 blend"){
            FB1mix=1;
            
        }//endife1
        
        if(e.target->getLabel()=="FB1 key"){
            FB1mix=2;
        }
        
        if(e.target->getLabel()=="FB2 none"){
            FB2mix=0;
        }
        
        
        if(e.target->getLabel()=="FB2 blend"){
            FB2mix=1;
            
        }//endife1
        
        if(e.target->getLabel()=="FB2 key"){
            FB2mix=2;
        }
        
        if(e.target->getLabel()=="FB3 none"){
            FB3mix=0;
        }
        
        
        if(e.target->getLabel()=="FB3 blend"){
            FB3mix=1;
            
        }//endife1
        
        if(e.target->getLabel()=="FB3 key"){
            FB3mix=2;
        }


        
        //fb invert toggles
        
       
     
      

        

    

        
        
        
        
        
        
    }


//--------------------



void GuiApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if(e.target->getLabel()=="tetrahedron"){tetrahedron_switch=!tetrahedron_switch;}
    
    
    if(e.target->getLabel()=="cam1 pixel switch"){cam1_pixel_switch=!cam1_pixel_switch;}
     if(e.target->getLabel()=="cam2 pixel switch"){cam2_pixel_switch=!cam2_pixel_switch;}

    
    if(e.target->getLabel()=="fb0 pixel switch"){fb0_pixel_switch=!fb0_pixel_switch;}
    
    if(e.target->getLabel()=="fb1 pixel switch"){fb1_pixel_switch=!fb1_pixel_switch;}
    
    if(e.target->getLabel()=="fb2 pixel switch"){fb2_pixel_switch=!fb2_pixel_switch;}
    
     if(e.target->getLabel()=="fb3 pixel switch"){fb3_pixel_switch=!fb3_pixel_switch;}

    if(e.target->getLabel()=="cam1 h mirror"){cam1_hflip_switch=!cam1_hflip_switch;}
    if(e.target->getLabel()=="cam1 v mirror"){cam1_vflip_switch=!cam1_vflip_switch;}
    
    if(e.target->getLabel()=="cam2 h mirror"){cam2_hflip_switch=!cam2_hflip_switch;}
    if(e.target->getLabel()=="cam2 v mirror"){cam2_vflip_switch=!cam2_vflip_switch;}
    
    if(e.target->getLabel()=="fb0 h mirror"){fb0_hflip_switch=!fb0_hflip_switch;}
    if(e.target->getLabel()=="fb0 v mirror"){fb0_vflip_switch=!fb0_vflip_switch;}
    
    if(e.target->getLabel()=="fb1 h mirror"){fb1_hflip_switch=!fb1_hflip_switch;}
    if(e.target->getLabel()=="fb1 v mirror"){fb1_vflip_switch=!fb1_vflip_switch;}
    
    if(e.target->getLabel()=="fb2 h mirror"){fb2_hflip_switch=!fb2_hflip_switch;}
    if(e.target->getLabel()=="fb2 v mirror"){fb2_vflip_switch=!fb2_vflip_switch;}
    
    if(e.target->getLabel()=="fb3 h mirror"){fb3_hflip_switch=!fb3_hflip_switch;}
    if(e.target->getLabel()=="fb3 v mirror"){fb3_vflip_switch=!fb3_vflip_switch;}

    
    if(e.target->getLabel()=="hue0 invert"){fb0_hue_invert=!fb0_hue_invert;}
    
    if(e.target->getLabel()=="saturationg0 invert"){fb0_saturation_invert=!fb0_saturation_invert;}
    
    if(e.target->getLabel()=="bright0 invert"){fb0_bright_invert=!fb0_bright_invert;}
    
    if(e.target->getLabel()=="hue1 invert"){fb1_hue_invert=!fb1_hue_invert;}
    
    if(e.target->getLabel()=="saturationg1 invert"){fb1_saturation_invert=!fb1_saturation_invert;}
    
    if(e.target->getLabel()=="bright1 invert"){fb1_bright_invert=!fb1_bright_invert;}
    
    if(e.target->getLabel()=="hue2 invert"){fb2_hue_invert=!fb2_hue_invert;}
    
    if(e.target->getLabel()=="saturationg2 invert"){fb2_saturation_invert=!fb2_saturation_invert;}
    
    if(e.target->getLabel()=="bright2 invert"){fb2_bright_invert=!fb2_bright_invert;}
    
    if(e.target->getLabel()=="hue3 invert"){fb3_hue_invert=!fb3_hue_invert;}
    
    if(e.target->getLabel()=="saturationg3 invert"){fb3_saturation_invert=!fb3_saturation_invert;}
    
    if(e.target->getLabel()=="bright3 invert"){fb3_bright_invert=!fb3_bright_invert;}
    
    

    
    
    if(e.target->getLabel() == "syphon out"){ syphonOutput=!syphonOutput;}
    
    
    
    
    
    //channel1toggles
    if(e.target->getLabel() == "ch1huepowmap"){
        ch1hue_powmaptoggle =! ch1hue_powmaptoggle;
    }
    
    if(e.target->getLabel() == "ch1satpowmap"){
        ch1sat_powmaptoggle =! ch1sat_powmaptoggle;
    }

    
    if(e.target->getLabel() == "ch1brightpowmap"){
        ch1bright_powmaptoggle =! ch1bright_powmaptoggle;
    }
    
    if(e.target->getLabel() == "ch1hueinvert"){
        ch1hue_powmaptoggle =! ch1hue_powmaptoggle;
    }
    
    if(e.target->getLabel() == "ch1satinvert"){
        ch1sat_inverttoggle =! ch1sat_inverttoggle;
    }
    
    
    if(e.target->getLabel() == "ch1brightinvert"){
        ch1bright_inverttoggle =! ch1bright_inverttoggle;
    }


    //----
    
    if(e.target->getLabel() == "ch1satwrap"){
        channel1satwrap =! channel1satwrap;
    }
    
    if(e.target->getLabel() == "ch1brightwrap"){
        channel1brightwrap =! channel1brightwrap;
    }
    
    
    //channel2toggles
    if(e.target->getLabel() == "ch2huepowmap"){
        ch2hue_powmaptoggle =! ch2hue_powmaptoggle;
    }
    
    if(e.target->getLabel() == "ch2satpowmap"){
        ch2sat_powmaptoggle =! ch2sat_powmaptoggle;
    }
    
    
    if(e.target->getLabel() == "ch2brightpowmap"){
        ch2bright_powmaptoggle =! ch2bright_powmaptoggle;
    }
    
    //----
    
    if(e.target->getLabel() == "ch2satwrap"){
        channel2satwrap =! channel2satwrap;
    }
    
    if(e.target->getLabel() == "ch2brightwrap"){
        channel2brightwrap =! channel2brightwrap;
    }
    
    
    if(e.target->getLabel() == "ch2hueinvert"){
        ch2hue_powmaptoggle =! ch2hue_powmaptoggle;
    }
    
    if(e.target->getLabel() == "ch2satinvert"){
        ch2sat_inverttoggle =! ch2sat_inverttoggle;
    }
    
    
    if(e.target->getLabel() == "ch2brightinvert"){
        ch2bright_inverttoggle =! ch2bright_inverttoggle;
    }

 
    
  
    
}

//----------------------------------
    void GuiApp::update() {
       
    }


//------------------------------
    void GuiApp::draw() {
        
        
    }


//---------------------------




