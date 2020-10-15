#version 120


uniform sampler2DRect tex0;

uniform sampler2DRect texmod;

varying vec2 texCoordVarying;

uniform float blur_amount;
uniform float blur_radius;

uniform float texmod_blur_amount;
uniform float texmod_blur_radius;


void main()
{
    vec4 color_blur=vec4(0.0,0.0,0.0,1.0);
    
    vec4 texmod_color=texture2DRect(texmod,texCoordVarying);
    float texmod_bright=texmod_color.r*.299+texmod_color.g*.587+texmod_color.b*.114;
    
    float blur_mod=texmod_bright*texmod_blur_amount+blur_amount;
    
    //new version: blur amount is the weight of the neighborhood
    //blur radius will be the distance of the neighborhood
    
    float blur_radius_mod=texmod_blur_radius*texmod_bright+blur_radius;
    
    vec4 blur_kernel=texture2DRect(tex0,texCoordVarying+vec2(blur_radius_mod,blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(0,blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(-blur_radius_mod,blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(-blur_radius_mod,0.0));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(-blur_radius_mod,-blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(0.0,-blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(blur_radius_mod,-blur_radius_mod));
    blur_kernel+=texture2DRect(tex0,texCoordVarying+vec2(blur_radius_mod,0.0));
    
    blur_kernel*=.125;
    
    color_blur.rgb=texture2DRect(tex0,texCoordVarying).rgb*(1.0-blur_mod)+blur_kernel.rgb*blur_mod;
    
   //lets also try a different blur sometime, this looks lame
    //do a half assed kawase for only 5 lookups first, compare with 9
    
    //gaussian blur
    // ok lets blur this here
    //horizontals
    /*
    color_blur += 0.000229 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * -4.0, 0.0));
    color_blur += 0.005977 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * -3.0, 0.0));
    color_blur += 0.060598 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * -2.0, 0.0));
    color_blur += 0.241732 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * -1.0, 0.0));
    
    color_blur += 0.382928 * texture2DRect(tex0, texCoordVarying + vec2(0.0, 0));
    
    color_blur += 0.241732 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * 1.0, 0.0));
    color_blur += 0.060598 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * 2.0, 0.0));
    color_blur += 0.005977 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * 3.0, 0.0));
    color_blur += 0.000229 * texture2DRect(tex0, texCoordVarying + vec2(blur_mod * 4.0, 0.0));
    
    //verticlas
    color_blur += 0.000229 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * 4.0));
    color_blur += 0.005977 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * 3.0));
    color_blur += 0.060598 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * 2.0));
    color_blur += 0.241732 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * 1.0));
    
    color_blur += 0.382928 * texture2DRect(tex0, texCoordVarying + vec2(0.0, 0.0));
    
    color_blur += 0.241732 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * -1.0));
    color_blur += 0.060598 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * -2.0));
    color_blur += 0.005977 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * -3.0));
    color_blur += 0.000229 * texture2DRect(tex0, texCoordVarying + vec2(0.0, blur_mod * -4.0));
    //divide by two because
    color_blur=color_blur/2;
    */
    
  
    gl_FragColor =color_blur;
}
