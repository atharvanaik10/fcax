# Video Processing using OpenCV and Cinder
### Project Description
I want to create a video processing engine using OpenCV. This will combine multiple features that are distinct, like image extraction, frame reading, video stabilization, and frame-by-france enhancement. A passed in file by the user will be read by OpenCV, and I'll use Fast Fourier Transforms to detect blurry frames, and stabilize them. Then, I'll try to enhance every frame (editing exposure, saturation etc.) to make it look better than original. This is more of a challenge since I need to make sure that it looks uniform over the whole video.

### Background and Internal Value
As a filmmaker, I think that color correction and stabilization are the biggest annoyances of editing. I thought it'd be cool to make something that does it for you. I know that it probably won't be as good as I'm thinking it will, but the proof of concept is satisfying in and of itself. 
As far as background knowledge about actually building it goes, I've never used OpenCV in such a capacity, and I read that Cinder integrates with OpenCV really well, so I want to try that out. 

### Timeline
- [ ] **Week 1:** Implement file input and frame extraction through Cinder
- [ ] **Week 2:** Pass frames into OpenCV and stabilize video. Enable video playback in Cinder app.
- [ ] **Week 3:** Pass frames into OpenCV to enhance images. Show 'before' and 'after' in Cinder app.

### Strech Goals
If I finish early, some stretch goals can be:
* Get user input for color correction (for fine tuning)
* Implement object detection within the video

