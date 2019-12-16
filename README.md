# VIDEO_WAAAVES_1.75
a video mixer, framebuffer delay, and feedback resynthesis engine built in openFrameworks https://openframeworks.cc/

![Image description](https://github.com/ex-zee-ex/VIDEO_WAAAVES_1_5/blob/master/hypercuuube.png)

requires ofxSyphon https://github.com/astellato/ofxSyphon, 
ofxMidi https://github.com/danomatika/ofxMidi, 
and ofxDatGui https://github.com/braitsch/ofxDatGui addons

for windows and linux check the noSyphon folder for alternate versions of some files to copy over into the src folder to get u up and running in syphon free zones

![Image description](https://github.com/ex-zee-ex/lil_waaaves/blob/master/lil_waaaves_0/Screen%20Shot%202019-11-23%20at%2011.47.25%20AM.png)

there are some potentially wonky things that can happen installing this!
0. if you're brand new to openFrameworks make sure that you've run through all the steps to get oF up and running and have tested some of the examples before installing video_waaaves.
1. when you unzip the folder after it has been downloaded the unarchiver program you used may have added an extra folder or two in process (like lil_waaaves_master->lil_waaaves->lil_waaaves_0->all the actual folder structure stuffs).  but openFrameworks has a real pathology about folder structures and is going to go kinda bonkers on you and throw some errors about not being able to find some necessary header files for compiling if you put the folder with all the code in it in several nested folders within myApps.  So check the folder structure in the picture above and make sure that matches up with what is happening in your folders!
2.  sometimes xcode will try to make duplicate xcodeproj files for this project. (i'm not sure if other ides will do this as well but it seems possible if not probable)  you can see in the picture above that there is a lil_waaaaves_0.xcodeproj and a Test_ing0.xcodeproj.  well the Test_ing0.xcodeproj is the one you need to double click on to open up in xcode, you are pretty much guaranteed some errors in yr build if you run the video_waaaves.xcodeproj!  check the youtube tutorial on getting projects downloaded from github running in openFrameworks for like animated details on this as well(https://www.youtube.com/playlist?list=PLTAAQQpCNd6Ss1fr4toVfyeCEjJ7qYKNr is a handy dandy video guide on how to get this up and running on your computer which seems to be especially helpful for anyone who is brand new to openFrameworks)!
3.  Apparantly running this project in newer versions of xcode (like 11.0 onward) will throw a "CodeSign Error" and adding --deep to "other CodeSign Flags" in "build settings" can fix this

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
