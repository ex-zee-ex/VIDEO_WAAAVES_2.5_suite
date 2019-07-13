#version 120


uniform sampler2DRect syphon;
uniform sampler2DRect cam1;
uniform sampler2DRect cam2;

uniform sampler2DRect fb0;
uniform sampler2DRect fb1;
uniform sampler2DRect fb2;

//fb0
uniform vec3 fb0_hsb_x;
uniform vec3 fb0_hue_x;
uniform vec3 fb0_rescale;
uniform vec3 fb0_modswitch;

//fb1
uniform vec3 fb1_hsb_x;
uniform vec3 fb1_hue_x;
uniform vec3 fb1_rescale;
uniform vec3 fb1_modswitch;

//fb2
uniform vec3 fb2_hsb_x;
uniform vec3 fb2_hue_x;
uniform vec3 fb2_rescale;
uniform vec3 fb2_modswitch;

uniform float compScalex;
uniform float compScaley;


uniform float delaymix;


uniform float ch1_h_mirror;

//vidmixervariables

uniform float scale1;
uniform float width;
uniform float height;







varying vec2 texCoordVarying;





//variables from gui
uniform int channel1;
uniform int channel2;

uniform int mix1;
uniform int mix2;


uniform int FBGLITCHSWITCH;
uniform int FB1GLITCHSWITCH;
uniform int FB2GLITCHSWITCH;




//mix1 variables
uniform float mix1blend1;


uniform float mix1keybright;
uniform float mix1keythresh;



//fbmixvariables
uniform float fb0lumakeyvalue;
uniform float fb0lumakeythresh;
uniform int fb0mix;
uniform float fb0blend;

uniform float fb1lumakeyvalue;
uniform float fb1lumakeythresh;
uniform int fb1mix;
uniform float fb1blend;


uniform float fb2lumakeyvalue;
uniform float fb2lumakeythresh;
uniform int fb2mix;
uniform float fb2blend;

//channel1 variablesfrom gui
uniform float channel1hue_x;
uniform float channel1saturation_x;
uniform float channel1bright_x;

uniform float channel1hue_powmap;
uniform float channel1sat_powmap;
uniform float channel1bright_powmap;


uniform int channel1satwrap;
uniform int channel1brightwrap;

uniform int ch1hue_powmaptoggle;
uniform int ch1sat_powmaptoggle;
uniform int ch1bright_powmaptoggle;

uniform int ch1hue_inverttoggle;
uniform int ch1sat_inverttoggle;
uniform int ch1bright_inverttoggle;


//channel2 variablesfrom gui
uniform float channel2hue_x;
uniform float channel2saturation_x;
uniform float channel2bright_x;

uniform float channel2hue_powmap;
uniform float channel2sat_powmap;
uniform float channel2bright_powmap;


uniform int channel2satwrap;
uniform int channel2brightwrap;

uniform int ch2hue_powmaptoggle;
uniform int ch2sat_powmaptoggle;
uniform int ch2bright_powmaptoggle;

uniform int ch2hue_inverttoggle;
uniform int ch2sat_inverttoggle;
uniform int ch2bright_inverttoggle;






uniform float ps;

uniform vec2 cam1dimensions;
uniform vec2 cam2dimensions;

uniform float pp=1.0;


uniform float qq;

vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}


vec3 fb_hsbop(vec3 c,vec3 hsbx,vec3 huex,vec3 modswitch)
{
    
    
    c.r=abs(c.r*hsbx.r+huex.z*sin(c.r/3.14));
    c.r=fract(mod(c.r,huex.x)+huex.y);
    c.g=c.g*hsbx.g;
    c.b=c.b*hsbx.b;
    
    
    if(c.g>1.0){c.g=1.0;}
    
    if(c.b>1.0){c.b=1.0;}
    
    if(modswitch.r==1.0){ c.r=1.0-c.r;}
    if(modswitch.g==1.0){ c.g=1.0-c.g;}
    if(modswitch.b==1.0){ c.b=1.0-c.b;}
    //do some overflow stuffs
    if(abs(c.x)>1.0){
        
        c.x=fract(c.x);
        c.x=abs(c.x);
    }
    
    if(abs(c.y)>1.0){
        // c.y=1.0-abs(c.y);
        c.y=abs(c.y);
        
        c.y=fract(c.y);
        
    }
    
    if(abs(c.z)>1.0){
        //c.z=1.0-abs(c.z);
        c.z=abs(c.z);
        c.z=fract(c.z);
        
    }
    
    //c.z=1.0-c.z;
     //c.y=1.0-c.y;
    return c;
    
}


//a function for all hsb operations to be invoked by each channel

//change every like hsb thing out there to a vec3 duh
vec3 channel_hsboperations(vec3 c,float hue_x,float sat_x, float bright_x
                           ,int hue_powmaptoggle, int sat_powmaptoggle, int bright_powmaptoggle
                           ,float hue_powmap, float sat_powmap, float bright_powmap
                           ,int satwrap,int brightwrap,int hueinvert,int satinvert,int brightinvert)
{
    
    //attenuators
    c.x=c.x*hue_x;
    c.y=c.y*sat_x;
    c.z=c.z*bright_x;
    
    
    
    //powmaps
    if(hue_powmaptoggle==1){
        c.x=fract(pow((c.x),hue_powmap));
    }
    
    if(sat_powmaptoggle==1){
        c.y=fract(pow((c.y),sat_powmap));
    }
    if(bright_powmaptoggle==1){
        c.z=clamp(fract(pow((c.z),bright_powmap)),0.0,1.0);
    }

    
    
    
    
    
    //deal with underflows
    if(c.x<0){
        if(hueinvert==0){ c.x=1.0-abs(c.x);}
        if(hueinvert==1){c.x=abs(1.0-abs(c.x));}
    }
    
    
    if(c.y<0){
        if(satinvert==0){ c.y=1.0-abs(c.y);}
        if(satinvert==1){c.y=abs(1.0-abs(c.y));}

    }
    
    
    if(c.z<0){
        if(brightinvert==0){ c.z=1.0-abs(c.z);}
        if(brightinvert==1){c.z=abs(1.0-abs(c.z));}
    }

    
    //and over flows
    if(satwrap==1.0){
        if(abs(c.y)>1.0){
            c.y=fract(c.y);
        }
    }
    
    if(brightwrap==1.0){
        if(abs(c.z)>1.0){
            c.z=fract(c.z);
        }
    }
    
    if(satwrap==0.0){
        if(c.y>1.0){
            c.y=1;
        }
    }
    
    if(brightwrap==0.0){
        if(c.z>1.0){
            c.z=1;
        }
    }

   
    
    c.x=fract(c.x);
    
    
    return c;
   }


//lets instead rewrite this for rgb modes bc i dont think blend works without rgb
//can just send the brightness value from the earlier hsb version along for the ride to calculate the lumakey thingss

vec4 mix_rgb(vec4 ch1, vec4 ch2, int mixswitch,float blend, float lumavalue, float lumathresh, float bright1,float bright2){
    vec4 mixout=vec4(0.0,0.0,0.0,0.0);
 
    
    //pass ch1 it thru
    
    if(mixswitch==0){
        mixout=ch1;
        
    }//endpass
    
    
    //blendit
    if(mixswitch==1){
        mixout=mix(ch1,ch2,blend);
            }//endblend
    
    //keyit
    if(mixswitch==2){
    
        if((bright1<lumavalue+lumathresh)&&(bright1>lumavalue-lumathresh)){
            mixout=mix(ch1,ch2,blend);
        
        }//endifbright1
        else{
            mixout=ch2;
        }
    
    
    }//keyit
    
    //mixout=vec3(mixhue,mixsat,mixbright);
    return mixout;
}//endmixfunction



void main()
{
    //set up dummy variables for each channel
    vec4 channel1_color=vec4(0.0, 0.0, 0.0, 0.0);
    
    vec4 channel2_color=vec4(0.0, 0.0, 0.0, 0.0);
    
    //so will want to do something similar here where there is a dif set of coordinates
    //for each of the framebuffers then each one can be seperatly remapped
    //1 variable for zoome in and out (multiplier plus modulo for wraparound
    //1 variable each for x and y shift
    //can rotations work in here?  try and research this a second
    vec2 compScaleCoord=vec2(compScalex*texCoordVarying.x,compScaley*texCoordVarying.y);
    
    //vec2 fb0_coord=fb0_rescale.z*texCoordVarying;
    
    //center should be a variable sent that displaces where yr center is wished to be
    int center=512;
    
    vec2 fb0_coord=vec2(texCoordVarying.x-center,texCoordVarying.y-center);
    fb0_coord=fb0_rescale.z*fb0_coord;
    fb0_coord.xy=fb0_rescale.xy+fb0_coord.xy+center;
    vec4 fb0_color = texture2DRect(fb0,fb0_coord);
    
    vec2 fb1_coord=vec2(texCoordVarying.x-center,texCoordVarying.y-center);
    fb1_coord=fb1_rescale.z*fb1_coord;
    fb1_coord.xy=fb1_rescale.xy+fb1_coord.xy+center;
    vec4 fb1_color = texture2DRect(fb1,fb1_coord);
    
    vec2 fb2_coord=vec2(texCoordVarying.x-center,texCoordVarying.y-center);
    fb2_coord=fb2_rescale.z*fb2_coord;
    fb2_coord.xy=fb2_rescale.xy+fb2_coord.xy+center;
    vec4 fb2_color = texture2DRect(fb2,fb2_coord);
    
    vec4 syphon_color=texture2DRect(syphon,texCoordVarying);
    
    
    
    

    //just like  spare dummy variabl for a color vector
	vec4 color = vec4(0.0, 0.0, 0.0, 0.0);
    
    
  
    //so we take flip from texCoordVarying so that then we can do some switching
    //if we want to flip or rotate or whatnot
    //same thing here with remapping as the framebuffers maybe?
    vec2 ch1_flip=texCoordVarying;
    vec2 ch2_flip=texCoordVarying;
    
    
    vec2 flip=texCoordVarying;

   
    
    
    
    
    
   
    
       vec4 cam1color=vec4(0.0,0.0,0.0,0.0);
    if((scale1*flip.x<cam1dimensions.x)&&(scale1*flip.y<cam1dimensions.y)){
        cam1color=texture2DRect(cam1,vec2(scale1*flip.x,scale1*flip.y));
    }
    
    vec4 cam2color=vec4(0.0,0.0,0.0,0.0);

    
    if((scale1*flip.x<cam2dimensions.x)&&(scale1*flip.y<cam2dimensions.y)){
        cam2color=texture2DRect(cam2,vec2(scale1*flip.x,scale1*flip.y));
    }
    
    
    
    //pixelate zones
    //turn this into fucntion
    /*
    vec4 pixel_color=vec4(0.0,0.0,0.0,0.0);
    float pixel_scale=floor(ps*(.33*cam2color.r+.5*cam2color.g+.16*cam2color.b));
    //float pixel_scale=floor(ps);
    vec2 pixelScaleCoord=vec2(0.0,0.0);
    pixelScaleCoord.x=scale1*flip.x/1024.0;
    pixelScaleCoord.y=scale1*flip.y/1024.0;
    
   
    
    pixelScaleCoord.x=floor(pixel_scale*pixelScaleCoord.x)/pixel_scale;
    pixelScaleCoord.y=floor(pixel_scale*pixelScaleCoord.y)/pixel_scale;
    
    pixelScaleCoord.x=1024*pixelScaleCoord.x;
    pixelScaleCoord.y=1024*pixelScaleCoord.y;
    
    pixel_color=texture2DRect(cam2, pixelScaleCoord);
    
    
    cam2color=mix(pixel_color,cam2color,.5);
    */
    
   
    
    
    
    //select which input for channel1
    
    
    
    if(channel1==1){
    
      
        channel1_color=cam1color;
        
        
       
    }//endifch1_1
    
    if(channel1==2){
        
        
        
        channel1_color=cam2color;
       
    }//endifch1_2
    
    
    if(channel1==3){
        channel1_color=syphon_color;
    }//endifch1_3
    
    if(channel2==1){
        
        channel2_color=cam1color;
      
    }
    
    if(channel2==2){
        
        channel2_color=cam2color;
        
    }
    
    
    if(channel2==3){
        channel2_color=syphon_color;
    }//endifch1_3


    
    
    
  
    
    
    //convert to hsb and make some variables for easy readin
    
    vec3 channel1color_hsb=rgb2hsv(vec3(channel1_color.r,channel1_color.g,channel1_color.b));
    vec3 channel2color_hsb=rgb2hsv(vec3(channel2_color.r,channel2_color.g,channel2_color.b));
   
    vec3 fb0color_hsb=rgb2hsv(vec3(fb0_color.r,fb0_color.g,fb0_color.b));
    
    vec3 fb1color_hsb=rgb2hsv(vec3(fb1_color.r,fb1_color.g,fb1_color.b));
    vec3 fb2color_hsb=rgb2hsv(vec3(fb2_color.r,fb2_color.g,fb2_color.b));
    
    
   
    //add an alpha channel to everything
   // fb0_color.w=fb0color_hsb.b;
    //channel1_color.w=channel1color_hsb.b;
    //run the hsb operations on every channel
    vec3 ch1_hsbstrip=channel_hsboperations(channel1color_hsb, channel1hue_x, channel1saturation_x, channel1bright_x
                                    ,ch1hue_powmaptoggle,ch1sat_powmaptoggle,ch1bright_powmaptoggle
                                    ,channel1hue_powmap,channel1sat_powmap,channel1bright_powmap
                                    ,channel1satwrap,channel1brightwrap,
                                            ch1hue_inverttoggle,ch1sat_inverttoggle,ch1bright_inverttoggle);
    
    vec3 ch2_hsbstrip=channel_hsboperations(channel2color_hsb, channel2hue_x, channel2saturation_x, channel2bright_x
                                            ,ch2hue_powmaptoggle,ch2sat_powmaptoggle,ch2bright_powmaptoggle
                                            ,channel2hue_powmap,channel2sat_powmap,channel2bright_powmap
                                            ,channel2satwrap,channel2brightwrap,
                                            ch2hue_inverttoggle,ch2sat_inverttoggle,ch2bright_inverttoggle);

    
    
     //  vec3 hsb_x=vec3(1.01,1.01,1.01);
  //  vec3 hue_x=vec3(1.0,0.0,0.0);
    fb0color_hsb=fb_hsbop(fb0color_hsb,fb0_hsb_x,fb0_hue_x,fb0_modswitch);
    
   // vec3 fb1_modswitch=vec3(0.0,0.0,0.0);
    //  vec3 hsb_x=vec3(1.01,1.01,1.01);
    //  vec3 hue_x=vec3(1.0,0.0,0.0);
    fb1color_hsb=fb_hsbop(fb1color_hsb,fb1_hsb_x,fb1_hue_x,fb1_modswitch);
    
    //vec3 fb2_modswitch=vec3(0.0,0.0,0.0);
      //vec3 fb2_hsb_x=vec3(1.01,1.01,2.01);
    //  vec3 hue_x=vec3(1.0,0.0,0.0);
    fb2color_hsb=fb_hsbop(fb2color_hsb,fb2_hsb_x,fb2_hue_x,fb2_modswitch);
    
    
   

    //convert back to vec4 rgb
    
    vec3 channel1_rgb=vec3(hsv2rgb(ch1_hsbstrip));
    vec3 channel2_rgb=vec3(hsv2rgb(ch2_hsbstrip));
   
    
    //switch on and off alpha in here... and test a lot more
    channel1_color=vec4(vec3(hsv2rgb(ch1_hsbstrip)),1.0);
     //channel1_color=vec4(vec3(hsv2rgb(ch1_hsbstrip)),ch1_hsbstrip.b);
    channel2_color=vec4(vec3(hsv2rgb(ch2_hsbstrip)),1.0);
   // fb0_color=vec4(vec3(hsv2rgb(fb0color_hsb)),fb0color_hsb.b);
    fb0_color=vec4(vec3(hsv2rgb(fb0color_hsb)),1.0);
    fb1_color=vec4(vec3(hsv2rgb(fb1color_hsb)),1.0);
    fb2_color=vec4(vec3(hsv2rgb(fb2color_hsb)),1.0);

    //next we do the mixxxing
  
    
    
    //vec4 mixout_color=vec4(0.0,0.0,0.0,0.0);
    
    vec4 mixout_color=mix_rgb(channel1_color,channel2_color,mix1,mix1blend1,mix1keybright,mix1keythresh,ch1_hsbstrip.z,ch2_hsbstrip.z);
    
    vec3 mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));
    
    
    
    mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));

    
    mixout_color=mix_rgb(mixout_color,fb0_color,fb0mix,fb0blend,fb0lumakeyvalue,fb0lumakeythresh, mixout_colorhsb.z,fb0color_hsb.z);
    
    mixout_color=mix_rgb(mixout_color,fb2_color,fb2mix,fb2blend,fb2lumakeyvalue,fb2lumakeythresh, mixout_colorhsb.z,fb2color_hsb.z);
    
    mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));
    
    
    
    
    mixout_color=mix_rgb(mixout_color,fb1_color,fb1mix,fb1blend,fb1lumakeyvalue,fb1lumakeythresh, mixout_colorhsb.z,fb1color_hsb.z);
    
  
    

   

    
    gl_FragColor = mixout_color;
    
    
    
    
    
    
    
    
 

    
    
    
    
    
    
    
    
    
    

}
