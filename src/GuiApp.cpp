/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"
#include <iostream>


int fbob=30;

int guiscale=275;

void GuiApp::setup(){
    
    ofBackground(0);
   
     gui.setup();
    
  }


//----------------------------------
    void GuiApp::update() {
       
    }


//------------------------------
    void GuiApp::draw() {
        
        
        
        auto mainSettings = ofxImGui::Settings();
        
        //list variables for ranges...not this time but probably at some point in the future
        //should normalize everything in the gui to -1 1 and then add coeffecients in ofApp.cpp
        float x_y_d=40;
        float lfom=10;
        
        
        int gui_hscaler=170;
        int gui_vscaler=80;
        ImGui::SetNextWindowPos(ImVec2(0*gui_hscaler, 0*gui_vscaler), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        
        
        gui.begin();
        
        
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
        //channel 1 select folder
        if (ofxImGui::BeginWindow("channel1", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                //ah ok so this is a const char not a string
                ImGui::Text("i'm in a collapsable folder");
                
                
                //so for dropdown menues set up a char array of items like so
                const char* items[] = { "cam1","cam2", "ndi" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){channel1_select=1;}
                if(item_current==1){channel1_select=2;}
                if(item_current==2){channel1_select=3;}
                
                ImGui::SliderFloat("hue", &ch1_hue, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation", &ch1_saturation, -5.0f, 5.0f);
                ImGui::SliderFloat("bright", &ch1_bright, -5.0f, 5.0f);
                
                ImGui::Checkbox("hue_alternate_invert", &ch1_hue_alt_invert_toggle);
                ImGui::Checkbox("saturation_alternate_invert", &ch1_saturation_alt_invert_toggle);
                ImGui::Checkbox("bright_alternate_invert", &ch1_bright_alt_invert_toggle);
                
                ImGui::Checkbox("saturation_wrap", &ch1_saturation_wrap);
                ImGui::Checkbox("bright_wrap", &ch1_bright_wrap);
                
                ImGui::SliderFloat("hue_powmap", &ch1_hue_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation_powmap", &ch1_saturation_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("bright_powmap", &ch1_bright_powmap, -5.0f, 5.0f);
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Little False Ovals");
                
                ImGui::SliderFloat("hue rate", &ch1_hue_lfo_theta,  .0f, lfom);
                ImGui::SliderFloat("hue amp", &ch1_hue_lfo_amp, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation rate", &ch1_saturation_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("saturation amp", &ch1_saturation_lfo_amp, -5.0f, 5.0f);
                ImGui::SliderFloat("bright rate", &ch1_bright_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("bright amp", &ch1_bright_lfo_amp, -5.0f, 5.0f);
                
                //ImGui::SliderFloat("saturation", &ch1_saturation, -5.0f, 5.0f);
                //ImGui::SliderFloat("bright", &ch1_bright, -5.0f, 5.0f);
                
                
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        //ImGui::End();
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 1*gui_vscaler));
        //channel 2 select folder
        if (ofxImGui::BeginWindow("channel2", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                //ah ok so this is a const char not a string
                ImGui::Text("i'm in a collapsable folder");
                
                
                //so for dropdown menues set up a char array of items like so
                const char* items[] = { "cam1","cam2", "ndi" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){channel2_select=1;}
                if(item_current==1){channel2_select=2;}
                if(item_current==2){channel2_select=3;}
                
                ImGui::SliderFloat("ch2_mix", &ch2_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("ch2_key_value", &ch2_key_value, .0f, 1.0f);
                
                ImGui::SliderFloat("hue", &ch2_hue, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation", &ch2_saturation, -5.0f, 5.0f);
                ImGui::SliderFloat("bright", &ch2_bright, -5.0f, 5.0f);
                
                ImGui::Checkbox("hue_alternate_invert", &ch2_hue_alt_invert_toggle);
                ImGui::Checkbox("saturation_alternate_invert", &ch2_saturation_alt_invert_toggle);
                ImGui::Checkbox("bright_alternate_invert", &ch2_bright_alt_invert_toggle);
                
                ImGui::Checkbox("saturation_wrap", &ch2_saturation_wrap);
                ImGui::Checkbox("bright_wrap", &ch2_bright_wrap);
                
                ImGui::SliderFloat("hue_powmap", &ch2_hue_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation_powmap", &ch2_saturation_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("bright_powmap", &ch2_bright_powmap, -5.0f, 5.0f);
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lets Find Orangutangs");
                
                ImGui::SliderFloat("hue rate", &ch2_hue_lfo_theta,  .0f, lfom);
                ImGui::SliderFloat("hue amp", &ch2_hue_lfo_amp, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation rate", &ch2_saturation_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("saturation amp", &ch2_saturation_lfo_amp, -5.0f, 5.0f);
                ImGui::SliderFloat("bright rate", &ch2_bright_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("bright amp", &ch2_bright_lfo_amp, -5.0f, 5.0f);
                
                //ImGui::SliderFloat("saturation", &ch1_saturation, -5.0f, 5.0f);
                //ImGui::SliderFloat("bright", &ch1_bright, -5.0f, 5.0f);
                
                
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        //ImGui::End();
        
      
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 2*gui_vscaler));
        
        
        //fb0 folder
        if (ofxImGui::BeginWindow("fb0", mainSettings, false)){
        
            if (ImGui::CollapsingHeader("parameters")){
            
                ImGui::Checkbox("tex_mod", &fb0_tex_mod);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb0_texmod_select=1;}
                if(item_current==1){fb0_texmod_select=2;}
                
                if (ImGui::CollapsingHeader("mix and delay amount")){
                    if(fb0_tex_mod==false){
                        ImGui::SliderFloat("fb0_mix", &fb0_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb0_key_value", &fb0_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("fb0_key_threshold", &fb0_key_threshold, .0f, 1.0f);
                    }
                    
                    if(fb0_tex_mod==true){
                        ImGui::SliderFloat("texmod fb0_mix", &tex_fb0_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb0_key_value", &tex_fb0_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("texmod fb0_key_threshold", &tex_fb0_key_threshold, .0f, 1.0f);
                    }
                    ImGui::SliderInt("fb0_delay_amount", &fb0_delay_amount, 0, fbob-1);
                }
                if (ImGui::CollapsingHeader("misc switches")){
                    
                    const char* items2[] = { "clamp","toroid","mirror" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){fb0_toroid_switch=0;}
                    if(item_current2==1){fb0_toroid_switch=1;}
                    if(item_current2==2){fb0_toroid_switch=2;}
                    
                    ImGui::Checkbox("fb0_h_mirror", &fb0_hflip_switch);
                    ImGui::Checkbox("fb0_v_mirror", &fb0_vflip_switch);
                    //ImGui::Checkbox("fb0_toroid", &fb0_toroid_switch);
                    ImGui::Checkbox("fb0_hue_invert", &fb0_hue_invert);
                    ImGui::Checkbox("fb0_saturation_invert", &fb0_saturation_invert);
                    ImGui::Checkbox("fb0_bright_invert", &fb0_bright_invert);
                }
                if (ImGui::CollapsingHeader("fb0 ranges")){
                    ImGui::SliderFloat("fb0 x displace range", &fb0_x_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb0 y displace range", &fb0_y_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb0 z displace range", &fb0_z_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb0 rotate range", &fb0_rotate_range, .0001f, TWO_PI);
                }
                if (ImGui::CollapsingHeader("color space")){
                      if(fb0_tex_mod==false){
                          ImGui::SliderFloat("fb0_hue", &fb0_hue, 8.0f, 12.0f);
                          ImGui::SliderFloat("fb0_saturation", &fb0_saturation, 8.0f, 12.0f);
                          ImGui::SliderFloat("fb0_bright", &fb0_bright, 8.0f, 12.0f);
                          ImGui::SliderFloat("fb0_huex_mod", &fb0_huex_mod, 0.0f, 10.0f);
                          ImGui::SliderFloat("fb0_huex_offset", &fb0_huex_offset, -20.0f, 20.0f);
                          ImGui::SliderFloat("fb0_huex_lfo", &fb0_huex_lfo, -20.0f, 20.0f);
                      }
                     if(fb0_tex_mod==true){
                         ImGui::SliderFloat("texmod fb0_hue", &tex_fb0_hue, -.25f, .25f);
                         ImGui::SliderFloat("texmod fb0_saturation", &tex_fb0_saturation, -.25f, .25f);
                         ImGui::SliderFloat("texmod fb0_bright", &tex_fb0_bright, -.25f, .25f);
                         ImGui::SliderFloat("texmod fb0_huex_mod", &tex_fb0_huex_mod, -1.0f, 0.0f);
                         ImGui::SliderFloat("texmod fb0_huex_offset", &tex_fb0_huex_offset, -2.0f, 2.0f);
                         ImGui::SliderFloat("texmod fb0_huex_lfo", &tex_fb0_huex_lfo, -2.0f, 2.0f);
                     }
                 }
                if (ImGui::CollapsingHeader("geometry")){
                    if(fb0_tex_mod==false){
                        ImGui::SliderFloat("fb0_x", &fb0_x_displace, -fb0_x_displace_range, fb0_x_displace_range);
                        ImGui::SliderFloat("fb0_y", &fb0_y_displace, -fb0_y_displace_range, fb0_y_displace_range);
                        ImGui::SliderFloat("fb0_z", &fb0_z_displace,  100.0f-fb0_z_displace_range, 100.0f+fb0_z_displace_range);
                        ImGui::SliderFloat("fb0_rotate", &fb0_rotate, -fb0_rotate_range, fb0_rotate_range);
                    }
                    if(fb0_tex_mod==true){
                        ImGui::SliderFloat("texmod fb0_x", &tex_fb0_x_displace, -fb0_x_displace_range, fb0_x_displace_range);
                        ImGui::SliderFloat("texmod fb0_y", &tex_fb0_y_displace,  -fb0_y_displace_range, fb0_y_displace_range);
                        ImGui::SliderFloat("texmod fb0_z", &tex_fb0_z_displace,  -fb0_y_displace_range, fb0_y_displace_range);
                        ImGui::SliderFloat("texmod fb0_rotate", &tex_fb0_rotate, -fb0_rotate_range, fb0_rotate_range);
                    }
                }
               
                
                
                
            }//end collapsing folder
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
               ImGui::Text("Loose Floating Object s");
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    ImGui::SliderFloat("fb0_mix_lfo_rate", &fb0_mix_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_mix_lfo_amp", &fb0_mix_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb0_lumakeyvalue_lfo_rate", &fb0_lumakeyvalue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_lumakeyvalue_lfo_amp", &fb0_lumakeyvalue_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb0_lumakeythreshold_lfo_rate", &fb0_lumakeythreshold_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_lumakeythreshold_lfo_amp", &fb0_lumakeythreshold_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb0_delay_lfo_rate", &fb0_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb0_delay_lfo_amp", &fb0_delay_lfo_amp, -1.0f, 1.0f);
                }
                if (ImGui::CollapsingHeader("color space lfo")){
                    ImGui::SliderFloat("fb0_hue_lfo_rate", &fb0_hue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_hue_lfo_amp", &fb0_hue_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb0_saturation_lfo_rate", &fb0_saturation_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_saturation_lfo_amp", &fb0_saturation_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb0_bright_lfo_rate", &fb0_bright_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_bright_lfo_amp", &fb0_bright_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb0_huexmod_lfo_rate", &fb0_huexmod_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_huexmod_lfo_amp", &fb0_huexmod_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb0_huexoffset_lfo_rate", &fb0_huexoffset_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_huexoffset_lfo_amp", &fb0_huexoffset_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb0_huexlfo_lfo_rate", &fb0_huexlfo_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_huexlfo_lfo_amp", &fb0_huexlfo_lfo_amp, -10.0f, 10.0f);
                }
                if (ImGui::CollapsingHeader("geometry lfo")){
                    ImGui::SliderFloat("fb0_x_displace_lfo_rate", &fb0_x_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_x_displace_lfo_amp", &fb0_x_lfo_amp, -fb0_x_displace_range, fb0_x_displace_range);
                    ImGui::SliderFloat("fb0_y_displace_lfo_rate", &fb0_y_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_y_displace_lfo_amp", &fb0_y_lfo_amp, -fb0_y_displace_range, fb0_y_displace_range);
                    ImGui::SliderFloat("fb0_z_displace_lfo_rate", &fb0_z_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_z_displace_lfo_amp", &fb0_z_lfo_amp, -fb0_z_displace_range, fb0_z_displace_range);
                    ImGui::SliderFloat("fb0_rotate_lfo_rate", &fb0_rotate_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb0_rotate_lfo_amp", &fb0_rotate_lfo_amp, -fb0_rotate_range, fb0_rotate_range);
                }
                
            }//endlfo folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 3*gui_vscaler));
        //fb1 folder
        if (ofxImGui::BeginWindow("fb1", mainSettings, false)){
            
            if (ImGui::CollapsingHeader("parameters")){
                
                ImGui::Checkbox("tex_mod", &fb1_tex_mod);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb1_texmod_select=1;}
                if(item_current==1){fb1_texmod_select=2;}
                
                if (ImGui::CollapsingHeader("mix and delay amount")){
                    if(fb1_tex_mod==false){
                        ImGui::SliderFloat("fb1_mix", &fb1_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb1_key_value", &fb1_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("fb1_key_threshold", &fb1_key_threshold, .0f, 1.0f);
                    }
                    
                    if(fb1_tex_mod==true){
                        ImGui::SliderFloat("texmod fb1_mix", &tex_fb1_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb1_key_value", &tex_fb1_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("texmod fb1_key_threshold", &tex_fb1_key_threshold, .0f, 1.0f);
                    }
                    ImGui::SliderInt("fb1_delay_amount", &fb1_delay_amount, 0, fbob-1);
                }
                if (ImGui::CollapsingHeader("misc switches")){
                    
                    const char* items2[] = { "clamp","toroid","mirror" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){fb1_toroid_switch=0;}
                    if(item_current2==1){fb1_toroid_switch=1;}
                    if(item_current2==2){fb1_toroid_switch=2;}
                    
                    ImGui::Checkbox("fb1_h_mirror", &fb1_hflip_switch);
                    ImGui::Checkbox("fb1_v_mirror", &fb1_vflip_switch);
                    //ImGui::Checkbox("fb1_toroid", &fb1_toroid_switch);
                    ImGui::Checkbox("fb1_hue_invert", &fb1_hue_invert);
                    ImGui::Checkbox("fb1_saturation_invert", &fb1_saturation_invert);
                    ImGui::Checkbox("fb1_bright_invert", &fb1_bright_invert);
                }
                if (ImGui::CollapsingHeader("fb1 ranges")){
                    ImGui::SliderFloat("fb1 x displace range", &fb1_x_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb1 y displace range", &fb1_y_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb1 z displace range", &fb1_z_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb1 rotate range", &fb1_rotate_range, .0001f, TWO_PI);
                }
                if (ImGui::CollapsingHeader("color space")){
                    if(fb1_tex_mod==false){
                        ImGui::SliderFloat("fb1_hue", &fb1_hue, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb1_saturation", &fb1_saturation, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb1_bright", &fb1_bright, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb1_huex_mod", &fb1_huex_mod, 0.0f, 10.0f);
                        ImGui::SliderFloat("fb1_huex_offset", &fb1_huex_offset, -20.0f, 20.0f);
                        ImGui::SliderFloat("fb1_huex_lfo", &fb1_huex_lfo, -20.0f, 20.0f);
                    }
                    if(fb1_tex_mod==true){
                        ImGui::SliderFloat("texmod fb1_hue", &tex_fb1_hue, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb1_saturation", &tex_fb1_saturation, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb1_bright", &tex_fb1_bright, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb1_huex_mod", &tex_fb1_huex_mod, -1.0f, 0.0f);
                        ImGui::SliderFloat("texmod fb1_huex_offset", &tex_fb1_huex_offset, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb1_huex_lfo", &tex_fb1_huex_lfo, -2.0f, 2.0f);
                    }
                }
                if (ImGui::CollapsingHeader("geometry")){
                    if(fb1_tex_mod==false){
                        ImGui::SliderFloat("fb1_x", &fb1_x_displace, -fb1_x_displace_range, fb1_x_displace_range);
                        ImGui::SliderFloat("fb1_y", &fb1_y_displace, -fb1_y_displace_range, fb1_y_displace_range);
                        ImGui::SliderFloat("fb1_z", &fb1_z_displace,  100.0f-fb1_z_displace_range, 100.0f+fb1_z_displace_range);
                        ImGui::SliderFloat("fb1_rotate", &fb1_rotate, -fb1_rotate_range, fb1_rotate_range);
                    }
                    if(fb1_tex_mod==true){
                        ImGui::SliderFloat("texmod fb1_x", &tex_fb1_x_displace, -fb1_x_displace_range, fb1_x_displace_range);
                        ImGui::SliderFloat("texmod fb1_y", &tex_fb1_y_displace,  -fb1_y_displace_range, fb1_y_displace_range);
                        ImGui::SliderFloat("texmod fb1_z", &tex_fb1_z_displace,  -fb1_y_displace_range, fb1_y_displace_range);
                        ImGui::SliderFloat("texmod fb1_rotate", &tex_fb1_rotate, -fb1_rotate_range, fb1_rotate_range);
                    }
                }
                
                
                
                
            }//end collapsing folder
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Light Fluffy Orb s");
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    ImGui::SliderFloat("fb1_mix_lfo_rate", &fb1_mix_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_mix_lfo_amp", &fb1_mix_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb1_lumakeyvalue_lfo_rate", &fb1_lumakeyvalue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_lumakeyvalue_lfo_amp", &fb1_lumakeyvalue_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb1_lumakeythreshold_lfo_rate", &fb1_lumakeythreshold_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_lumakeythreshold_lfo_amp", &fb1_lumakeythreshold_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb1_delay_lfo_rate", &fb1_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb1_delay_lfo_amp", &fb1_delay_lfo_amp, -1.0f, 1.0f);
                }
                if (ImGui::CollapsingHeader("color space lfo")){
                    ImGui::SliderFloat("fb1_hue_lfo_rate", &fb1_hue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_hue_lfo_amp", &fb1_hue_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb1_saturation_lfo_rate", &fb1_saturation_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_saturation_lfo_amp", &fb1_saturation_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb1_bright_lfo_rate", &fb1_bright_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_bright_lfo_amp", &fb1_bright_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb1_huexmod_lfo_rate", &fb1_huexmod_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_huexmod_lfo_amp", &fb1_huexmod_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb1_huexoffset_lfo_rate", &fb1_huexoffset_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_huexoffset_lfo_amp", &fb1_huexoffset_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb1_huexlfo_lfo_rate", &fb1_huexlfo_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_huexlfo_lfo_amp", &fb1_huexlfo_lfo_amp, -10.0f, 10.0f);
                }
                if (ImGui::CollapsingHeader("geometry lfo")){
                    ImGui::SliderFloat("fb1_x_displace_lfo_rate", &fb1_x_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_x_displace_lfo_amp", &fb1_x_lfo_amp, -fb1_x_displace_range, fb1_x_displace_range);
                    ImGui::SliderFloat("fb1_y_displace_lfo_rate", &fb1_y_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_y_displace_lfo_amp", &fb1_y_lfo_amp, -fb1_y_displace_range, fb1_y_displace_range);
                    ImGui::SliderFloat("fb1_z_displace_lfo_rate", &fb1_z_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_z_displace_lfo_amp", &fb1_z_lfo_amp, -fb1_z_displace_range, fb1_z_displace_range);
                    ImGui::SliderFloat("fb1_rotate_lfo_rate", &fb1_rotate_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb1_rotate_lfo_amp", &fb1_rotate_lfo_amp, -fb1_rotate_range, fb1_rotate_range);
                }
                
            }//endlfo folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 4*gui_vscaler));
        //fb2 folder
        if (ofxImGui::BeginWindow("fb2", mainSettings, false)){
            
            if (ImGui::CollapsingHeader("parameters")){
                
                ImGui::Checkbox("tex_mod", &fb2_tex_mod);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb2_texmod_select=1;}
                if(item_current==1){fb2_texmod_select=2;}
                
                if (ImGui::CollapsingHeader("mix and delay amount")){
                    if(fb2_tex_mod==false){
                        ImGui::SliderFloat("fb2_mix", &fb2_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb2_key_value", &fb2_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("fb2_key_threshold", &fb2_key_threshold, .0f, 1.0f);
                    }
                    
                    if(fb2_tex_mod==true){
                        ImGui::SliderFloat("texmod fb2_mix", &tex_fb2_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb2_key_value", &tex_fb2_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("texmod fb2_key_threshold", &tex_fb2_key_threshold, .0f, 1.0f);
                    }
                    ImGui::SliderInt("fb2_delay_amount", &fb2_delay_amount, 0, fbob-1);
                }
                if (ImGui::CollapsingHeader("misc switches")){
                    
                    const char* items2[] = { "clamp","toroid","mirror" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){fb2_toroid_switch=0;}
                    if(item_current2==1){fb2_toroid_switch=1;}
                    if(item_current2==2){fb2_toroid_switch=2;}
                    
                    ImGui::Checkbox("fb2_h_mirror", &fb2_hflip_switch);
                    ImGui::Checkbox("fb2_v_mirror", &fb2_vflip_switch);
                    //ImGui::Checkbox("fb2_toroid", &fb2_toroid_switch);
                    ImGui::Checkbox("fb2_hue_invert", &fb2_hue_invert);
                    ImGui::Checkbox("fb2_saturation_invert", &fb2_saturation_invert);
                    ImGui::Checkbox("fb2_bright_invert", &fb2_bright_invert);
                }
                if (ImGui::CollapsingHeader("fb2 ranges")){
                    ImGui::SliderFloat("fb2 x displace range", &fb2_x_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb2 y displace range", &fb2_y_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb2 z displace range", &fb2_z_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb2 rotate range", &fb2_rotate_range, .0001f, TWO_PI);
                }
                if (ImGui::CollapsingHeader("color space")){
                    if(fb2_tex_mod==false){
                        ImGui::SliderFloat("fb2_hue", &fb2_hue, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb2_saturation", &fb2_saturation, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb2_bright", &fb2_bright, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb2_huex_mod", &fb2_huex_mod, 0.0f, 10.0f);
                        ImGui::SliderFloat("fb2_huex_offset", &fb2_huex_offset, -20.0f, 20.0f);
                        ImGui::SliderFloat("fb2_huex_lfo", &fb2_huex_lfo, -20.0f, 20.0f);
                    }
                    if(fb2_tex_mod==true){
                        ImGui::SliderFloat("texmod fb2_hue", &tex_fb2_hue, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb2_saturation", &tex_fb2_saturation, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb2_bright", &tex_fb2_bright, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb2_huex_mod", &tex_fb2_huex_mod, -1.0f, 0.0f);
                        ImGui::SliderFloat("texmod fb2_huex_offset", &tex_fb2_huex_offset, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb2_huex_lfo", &tex_fb2_huex_lfo, -2.0f, 2.0f);
                    }
                }
                if (ImGui::CollapsingHeader("geometry")){
                    if(fb2_tex_mod==false){
                        ImGui::SliderFloat("fb2_x", &fb2_x_displace, -fb2_x_displace_range, fb2_x_displace_range);
                        ImGui::SliderFloat("fb2_y", &fb2_y_displace, -fb2_y_displace_range, fb2_y_displace_range);
                        ImGui::SliderFloat("fb2_z", &fb2_z_displace,  100.0f-fb2_z_displace_range, 100.0f+fb2_z_displace_range);
                        ImGui::SliderFloat("fb2_rotate", &fb2_rotate, -fb2_rotate_range, fb2_rotate_range);
                    }
                    if(fb2_tex_mod==true){
                        ImGui::SliderFloat("texmod fb2_x", &tex_fb2_x_displace, -fb2_x_displace_range, fb2_x_displace_range);
                        ImGui::SliderFloat("texmod fb2_y", &tex_fb2_y_displace,  -fb2_y_displace_range, fb2_y_displace_range);
                        ImGui::SliderFloat("texmod fb2_z", &tex_fb2_z_displace,  -fb2_y_displace_range, fb2_y_displace_range);
                        ImGui::SliderFloat("texmod fb2_rotate", &tex_fb2_rotate, -fb2_rotate_range, fb2_rotate_range);
                    }
                }
                
                
                
                
            }//end collapsing folder
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Lucid Forensic Optometrist s");
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    ImGui::SliderFloat("fb2_mix_lfo_rate", &fb2_mix_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_mix_lfo_amp", &fb2_mix_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb2_lumakeyvalue_lfo_rate", &fb2_lumakeyvalue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_lumakeyvalue_lfo_amp", &fb2_lumakeyvalue_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb2_lumakeythreshold_lfo_rate", &fb2_lumakeythreshold_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_lumakeythreshold_lfo_amp", &fb2_lumakeythreshold_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb2_delay_lfo_rate", &fb2_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb2_delay_lfo_amp", &fb2_delay_lfo_amp, -1.0f, 1.0f);
                }
                if (ImGui::CollapsingHeader("color space lfo")){
                    ImGui::SliderFloat("fb2_hue_lfo_rate", &fb2_hue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_hue_lfo_amp", &fb2_hue_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb2_saturation_lfo_rate", &fb2_saturation_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_saturation_lfo_amp", &fb2_saturation_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb2_bright_lfo_rate", &fb2_bright_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_bright_lfo_amp", &fb2_bright_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb2_huexmod_lfo_rate", &fb2_huexmod_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_huexmod_lfo_amp", &fb2_huexmod_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb2_huexoffset_lfo_rate", &fb2_huexoffset_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_huexoffset_lfo_amp", &fb2_huexoffset_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb2_huexlfo_lfo_rate", &fb2_huexlfo_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_huexlfo_lfo_amp", &fb2_huexlfo_lfo_amp, -10.0f, 10.0f);
                }
                if (ImGui::CollapsingHeader("geometry lfo")){
                    ImGui::SliderFloat("fb2_x_displace_lfo_rate", &fb2_x_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_x_displace_lfo_amp", &fb2_x_lfo_amp, -fb2_x_displace_range, fb2_x_displace_range);
                    ImGui::SliderFloat("fb2_y_displace_lfo_rate", &fb2_y_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_y_displace_lfo_amp", &fb2_y_lfo_amp, -fb2_y_displace_range, fb2_y_displace_range);
                    ImGui::SliderFloat("fb2_z_displace_lfo_rate", &fb2_z_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_z_displace_lfo_amp", &fb2_z_lfo_amp, -fb2_z_displace_range, fb2_z_displace_range);
                    ImGui::SliderFloat("fb2_rotate_lfo_rate", &fb2_rotate_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb2_rotate_lfo_amp", &fb2_rotate_lfo_amp, -fb2_rotate_range, fb2_rotate_range);
                }
                
            }//endlfo folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 5*gui_vscaler));
        //fb3 folder
        if (ofxImGui::BeginWindow("fb3", mainSettings, false)){
            
            if (ImGui::CollapsingHeader("parameters")){
                
                ImGui::Checkbox("tex_mod", &fb3_tex_mod);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb3_texmod_select=1;}
                if(item_current==1){fb3_texmod_select=2;}
                
                if (ImGui::CollapsingHeader("mix and delay amount")){
                    if(fb3_tex_mod==false){
                        ImGui::SliderFloat("fb3_mix", &fb3_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb3_key_value", &fb3_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("fb3_key_threshold", &fb3_key_threshold, .0f, 1.0f);
                    }
                    
                    if(fb3_tex_mod==true){
                        ImGui::SliderFloat("texmod fb3_mix", &tex_fb3_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb3_key_value", &tex_fb3_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("texmod fb3_key_threshold", &tex_fb3_key_threshold, .0f, 1.0f);
                    }
                    ImGui::SliderInt("fb3_delay_amount", &fb3_delay_amount, 0, fbob-1);
                }
                if (ImGui::CollapsingHeader("misc switches")){
                    
                    const char* items2[] = { "clamp","toroid","mirror" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){fb3_toroid_switch=0;}
                    if(item_current2==1){fb3_toroid_switch=1;}
                    if(item_current2==2){fb3_toroid_switch=2;}
                    
                    ImGui::Checkbox("fb3_h_mirror", &fb3_hflip_switch);
                    ImGui::Checkbox("fb3_v_mirror", &fb3_vflip_switch);
                    //ImGui::Checkbox("fb3_toroid", &fb3_toroid_switch);
                    ImGui::Checkbox("fb3_hue_invert", &fb3_hue_invert);
                    ImGui::Checkbox("fb3_saturation_invert", &fb3_saturation_invert);
                    ImGui::Checkbox("fb3_bright_invert", &fb3_bright_invert);
                }
                if (ImGui::CollapsingHeader("fb3 ranges")){
                    ImGui::SliderFloat("fb3 x displace range", &fb3_x_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb3 y displace range", &fb3_y_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb3 z displace range", &fb3_z_displace_range, .0001f, 100.0f);
                    ImGui::SliderFloat("fb3 rotate range", &fb3_rotate_range, .0001f, TWO_PI);
                }
                if (ImGui::CollapsingHeader("color space")){
                    if(fb3_tex_mod==false){
                        ImGui::SliderFloat("fb3_hue", &fb3_hue, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb3_saturation", &fb3_saturation, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb3_bright", &fb3_bright, 8.0f, 12.0f);
                        ImGui::SliderFloat("fb3_huex_mod", &fb3_huex_mod, 0.0f, 10.0f);
                        ImGui::SliderFloat("fb3_huex_offset", &fb3_huex_offset, -20.0f, 20.0f);
                        ImGui::SliderFloat("fb3_huex_lfo", &fb3_huex_lfo, -20.0f, 20.0f);
                    }
                    if(fb3_tex_mod==true){
                        ImGui::SliderFloat("texmod fb3_hue", &tex_fb3_hue, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb3_saturation", &tex_fb3_saturation, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb3_bright", &tex_fb3_bright, -.25f, .25f);
                        ImGui::SliderFloat("texmod fb3_huex_mod", &tex_fb3_huex_mod, -1.0f, 0.0f);
                        ImGui::SliderFloat("texmod fb3_huex_offset", &tex_fb3_huex_offset, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb3_huex_lfo", &tex_fb3_huex_lfo, -2.0f, 2.0f);
                    }
                }
                if (ImGui::CollapsingHeader("geometry")){
                    if(fb3_tex_mod==false){
                        ImGui::SliderFloat("fb3_x", &fb3_x_displace, -fb3_x_displace_range, fb3_x_displace_range);
                        ImGui::SliderFloat("fb3_y", &fb3_y_displace, -fb3_y_displace_range, fb3_y_displace_range);
                        ImGui::SliderFloat("fb3_z", &fb3_z_displace,  100.0f-fb3_z_displace_range, 100.0f+fb3_z_displace_range);
                        ImGui::SliderFloat("fb3_rotate", &fb3_rotate, -fb3_rotate_range, fb3_rotate_range);
                    }
                    if(fb3_tex_mod==true){
                        ImGui::SliderFloat("texmod fb3_x", &tex_fb3_x_displace, -fb3_x_displace_range, fb3_x_displace_range);
                        ImGui::SliderFloat("texmod fb3_y", &tex_fb3_y_displace,  -fb3_y_displace_range, fb3_y_displace_range);
                        ImGui::SliderFloat("texmod fb3_z", &tex_fb3_z_displace,  -fb3_y_displace_range, fb3_y_displace_range);
                        ImGui::SliderFloat("texmod fb3_rotate", &tex_fb3_rotate, -fb3_rotate_range, fb3_rotate_range);
                    }
                }
                
                
                
                
            }//end collapsing folder
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Languid Fox Organizer s");
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    ImGui::SliderFloat("fb3_mix_lfo_rate", &fb3_mix_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_mix_lfo_amp", &fb3_mix_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb3_lumakeyvalue_lfo_rate", &fb3_lumakeyvalue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_lumakeyvalue_lfo_amp", &fb3_lumakeyvalue_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb3_lumakeythreshold_lfo_rate", &fb3_lumakeythreshold_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_lumakeythreshold_lfo_amp", &fb3_lumakeythreshold_lfo_amp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb3_delay_lfo_rate", &fb3_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb3_delay_lfo_amp", &fb3_delay_lfo_amp, -1.0f, 1.0f);
                }
                if (ImGui::CollapsingHeader("color space lfo")){
                    ImGui::SliderFloat("fb3_hue_lfo_rate", &fb3_hue_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_hue_lfo_amp", &fb3_hue_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb3_saturation_lfo_rate", &fb3_saturation_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_saturation_lfo_amp", &fb3_saturation_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb3_bright_lfo_rate", &fb3_bright_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_bright_lfo_amp", &fb3_bright_lfo_amp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb3_huexmod_lfo_rate", &fb3_huexmod_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_huexmod_lfo_amp", &fb3_huexmod_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb3_huexoffset_lfo_rate", &fb3_huexoffset_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_huexoffset_lfo_amp", &fb3_huexoffset_lfo_amp, -10.0f, 10.0f);
                    ImGui::SliderFloat("fb3_huexlfo_lfo_rate", &fb3_huexlfo_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_huexlfo_lfo_amp", &fb3_huexlfo_lfo_amp, -10.0f, 10.0f);
                }
                if (ImGui::CollapsingHeader("geometry lfo")){
                    ImGui::SliderFloat("fb3_x_displace_lfo_rate", &fb3_x_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_x_displace_lfo_amp", &fb3_x_lfo_amp, -fb3_x_displace_range, fb3_x_displace_range);
                    ImGui::SliderFloat("fb3_y_displace_lfo_rate", &fb3_y_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_y_displace_lfo_amp", &fb3_y_lfo_amp, -fb3_y_displace_range, fb3_y_displace_range);
                    ImGui::SliderFloat("fb3_z_displace_lfo_rate", &fb3_z_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_z_displace_lfo_amp", &fb3_z_lfo_amp, -fb3_z_displace_range, fb3_z_displace_range);
                    ImGui::SliderFloat("fb3_rotate_lfo_rate", &fb3_rotate_lfo_theta, .0f, lfom);
                    ImGui::SliderFloat("fb3_rotate_lfo_amp", &fb3_rotate_lfo_amp, -fb3_rotate_range, fb3_rotate_range);
                }
                
            }//endlfo folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 6*gui_vscaler));
        ImGui::SetNextWindowPos(ImVec2(600, 600), ImGuiCond_FirstUseEver);
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        //global folder
        if (ofxImGui::BeginWindow("global", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("tex_mod", &global_texmod);
                
                const char* items[] = { "cam1","cam2","ndi" };
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){global_texmod_select=0;}
                if(item_current==1){global_texmod_select=1;}
                if(item_current==2){global_texmod_select=2;}
                
                //ImGui::Button("framebuffer clear");
                framebuffer_clear=false;
                ImGui::Checkbox("framebuffer clear", &framebuffer_clear);
                
                control_reset=false;
                ImGui::Checkbox("control_reset", &control_reset);
                
                if(global_texmod==false){
                    //blur
                    ImGui::SliderFloat("blur amount", &blur_amount, -2.0f, 2.0f);
                    ImGui::SliderFloat("blur radius", &blur_radius, .0f, 10.0f);
                    //sharpen
                    ImGui::SliderFloat("sharpen", &sharpen_amount, -.6f, .6f);
                    ImGui::SliderFloat("sharpen_radius", &sharpen_radius, .0f, 10.f);
                    
                    ImGui::SliderFloat("sharpen_boost", &sharpen_boost, .0f, 1.0f);
                }
                
                if(global_texmod==true){
                    //blur
                    ImGui::SliderFloat("texmod blur amount", &texmod_blur_amount, -4.0f, 4.0f);
                    ImGui::SliderFloat("texmod blur radius", &texmod_blur_radius, -2.0f, 2.0f);
                    //sharpen
                    ImGui::SliderFloat("texmod sharpen", &texmod_sharpen_amount, -.6f, .6f);
                    ImGui::SliderFloat("texmod sharpen_radius", &texmod_sharpen_radius, .0f, 10.f);
                    
                    ImGui::SliderFloat("texmod sharpen_boost", &texmod_sharpen_boost, -.4f, .4f);
                }
                //ImGui::SliderFloat("sharpen_chi", &sharpen_chi, .0f, 2.f);

                //camscale
                ImGui::SliderFloat("cam1_scale", &cam1_scale, .0f, 2.0f);
                ImGui::SliderFloat("cam2_scale", &cam2_scale, .0f, 2.0f);
                ImGui::SliderFloat("ndi_scale", &ndi_scale, -1000.0f, 500.0f);
                //camflip
                ImGui::Checkbox("cam1_hflip", &cam1_hflip_switch);
                ImGui::Checkbox("cam1_vflip", &cam1_vflip_switch);
                ImGui::Checkbox("cam2_hflip", &cam2_hflip_switch);
                ImGui::Checkbox("cam2_vflip", &cam2_vflip_switch);
                //xskew
                ImGui::SliderFloat("x_skew", &x_skew, -3.14f, 3.14f);
                //yskew
                ImGui::SliderFloat("y_skew", &y_skew, -3.14f, 3.14f);
                //tetrahedron
                ImGui::Checkbox("tetrahedron", &tetrahedron_switch);
                //hypercube
                ImGui::Checkbox("hypercube", &hypercube_switch);
                ImGui::SliderFloat("hypercube_theta_rate", &hypercube_theta_rate, -.1,.1);
                ImGui::SliderFloat("hypercube_phi_rate", &hypercube_phi_rate, -.1,.1);
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lusty Fresh Onagers s");
                
                ImGui::SliderFloat("blur_lfo_amp", &blur_amount_lfo_amp, -10.0f, 10.0f);
                ImGui::SliderFloat("blur_lfo_rate", &blur_amount_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("blur_radius_lfo_amp", &blur_radius_lfo_amp, -10.0f, 10.0f);
                ImGui::SliderFloat("blur_radius_lfo_rate", &blur_radius_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_lfo_amp", &sharpen_amount_lfo_amp, -.6f, .6f);
                ImGui::SliderFloat("sharpen_lfo_rate", &sharpen_amount_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_radius_lfo_amp", &sharpen_radius_lfo_amp, -10.0f, 10.f);
                ImGui::SliderFloat("sharpen_radius_lfo_rate", &sharpen_radius_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_boost_lfo_amp", &sharpen_boost_lfo_amp, -1.0f, 1.0f);
                ImGui::SliderFloat("sharpen_boost_lfo_rate", &sharpen_boost_lfo_theta, .0f, 20.0f);

            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 0*gui_vscaler));
        if (ofxImGui::BeginWindow("cam1_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &cam1_pixel_switch);
                ImGui::SliderInt("pixel scale_x", &cam1_pixel_scale_x, .0f, 256.0f);
                ImGui::SliderInt("pixel scale_y", &cam1_pixel_scale_y, .0f, 256.0f);
                ImGui::SliderFloat("pixel mix", &cam1_pixel_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("bright_scale", &cam1_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lfos For Oscillation s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &cam1_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &cam1_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &cam1_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &cam1_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &cam1_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &cam1_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &cam1_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &cam1_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 1*gui_vscaler));
        if (ofxImGui::BeginWindow("cam2_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &cam2_pixel_switch);
                ImGui::SliderInt("pixel scale_x", &cam2_pixel_scale_x, .0f, 256.0f);
                ImGui::SliderInt("pixel scale_y", &cam2_pixel_scale_y, .0f, 256.0f);
                ImGui::SliderFloat("pixel mix", &cam2_pixel_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("bright_scale", &cam2_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lascivious For Orgone s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &cam2_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &cam2_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &cam2_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &cam2_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &cam2_pixel_mix_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel mix_rate", &cam2_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &cam2_pixel_brightscale_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel bright scale rate", &cam2_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 2*gui_vscaler));
        if (ofxImGui::BeginWindow("fb0_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("tex_mod", &fb0_pixel_texmod);
                
                const char* items[] = { "channel1", "channel2"};
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb0_pixel_texmod_select=0;}
                if(item_current==1){fb0_pixel_texmod_select=1;}
                
                ImGui::Checkbox("pixelate", &fb0_pixel_switch);
                if(fb0_pixel_texmod==false){
                    ImGui::SliderInt("pixel scale x", &fb0_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale y", &fb0_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &fb0_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &fb0_pixel_brightscale, -2.0f, 2.0f);
                }
                
                if(fb0_pixel_texmod==true){
                    ImGui::SliderInt("texmod pixel scale x", &texmod_fb0_pixel_scale_x, -256.0f, 256.0f);
                    ImGui::SliderInt("texmod pixel scale y", &texmod_fb0_pixel_scale_y, -256.0f, 256.0f);
                    ImGui::SliderFloat("texmod pixel mix", &texmod_fb0_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("texmod bright_scale", &texmod_fb0_pixel_brightscale, -2.0f, 2.0f);
                }
                
               
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Love Flange Orgasms s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &fb0_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &fb0_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &fb0_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &fb0_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &fb0_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &fb0_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &fb0_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &fb0_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 3*gui_vscaler));
        if (ofxImGui::BeginWindow("fb1_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("tex_mod", &fb1_pixel_texmod);
                
                const char* items[] = { "channel1", "channel2"};
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb1_pixel_texmod_select=0;}
                if(item_current==1){fb1_pixel_texmod_select=1;}
                
                ImGui::Checkbox("pixelate", &fb1_pixel_switch);
                if(fb1_pixel_texmod==false){
                    ImGui::SliderInt("pixel scale x", &fb1_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale y", &fb1_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &fb1_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &fb1_pixel_brightscale, -2.0f, 2.0f);
                }
                
                if(fb1_pixel_texmod==true){
                    ImGui::SliderInt("texmod pixel scale x", &texmod_fb1_pixel_scale_x, -256.0f, 256.0f);
                    ImGui::SliderInt("texmod pixel scale y", &texmod_fb1_pixel_scale_y, -256.0f, 256.0f);
                    ImGui::SliderFloat("texmod pixel mix", &texmod_fb1_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("texmod bright_scale", &texmod_fb1_pixel_brightscale, -2.0f, 2.0f);
                }
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Loose Filbert Organ s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &fb1_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &fb1_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &fb1_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &fb1_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &fb1_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &fb1_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &fb1_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &fb1_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 4*gui_vscaler));
        if (ofxImGui::BeginWindow("fb2_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("tex_mod", &fb2_pixel_texmod);
                
                const char* items[] = { "channel1", "channel2"};
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb2_pixel_texmod_select=0;}
                if(item_current==1){fb2_pixel_texmod_select=1;}
                
                ImGui::Checkbox("pixelate", &fb2_pixel_switch);
                if(fb2_pixel_texmod==false){
                    ImGui::SliderInt("pixel scale x", &fb2_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale y", &fb2_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &fb2_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &fb2_pixel_brightscale, -2.0f, 2.0f);
                }
                
                if(fb2_pixel_texmod==true){
                    
                    ImGui::SliderInt("texmod pixel scale x", &texmod_fb2_pixel_scale_x, -256.0f, 256.0f);
                    ImGui::SliderInt("texmod pixel scale y", &texmod_fb2_pixel_scale_y, -256.0f, 256.0f);
                    ImGui::SliderFloat("texmod pixel mix", &texmod_fb2_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("texmod bright_scale", &texmod_fb2_pixel_brightscale, -2.0f, 2.0f);
                }
                
               
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lithe Floam Orthopedic s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &fb2_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &fb2_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &fb2_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &fb2_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &fb2_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &fb2_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &fb2_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &fb2_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 5*gui_vscaler));
        if (ofxImGui::BeginWindow("fb3_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("tex_mod", &fb3_pixel_texmod);
                
                const char* items[] = { "channel1", "channel2"};
                static int item_current = 0;
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
                if(item_current==0){fb3_pixel_texmod_select=0;}
                if(item_current==1){fb3_pixel_texmod_select=1;}
                
                ImGui::Checkbox("pixelate", &fb3_pixel_switch);
                if(fb3_pixel_texmod==false){
                    ImGui::SliderInt("pixel scale x", &fb3_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale y", &fb3_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &fb3_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &fb3_pixel_brightscale, -2.0f, 2.0f);
                }
                
                if(fb3_pixel_texmod==true){
                    ImGui::SliderInt("texmod pixel scale x", &texmod_fb3_pixel_scale_x, -256.0f, 256.0f);
                    ImGui::SliderInt("texmod pixel scale y", &texmod_fb3_pixel_scale_y, -256.0f, 256.0f);
                    ImGui::SliderFloat("texmod pixel mix", &texmod_fb3_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("texmod bright_scale", &texmod_fb3_pixel_brightscale, -2.0f, 2.0f);
                }
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Loamy Florid Onyx s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &fb3_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &fb3_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &fb3_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &fb3_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &fb3_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &fb3_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &fb3_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &fb3_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 6*gui_vscaler));
        if (ofxImGui::BeginWindow("ndi_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &ndi_pixel_switch);
                ImGui::SliderInt("pixel scale_x", &ndi_pixel_scale_x, .0f, 256.0f);
                ImGui::SliderInt("pixel scale_y", &ndi_pixel_scale_y, .0f, 256.0f);
                ImGui::SliderFloat("pixel mix", &ndi_pixel_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("bright_scale", &ndi_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Los Fuegos Oculto s");
                
                ImGui::SliderFloat("pixel scale_x_amp", &ndi_pixel_scale_x_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_x_rate", &ndi_pixel_scale_x_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel scale_y_amp", &ndi_pixel_scale_y_lfo_amp, -256.0f, 256.0f);
                ImGui::SliderFloat("pixel scale_y_rate", &ndi_pixel_scale_y_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel mix_amp", &ndi_pixel_mix_lfo_amp, -20.0f, 20.0f);
                ImGui::SliderFloat("pixel mix_rate", &ndi_pixel_mix_lfo_theta, .0f, 20.0f);
                
                ImGui::SliderFloat("pixel bright scale amp", &ndi_pixel_brightscale_lfo_amp, -2.0f, 2.0f);
                ImGui::SliderFloat("pixel bright scale rate", &ndi_pixel_brightscale_lfo_theta, .0f, 20.0f);
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
       
        
        gui.end();
        
    }


//---------------------------




