#version 120


uniform sampler2DRect tex0;

varying vec2 texCoordVarying;

uniform float sharpAmnt;

void main()
{
    vec4 color_sharpen=vec4(0);
    
    float steppp=5.0;
    float chi=1.0;
    
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
    color_sharpen=color_sharpen/9;
    //gl_FragColor = color_sharpenandblur;
    
    color_sharpen=texture2DRect(tex0,texCoordVarying)+sharpAmnt*color_sharpen;
   // gl_FragColor = texture2DRect(texCoordVarying,tex0);
   // gl_FragColor =color_sharpen;
    
     gl_FragColor =color_sharpen;
}
