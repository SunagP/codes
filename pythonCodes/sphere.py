from vpython import *
sph=sphere(pos =vector(0,0,0), color=vector(1,2,5), shininess = 1, opacity=0.6, radius =2, size=vector(1,1,1), texture=textures.stucco)
i = 1
dx=0.1
text(text = "Welcome", pos=vector(-2,-1,0),color = vector(2,3,6),opacity = 0.5,shininess = 1,emissive = True, font="serif") 
while(i<=1000):
    rate(10) #no. of loops per second
    sph.pos.x=sph.pos.x+dx
    i+=1