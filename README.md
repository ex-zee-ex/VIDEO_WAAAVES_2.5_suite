# VIDEO_WAAAVES_1.75
a video mixer, framebuffer delay, and feedback resynthesis engine built in openFrameworks https://openframeworks.cc/

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/hypercuuube.png)

requires ofxSyphon https://github.com/astellato/ofxSyphon, 
ofxMidi https://github.com/danomatika/ofxMidi, 
and ofxDatGui https://github.com/braitsch/ofxDatGui addons

for windows and linux check the noSyphon folder for alternate versions of some files to copy over into the src folder to get u up and running in syphon free zones.  though apparantly the code will still compile on linux and windows if you just install the ofxSyphon addon over there!  it just will add nothing to the functionality

![Image description](https://github.com/ex-zee-ex/lil_waaaves/blob/master/lil_waaaves_0/Screen%20Shot%202019-11-23%20at%2011.47.25%20AM.png)

there are some potentially wonky things that can happen installing this!

0. if you're brand new to openFrameworks make sure that you've run through all the steps to get oF up and running and have tested some of the examples before installing video_waaaves.
1. when you unzip the folder after it has been downloaded the unarchiver program you used may have added an extra folder or two in process (like video_waaaves_master->video_waaaves->video_waaaves_1_75->all the actual folder structure stuffs).  but openFrameworks has a real pathology about folder structures and is going to go kinda bonkers on you and throw some errors about not being able to find some necessary header files for compiling if you put the folder with all the code in it in several nested folders within myApps.  So check the folder structure in the picture above using lil_waaaves as an example folder and make sure that matches up with what is happening in your folders!
2.  sometimes xcode will try to make duplicate xcodeproj files for this project. (i'm not sure if other ides will do this as well but it seems possible if not probable)  you can see in the picture above that there is a lil_waaaaves_0.xcodeproj and a Test_ing0.xcodeproj.  well the Test_ing0.xcodeproj is the one you need to double click on to open up in xcode, you are pretty much guaranteed some errors in yr build if you run the video_waaaves.xcodeproj!  check the youtube tutorial on getting projects downloaded from github running in openFrameworks for like animated details on this as well(https://www.youtube.com/playlist?list=PLTAAQQpCNd6Ss1fr4toVfyeCEjJ7qYKNr is a handy dandy video guide on how to get this up and running on your computer which seems to be especially helpful for anyone who is brand new to openFrameworks)!
3.  Apparantly running this project in newer versions of xcode (like 11.0 onward) will throw a "CodeSign Error" and adding --deep to "other CodeSign Flags" in "build settings" can fix this

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/vlcsnap-2019-08-10-22h55m38s489.png)

numereous secret keyboard commands
to scale syphon input press[] and ;/

to rotate and shift framebuffer xyz positions a,z,s,x,d,c,f,v,g,b,h,n,t,y can all be used, the numerical key '3' resets all positions

the numerical key '1' clears the framebuffer

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/vlcsnap-2019-08-10-22h57m07s147.png)



some notes on controls!

I will fully admit that many of the controls are obscure and nearly occult in their nomenclature and applications.  user experience is not my forte so any feedback is totally welcome.  either way here is a little guide to some of the more confusing controls.  the best advice i have before starting is simply try adjusting things very slightly at first and make sure that the channel or framebuffer you are playing with are active in the signal flow so that you can see what is happening in real time.  

fb0, fb1, fb2, fb3 (fbx for short) all refer to channels available to mix in from the framebuffer delay line ( a variable length delay line consisting of past frames which have been drawn to the screen).  in ofApp.cpp if you search for the variable "fbob" this sets the maximum length of delay time so if you are having difficulty with losing frame rate stability or other gpu issues you can try smaller values.  If you have a gpu with a lot of vram you can also try larger values for longer delay times though you will also have to edit some stuff over in the gui section as well.  default frame rate for this project is 30fps so fbob=30 means a total delay length of 1 second, fbob=60 -> 2 seconds, fbob=240 ->8 seconds etc etc. 

luma key V and luma key T refer to luma key Value (the brightness value which is keyed out) and luma key Threshold (the amount of area around the value which is also keyed out).  they work in somewhat unintuitive ways, luma key V at 0 keys out the brightest part of the input and luma key V at 1 keys out the blackest part.  for some reason the threshold thing also works inverted to how one would intuit, luma key T at 0 keys out almost the entire span from 0 to 1 around the value while luma key T at 100 keys out basically nothing.  

mix just means fading between channels. a value of 0 passes through the original channel unchanged while a value of 1 passes through only the mixed channel.  values below 0 and above 1 work in fun and unexpected ways.  often times when one ends up in a state where the screen seems to be frozen up or locked into some solid color you can try changing values of mix for any of fbx to mix more of the camera or syphon inputs in to get a reset on the feedback loops.  

blur and sharpen happen downstream from all of the mixing and other processing and are fed into the feedback loops as well so they have potentially unexpected effects from the naturally artefact amplifying effects of video feedback loops.  small values of sharpen (.03 to .13 or so) will darken the total output considerably and have an edge detect effect upon fb0 and fb1 when the brightness is on full.  larger values of sharpen (.13 on up) will have a more traditional sharpening effect upon the final draw.  

in the subfolders labeled channelxops there are some switches for hue, saturation, and brightness invert.  these switches dont actually invert the channels but turn on different kinds of inversions which work extremely well with feedback.  To invert any of these channels simply move the chxhue,chxsaturation, or chx brightness sliders over to negative values.  to see whats happening with these invert switches try putting a usb cam in channel 1, moving ch1brightness over to -1.5, point the camera at the screen and then hit the switch.  
the switches labeled satwrap and brightwrap turn on wraparound on the saturation and brightness channels.  what this means is that if you dial ch1brightness up to 2 then all brightness values over 1 will have the integer value chopped off and be remapped just to the decimal part of the value.  for example with brightwrap enabled try values of ch1brightness between 0-1 and then try ch1brightness between 1-2 and see what happens to the brightness.  the effect can have something of a topographical map effect on the brightness or saturation channels and is pretty great with camera feedback.  there is no huewrap function because hue space is naturally cyclical

the switches labeled xxxxpowmap and the sliders labled xxxxpowmap work together.  for example the slider ch1brightnesspowmap won't have any effect unless the switch ch1brightnesspowmap is enabled.  what powmap does is apply different scaling curves to the values described. these can work both as simple eqs or as crazy distortions.  for example try setting ch1brightness to 1, ch1brightwrap off, ch1brightpowmap on and then move the ch1brightpowmap slider around values between 0 and 1.  you should notice that the total brightness range of the input gets kind of squashed down.  then try values between 1 and 2.  you will notice that values of brightness near 0 become darker and values of brightness near 1 become much brighter and as the slider gets larger the more the total input ends up being close to just pretty much all total darkness and clamped out maximum brightness.  this can be handy for increasing contrast for doing screen feedback or for setting lumakey values more precisly.  then try the same stuff but with brightwrap turned on.  



in the subfolders labeled fbxops are a host of controls for affecting hue, saturation, brightness, and position of the framebuffer being mixed in.  i'm still testing all of these out in terms of how they should appear and how they should scale so bear with me!  
huex, saturationx, and brightx are all scaled from 0 to 20 on the gui but the actual effects are multipying the hsb values by the numbers rescaled from 0 to 2.0.  because multiplicative attenuations like this have an exponental effect when fed into a feedback loop it can be best to start out with moving these values between 9.0 and 11.0 to see more subtle effects of what these do, larger and smaller values will have more unpredictable and chaotic effects in practice.  hue saturation and brightness invert switches multiply each channel by -1 to extend the total range of attenuation from -2 to 2.  

huex mod, hue offset, and hue lfo all are mainly intended to adjust the hue attenuation in ways that vary the behavior up from the standard hue cycling modes, some combinations of these 3 parameters along with the huex parameter can actually affect saturation and brightness as well in surprising ways.  often times if you end up in a situation where all the hue seems to dissapear and you would like to get some back it can help to slowly move huex mod around until you start to see some strobeing effects kick in.  


x displace, y displace, z displace, and rotate all affect the general location of the framebuffer in relation to the frame being redrawn.  these can have very similar effects to that of moving a camera around while it is pointed at a screen to control the shapes and speeds of feedback effects.  for slower and softer feedback patterns try x and y displace at values between -2 and 2 and z displace values between 99 and 101 (yes for some reason z displace goes from 90 to 110 with 100 being no change in z position.  its totally weird i know!).  rotate is scaled from -PI/4 to PI/4 and happens after each of the xyz displaces occur so it an be used to get spiraling effects



check within the code for more tips on how to use this as a music visualizer, for playing video loops, and for midi mapping controls 

https://youtu.be/PYapmZSiSE4 is a handy dandy video tutorial on how to get started playing around in heres!

https://youtu.be/LNDmF9-AcW8 on how to use the audio visualizer and midi mapping functions

https://vimeo.com/andreijay for many examples of this program in action.  


if this program feels too huge I'd recommend trying out the scaled down https://github.com/ex-zee-ex/lil_waaaves for regular sized operating systems or if you're comfortable with raspberry pi try the even more scaled down https://github.com/ex-zee-ex/waaaave_pool
