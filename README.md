## eo_apm_tracker
### By: Erik Olivesjoe

Simple program that keeps track of your [APM](https://en.wikipedia.org/wiki/Actions_per_minute). I use it when playing Age of Empires II.

It creates a small window in the bottom left of the screen that will track the number of actions you've made in the last 60 seconds, excluding scrolling.

It currently supports both 2560x1440 and 1920x1080.

![apm_tracker](https://user-images.githubusercontent.com/53548129/208678872-5642b132-0277-45a3-85bd-1c9c9dc9bed2.png)

Uses [wxWidget](https://www.wxwidgets.org/) as the GUI library.

#### TODO:

  Add support for more resolutions
  
  Still need to correct 1920x1080 position
  
  Expand GUI with start/stop and keeping track of open applications

  Heat map

  Store highest / lowest apm

  Calculate effective apm (https://sites.google.com/site/sc2gears/features/replay-analyzer/apm-types)
