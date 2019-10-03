import os
def citire():
    with open('in.txt', 'r') as f:
        content=f.read()
        content=content.split(":")
        nr=content[0]
        content=content[1:]
        content=content[0].split(",")
        return nr, content

def is_split(x,y):
    if x<10 and y<10:
        if x+y==10:
            return True
    return False

def is_strike(x):
    if x==10:
        return True
    return False
def afisare(suma):
    with open('out.txt','a') as f:
        f.write(str(suma))
        f.write(",")
def eliminare_caracter():
    with open('out.txt', 'rb+') as filehandle:
        filehandle.seek(-1, os.SEEK_END)
        filehandle.truncate()

def run():
    with open('out.txt', 'w') as f:
        pass
    nr, lst=citire()
    nr=int(nr)
    lun=len(lst)
    i=0
    nr_ture=0
    suma=0
    while nr_ture<nr:
        if i<lun:
            x=int(lst[i])
            y=-1
            if is_strike(x):
                suma+=10
                i=i+1
                if i<lun:
                    x=int(lst[i])
                    i=i+1
                    if i<lun:
                        y=int(lst[i])
                        suma += y
                        i=i-1
                suma+=x
                afisare(suma)
                i=i-1
            elif not is_strike(x):
                i=i+1
                suma += x
                if i < lun:
                    y=int(lst[i])
                    suma+=y
                    if is_split(x,y):
                        x=y
                        i=i+1
                        if i < lun:
                            y=int(lst[i])
                            suma+=y
                            i=i-1
                afisare(suma)
            else:
                i=i+1
                if i < lun:
                    y=int(lst[i])
                    suma+=y
                suma+=x
                afisare(suma)
        i=i+1
        nr_ture+=1
    eliminare_caracter()
    #print(suma)


run()
