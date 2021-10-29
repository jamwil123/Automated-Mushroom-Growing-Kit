Automated Mushroom Growing Box

This is a place to document my journey on this project 

This is my first-ever Arduino project, the main motivation was so that I wouldn't have to look after my small mushroom growing farm 24/7. The process of having to fan and mist the mushroom 2-3 times a day sounded laborious. 

Sure there are off the shelf products that could do what I am setting out to do, but these products are expensive, I would need several of them and let's face it, It's not as fun. 

I started out with a parts list of what I'd need for the project and started with some basic Arduino tests, like traffic lights and displaying tests on a liquid crystal screen. 

Once the hardware was purchased, I started to plan the software. Taking on a project like this for the first time isn't going to be easy. This is my first Arduino project and even my first exposure to real-world code, also in a language I have no experience. 

I started by documenting what I will need to do with some pseudocode 

// list of tasks 

// 1. Lights turn off after 12 hours and stay on for 12 hours 
// 2. Water is pumped into the monotub 3 times a day for XX minutes 
// 3. Fans come on after the water is pumped in and stay on for 30 seconds 
// 4. Humidity controller comes on when the humidity drops below 80% 

The first 'Function' I took on was turning lights on and off. This task was very simple, and I found that using the delay() method, I could delay the lights to stay off for a specific amount of time before the code would stop and run again. OK, so, that's one done, right? 

I moved onto the fans that would need to come on 3 times a day for around 3-4 mins at a time. Again, this task wasn't too hard, and I found myself using the same delay() method to solve the problem. I quickly realised that once I ran the script, the code would delay on the first function and then stay there until the delay ends and then run the next line. This was a big problem as I needed all the code to run at the same time. 

I Googled the issue for a short while, until I stumbled onto Millis(). Now, as a juvenile in all of this, I thought it would be a simple implementation that would be as simple as a copy and paste, but that wasn't the case. Having looked back now I know more, I realise this is asynchronous code, and I was undertaking a bit of a large task for a rookie. 

I watched lots of YouTube videos and read lots of documentation, and eventually I understood it enough to implement it. This was exactly what I needed, and it opened the door for the project to be completed. 

After implementing millis, the rest of the code was relatively simple, and I very much enjoyed watching the code grow. 

The system has worked well in my setup since, and it has saved me a lot of time. I have been able to dial in the misting and the fanning for specific species. In the future I would love to install a Bluetooth receiver and be able to update the script wirelessly. Also, another feature I would love to implement is an over the internet sensor data tracker. This would allow me to view the data from anywhere in the world. If I managed to implement that feature, I would then implement a web app with a GUI that would allow me to dial in the mist amount, time, fan speed and temperature. 


Overall, this has been a very fun project that I am quite proud of. It was a problem I wanted to solve, but off the shelf products didn't do it all, so I made my own. Thanks for reading. 

James


