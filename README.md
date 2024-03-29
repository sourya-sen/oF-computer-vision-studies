Personal studies in computer vision using openFrameworks and ofxCv as a lot of the resources and examples out there seem to be out of date with the latest oF version (0.10.x+). For posterity, will be maintaining a log here, in case it comes in handy for anyone else out there but I cannot promise that these will be the most efficient way of doing things. Feel free to follow along and send PRs in case you notice anything untoward.

Dependencies / [openFrameworks 0.10.x](https://openFrameworks.cc), [ofxCv](https://github.com/kylemcdonald/ofxCv), ofxGui (for some projects).

## 00_Thresholding
![Thresholding-example](screenshots/00-Thresholding.png)

Opens the camera, converts to grayscale, and visualizes thresholding and autothresholding. Pressing `up arrow` increases the threshold value and `down arrow` decreases the threshold value.

Based on [example-threshold](https://github.com/kylemcdonald/ofxCv/tree/master/example-threshold) from the ofxCv repository.

## 01_FrameDifferencing
![Differencing-Example](screenshots/01-Differencing.png)

Plays back file, converts to grayscale, visualizes absolute frame difference, amplified frame difference and visualized buffer holding frame difference values.

Based on the [motion detection example](https://github.com/firmread/ofDemystified/tree/master/09-OpenCV-01-MotionDetection) from the book [Creative Coding Demysitfied by Denis Perevalov](https://www.packtpub.com/in/application-development/mastering-openframeworks-creative-coding-demystified).

## 02_Blurs
![Blurs-Example](screenshots/02-Blurs.png)

Visualizing the different kind of blurs available within the `ofxCv` wrapper, optionally converting to greyscale before applying the blur. Points to note: differing frame rate/performance between RGB and greyscale versions, as well as performance of the gaussian blur filter.

## 03_LinearBlend
![LinearBlend-Example](screenshots/03-LinearBlend.png)

Based on the [linear blend tutorial on opencv.org](https://docs.opencv.org/master/d5/dc4/tutorial_adding_images.html)

## 04_BrightnessContrast
![04_BrightnessContrast-Example](screenshots/04-BrightnessContrast.png)

Based on the [Changing the contrast and brightness of an image tutorial on opencv.org](https://docs.opencv.org/master/d3/dc1/tutorial_basic_linear_transform.html).

Note: for adjusting gamma/custom LUTs, look at the [ofxCV gamma example](https://github.com/kylemcdonald/ofxCv/tree/master/example-gamma) which is similar to the follow up to the aforementioned openCV tutorial.

## 05_MeshFlow
![05_MeshFlow-Example](screenshots/05-MeshFlow.png)

Based on the [flow-distort-example in the ofxCv repo](https://github.com/kylemcdonald/ofxCv/tree/master/example-flow-distort) but modified and updated with inspiration from the Video Morphing Example from [Creative Coding Demysitfied by Denis Perevalov](https://www.packtpub.com/in/application-development/mastering-openframeworks-creative-coding-demystified).
