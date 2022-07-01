## To do list
#### Implement opencv module
- [x] Initialise class object as camera entity and define masks
- [x] Destroy class object as destroying all created entities during the Initialisation
- [ ] Make basic Run function to make all the stuff and return required coordinates
- [x] Make function for retrieving an image
- [x] Make function for finding colors` contours
- [x] Make function for finding contours` centers
- [ ] Debug via real-time video processing and displaying center dots on the image    
#### Implement TCP module
- [ ] Initialise class object as socket entity and define settings
- [ ] Destroy class object as destroying all created entities during the Initialisation
- [ ] Make Send function
- [ ] Make Recieve function
- [ ] Make package wrapper (json, xml (?))
- [ ] Debug via test packages    
#### Issues
- [ ] cv2.VideoCapture(0) takes near 15 secs. Speedup(?)
- [ ] Image displaying. Too complicated code. Simplify, improve (?)
- [ ] More accurate calibration. Try better camera (?)
