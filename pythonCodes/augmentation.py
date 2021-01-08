import numpy as np
import random
import itertools
import librosa
import IPython.display as ipd
import matplotlib.pyplot as plt


# For reding the original file

def load_audio_file(file_path):
    #input_length = 90000       # This value changes depending on the file time length
    input_length=librosa.get_duration(filename=file_path)
    data = librosa.core.load(file_path)[0]
    if len(data)>input_length:
        data = data[:input_length]
    else:
        data = np.pad(data, (0, max(0, input_length - len(data))), "constant")
    return data
def plot_time_series(data):
    fig = plt.figure(figsize=(14, 8))
    plt.title('Raw wave ')
    plt.ylabel('Amplitude')
    plt.plot(np.linspace(0, 2, len(data)), data)
    plt.show()



data = load_audio_file("C:\\Users\\Asus\\Desktop\\pyhonCodes\\filteredDataSet\\247.wav")

plot_time_series(data)

# For listening
ipd.Audio(data, rate=20000)
# Change the rate accn to the file
