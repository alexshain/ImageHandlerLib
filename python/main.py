import matplotlib.pyplot as plt
import struct
import numpy as np

file_path = 'removed.raw'

with open(file_path, "rb") as file:
    # Читаем первые 16 байта для размеров массива
    header_data = file.read(16)
    dims = struct.unpack("2Q", header_data)  # 3 unsigned long long (Q)

    # Вычисляем размер массива
    total_elements = dims[0] * dims[1]

    # Читаем оставшиеся данные как 1-байтные целые числа
    array_data = np.fromfile(file, dtype=np.uint8, count=total_elements)

    # Преобразуем в 3D массив
    array_2d = array_data.reshape(dims)

plt.imshow(array_2d)
plt.colorbar()
plt.show()
