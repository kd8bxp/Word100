# Word100 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/Word100%20Library.svg?)](https://www.ardu-badge.com/Word100%20Library)  

A simple library for The "100+ Word" Arduino Audio Shield! Speak Arduino, Speak!  
by Patrick Thomas Mitchell  
http://www.engineeringshock.com/100-word-arduino-audio-shield.html  
  

## Installation

NEW Way: This library is now included in the Arduino Library manager, it's recommended to use the manager and look for Word100. This will let you receive updates quickly.  
  
OLD Way: Remove the -master from the file name, unzip and move folder to your Arduino library folder.  

## Versions

Library version 1.0 Sept 23, 2017 by LeRoy Miller  
Library version 1.5 Mar 6, 2018 Updated to work with the Little Buddy Talker made by Patrick Thomas Mitchell  
http://www.engineeringshock.com/the-little-buddy-talker-project-page.html  
Mar 16 Updated to Arduino 1.5 Library Specs. Change version numbers to Semantic
versioning. V1.5 now becomes v2.1.0 since it was a major change at the time.  
See Information_README.txt for minor changes.  
Library version 3.0.0 - Mar 19, 2018 Major change after finding some issues with LBT and 100+ Word Shield with HAM chip.  
New version has the three variations split into three different libraries, see below for more information.  
Version 4.0.0 - Apr 13, 2018 - All words are now UPPERCASE and use a underscore. This fixes a problem I found with some other libraries.  
Version 5.0.0 - May 5, 2018 - Big Buddy Talker added with over 1000+ words  
http://www.engineeringshock.com/the-big-buddy-talker-project-page.html  
Version 5.0.8 - Feb 26, 2019 - Added example for the Arduino E-Z Comms Shield for the LBT chip.  
http://www.engineeringshock.com/arduino-e-z-comms-project-page.html  
v5.1.0 - Mar 22, 2019 added support for softwareSPI - allows the 100+ Word Shield and E-Z Comms shield to work with the Leonardo and MEGA2560
Requires: The softwareSPI library by RevPhil https://github.com/RevPhil/arduino_SoftwareSPI  

## Usage

The library attempts to use the words from the word list provided by Patrick Thomas Mitchell.  For the most part this is accomplished.  
 See the Information_README.txt file for specifics on some of the words.  
  
include the library  
```#include "Word100.h"; //for the 100+ Word Shield with standard chip```   
```#include "Word100Ham.h"; //for the 100+ Word Shield with Ham chip```  
```#include "Word100LBT.h"; //for the LBT (Little Buddy Talker)```  
```#include "Word100BBT.h"; //for the BBT (Big Buddy Talker)```  
invoke the class for your device:  
```Word100 Word100(10);```   
or for the custom ham radio chip:   
```Word100ham Word100(10);```   
For Little Buddy Talker (LBT) invoke:  
```Word100lbt Word100(10);```  
For Big Buddy Talker (BBT) invoke:  
```Word100bbt Word100(7,8,9,10);```  
in setup begin the class:   
```Word100.begin();```  
say your word - examples show how to do this from an array, but...   
```Word100.say(word);```   

See Information_README.txt file for more information on the specifics of some of  
the words used in this library.   


## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2017 LeRoy Miller  
Copyright (C) 2018 LeRoy Miller  
Copyright (C) 2019 LeRoy Miller  

Portions of Code based on Matt Ganis saynumber code.  
Matt Ganis (c) 2018  

Contributions by  
Matt Ganis, Dr. H  

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
