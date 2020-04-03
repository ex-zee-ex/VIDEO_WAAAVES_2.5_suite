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
   
     gui.setup();
    
  }


//----------------------------------
    void GuiApp::update() {
       
    }


//------------------------------
    void GuiApp::draw() {
        
        
        
        auto mainSettings = ofxImGui::Settings();
        
        float x_y_d=40;
        float lfom=10;
        
        
        int gui_hscaler=170;
        int gui_vscaler=80;
        ImGui::SetNextWindowPos(ImVec2(0*gui_hscaler, 0*gui_vscaler), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        
        
        gui.begin();
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
        //channel 1 select folder
        if (ofxImGui::BeginWindow("channel1", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                //ah ok so this is a const char not a string
                ImGui::Text("i'm in a collapsable folder");
                
                
                //so for dropdown menues set up a char array of items like so
                const char* items[] = { "cam1","cam2", "syphon" };
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
                ImGui::Checkbox("hue_powmap_toggle", &ch1_hue_powmap_toggle);
                ImGui::Checkbox("saturation_powmap_toggle", &ch1_saturation_powmap_toggle);
                ImGui::Checkbox("bright_powmap_toggle", &ch1_bright_powmap_toggle);
                
                ImGui::SliderFloat("hue_powmap", &ch1_hue_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation_powmap", &ch1_saturation_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("bright_powmap", &ch1_bright_powmap, -5.0f, 5.0f);
                
                
                
                
            }//end collapsing folder
            
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
                const char* items[] = { "cam1","cam2", "syphon" };
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
                ImGui::Checkbox("hue_powmap_toggle", &ch2_hue_powmap_toggle);
                ImGui::Checkbox("saturation_powmap_toggle", &ch2_saturation_powmap_toggle);
                ImGui::Checkbox("bright_powmap_toggle", &ch2_bright_powmap_toggle);
                
                ImGui::SliderFloat("hue_powmap", &ch2_hue_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("saturation_powmap", &ch2_saturation_powmap, -5.0f, 5.0f);
                ImGui::SliderFloat("bright_powmap", &ch2_bright_powmap, -5.0f, 5.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        //ImGui::End();
        
      
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 2*gui_vscaler));
        
        
        //fb0 folder
        if (ofxImGui::BeginWindow("fb0", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Text("i'm in a collapsable folder");
                
                
                ImGui::SliderFloat("fb0_mix", &fb0_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb0_key_value", &fb0_key_value, .0f, 1.0f);
                //ImGui::SliderFloat("fb0_key_threshold", &fb0_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb0_delay_amount", &fb0_delay_amount, 0, fbob-1);
                
                ImGui::Checkbox("fb0_h_mirror", &fb0_hflip_switch);
                ImGui::Checkbox("fb0_v_mirror", &fb0_vflip_switch);
                ImGui::Checkbox("fb0_toroid", &fb0_toroid_switch);
                
                
                
                ImGui::SliderFloat("fb0_hue", &fb0_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb0_saturation", &fb0_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb0_bright", &fb0_bright, 8.0f, 12.0f);
                
                ImGui::Checkbox("fb0_hue_invert", &fb0_hue_invert);
                ImGui::Checkbox("fb0_saturation_invert", &fb0_saturation_invert);
                ImGui::Checkbox("fb0_bright_invert", &fb0_bright_invert);
                
                ImGui::SliderFloat("fb0_huex_mod", &fb0_huex_mod, 0.0f, 10.0f);
                ImGui::SliderFloat("fb0_huex_offset", &fb0_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb0_huex_lfo", &fb0_huex_lfo, -20.0f, 20.0f);
                
                
                ImGui::SliderFloat("fb0_x", &fb0_x_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb0_y", &fb0_y_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb0_z", &fb0_z_displace, 0.0f, 200.0f);
                ImGui::SliderFloat("fb0_rotate", &fb0_rotate, -3.14f, 3.14f);
                
                //ImGui::SliderFloat("fb0_z_displace_lfo_rate", &fb0_z_displace_lfo_theta, .0f, 10.0f);
                //ImGui::SliderFloat("fb0_z_displace_lfo_amp", &fb0_z_displace_lfo_amp, .0f, 1.0f);
                
                
                
            }//end collapsing folder
            
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Loose Floating Object s");

                

                
                ImGui::SliderFloat("fb0_mix_lfo_rate", &fb0_mix_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_mix_lfo_amp", &fb0_mix_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb0_delay_lfo_rate", &fb0_delay_lfo_theta, .0f, 10.0f);
                ImGui::SliderFloat("fb0_delay_lfo_amp", &fb0_delay_lfo_amp, .0f, 1.0f);
                
                ImGui::SliderFloat("fb0_hue_lfo_rate", &fb0_hue_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_hue_lfo_amp", &fb0_hue_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb0_saturation_lfo_rate", &fb0_saturation_lfo_theta, .0f, lfom);                ImGui::SliderFloat("fb0_saturation_lfo_amp", &fb0_saturation_lfo_amp, .0f, 2.0f);

                
                ImGui::SliderFloat("fb0_bright_lfo_rate", &fb0_bright_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_bright_lfo_amp", &fb0_bright_lfo_amp, .0f, 2.0f);

                ImGui::SliderFloat("fb0_huexmod_lfo_rate", &fb0_huexmod_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_huexmod_lfo_amp", &fb0_huexmod_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb0_huexoffset_lfo_rate", &fb0_huexoffset_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_huexoffset_lfo_amp", &fb0_huexoffset_lfo_amp, .0f, 10.0f);

                ImGui::SliderFloat("fb0_huexlfo_lfo_rate", &fb0_huexlfo_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_huexlfo_lfo_amp", &fb0_huexlfo_lfo_amp, .0f, 10.0f);


                
                ImGui::SliderFloat("fb0_x_displace_lfo_rate", &fb0_x_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_x_displace_lfo_amp", &fb0_x_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb0_y_displace_lfo_rate", &fb0_y_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_y_displace_lfo_amp", &fb0_y_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb0_z_displace_lfo_rate", &fb0_z_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_z_displace_lfo_amp", &fb0_z_lfo_amp, .0f, .05f);
                
                ImGui::SliderFloat("fb0_rotate_lfo_rate", &fb0_rotate_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb0_rotate_lfo_amp", &fb0_rotate_lfo_amp, .0f, 3.14f);
                
                
                
            }//endlfo folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 3*gui_vscaler));
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        //fb1 folder
        if (ofxImGui::BeginWindow("fb1", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Text("i'm in a collapsable folder");
                
                
                ImGui::SliderFloat("fb1_mix", &fb1_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb1_key_value", &fb1_key_value, .0f, 1.0f);
                //ImGui::SliderFloat("fb1_key_threshold", &fb1_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb1_delay_amount", &fb1_delay_amount, 0, fbob-1);
                
                ImGui::Checkbox("fb1_h_mirror", &fb1_hflip_switch);
                ImGui::Checkbox("fb1_v_mirror", &fb1_vflip_switch);
                ImGui::Checkbox("fb1_toroid", &fb1_toroid_switch);
                
                
                
                ImGui::SliderFloat("fb1_hue", &fb1_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb1_saturation", &fb1_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb1_bright", &fb1_bright, 8.0f, 12.0f);
                
                ImGui::Checkbox("fb1_hue_invert", &fb1_hue_invert);
                ImGui::Checkbox("fb1_saturation_invert", &fb1_saturation_invert);
                ImGui::Checkbox("fb1_bright_invert", &fb1_bright_invert);
                
                ImGui::SliderFloat("fb1_huex_mod", &fb1_huex_mod, 0.0f, 20.0f);
                ImGui::SliderFloat("fb1_huex_offset", &fb1_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb1_huex_lfo", &fb1_huex_lfo, -20.0f, 20.0f);
                
                
                ImGui::SliderFloat("fb1_x", &fb1_x_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb1_y", &fb1_y_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb1_z", &fb1_z_displace, 0.0f, 200.0f);
                ImGui::SliderFloat("fb1_rotate", &fb1_rotate, -3.14f, 3.14f);
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Light Fluffy Orb s");
                
                ImGui::SliderFloat("fb1_mix_lfo_rate", &fb1_mix_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_mix_lfo_amp", &fb1_mix_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb1_delay_lfo_rate", &fb1_delay_lfo_theta, .0f, 10.0f);
                ImGui::SliderFloat("fb1_delay_lfo_amp", &fb1_delay_lfo_amp, .0f, 1.0f);
                
                ImGui::SliderFloat("fb1_hue_lfo_rate", &fb1_hue_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_hue_lfo_amp", &fb1_hue_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb1_saturation_lfo_rate", &fb1_saturation_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_saturation_lfo_amp", &fb1_saturation_lfo_amp, .0f, 2.0f);
                
                
                ImGui::SliderFloat("fb1_bright_lfo_rate", &fb1_bright_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_bright_lfo_amp", &fb1_bright_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb1_huexmod_lfo_rate", &fb1_huexmod_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_huexmod_lfo_amp", &fb1_huexmod_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb1_huexoffset_lfo_rate", &fb1_huexoffset_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_huexoffset_lfo_amp", &fb1_huexoffset_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb1_huexlfo_lfo_rate", &fb1_huexlfo_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_huexlfo_lfo_amp", &fb1_huexlfo_lfo_amp, .0f, 10.0f);
                ImGui::SliderFloat("fb1_x_displace_lfo_rate", &fb1_x_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_x_displace_lfo_amp", &fb1_x_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb1_y_displace_lfo_rate", &fb1_y_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_y_displace_lfo_amp", &fb1_y_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb1_z_displace_lfo_rate", &fb1_z_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_z_displace_lfo_amp", &fb1_z_lfo_amp, .0f, .5f);
                
                ImGui::SliderFloat("fb1_rotate_lfo_rate", &fb1_rotate_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb1_rotate_lfo_amp", &fb1_rotate_lfo_amp, .0f, 3.14f);
                
                
                
            }//endlfo folder

            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 4*gui_vscaler));
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        //fb2 folder
        if (ofxImGui::BeginWindow("fb2", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Text("i'm in a collapsable folder");
                
                
                ImGui::SliderFloat("fb2_mix", &fb2_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb2_key_value", &fb2_key_value, .0f, 1.0f);
                //ImGui::SliderFloat("fb2_key_threshold", &fb2_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb2_delay_amount", &fb2_delay_amount, 0, fbob-1);
                
                ImGui::Checkbox("fb2_h_mirror", &fb2_hflip_switch);
                ImGui::Checkbox("fb2_v_mirror", &fb2_vflip_switch);
                ImGui::Checkbox("fb2_toroid", &fb2_toroid_switch);
                
                
                
                ImGui::SliderFloat("fb2_hue", &fb2_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb2_saturation", &fb2_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb2_bright", &fb2_bright, 8.0f, 12.0f);
                
                ImGui::Checkbox("fb2_hue_invert", &fb2_hue_invert);
                ImGui::Checkbox("fb2_saturation_invert", &fb2_saturation_invert);
                ImGui::Checkbox("fb2_bright_invert", &fb2_bright_invert);
                
                ImGui::SliderFloat("fb2_huex_mod", &fb2_huex_mod, 0.0f, 20.0f);
                ImGui::SliderFloat("fb2_huex_offset", &fb2_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb2_huex_lfo", &fb2_huex_lfo, -20.0f, 20.0f);
                
                
                ImGui::SliderFloat("fb2_x", &fb2_x_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb2_y", &fb2_y_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb2_z", &fb2_z_displace, 0.0f, 200.0f);
                ImGui::SliderFloat("fb2_rotate", &fb2_rotate, -3.14f, 3.14f);
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lucid Forensic Optometrist s");
                
                ImGui::SliderFloat("fb2_mix_lfo_rate", &fb2_mix_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_mix_lfo_amp", &fb2_mix_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb2_delay_lfo_rate", &fb2_delay_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_delay_lfo_amp", &fb2_delay_lfo_amp, .0f, 1.0f);
                
                ImGui::SliderFloat("fb2_hue_lfo_rate", &fb2_hue_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_hue_lfo_amp", &fb2_hue_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb2_saturation_lfo_rate", &fb2_saturation_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_saturation_lfo_amp", &fb2_saturation_lfo_amp, .0f, 2.0f);
                
                
                ImGui::SliderFloat("fb2_bright_lfo_rate", &fb2_bright_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_bright_lfo_amp", &fb2_bright_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb2_huexmod_lfo_rate", &fb2_huexmod_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_huexmod_lfo_amp", &fb2_huexmod_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb2_huexoffset_lfo_rate", &fb2_huexoffset_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_huexoffset_lfo_amp", &fb2_huexoffset_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb2_huexlfo_lfo_rate", &fb2_huexlfo_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_huexlfo_lfo_amp", &fb2_huexlfo_lfo_amp, .0f, 10.0f);
                ImGui::SliderFloat("fb2_x_displace_lfo_rate", &fb2_x_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_x_displace_lfo_amp", &fb2_x_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb2_y_displace_lfo_rate", &fb2_y_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_y_displace_lfo_amp", &fb2_y_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb2_z_displace_lfo_rate", &fb2_z_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_z_displace_lfo_amp", &fb2_z_lfo_amp, .0f, .5f);
                
                ImGui::SliderFloat("fb2_rotate_lfo_rate", &fb2_rotate_lfo_theta, .0f, lfom);
                ImGui::SliderFloat("fb2_rotate_lfo_amp", &fb2_rotate_lfo_amp, .0f, 3.14f);
                
                
                
            }//endlfo folder

            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 5*gui_vscaler));
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        //fb3 folder
        if (ofxImGui::BeginWindow("fb3", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Text("i'm in a collapsable folder");
                
                
                ImGui::SliderFloat("fb3_mix", &fb3_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb3_key_value", &fb3_key_value, .0f, 1.0f);
                //ImGui::SliderFloat("fb3_key_threshold", &fb3_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb3_delay_amount", &fb3_delay_amount, 0, fbob-1);
                
                ImGui::Checkbox("fb3_h_mirror", &fb3_hflip_switch);
                ImGui::Checkbox("fb3_v_mirror", &fb3_vflip_switch);
                ImGui::Checkbox("fb3_toroid", &fb3_toroid_switch);
                
                
                
                ImGui::SliderFloat("fb3_hue", &fb3_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb3_saturation", &fb3_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb3_bright", &fb3_bright, 8.0f, 12.0f);
                
                ImGui::Checkbox("fb3_hue_invert", &fb3_hue_invert);
                ImGui::Checkbox("fb3_saturation_invert", &fb3_saturation_invert);
                ImGui::Checkbox("fb3_bright_invert", &fb3_bright_invert);
                
                ImGui::SliderFloat("fb3_huex_mod", &fb3_huex_mod, 0.0f, 20.0f);
                ImGui::SliderFloat("fb3_huex_offset", &fb3_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb3_huex_lfo", &fb3_huex_lfo, -20.0f, 20.0f);
                
                
                ImGui::SliderFloat("fb3_x", &fb3_x_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb3_y", &fb3_y_displace, -x_y_d, x_y_d);
                ImGui::SliderFloat("fb3_z", &fb3_z_displace, 0.0f, 200.0f);
                ImGui::SliderFloat("fb3_rotate", &fb3_rotate, -3.14f, 3.14f);
                
            }//end collapsing folder
            
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Languid Fox Organizer s");
                
                ImGui::SliderFloat("fb3_mix_lfo_rate", &fb3_mix_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_mix_lfo_amp", &fb3_mix_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb3_delay_lfo_rate", &fb3_delay_lfo_theta, .0f, 10.0f);
                ImGui::SliderFloat("fb3_delay_lfo_amp", &fb3_delay_lfo_amp, .0f, 1.0f);
                
                ImGui::SliderFloat("fb3_hue_lfo_rate", &fb3_hue_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_hue_lfo_amp", &fb3_hue_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb3_saturation_lfo_rate", &fb3_saturation_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_saturation_lfo_amp", &fb3_saturation_lfo_amp, .0f, 2.0f);
                
                
                ImGui::SliderFloat("fb3_bright_lfo_rate", &fb3_bright_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_bright_lfo_amp", &fb3_bright_lfo_amp, .0f, 2.0f);
                
                ImGui::SliderFloat("fb3_huexmod_lfo_rate", &fb3_huexmod_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_huexmod_lfo_amp", &fb3_huexmod_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb3_huexoffset_lfo_rate", &fb3_huexoffset_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_huexoffset_lfo_amp", &fb3_huexoffset_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb3_huexlfo_lfo_rate", &fb3_huexlfo_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_huexlfo_lfo_amp", &fb3_huexlfo_lfo_amp, .0f, 10.0f);
                
                ImGui::SliderFloat("fb3_x_displace_lfo_rate", &fb3_x_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_x_displace_lfo_amp", &fb3_x_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb3_y_displace_lfo_rate", &fb3_y_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_y_displace_lfo_amp", &fb3_y_lfo_amp, .0f, 20.0f);
                
                ImGui::SliderFloat("fb3_z_displace_lfo_rate", &fb3_z_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_z_displace_lfo_amp", &fb3_z_lfo_amp, .0f, .5f);
                
                ImGui::SliderFloat("fb3_rotate_lfo_rate", &fb3_rotate_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("fb3_rotate_lfo_amp", &fb3_rotate_lfo_amp, .0f, 3.14f);
                
                
                
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
                //blur
                ImGui::SliderFloat("blur", &blur_amount, .0f, 10.0f);
                //sharpen
                ImGui::SliderFloat("sharpen", &sharpen_amount, .0f, .3f);
                ImGui::SliderFloat("sharpen_radius", &sharpen_radius, .0f, 10.f);
                
                ImGui::SliderFloat("sharpen_boost", &sharpen_boost, .0f, 2.f);
                
                ImGui::SliderFloat("sharpen_chi", &sharpen_chi, .0f, 2.f);

                //camscale
                ImGui::SliderFloat("cam1_scale", &cam1_scale, .0f, 2.0f);
                ImGui::SliderFloat("cam2_scale", &cam2_scale, .0f, 2.0f);
                ImGui::SliderFloat("syphon_scale", &syphon_scale, .0f, 2.0f);
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
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 0*gui_vscaler));
        if (ofxImGui::BeginWindow("cam1_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &cam1_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &cam1_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &cam1_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &cam1_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 1*gui_vscaler));
        if (ofxImGui::BeginWindow("cam2_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &cam2_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &cam2_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &cam2_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &cam2_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 2*gui_vscaler));
        if (ofxImGui::BeginWindow("fb0_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &fb0_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &fb0_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &fb0_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &fb0_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 3*gui_vscaler));
        if (ofxImGui::BeginWindow("fb1_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &fb1_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &fb1_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &fb1_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &fb1_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 4*gui_vscaler));
        if (ofxImGui::BeginWindow("fb2_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &fb2_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &fb2_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &fb2_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &fb2_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
         mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 5*gui_vscaler));
        if (ofxImGui::BeginWindow("fb3_pixelate", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsing folder"))
            {
                ImGui::Checkbox("pixelate", &fb3_pixel_switch);
                //blur
                ImGui::SliderInt("pixel scale", &fb3_pixel_scale, .0f, 256.0f);
                //sharpen
                ImGui::SliderFloat("pixel mix", &fb3_pixel_mix, -2.0f, 2.0f);
                //camscale
                ImGui::SliderFloat("bright_scale", &fb3_pixel_brightscale, -2.0f, 2.0f);
                
                
                
                
            }//end collapsing folder
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
       
        
        gui.end();
        
    }


//---------------------------




