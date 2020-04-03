#version 120


uniform sampler2DRect tex0;

varying vec2 texCoordVarying;

uniform float sharpAmnt;

uniform float sharpen_boost;

uniform float steppp;

uniform float chi;

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


void main()
{
    vec4 color_sharpen=vec4(0);
    
    //float steppp=.0;
   // float chi=1.0;
    
    color_sharpen=(chi)*texture2DRect(tex0,texCoordVarying)+(-chi*8)*(
                texture2DRect(tex0,texCoordVarying+vec2(steppp,0))+
                texture2DRect(tex0,texCoordVarying+vec2(-steppp,0))+
                texture2DRect(tex0,texCoordVarying+vec2(0,steppp))+
                texture2DRect(tex0,texCoordVarying+vec2(0,-steppp))+
                texture2DRect(tex0,texCoordVarying+vec2(steppp,steppp))+
                texture2DRect(tex0,texCoordVarying+vec2(-steppp,steppp))+
                texture2DRect(tex0,texCoordVarying+vec2(steppp,-steppp))+
                texture2DRect(tex0,texCoordVarying+vec2(-steppp,-steppp))
                                                                      );
    //color_sharpen=color_sharpen/9;
    
    color_sharpen=color_sharpen/9;
    //gl_FragColor = color_sharpenandblur;
    
     color_sharpen=texture2DRect(tex0,texCoordVarying)+sharpAmnt*color_sharpen;
    
    //vec3 color_sharpen_hsb=vec3(0);
    
    vec3 color_sharpen_hsb=rgb2hsv(vec3(color_sharpen.r,color_sharpen.g,color_sharpen.b));
    
    color_sharpen_hsb.b=(sharpen_boost+1.0)*color_sharpen_hsb.b;
    
    color_sharpen_hsb.b=(sharpen_boost+1.0)*color_sharpen_hsb.b;
    
    color_sharpen=vec4(hsv2rgb(vec3(color_sharpen_hsb.r,color_sharpen_hsb.g,color_sharpen_hsb.b)),1.0);
    //color_sharpen.rgb=texture2DRect(tex0,texCoordVarying).rgb+sharpAmnt*color_sharpen.rgb;
   // color_sharpen.a=1.0;
   // gl_FragColor = texture2DRect(texCoordVarying,tex0);
   // gl_FragColor =color_sharpen;
    
     gl_FragColor =color_sharpen;
}
