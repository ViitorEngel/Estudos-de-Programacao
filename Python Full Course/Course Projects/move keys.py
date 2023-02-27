from tkinter import *

def move_up(event):
    label.place(x=label.winfo_x(),y=label.winfo_y()-10)
def move_down(event):
    label.place(x=label.winfo_x(),y=label.winfo_y()+10)
def move_right(event):
    label.place(x=label.winfo_x()+10,y=label.winfo_y())
def move_left(event):
    label.place(x=label.winfo_x()-10,y=label.winfo_y())

window = Tk()
window.geometry("800x800")

window.bind("<w>",move_up)
window.bind("<s>",move_down)
window.bind("<d>",move_right)
window.bind("<a>",move_left)


label = Label(window,width=6,height=3,bg="blue")
label.place(x=400,y=400)

window.mainloop()