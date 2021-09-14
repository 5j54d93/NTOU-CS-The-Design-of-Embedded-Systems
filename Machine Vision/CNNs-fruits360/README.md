# Train CNNs for the fruits360 data set.

## CNN on a pretrained model.ipynb

Build a CNN on a pretrained model, ResNet50.  
Finetune the pretrained model when training my CNN.  

### 定義卷積神經網路架構：

    def fruit_model_on_pretrained(height,width,channel):
        model = Sequential(name="fruit_pretrained")

        pretrained = tf.keras.applications.resnet.ResNet50(include_top=False,input_shape=(100,100,3))
        model.add(pretrained)
        model.add(tf.keras.layers.GlobalAveragePooling2D())
        model.add(Dense(16, activation='relu'))
        model.add(Dense(16, activation='relu'))
        model.add(Dense(2,activation='softmax'))
        pretrained.trainable = False
        model.compile(loss=tf.keras.losses.SparseCategoricalCrossentropy(),optimizer='adam', metrics=['accuracy'])
        return model

        model = fruit_model_on_pretrained(100,100,3)
        model.summary()

## CNN's neural architecture include ResBlock.ipynb

Build a CNN whose neural architecture includes ResBlock.

### 定義卷積神經網路架構：

    images = keras.layers.Input(x_train.shape[1:])

    x = keras.layers.Conv2D(filters=16, kernel_size=[1,1], padding='same')(images)
    block = keras.layers.Conv2D(filters=16, kernel_size=[3,3], padding="same")(x)
    block = keras.layers.BatchNormalization()(block)
    block = keras.layers.Activation("relu")(block)
    block = keras.layers.Conv2D(filters=16, kernel_size=[3,3],padding="same")(block)
    net = keras.layers.add([x,block])
    net = keras.layers.BatchNormalization()(net)
    net = keras.layers.Activation("relu")(net)
    net = keras.layers.MaxPooling2D(pool_size=(2,2),name="block_1")(net)
    x = keras.layers.Conv2D(filters=32, kernel_size=[1,1], padding='same')(net)
    block = keras.layers.Conv2D(filters=32, kernel_size=[3,3], padding="same")(x)
    block = keras.layers.BatchNormalization()(block)
    block = keras.layers.Activation("relu")(block)
    block = keras.layers.Conv2D(filters=32, kernel_size=[3,3],padding="same")(block)
    net = keras.layers.add([x,block])net=keras.layers.BatchNormalization()(net)
    net = keras.layers.Activation("relu")(net)
    net = keras.layers.MaxPooling2D(pool_size=(2,2),name="block_2")(net)

    x = keras.layers.Conv2D(filters=64, kernel_size=[1,1], padding='same')(net)
    block = keras.layers.Conv2D(filters=64, kernel_size=[3,3], padding="same")(x)
    block = keras.layers.BatchNormalization()(block)
    block = keras.layers.Activation("relu")(block)
    block = keras.layers.Conv2D(filters=64, kernel_size=[3,3],padding="same")(block)
    net = keras.layers.add([x,block])
    net = keras.layers.Activation("relu", name="block_3")(net)

    net = keras.layers.BatchNormalization()(net)
    net = keras.layers.Dropout(0.25)(net)

    net = keras.layers.GlobalAveragePooling2D()(net)
    net = keras.layers.Dense(units=nclasses,activation="softmax")(net)

    model = keras.models.Model(inputs=images,outputs=net)
    model.summary()
