import tensorflow as tf
import numpy
x = tf.data.Dataset.range(5,15)
y = tf.data.Dataset.range(-1,-50,-1)

zipped=tf.data.Dataset.zip((x,y))
b=zipped.batch(7)
for batch in b.take(4):
    print([i.numpy()for i in batch])
