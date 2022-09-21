## eo_apm_tracker
### By: Erik Olivesjoe

Simple program that keeps track of your [APM](https://en.wikipedia.org/wiki/Actions_per_minute). I use it when playing Age of Empires II.

It creates a small windows in the top right corner that will track the number of actions you've made in the last 60 seconds, excluding scrolling.

Currently only displays correctly for 1920x1080.

Uses [wxWidget](https://www.wxwidgets.org/) as the GUI library.

![image](https://user-images.githubusercontent.com/53548129/191281034-879ed948-1731-47b0-830a-1255291d4502.png)


#### TODO:

  Add support for more resolutions.
  
  Expand GUI with start/stop and keeping track of open applications.

  Heat map.

  Store highest / lowest apm.

  Calculate effective apm. (https://sites.google.com/site/sc2gears/features/replay-analyzer/apm-types).
