#pragma once

#include "ofMain.h"
//#include "ofxDatGui.h"
#include "ofxImGui.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
  
   
    
    ofxImGui::Gui gui;
    
    //double check that these work
    int channel1_select=1;
    int channel2_select=3;
    
    //channel1
    float ch1_bright=1.0;
    float ch1_hue=1.0;
    float ch1_saturation=1.0;
    bool ch1_hue_alt_invert_toggle=0;
    bool ch1_saturation_alt_invert_toggle=0;
    bool ch1_bright_alt_invert_toggle=0;
    bool ch1_saturation_wrap=0;
    bool ch1_bright_wrap=0;
    float ch1_bright_powmap=1.0;
    float ch1_hue_powmap=1.0;
    float ch1_saturation_powmap=1.0;
    
    //ch1 lfo
    float ch1_hue_lfo_amp=0;
    float ch1_hue_lfo_theta=0;
    float ch1_saturation_lfo_amp=0;
    float ch1_saturation_lfo_theta=0;
    float ch1_bright_lfo_amp=0;
    float ch1_bright_lfo_theta=0;
    
    //channel 2
    float ch2_mix=0;
    float ch2_key_value=0;
    
    float ch2_bright=1.0;
    float ch2_hue=1.0;
    float ch2_saturation=1.0;
    bool ch2_hue_alt_invert_toggle=0;
    bool ch2_saturation_alt_invert_toggle=0;
    bool ch2_bright_alt_invert_toggle=0;
    bool ch2_saturation_wrap=0;
    bool ch2_bright_wrap=0;
    float ch2_bright_powmap=1.0;
    float ch2_hue_powmap=1.0;
    float ch2_saturation_powmap=1.0;
    
    //ch2 lfos
    float ch2_hue_lfo_amp=0;
    float ch2_hue_lfo_theta=0;
    float ch2_saturation_lfo_amp=0;
    float ch2_saturation_lfo_theta=0;
    float ch2_bright_lfo_amp=0;
    float ch2_bright_lfo_theta=0;

    
    
    //fb0
    float fb0_key_value=0.0;
    float fb0_key_threshold=0.0;
    int fb0_delay_amount=0;
    float fb0_mix=.0;
    bool fb0_hflip_switch=0;
    bool fb0_vflip_switch=0;
    int fb0_toroid_switch=0;
    float fb0_hue=10.0;
    float fb0_saturation=10.0;
    float fb0_bright=10.0;
    bool fb0_hue_invert=0;
    bool fb0_saturation_invert=0;
    bool fb0_bright_invert=0;
    float fb0_huex_mod=10.0;
    float fb0_huex_offset=0.0;
    float fb0_huex_lfo=0.0;
    float fb0_x_displace=0.0;
    float fb0_y_displace=0.0;
    float fb0_z_displace=100.0;
    float fb0_rotate=0;
    
    //fb0 rangemods
    float fb0_x_displace_range=40;
    float fb0_y_displace_range=40;
    float fb0_z_displace_range=10;
    float fb0_rotate_range= PI;
    
    //fb0 texmods
    int fb0_texmod_select=2;
    bool fb0_tex_mod=false;
    
    float tex_fb0_key_value=0.0;
    float tex_fb0_key_threshold=0.0;
    float tex_fb0_mix=.0;
    float tex_fb0_hue=0;
    float tex_fb0_saturation=0.0;
    float tex_fb0_bright=0.0;
    float tex_fb0_huex_mod=0;
    float tex_fb0_huex_offset=0;
    float tex_fb0_huex_lfo=0.0;
    float tex_fb0_x_displace=0.0;
    float tex_fb0_y_displace=0.0;
    float tex_fb0_z_displace=0;
    float tex_fb0_rotate=0;
   
    
    //fb0 lfos
    float fb0_lumakeyvalue_lfo_theta=0;
    float fb0_lumakeyvalue_lfo_amp=0;
    float fb0_lumakeythreshold_lfo_theta=0;
    float fb0_lumakeythreshold_lfo_amp=0;
    float fb0_x_lfo_theta=0;
    float fb0_x_lfo_amp=0;
    float fb0_y_lfo_theta=0;
    float fb0_y_lfo_amp=0;
    float fb0_z_lfo_theta=0;
    float fb0_z_lfo_amp=0;
    float fb0_rotate_lfo_theta=0;
    float fb0_rotate_lfo_amp=0;
    float fb0_mix_lfo_theta=0;
    float fb0_mix_lfo_amp=0;
    float fb0_delay_lfo_theta=0;
    float fb0_delay_lfo_amp=0;
    float fb0_hue_lfo_theta=0;
    float fb0_hue_lfo_amp=0;
    float fb0_saturation_lfo_theta=0;
    float fb0_saturation_lfo_amp=0;
    float fb0_bright_lfo_theta=0;
    float fb0_bright_lfo_amp=0;
    float fb0_huexmod_lfo_theta=0;
    float fb0_huexmod_lfo_amp=0;
    float fb0_huexoffset_lfo_theta=0;
    float fb0_huexoffset_lfo_amp=0;
    float fb0_huexlfo_lfo_theta=0;
    float fb0_huexlfo_lfo_amp=0;
    
    
    //fb1
    float fb1_key_value=0.0;
    float fb1_key_threshold=0.0;
    int fb1_delay_amount=0;
    float fb1_mix=.0;
    bool fb1_hflip_switch=0;
    bool fb1_vflip_switch=0;
    int fb1_toroid_switch=0;
    float fb1_hue=10.0;
    float fb1_saturation=10.0;
    float fb1_bright=10.0;
    bool fb1_hue_invert=0;
    bool fb1_saturation_invert=0;
    bool fb1_bright_invert=0;
    float fb1_huex_mod=10.0;
    float fb1_huex_offset=0.0;
    float fb1_huex_lfo=0.0;
    float fb1_x_displace=0.0;
    float fb1_y_displace=0.0;
    float fb1_z_displace=100.0;
    float fb1_rotate=0;
    
    //fb1 rangemods
    float fb1_x_displace_range=40;
    float fb1_y_displace_range=40;
    float fb1_z_displace_range=10;
    float fb1_rotate_range= PI;
    
    //fb1 texmods
    int fb1_texmod_select=2;
    bool fb1_tex_mod=false;
    
    float tex_fb1_key_value=0.0;
    float tex_fb1_key_threshold=0.0;
    float tex_fb1_mix=.0;
    float tex_fb1_hue=0;
    float tex_fb1_saturation=0.0;
    float tex_fb1_bright=0.0;
    float tex_fb1_huex_mod=0;
    float tex_fb1_huex_offset=0;
    float tex_fb1_huex_lfo=0.0;
    float tex_fb1_x_displace=0.0;
    float tex_fb1_y_displace=0.0;
    float tex_fb1_z_displace=0;
    float tex_fb1_rotate=0;
    
    
    //fb1 lfos
    float fb1_lumakeyvalue_lfo_theta=0;
    float fb1_lumakeyvalue_lfo_amp=0;
    float fb1_lumakeythreshold_lfo_theta=0;
    float fb1_lumakeythreshold_lfo_amp=0;
    float fb1_x_lfo_theta=0;
    float fb1_x_lfo_amp=0;
    float fb1_y_lfo_theta=0;
    float fb1_y_lfo_amp=0;
    float fb1_z_lfo_theta=0;
    float fb1_z_lfo_amp=0;
    float fb1_rotate_lfo_theta=0;
    float fb1_rotate_lfo_amp=0;
    float fb1_mix_lfo_theta=0;
    float fb1_mix_lfo_amp=0;
    float fb1_delay_lfo_theta=0;
    float fb1_delay_lfo_amp=0;
    float fb1_hue_lfo_theta=0;
    float fb1_hue_lfo_amp=0;
    float fb1_saturation_lfo_theta=0;
    float fb1_saturation_lfo_amp=0;
    float fb1_bright_lfo_theta=0;
    float fb1_bright_lfo_amp=0;
    float fb1_huexmod_lfo_theta=0;
    float fb1_huexmod_lfo_amp=0;
    float fb1_huexoffset_lfo_theta=0;
    float fb1_huexoffset_lfo_amp=0;
    float fb1_huexlfo_lfo_theta=0;
    float fb1_huexlfo_lfo_amp=0;

    //fb2
    float fb2_key_value=0.0;
    float fb2_key_threshold=0.0;
    int fb2_delay_amount=0;
    float fb2_mix=.0;
    bool fb2_hflip_switch=0;
    bool fb2_vflip_switch=0;
    int fb2_toroid_switch=0;
    float fb2_hue=10.0;
    float fb2_saturation=10.0;
    float fb2_bright=10.0;
    bool fb2_hue_invert=0;
    bool fb2_saturation_invert=0;
    bool fb2_bright_invert=0;
    float fb2_huex_mod=10.0;
    float fb2_huex_offset=0.0;
    float fb2_huex_lfo=0.0;
    float fb2_x_displace=0.0;
    float fb2_y_displace=0.0;
    float fb2_z_displace=100.0;
    float fb2_rotate=0;
    
    //fb2 rangemods
    float fb2_x_displace_range=40;
    float fb2_y_displace_range=40;
    float fb2_z_displace_range=10;
    float fb2_rotate_range= PI;
    
    //fb2 texmods
    int fb2_texmod_select=2;
    bool fb2_tex_mod=false;
    
    float tex_fb2_key_value=0.0;
    float tex_fb2_key_threshold=0.0;
    float tex_fb2_mix=.0;
    float tex_fb2_hue=0;
    float tex_fb2_saturation=0.0;
    float tex_fb2_bright=0.0;
    float tex_fb2_huex_mod=0;
    float tex_fb2_huex_offset=0;
    float tex_fb2_huex_lfo=0.0;
    float tex_fb2_x_displace=0.0;
    float tex_fb2_y_displace=0.0;
    float tex_fb2_z_displace=0;
    float tex_fb2_rotate=0;
    
    
    //fb2 lfos
    float fb2_lumakeyvalue_lfo_theta=0;
    float fb2_lumakeyvalue_lfo_amp=0;
    float fb2_lumakeythreshold_lfo_theta=0;
    float fb2_lumakeythreshold_lfo_amp=0;
    float fb2_x_lfo_theta=0;
    float fb2_x_lfo_amp=0;
    float fb2_y_lfo_theta=0;
    float fb2_y_lfo_amp=0;
    float fb2_z_lfo_theta=0;
    float fb2_z_lfo_amp=0;
    float fb2_rotate_lfo_theta=0;
    float fb2_rotate_lfo_amp=0;
    float fb2_mix_lfo_theta=0;
    float fb2_mix_lfo_amp=0;
    float fb2_delay_lfo_theta=0;
    float fb2_delay_lfo_amp=0;
    float fb2_hue_lfo_theta=0;
    float fb2_hue_lfo_amp=0;
    float fb2_saturation_lfo_theta=0;
    float fb2_saturation_lfo_amp=0;
    float fb2_bright_lfo_theta=0;
    float fb2_bright_lfo_amp=0;
    float fb2_huexmod_lfo_theta=0;
    float fb2_huexmod_lfo_amp=0;
    float fb2_huexoffset_lfo_theta=0;
    float fb2_huexoffset_lfo_amp=0;
    float fb2_huexlfo_lfo_theta=0;
    float fb2_huexlfo_lfo_amp=0;

    
    //fb3
    float fb3_key_value=0.0;
    float fb3_key_threshold=0.0;
    int fb3_delay_amount=0;
    float fb3_mix=.0;
    bool fb3_hflip_switch=0;
    bool fb3_vflip_switch=0;
    int fb3_toroid_switch=0;
    float fb3_hue=10.0;
    float fb3_saturation=10.0;
    float fb3_bright=10.0;
    bool fb3_hue_invert=0;
    bool fb3_saturation_invert=0;
    bool fb3_bright_invert=0;
    float fb3_huex_mod=10.0;
    float fb3_huex_offset=0.0;
    float fb3_huex_lfo=0.0;
    float fb3_x_displace=0.0;
    float fb3_y_displace=0.0;
    float fb3_z_displace=100.0;
    float fb3_rotate=0;
    
    //fb3 rangemods
    float fb3_x_displace_range=40;
    float fb3_y_displace_range=40;
    float fb3_z_displace_range=10;
    float fb3_rotate_range= PI;
    
    //fb3 texmods
    int fb3_texmod_select=2;
    bool fb3_tex_mod=false;
    
    float tex_fb3_key_value=0.0;
    float tex_fb3_key_threshold=0.0;
    float tex_fb3_mix=.0;
    float tex_fb3_hue=0;
    float tex_fb3_saturation=0.0;
    float tex_fb3_bright=0.0;
    float tex_fb3_huex_mod=0;
    float tex_fb3_huex_offset=0;
    float tex_fb3_huex_lfo=0.0;
    float tex_fb3_x_displace=0.0;
    float tex_fb3_y_displace=0.0;
    float tex_fb3_z_displace=0;
    float tex_fb3_rotate=0;
    
    
    //fb3 lfos
    float fb3_lumakeyvalue_lfo_theta=0;
    float fb3_lumakeyvalue_lfo_amp=0;
    float fb3_lumakeythreshold_lfo_theta=0;
    float fb3_lumakeythreshold_lfo_amp=0;
    float fb3_x_lfo_theta=0;
    float fb3_x_lfo_amp=0;
    float fb3_y_lfo_theta=0;
    float fb3_y_lfo_amp=0;
    float fb3_z_lfo_theta=0;
    float fb3_z_lfo_amp=0;
    float fb3_rotate_lfo_theta=0;
    float fb3_rotate_lfo_amp=0;
    float fb3_mix_lfo_theta=0;
    float fb3_mix_lfo_amp=0;
    float fb3_delay_lfo_theta=0;
    float fb3_delay_lfo_amp=0;
    float fb3_hue_lfo_theta=0;
    float fb3_hue_lfo_amp=0;
    float fb3_saturation_lfo_theta=0;
    float fb3_saturation_lfo_amp=0;
    float fb3_bright_lfo_theta=0;
    float fb3_bright_lfo_amp=0;
    float fb3_huexmod_lfo_theta=0;
    float fb3_huexmod_lfo_amp=0;
    float fb3_huexoffset_lfo_theta=0;
    float fb3_huexoffset_lfo_amp=0;
    float fb3_huexlfo_lfo_theta=0;
    float fb3_huexlfo_lfo_amp=0;

    
    //global
    int global_texmod_select=0;
    bool global_texmod=false;
    bool control_reset=false;
    bool framebuffer_clear=false;
    float blur_amount=0.0;
    float blur_radius=1.0;
    float sharpen_amount=0.0;
    float sharpen_radius=1.0;
    float sharpen_boost=0.0;
    float cam1_scale=1;
    float cam2_scale=1;
    float ndi_scale=0;
    bool cam1_hflip_switch=0;
    bool cam1_vflip_switch=0;
    bool cam2_hflip_switch=0;
    bool cam2_vflip_switch=0;
    float x_skew=0;
    float y_skew=0;
    bool tetrahedron_switch=0;
    bool hypercube_switch=0;
    float hypercube_theta_rate=0.01;
    float hypercube_phi_rate=0.01;
    
    //this doesnt work yet
    bool ndiOutput=0;
    
    //global texmods
    float texmod_blur_amount=0.0;
    float texmod_blur_radius=1.0;
    float texmod_sharpen_amount=0.0;
    float texmod_sharpen_radius=1.0;
    float texmod_sharpen_boost=0.0;
    
    //global lfos
    float blur_amount_lfo_amp=0.0;
    float blur_amount_lfo_theta=0.0;
    float blur_radius_lfo_amp=0.0;
    float blur_radius_lfo_theta=0.0;
    float sharpen_amount_lfo_amp=0.0;
    float sharpen_amount_lfo_theta=0.0;
    float sharpen_radius_lfo_amp=1.0;
    float sharpen_radius_lfo_theta=1.0;
    float sharpen_boost_lfo_amp=0.0;
    float sharpen_boost_lfo_theta=0.0;
    
   
    
    

    //pixels:
    //cam1
    
    
    bool cam1_pixel_switch=0;
    int cam1_pixel_scale_x=64;
    int cam1_pixel_scale_y=64;
    float cam1_pixel_mix=1;
    float cam1_pixel_brightscale=0;
    
    //cam1 pixel lfo
    
    float cam1_pixel_scale_x_lfo_theta=0;
    float cam1_pixel_scale_x_lfo_amp=0;
    float cam1_pixel_scale_y_lfo_theta=0;
    float cam1_pixel_scale_y_lfo_amp=0;
    float cam1_pixel_mix_lfo_theta=0;
    float cam1_pixel_mix_lfo_amp=0;
    float cam1_pixel_brightscale_lfo_theta=0;
    float cam1_pixel_brightscale_lfo_amp=0;
    
    //cam2
    
    bool cam2_pixel_switch=0;
    int cam2_pixel_scale_x=64;
    int cam2_pixel_scale_y=64;
    float cam2_pixel_mix=1;
    float cam2_pixel_brightscale=0;
    
    float cam2_pixel_scale_x_lfo_theta=0;
    float cam2_pixel_scale_x_lfo_amp=0;
    float cam2_pixel_scale_y_lfo_theta=0;
    float cam2_pixel_scale_y_lfo_amp=0;
    float cam2_pixel_mix_lfo_theta=0;
    float cam2_pixel_mix_lfo_amp=0;
    float cam2_pixel_brightscale_lfo_theta=0;
    float cam2_pixel_brightscale_lfo_amp=0;

    
    
    //fb0
    bool fb0_pixel_switch=0;
    int fb0_pixel_scale_x=64;
    int fb0_pixel_scale_y=64;
    float fb0_pixel_mix=1;
    float fb0_pixel_brightscale=0;
    
    
    //fb0 pixel texmods
    int fb0_pixel_texmod_select=0;
    bool fb0_pixel_texmod=false;
    int  texmod_fb0_pixel_scale_x=0;
    int texmod_fb0_pixel_scale_y=0;
    float texmod_fb0_pixel_mix=0;
    float texmod_fb0_pixel_brightscale=0;
    
    //fb0 pixel lfo
    
    float fb0_pixel_scale_x_lfo_theta=0;
    float fb0_pixel_scale_x_lfo_amp=0;
    float fb0_pixel_scale_y_lfo_theta=0;
    float fb0_pixel_scale_y_lfo_amp=0;
    float fb0_pixel_mix_lfo_theta=0;
    float fb0_pixel_mix_lfo_amp=0;
    float fb0_pixel_brightscale_lfo_theta=0;
    float fb0_pixel_brightscale_lfo_amp=0;
    
    //fb1
    
    bool fb1_pixel_switch=0;
    int fb1_pixel_scale_x=64;
    int fb1_pixel_scale_y=64;
    float fb1_pixel_mix=1;
    float fb1_pixel_brightscale=0;
    
    //fb1 pixel texmods
    int fb1_pixel_texmod_select=0;
    bool fb1_pixel_texmod=false;
    int texmod_fb1_pixel_scale_x=0;
    int texmod_fb1_pixel_scale_y=0;
    float texmod_fb1_pixel_mix=0;
    float texmod_fb1_pixel_brightscale=0;
    
    //fb1 pixel lfo
    
    float fb1_pixel_scale_x_lfo_theta=0;
    float fb1_pixel_scale_x_lfo_amp=0;
    float fb1_pixel_scale_y_lfo_theta=0;
    float fb1_pixel_scale_y_lfo_amp=0;
    float fb1_pixel_mix_lfo_theta=0;
    float fb1_pixel_mix_lfo_amp=0;
    float fb1_pixel_brightscale_lfo_theta=0;
    float fb1_pixel_brightscale_lfo_amp=0;
    
    //fb2
    
    bool fb2_pixel_switch=0;
    int fb2_pixel_scale_x=64;
    int fb2_pixel_scale_y=64;
    float fb2_pixel_mix=1;
    float fb2_pixel_brightscale=0;
    
    //fb2 texmods
    int fb2_pixel_texmod_select=0;
    bool fb2_pixel_texmod=false;
    int texmod_fb2_pixel_scale_x=0;
    int texmod_fb2_pixel_scale_y=0;
    float texmod_fb2_pixel_mix=0;
    float texmod_fb2_pixel_brightscale=0;
    
    //fb2 pixel lfo
    
    float fb2_pixel_scale_x_lfo_theta=0;
    float fb2_pixel_scale_x_lfo_amp=0;
    float fb2_pixel_scale_y_lfo_theta=0;
    float fb2_pixel_scale_y_lfo_amp=0;
    float fb2_pixel_mix_lfo_theta=0;
    float fb2_pixel_mix_lfo_amp=0;
    float fb2_pixel_brightscale_lfo_theta=0;
    float fb2_pixel_brightscale_lfo_amp=0;
    
    //fb3
    
    bool fb3_pixel_switch=0;
    int fb3_pixel_scale_x=64;
    int fb3_pixel_scale_y=64;
    float fb3_pixel_mix=1;
    float fb3_pixel_brightscale=0;
    
    //fb3 texmods
    int fb3_pixel_texmod_select=0;
    bool fb3_pixel_texmod=false;
    int texmod_fb3_pixel_scale_x=0;
    int texmod_fb3_pixel_scale_y=0;
    float texmod_fb3_pixel_mix=0;
    float texmod_fb3_pixel_brightscale=0;
    
    //fb3 pixel lfo
    
    float fb3_pixel_scale_x_lfo_theta=0;
    float fb3_pixel_scale_x_lfo_amp=0;
    float fb3_pixel_scale_y_lfo_theta=0;
    float fb3_pixel_scale_y_lfo_amp=0;
    float fb3_pixel_mix_lfo_theta=0;
    float fb3_pixel_mix_lfo_amp=0;
    float fb3_pixel_brightscale_lfo_theta=0;
    float fb3_pixel_brightscale_lfo_amp=0;
    
    
    //ndi
    
    bool ndi_pixel_switch=0;
    int ndi_pixel_scale_x=64;
    int ndi_pixel_scale_y=64;
    float ndi_pixel_mix=1;
    float ndi_pixel_brightscale=0;
    
    float ndi_pixel_scale_x_lfo_theta=0;
    float ndi_pixel_scale_x_lfo_amp=0;
    float ndi_pixel_scale_y_lfo_theta=0;
    float ndi_pixel_scale_y_lfo_amp=0;
    float ndi_pixel_mix_lfo_theta=0;
    float ndi_pixel_mix_lfo_amp=0;
    float ndi_pixel_brightscale_lfo_theta=0;
    float ndi_pixel_brightscale_lfo_amp=0;
  
   
   };
