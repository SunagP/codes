import turtle , time
pen= turtle.Turtle()

def eye(col,rad):

    pen.down()
    pen.fillcolor(col)
    pen.begin_fill()
    pen.circle(rad)
    pen.fill_end()
    pen.up()

#face
pen.fillcolor("yellow")
pen.begin_fill()
pen.circle(100)
pen.end_fill()
pen.up()

#drawing eye
pen.goto(-40,120)
eye('white',15)
pen.goto(-37,125)
eye('brown',5)
pen.goto(40,120)
eye('white',15)
pen.goto(40,125)
eye('brown',5)
#drawing nose

pen.goto(0,75)
eye('black',8)
#mouth
pen.goto(-40,85)
pen.down()
pen.right(90)
pen.circle(40,180)
pen.up()

#tongue
pen.goto(-10,45)
pen.down()
pen.right(100)
pen.fillcolor("red")
pen.begin_fill()
pen.circle(10,180)
pen.end_fill()
pen.hideturtle()

time.sleep(10)
