# flight_sim1
flight_sim1 is an interpreter for a language that Dr. Eliahu Khalastchi has invented.
It takes a text file and converts it into a running program (which fly an airplane), using the [Flightgear](https://www.flightgear.org/) simulator.

# running the program
In order to run the project you need to clone it and use the following command:
```
 g++ -std=c++14 */*.cpp */*/*.cpp  *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
 ```
 
In addition, you need to provide a text file for the program to interpret, and a xml file of the flight simulator values

# Github link
[Our Project](https://github.com/YekaterinaB/flight_sim1)
