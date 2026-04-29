import tkinter as tk


root = tk.Tk()
root.title("iris+")
root.geometry("320x500")
root.resizable(False, False)
root.configure(bg='#1E1E1E')
v = tk.IntVar() 

root.columnconfigure(0, weight=1)
root.columnconfigure(1, weight=1)

root.rowconfigure(0, weight=1)
root.rowconfigure(4, weight=1)

label = tk.Label(root, text="IP ADDRESS/DOMAIN", bg='#1E1E1E', fg="#EBE0E0")
label.grid(row=1, column=0,  columnspan=2, pady=1)


address = tk.Entry(root)
address.grid(row=2, column=0,  columnspan=2, pady=1, sticky="n")

scan = tk.Radiobutton(root, text="Port Scan", variable=v, value=1, bg='#1E1E1E', fg="#EBE0E0", highlightbackground='#282828', selectcolor="#282828", activebackground="#1E1E1E")
scan.grid(row=3, column=0, pady=5, sticky="e")

resfind = tk.Radiobutton(root, text="Resolve Finder", variable=v, value=2, bg='#1E1E1E', fg="#EBE0E0", highlightbackground ='#282828', selectcolor="#282828", activebackground="#1E1E1E")
resfind.grid(row=3, column=1, pady=5, sticky="w") 

button = tk.Button(root, text="Start", width=25, command=root.destroy, bg='#1E1E1E', fg="#EBE0E0", highlightbackground ='#282828', activebackground="#282828", activeforeground="#EBE0E0" )
button.grid(row=4, column=0, columnspan=2, pady=20, padx=20, sticky="n") 

root.mainloop()