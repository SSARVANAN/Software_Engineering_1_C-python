From this full codebase in C++ (yes, we're moving on), starting from Point2D as seen during the course, making it richer, and going to StraightLine via LineSegment, you have an full implementation of a "Polygonal Chain", using a "next shortest line segment" implementation, rather similar to the "next best route" for TCP/IP.

The provided implementation in C++ is of a decent professional standard in software engineering (albeit not using latest C++ features): a library is created, compiling and linking processes are controlled for 32 and 64 bit, project build orders and dependencies are set.
You are not required to solve an algorithmic problem but rather use all the possibilities of standard Python to also reach a "clean" implementation.

Using this codebase to be converted in Python is a interesting exercise for becoming more "fluent" in Python.

Some code is very C++ specific and makes no sense in Python (i.e. the friend methods that you'll discover or the question of passing parameters either by copy or address), some standard C++ will be more difficult to "translate" in Python (i.e. the great C++ algorithm class which has no direct match in Python)

The only thing I'm asking not to do: refrain to use numpy or pandas and to try and stick to the Python Standard Library as the objective is for you to practice Python coding.
