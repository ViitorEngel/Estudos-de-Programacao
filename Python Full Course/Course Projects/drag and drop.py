from tkinter import *

def drag_start(event):
    label.startX = event.x
    label.startY = event.y

def drag_motion(event):
    x = label.winfo_x() - label.startX + event.x
    y = label.winfo_y() - label.startY + event.y
    label.place(x=x, y=y)

window = Tk()

label = Label(window,bg="red",width=10,height=5)
label.place(x=0,y=0)

label.bind("<Button-1>",drag_start)
label.bind("<B1-Motion>",drag_motion)


window.mainloop()