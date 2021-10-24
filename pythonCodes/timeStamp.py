dob="23-03-2001"
time="20-19-56"
ms=1
def time_stamp(dob,time):
    global ms
    date=''.join(dob.split("-"))
    hrs,mins,sec=time.split("-")
    Isecs=int(hrs)*60*60+int(mins)*60+int(sec)+(ms/1000)
    ms=ms+1
    date+=str(''.join(str(Isecs).split(".")))
    print(date)
    print(ms)
    return date
time_stamp(dob,time)
time_stamp(dob,time)
time_stamp(dob,time)
time_stamp(dob,time)