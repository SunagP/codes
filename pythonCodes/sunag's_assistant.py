import pyttsx3
import speech_recognition as sr
def take_commands():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening')
        r.pause_threshold = 0.5
        audio = r.listen(source)
        try:
            print("Recognizing")
            Query = r.recognize_google(audio)
            print("the query is printed='", Query, "'")
        except Exception as e:
            print(e)
            print("Say that again sir")
            return "None"
    return Query

def Speak(audio):
    engine = pyttsx3.init()
    voices=engine.getProperty('voices')
   # engine.setProperty('voice',voices[1].id)
    engine.say(audio)
    engine.runAndWait()



if __name__ == '__main__':
    x=1
    while x:
        command = take_commands()

        if "exit" in command:
            Speak("Sure sir! as your wish, bai")
            break
        if "shutdown" in command :
            import os
            Speak("Do you wish to shutdown your computer y/n?")
            shutdown = input("Do you wish to shutdown your computer ? (y / n): ")

            if shutdown == 'n':
            	exit()
            else:
            	os.system("shutdown /s /t 1")

        if  "hello" in command:
            Speak("Hi I am MR Sunag's Assistant , WHAT can i do for u")
        if "Instagram" in command:
            Speak("it's a social media")
        if "address" in command:
            Speak("number 151 3rd cross MEI colony laggere Bengaluru")
        if "date" in command:
            Speak("30th july 2000")
        if "parents" in command:
            Speak("Sunag is son of MR Prabhakar A S and MS Rajini P")
        if "user" in command:
            Speak("sunag is the user of this PC")
        if "details" in command:
            Speak("MR Sunag the creator of me is born in Shivamogga and currently staying in bangalore and persuing his Engineering in BMS College of Engineering")
        if "browser" in command:
            Speak("opening chrome browser for you")
            import webbrowser
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open("http://google.com")
        if "email" in command:
            import emailBot
            exec(open('emailBot.py').read())
        if "download" in  command:
            import youtubeDownloader
            exec(open('youtubeDownloader.py').read())

        if "time" in command:
            import datetime
            now=datetime.datetime.now()
            print(now)
            Speak(now)
        if "brother" in command:
            Speak("MR Pannag is the brother of sunag")
        if "star" in command:
            Speak("Sure I can")
            import turtle
            pen= turtle.Turtle()

            n=30

            for i in range(n):
                pen.forward(i*10)
                #in clockwise
                pen.right(144)

            turtle.done()

        if "tree" in command:
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
