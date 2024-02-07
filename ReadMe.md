The problem to solve is following:
                You monitor devices, which are sending data to you.
                Each device has a unique name.
                Each device produces measurements.

The challenge is:
                Compute the number of messages you got or read from the devices.

The solution has to be in C++.

The scope is open, you must decide how the “devices” will work in your system.

The solution should be posted on GitHub or a similar page for review.

**Instructions how to run/read solution**

You can clone repository and execute file test_assignment2/x64/Debug/iterview_test_assignment.exe

To run and debug code you should open project solution file in Visual Studio and have c++ development stuff installed 

**Solution explanation**

I reused observer pattern, I have observer class that writes all data sent from devices to log file, 

also I defined device interface for all devices so each of them have to assign observer in constructor

Also I prepared 2 classes like SpeedSensor and AirFlowSensor that can update sensor values and send them to observer with a timestamp and sensor name that sent the data

In main function it loops endlessly and updates sensor data randomly and notifies observer every 5 seconds

Data can be updated from some callback, event or network request in specific cases, I kept it simple to show approach

Also I believe it can be done asyncronously so each device has own thread and observer watches them from main thread in case this monitoring needs to be done in background
