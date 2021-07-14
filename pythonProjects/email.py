import smtplib
# import speech_recognition as sr
# import pyttsx3
from email.message import EmailMessage

# listener = sr.Recognizer()
engine = pyttsx3.init()


# def talk(text):
#     engine.say(text)
#     engine.runAndWait()
#

# def get_info():
#     try:
#         with sr.Microphone() as source:
#             print('listening...')
#             voice = listener.listen(source)
#             info = listener.recognize_google(voice)
#             print(info)
#             return info.lower()
#     except:
#         pass


def send_email(receiver, subject, message):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    # Make sure to give app access in your Google account
    server.login('sunag.p3007@gmail.com', 'Pannag@2707')
    email = EmailMessage()
    email['From'] = 'Sender_Email'
    email['To'] = receiver
    email['Subject'] = subject
    email.set_content(message)
    server.send_message(email)


email_list = {
    'sunag': 'sunag.p3007@gmail.com',
    'abc': 'rajiniprabhakar65@gmail.com',
    'pannag': 'pannag.amidhal2707@gmail.com'

}


def get_email_info():
    talk('To Whom you want to send email')
    name = get_info()
    receiver = email_list[name]
    print(receiver)
    #
    # if name in email_list:
    #     receiver = email_list[name]
    #     print(receiver)
    # else:
    #     talk("Email not found in internal database.Please check the name again")
    #     get_email_info()
    talk('What is the subject of your email?')
    subject = get_info()
    talk('Tell me the text in your email')
    message = get_info()
    send_email(receiver, subject, message)
    talk('Hey lazy ass. Your email is sent.... bye')
    # talk('Do you want to send more email?')
    # send_more = get_info()
    # if 'yes' in send_more:
    #     get_email_info()
    # else:
    #     talk("Thank you..bye")


get_email_info()
