import tensorflow as tf
import numpy as np
from tensorflow import keras
model = tf.keras.Sequential([keras.layers.Dense(units=1, input_shape=[1])])
model.compile(optimizer='sgd', loss='mean_squared_error')
xs = np.array(['00','01','10','11'], dtype= string)
ys = np.array(['0','1','1',0], dtype= string)
model.fit(xs, ys, epochs=500)
print(model.predict([10.0]))
