import turtle
pen= turtle.Turtle()

pen.setheading(90)

def branch():
    pen.color("brown")
    pen.forward(40)

branch()
def branch(len):
     pen.color("brown")
     pen.forward(len)
branch(40)

def branch(len):
    pen.color("brown")
    pen.forward(len)
    pen.right(25)
    branch(len)

def branch(len):
    pen.color("brown")
    pen.forward(len)
    pen.right(25)
    branch(len-5)

def branch(len):
    if len>5:
        pen.color("brown")
        pen.forward(len)
        pen.right(25)
        branch(len-5)

def branch(len):
    if len>5:
        pen.color("green")
        pen.forward(len)
        pen.right(25)
        branch(len-5)
        pen.left(50)
        branch(len-5)
        pen.right(25)
        pen.backward(len)
branch(40)
