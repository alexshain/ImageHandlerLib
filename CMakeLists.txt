cmake_minimum_required(VERSION 3.29)

project(quasi-one-dimensional LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Исполняемый файл с указанием исходных файлов
add_executable(image_lib 
			src/main.cpp
			src/consoleApplicationImageOperation.cpp
			src/file_operations.cpp
			src/image_handler/factory/imageHandlerFactory.cpp 
			src/image_handler/addWallsHandler.cpp 
			src/image_handler/cutOutAreaHandler.cpp 
			src/image_handler/removeClosedPoresHandler.cpp 
			src/image_handler/slice3DImage.cpp
			src/standard_image_lib/factory/standardImageFactory.cpp
			src/standard_image_lib/circle.cpp
			src/standard_image_lib/sinusoidalChannel.cpp
			src/standard_image_lib/twoChannels.cpp
			src/standard_image_lib/standardImage.cpp)

