Use this unwisely, as it was made unwisely. race_random() take three arguments, a minimum, a maximum and a coefficient.
min and max are obvious. The variance_coefficient modifies the number of times the thread will increment a global variable.
Higher coefficient values lead to a more normal distribution curve, peaking at the midpoint between min and max.
For "true" fake random, leave it at 1.

Enjoy.
