#version 120

varying vec2 texCoordVarying;

uniform sampler2DRect fb0;

uniform sampler2DRect cam1;
uniform vec4 bright_xyz;

void main(void)
{
	texCoordVarying = gl_MultiTexCoord0.xy;
    
    
    
    vec4 d = texture2DRect(fb0,texCoordVarying);
    float bright=.33*d.r+.5*d.g+.16*d.b;
    
    vec4 displace=ftransform();
   
    //if(displace.y>0.0){
        displace.y=(displace.y+bright_xyz.y*bright);
   // }
    
    //if(displace.x>0.0){
        displace.x=(displace.x+bright_xyz.x*bright);
    //}
    
  //  if(displace.z>0.0){
        displace.z=(displace.z+bright_xyz.z*bright);
    
        displace.w=(displace.w+bright_xyz.w*bright);
   // }
    
    
    
    
    
	gl_Position = displace;
}
