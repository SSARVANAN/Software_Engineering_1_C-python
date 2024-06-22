#!/usr/bin/env python
# coding: utf-8

# In[1]:


class Point:
    def __init__(self,a,b):
        self.x = a
        self.y = b
    def translate(self,deltax,deltay):
        #shift (x,y) to (x+deltax,y+deltay)
        self.x += deltax  # same as selfx = self.x+deltax
        self.y += deltay 
import math        
class point:
    ...
    def odistance(self):
        # Distance from(0,0)
        # from math import *
        return(sqrt(self.x*self.x)+(self.y*self.y))


# In[3]:


class Point:
    def __init__(self,a,b):
        self.r = sqrt(a*a + b*b)
        if a == 0:
            self.theta = 0
        else:
            self.theta = atan(b/a)
            
    def odistance(self):
        return(self.r)
    
    def translate(self,deltax,deltay):
        #Convert (r,theta) to (x,y) and back!


# In[ ]:




