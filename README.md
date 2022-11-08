# Cellular-Automator
A simple automaton to simulate and water flow, hacker background and a rug maker

 [demo](https://drive.google.com/file/d/18GzwUiuVNLDsyYYasL45_YDPK4vCzRZE/view?usp=sharing)
 A make file is available to make a run function.

The project started with asking the user the canvas size and making a grid(a 2D array) as my canvas
![355](https://user-images.githubusercontent.com/81000984/200462462-9902300a-c0e5-4bc8-a7e6-1b1442c9c715.png)

Then it will ask the user if they want to run a water flow function or hacking function or a rugmaker function. 

If the user picks the water flow function, first the function will slowly start to show the star line by line, this is done by reading the last line and then flipping to the next line. For example, if the input line is * * * *, then the next line will try to read the last link and if it reads a star, then it will become a space and if it's a space, it will become a star. So the result will be  * * * . Then after guid has been filed, it will flip every index and make it look like water flowing.

If the user picks the hacking function, the function this time will make a random start, and keep reading the first line. After reading the first line, the function will update all the lines to the next line and update a new line base on the previous first line. Every time time it is updated it will print all the letters in green and make it like a hacking computer screen. It’s a much complex version of the water flow and I think it’s cool

If the user picks the rugMaker, the function will first fill the first line randomly and then read the first like 3 by 3, using the last 3 nodes to create a new 3 node after the last line. After the rug has been made, the function will be “Hacked” and the hacking function. Users can’t get their final result. (It can easily be solved by just common out the hacking function)
