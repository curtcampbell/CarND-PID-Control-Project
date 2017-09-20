# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

####Describe the effect each of the P, I, D components had in your implementation.
**P** establishes an error correction that is proportional to the cross track error.  
Increasing this value strengthens the amount the controller will try to correct when there is error.  
Increasing this value will cause the controller to respond more quickly to error in the system.

**I** is the integral parameter.  It determines how much the controller responds to any bias in the system.  
An example of bias would be if there was a tendency for the car to pull in one direction or another.  
Maybe this could be caused by wheel alignment, or even a consistent gusty wind.  Adjusting this parameter 
determines how aggressively the controller will try to correct for any system bias.  Setting this too high 
will  cause oscillations as the controller applies too much correction when there is an error.  Additionally 
if the car gets stuck on one side or another this term will continue to increase or decrease depending on what 
side of the error the car is on.  In my run, this sent the car doing doughnuts on the side of the road.

**D** is the derivative parameter.  This term tries to dampen any oscillations caused by the P term.  This 
term will tend to be higher compared to the other terms.  Setting this term too low will not counteract 
oscillations from the P term.  Setting too high doesn't seem to have adverse affects in the simulator.  This may 
not be the case in a real system however. 

####Describe how the final hyperparameters were chosen.
I chose the final hyperparameters mostly through trial and error.  There are a few automated approaches I could 
have taken.  Twiddle is one of them.  However it was simple enough to play with it manually.  Additionally I 
feel that manually adjusting the parameters gave be a better feel for the effects of adjusting each parameter.  
I ended up settling on the following settings:

P = 0.15
I = 0.00001
D = 70.0

Overall my approach was to adjust P first, looking for produce symmetric oscillations about the center.  Next, 
I adjusted the D parameter with the goal of dampening the oscillations.  Finally, I adjusted I.  The goal was 
to eliminate any bias that would show up in the system.  In truth however, I didn't really perceive any bias 
so this parameter was set really now.
