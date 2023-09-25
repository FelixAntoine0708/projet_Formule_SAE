import turtle as t

s = t.Screen()
t.hideturtle()
t.speed(200)

def battery():
    t.circle(80)
    t.penup()
    t.right(270)
    t.forward(20)
    t.right(90)
    t.pendown()
    t.circle(60)
    t.penup()

def pourcentage(p):
    angles = calcul_angle(p)
    t.right(270)
    t.forward(140)
    t.right(180)
    t.pendown()
    t.forward(84)
    t.left(180)
    t.right(angles)
    t.forward(85)
    t.right(angles)
    t.circle(60,angles)
    #t.fillcolor(0,50,0)

def calcul_angle(pourcent):
    result = (360*pourcent)/100
    return result

battery()
pourcentage(20)
s.exitonclick()  