# VIDEO_WAAAVES_1.5
a video mixer, framebuffer delay, and feedback resynthesis engine built in openFrameworks https://openframeworks.cc/

OK! so installing from these files here on the github are kind of only for folks reasonably well versed in navigating openFrameworks already!  I can't really help anyone out anymore with this sort of thing as the volume of requests has greatly outpaced the amount of time I can afford to spend on that! But for everyone who has no idea what the heck an open frame work is don't worry I jurry rigged a reasonable solution for yalls!  Download the zip here https://drive.google.com/open?id=1a2TScyK68Qm4_pSTsc3hG2fPHbgm-uLf, unzip and follow the instructions in the txt file named "(()))00ReadThisTextFile!" and have fun!

The most notable thing about the Square root of Pi update (~1.77245385091...) is a new beta test of midi functionality.  scroll down to the bottom of this readme for midi cc lists!

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/hypercuuube.png)

requires ofxSyphon https://github.com/astellato/ofxSyphon, 
ofxMidi https://github.com/danomatika/ofxMidi, 
and ofxDatGui https://github.com/braitsch/ofxDatGui addons

for windows and linux check the noSyphon folder for alternate versions of some files to copy over into the src folder to get u up and running in syphon free zones

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/swirl.png)

if you have never used oF and/or Xcode before here are some troubleshooting tips to try before contacting me
1. the entire folder structure needs to be intact and moved into the apps/myApps folder within the openframeworks folder
2. try running project generator and importing this folder (with the abovementioned addons) if theres still errors
3. https://openframeworks.cc/setup/xcode/ has some advice on how to troubleshoot troublesome addons as well so check this out too!

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/vlcsnap-2019-08-10-22h55m38s489.png)

numereous secret keyboard commands
to scale syphon input press[] and ;/

to rotate and shift framebuffer xyz positions a,z,s,x,d,c,f,v,g,b,h,n,t,y can all be used, the numerical key '3' resets all positions

the numerical key '1'clears the framebuffer

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/vlcsnap-2019-08-10-22h57m07s147.png)


check within the code for more tips on how to use this as a music visualizer, for playing video loops, and for midi mapping controls 

https://youtu.be/PYapmZSiSE4 is a handy dandy video tutorial on how to get started playing around in heres!

https://youtu.be/LNDmF9-AcW8 on how to use the audio visualizer and midi mapping functions

https://vimeo.com/andreijay for many examples of this program in action.  





midi cc list for video waaaves!
ch1 hue  20

ch1 saturation  21

ch1 brightness  22


blur -25

sharpen 24

fb0 key V 28

fb0 mix 29

fb0 delay 30

fb0 x  4

fb0 y  3

fb0 z  12

fb0 rotate 11

fb0 hue 5

fb0 sat 2

fb0 bright 13

fb0 huemod 16-not bipolar

fb0 hueoffset 10

fb0 huelfo 17

fb1 key V 31

fb1 mix 27  

fb1 delay 26

fb0 x  6

fb0 y  1

fb0 z  14

fb0 rotate 9

fb0 hue 7

fb0 sat 0

fb0 bright 15

fb0 huemod 18-not bipolar

fb0 hueoffset 8

fb0 huelfo 19
