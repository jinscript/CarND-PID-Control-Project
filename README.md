# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Effect of PID
### P controller
P controller sets steering angle proportion to the cross track error in order to drive towards
the middle of the lane. However, it overshoots badly so that the car drives in a zig zag manner
and eventually goes off the lane.

### D controller
D controller with proper parameter mitigates the overshooting effect and let the car drive smoothly
towards the middle of the lane. PD controller works well in most of the senarios in the simulation.

### I controller
I controller counters the bias in the system such as steering drift. In the simulation, it helps
the car turn smoother on sharp angles.

## Hyperparameter Selection
Hyperparameters are tuned manually at the beginning. After getting a set of parameters that car
can drive on the road for 5 seconds, Twiddle is used for searching an optimal set of parameters
for the controller. The controller is evaluated by the average cross track error on first 500
data points. The optimal hyperparameters are obtained at the time Twiddle converges.
