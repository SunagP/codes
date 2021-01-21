import turtle

x=turtle.Turtle()
y=10
for z in range(100):

    x.forward(y*z)
    x.left(90)
    x.forward(100)
    x.left(90)
