Fill this in before the final project deadline. Someone who has _no familiarity_ with your project should be able to read this and understand:
* what your project does
* how to set it up and run it

#Final Cut Amateur X
######_(Because why pay $300?)_

Are you really bad at filming on your ridiculously expensive phone? Fret not, because FCAX will (attempt to) stabilize 
your video and color correct it for you! You'll get Roger Deakins like cinematography in no time!

On a more serious note, FCAX is a C++ application that uses OpenCV to stabilize and color correct videos. 
It's built with a [Cinder](libcinder.org) user interface. 

##Handling OpenCV 
You'll need to have OpenCV installed on your machine. The steps below show how to do that if you need to.

If you already have Homebrew installed, you can use the command ```brew install opencv```

To install homebrew, type this in your terminal (more information [here](brew.sh)): 
```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```

##Using the App
Once you've installed OpenCV, you should be ready to go. Open the project in your favourite IDE,
and edit your input and output filepaths in the `video_player.h` file. 
Once you've done this, you can simply run tha app.

Now that the original video file has been loaded, a Cinder GUI will show up 
with the original video, and the corrected video side by side.

The playbar will allow you to seek to desired locations in the video. 

You can use the `k` key to play/pause, `j` to move one frame back, and `l` to move one frame forward.

##How it works
FCAX makes use of the [OpenCV api](docs.opencv.org) to do most of the heavy lifting. 

The Stabilizer calculates frame by frame changes in the video using `cv::goodFeaturesToTrack()`, and then creates
appropriate transformations so the "good features" move in a smooth motion throughout the video. The engine then applies
this transformation accross the video and writes it to file. 

The Color Corrector uses OpenCV's white balancer (`cv::xphoto::WhiteBalancer`) to balance the colors in the video. 
It creates a new version of the images which are then passed to engine to write to file.

The CinderGUI takes in the original file (and creates a copy of it so as to not change the original) 
and also the newly written file by the engine.
It then shows the copy and the edited versions side by side. A keyboard listener listens for input keys
and a mouse listener listens for clicks and drags. 

