import streamlit as st
import string
import joblib
import nltk
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
stemmer = PorterStemmer()


def transform_text(text):
    text = text.lower()
    text = nltk.word_tokenize(text)

    y = []
    for i in text:
        if i.isalnum:
            y.append(i)

    text = y[:]
    y.clear()

    for i in text:
        if i not in stopwords.words('english') and i not in string.punctuation:
            y.append(i)

    text = y[:]
    y.clear()

    for i in text:
        y.append(stemmer.stem(i))

    return " ".join(y)


tfidf = joblib.load(r'C:\Users\Asus\Desktop\GIT\codes\MLG\vectorizer.pkl')
model = joblib.load(r'C:\Users\Asus\Desktop\GIT\codes\MLG\model.pkl')

st.title("E-mail/SMS Spam Classifier")

inputtxt = st.text_area("Enter the contents of the e-mail to detect:")

if st.button('Predict'):
    # 1. Preprocess
    transformed_text = transform_text(inputtxt)
    # 2. Vectorize
    vectored_text = tfidf.fit_transform([transformed_text])
    # 3. Predict
    result = model.predict(vectored_text)[0]
    # 4. Display
    if result == 1:
        st.header("Spam")
    else:
        st.header("Not-Spam")
